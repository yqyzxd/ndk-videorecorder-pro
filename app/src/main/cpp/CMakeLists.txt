cmake_minimum_required(VERSION 3.22.1)
set(NAME "video_recorder")
project(${NAME})


set(THIRD_PARTY "${CMAKE_SOURCE_DIR}/thirdparty")
set(FFMPEG_LIBS "${THIRD_PARTY}/prebuilt/${CMAKE_ANDROID_ARCH_ABI}/")
include_directories(${THIRD_PARTY}/ffmpeg/include/)
include_directories(${THIRD_PARTY}/sox/include/)
#链接ffmpeng
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -L${FFMPEG_LIBS}")


include_directories(libs/handler)
add_subdirectory(libs/handler)

include_directories(libgles)
add_subdirectory(libgles)

include_directories(libs/lock)
add_subdirectory(libs/lock)


include_directories(libyuv/include)
add_subdirectory(libyuv)


add_library( # Sets the name of the library.
        ${NAME}

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        camera_preview/com_wind_ndk_camera_CameraPreviewScheduler.cpp
        camera_preview/camera_preview_controller.cpp
        camera_preview/camera_filter.cpp
        camera_preview/preview_renderer.cpp
        camera_preview/screen_filter.cpp

        camera_preview/camera_preview_scheduler_caller.cpp
        camera_preview/camera_info.cpp

        encoder/video_encoder_adapter.cpp
        encoder/soft/soft_video_encoder_adapter.cpp
        encoder/soft/x264_encoder.cpp
        encoder/soft/copy_texture_renderer.cpp

        encoder/soft/x264_parser.cpp

        video_packet_pool.cpp

        com_wind_ndk_camera_VideoRecorder.cpp
        video_consumer.cpp
        video_publisher.cpp

        audio/audio_encoder.cpp
        audio/com_wind_ndk_audio_recorder_PcmCollector.cpp
        audio/pcm_collector.cpp
        audio/audio_encoder_adapter.cpp
        audio/audio_process_encoder_adapter.cpp
        audio/merger/music_merger.cpp

        audio/player/com_wind_ndk_audio_player_AudioTrackPlayer.cpp
        audio/player/audio_track_player.cpp
        audio/player/audio_track_caller.cpp
        audio/player/audio_decoder.cpp

        audio/effect/audio_effect_adapter.cpp
        audio/effect/audio_effect_builder.cpp
        audio/effect/audio_effect.cpp
        audio/effect/param/sox_filter_compressor_param.cpp
        audio/effect/param/sox_filter_equalizer_param.cpp
        audio/effect/param/sox_filter_reverb_param.cpp
        audio/effect/param/sox_filter_chain_param.cpp
        audio/effect/param/compressor_param_builder.cpp

        audio/effect/processor/audio_effect_processor_factory.cpp
        audio/effect/processor/audio_request.cpp
        audio/effect/processor/audio_response.cpp
        audio/effect/processor/audio_effect_context.cpp
        audio/effect/processor/post/audio_effect_post_processor.cpp
        audio/effect/processor/live/audio_effect_live_processor.cpp

        audio/effect/filter/audio_effect_filter_chain.cpp
        audio/effect/filter/audio_effect_filter_factory.cpp
        audio/effect/volume_adjuster.cpp

        audio/effect/filter/impl/volume_adjust/vocal_agc_volume_adjust_effect_filter.cpp
        audio/effect/filter/impl/volume_adjust/accompany_agc_volume_adjust_effect_filter.cpp
        audio/effect/filter/impl/sox_effect/compressor_effect_filter.cpp
        audio/effect/filter/impl/sox_effect/sox_base_effect.cpp
        audio/effect/filter/impl/sox_effect/sox_compressor_effect.cpp
        audio/effect/filter/impl/specific/mix_effect_filter.cpp
        audio/effect/filter/impl/specific/pitch_shift_mix_effect_filter.cpp


        video_effect/opengl_video_frame.cpp
        video_effect/video_effect_processor.cpp
        video_effect/model_filter.cpp
        video_effect/model_timeline.cpp
        video_effect/model_track.cpp
        video_effect/video_filter_utils.cpp
        video_effect/filter/selective_blur_scene/selective_blur_scene_filter.cpp
        video_effect/video_effect_cache.cpp


        video_effect/base_video_effect.cpp
        video_effect/saturation_scene/saturation_effect.cpp
        video_effect/time_stretch/time_stretch_effect.cpp
        video_effect/beautify_face/beautify_face_cool_effect.cpp
        video_effect/group_video_effect.cpp
        video_effect/beautify_face/smooth_skin_horizontal_effect.cpp
        video_effect/beautify_face/smooth_skin_vertical_effect.cpp
        video_effect/beautify_face/hue_effect.cpp
        video_effect/beautify_face/sharpen_effect.cpp
        video_effect/beautify_face/tone_curve_effect.cpp


        utils/jni_caller.cpp

        )


target_link_libraries( # Specifies the target library.
        ${NAME}

        # Links the target library to the log library
        # included in the NDK.
        log
        android
        z

        handler
        lock
        eglcore

        fdk-aac
        x264
        avcodec
        avfilter
        avformat
        avutil
        swresample
        swscale

        sox
        yuv
        )