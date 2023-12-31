package com.wind.ndk.video.recorder

import android.app.Application
import android.os.Handler
import android.os.Looper
import androidx.lifecycle.AndroidViewModel
import androidx.lifecycle.ViewModelProvider
import androidx.lifecycle.ViewModelProvider.AndroidViewModelFactory.Companion.APPLICATION_KEY
import androidx.lifecycle.viewModelScope
import androidx.lifecycle.viewmodel.CreationExtras
import androidx.lifecycle.viewmodel.initializer
import androidx.lifecycle.viewmodel.viewModelFactory
import com.wind.ndk.audio.effect.AudioEffectEQ
import com.wind.ndk.audio.effect.AudioEffectParamController
import com.wind.ndk.audio.effect.AudioEffectStyle
import com.wind.ndk.audio.effect.AudioInfo
import com.wind.ndk.audio.player.IAudioPlayer
import com.wind.ndk.audio.recorder.AudioRecorder
import com.wind.ndk.camera.CameraPreviewScheduler
import com.wind.ndk.camera.VideoRecorder
import com.wind.ndk.combine
import kotlinx.coroutines.flow.SharingStarted
import kotlinx.coroutines.flow.StateFlow
import kotlinx.coroutines.flow.stateIn
import java.io.File
import kotlin.math.pow

/**
 * FileName: VideoRecordViewModel
 * Author: wind
 * Date: 2023/5/28 11:46
 * Description:
 * Path:
 * History:
 *  <author> <time> <version> <desc>
 *
 */
class VideoRecordViewModel(
    private val mApp: Application,
    private val mVideoRecorder: VideoRecorder,
    private val mAudioPlayer:IAudioPlayer,
) : AndroidViewModel(mApp) {
    private val mInteractor=RecordingTimeInteractor()
    private val mSongInteractor=SongInteractor()
    private val mHandler = Handler(Looper.getMainLooper())
    private var mSecs = 0

    private var mAccompanyPlaying=false

    val state: StateFlow<RecordViewState> = combine(mInteractor.flow,mSongInteractor.flow){ t1,t2 ->
        RecordViewState(formattedTime=t1,song = t2)
    }
        .stateIn(
            scope = viewModelScope,
            started = SharingStarted.WhileSubscribed(),
            initialValue = RecordViewState.Empty,
        )

    init {
        mSongInteractor("")
        mInteractor(0)
    }

    private var mRecording = false
    //[-3, 3] 0代表正常不变调
    private var mPitchShiftLevel=0
    //十二平均律   每个音的频率为前一个音的“根号2开12次方”，即1.059463094359295倍。
    private var mAccompanyPitch = 1.059463094359295.toFloat().pow(mPitchShiftLevel.toFloat())


    private var mAudioVolume=1.0f
    fun onClickRecord() {
        if (!mRecording) {
            mSecs = 0
            mRecording = true

            val audioEffect = AudioEffectParamController.extractParam(AudioEffectStyle.POPULAR,AudioEffectEQ.STANDARD)
            val duration=120 * 60*1000
            val audioSampleRate=44100
            val channels=1
            val recordedTimeMillis=duration
            val totalTimeMillis=duration
            val accompanyAGCVolume=1.0f
            val audioAGCVolume=1.0f
            val audioInfo=AudioInfo(
                channels=channels,
                audioSampleRate=audioSampleRate,
                recordedTimeMillis=recordedTimeMillis,
                totalTimeMillis=totalTimeMillis,
                accompanyAGCVolume=accompanyAGCVolume,
                audioAGCVolume=audioAGCVolume,
                melFilePath = "",
                accompanyPitch = mAccompanyPitch ,
                harmonicOnlyChorus = false,
                harmonicFastMode = false,
                pitchShiftLevel = mPitchShiftLevel
            )
            audioEffect.audioVolume=mAudioVolume
            audioEffect.audioInfo=audioInfo


            val h264File = "${mApp.getExternalFilesDir(null)?.absolutePath}/record.flv"
            val file = File(h264File)
            if (file.exists()) {
                file.delete()
            }
            mVideoRecorder.startRecord(
                outputUri = h264File,
                videoFrameRate = 24,
                videoBitrate = 1280 * 720 * 4,
                videoWidth = 720,
                videoHeight = 1280,
                audioBitrate = 64 * 1000,
                audioChannels = 1, //录制的时候使用单声道，后期使用ffmpeg转化成双声道
                audioSampleRate = 44100,

                )
            startRecordingTimer()
        } else {
            mVideoRecorder.stop()
            mRecording = false
            mSecs = 0
            mInteractor(mSecs)
            mHandler.removeCallbacksAndMessages(null)
            mVideoRecorder.release()
            mAudioPlayer.stop()
            mAudioPlayer.release()
        }

    }

    fun onSongChange(song :String){
        mSongInteractor(song)

        mAudioPlayer.setDataSource("${mApp.getExternalFilesDir(null)?.absolutePath}/${song}")
        mAudioPlayer.prepare()
    }
    fun onClickPlayAccompany(){
        if (mRecording) {
            if (!mAccompanyPlaying) {
                mAudioPlayer.start()
                mAccompanyPlaying = true
            } else {
                mAudioPlayer.pause()
                mAccompanyPlaying = false
            }
        }
    }

    private fun startRecordingTimer() {
        mSecs = 0
        mInteractor(mSecs)
        runRecordingTimer()
    }



    private val mRunnable = Runnable {
        mSecs++
        runRecordingTimer()
    }

    private fun runRecordingTimer() {
        mInteractor(mSecs)
        mHandler.postDelayed(mRunnable, 1000)
    }


    override fun onCleared() {
        super.onCleared()
        if (mRecording) {
            mVideoRecorder.stop()
            mRecording = false
        }
        mVideoRecorder.release()

        mAudioPlayer.stop()
        mAudioPlayer.release()

        mHandler.removeCallbacksAndMessages(null)
    }


    companion object {
        private object CameraPreviewKeyImpl : CreationExtras.Key<CameraPreviewScheduler>

        @JvmField
        val CAMERA_PREVIEW_KEY: CreationExtras.Key<CameraPreviewScheduler> = CameraPreviewKeyImpl

        private object AudioRecorderKeyImpl : CreationExtras.Key<AudioRecorder>

        @JvmField
        val AUDIO_RECORDER_KEY: CreationExtras.Key<AudioRecorder> = AudioRecorderKeyImpl


        private object AudioPlayerKeyImpl : CreationExtras.Key<IAudioPlayer>

        @JvmField
        val AUDIO_PLAYER_KEY: CreationExtras.Key<IAudioPlayer> = AudioPlayerKeyImpl

        val Factory: ViewModelProvider.Factory = viewModelFactory {
            initializer {
                val app = this[APPLICATION_KEY] as Application
                val cameraPreviewScheduler = this[CAMERA_PREVIEW_KEY] as CameraPreviewScheduler
                val audioRecorder = this[AUDIO_RECORDER_KEY] as AudioRecorder
                val audioPlayer = this[AUDIO_PLAYER_KEY] as IAudioPlayer
                VideoRecordViewModel(app, VideoRecorder(cameraPreviewScheduler, audioRecorder),audioPlayer)
            }
        }
    }
}