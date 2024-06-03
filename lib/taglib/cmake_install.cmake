# Install script for directory: /home/phuongvn/Downloads/taglib/taglib

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/phuongvn/Downloads/taglib/build/taglib/libtag.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/taglib" TYPE FILE FILES
    "/home/phuongvn/Downloads/taglib/taglib/tag.h"
    "/home/phuongvn/Downloads/taglib/taglib/fileref.h"
    "/home/phuongvn/Downloads/taglib/taglib/audioproperties.h"
    "/home/phuongvn/Downloads/taglib/taglib/taglib_export.h"
    "/home/phuongvn/Downloads/taglib/taglib/toolkit/taglib.h"
    "/home/phuongvn/Downloads/taglib/taglib/toolkit/tstring.h"
    "/home/phuongvn/Downloads/taglib/taglib/toolkit/tlist.h"
    "/home/phuongvn/Downloads/taglib/taglib/toolkit/tlist.tcc"
    "/home/phuongvn/Downloads/taglib/taglib/toolkit/tstringlist.h"
    "/home/phuongvn/Downloads/taglib/taglib/toolkit/tbytevector.h"
    "/home/phuongvn/Downloads/taglib/taglib/toolkit/tbytevectorlist.h"
    "/home/phuongvn/Downloads/taglib/taglib/toolkit/tvariant.h"
    "/home/phuongvn/Downloads/taglib/taglib/toolkit/tbytevectorstream.h"
    "/home/phuongvn/Downloads/taglib/taglib/toolkit/tiostream.h"
    "/home/phuongvn/Downloads/taglib/taglib/toolkit/tfile.h"
    "/home/phuongvn/Downloads/taglib/taglib/toolkit/tfilestream.h"
    "/home/phuongvn/Downloads/taglib/taglib/toolkit/tmap.h"
    "/home/phuongvn/Downloads/taglib/taglib/toolkit/tmap.tcc"
    "/home/phuongvn/Downloads/taglib/taglib/toolkit/tpicturetype.h"
    "/home/phuongvn/Downloads/taglib/taglib/toolkit/tpropertymap.h"
    "/home/phuongvn/Downloads/taglib/taglib/toolkit/tdebuglistener.h"
    "/home/phuongvn/Downloads/taglib/taglib/toolkit/tversionnumber.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/mpegfile.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/mpegproperties.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/mpegheader.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/xingheader.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v1/id3v1tag.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v1/id3v1genres.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/id3v2.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/id3v2extendedheader.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/id3v2frame.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/id3v2header.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/id3v2synchdata.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/id3v2footer.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/id3v2framefactory.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/id3v2tag.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/frames/attachedpictureframe.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/frames/commentsframe.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/frames/eventtimingcodesframe.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/frames/generalencapsulatedobjectframe.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/frames/ownershipframe.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/frames/popularimeterframe.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/frames/privateframe.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/frames/relativevolumeframe.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/frames/synchronizedlyricsframe.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/frames/textidentificationframe.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/frames/uniquefileidentifierframe.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/frames/unknownframe.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/frames/unsynchronizedlyricsframe.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/frames/urllinkframe.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/frames/chapterframe.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/frames/tableofcontentsframe.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpeg/id3v2/frames/podcastframe.h"
    "/home/phuongvn/Downloads/taglib/taglib/ogg/oggfile.h"
    "/home/phuongvn/Downloads/taglib/taglib/ogg/oggpage.h"
    "/home/phuongvn/Downloads/taglib/taglib/ogg/oggpageheader.h"
    "/home/phuongvn/Downloads/taglib/taglib/ogg/xiphcomment.h"
    "/home/phuongvn/Downloads/taglib/taglib/ogg/vorbis/vorbisfile.h"
    "/home/phuongvn/Downloads/taglib/taglib/ogg/vorbis/vorbisproperties.h"
    "/home/phuongvn/Downloads/taglib/taglib/ogg/flac/oggflacfile.h"
    "/home/phuongvn/Downloads/taglib/taglib/ogg/speex/speexfile.h"
    "/home/phuongvn/Downloads/taglib/taglib/ogg/speex/speexproperties.h"
    "/home/phuongvn/Downloads/taglib/taglib/ogg/opus/opusfile.h"
    "/home/phuongvn/Downloads/taglib/taglib/ogg/opus/opusproperties.h"
    "/home/phuongvn/Downloads/taglib/taglib/flac/flacfile.h"
    "/home/phuongvn/Downloads/taglib/taglib/flac/flacpicture.h"
    "/home/phuongvn/Downloads/taglib/taglib/flac/flacproperties.h"
    "/home/phuongvn/Downloads/taglib/taglib/flac/flacmetadatablock.h"
    "/home/phuongvn/Downloads/taglib/taglib/ape/apefile.h"
    "/home/phuongvn/Downloads/taglib/taglib/ape/apeproperties.h"
    "/home/phuongvn/Downloads/taglib/taglib/ape/apetag.h"
    "/home/phuongvn/Downloads/taglib/taglib/ape/apefooter.h"
    "/home/phuongvn/Downloads/taglib/taglib/ape/apeitem.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpc/mpcfile.h"
    "/home/phuongvn/Downloads/taglib/taglib/mpc/mpcproperties.h"
    "/home/phuongvn/Downloads/taglib/taglib/wavpack/wavpackfile.h"
    "/home/phuongvn/Downloads/taglib/taglib/wavpack/wavpackproperties.h"
    "/home/phuongvn/Downloads/taglib/taglib/trueaudio/trueaudiofile.h"
    "/home/phuongvn/Downloads/taglib/taglib/trueaudio/trueaudioproperties.h"
    "/home/phuongvn/Downloads/taglib/taglib/riff/rifffile.h"
    "/home/phuongvn/Downloads/taglib/taglib/riff/aiff/aifffile.h"
    "/home/phuongvn/Downloads/taglib/taglib/riff/aiff/aiffproperties.h"
    "/home/phuongvn/Downloads/taglib/taglib/riff/wav/wavfile.h"
    "/home/phuongvn/Downloads/taglib/taglib/riff/wav/wavproperties.h"
    "/home/phuongvn/Downloads/taglib/taglib/riff/wav/infotag.h"
    "/home/phuongvn/Downloads/taglib/taglib/asf/asffile.h"
    "/home/phuongvn/Downloads/taglib/taglib/asf/asfproperties.h"
    "/home/phuongvn/Downloads/taglib/taglib/asf/asftag.h"
    "/home/phuongvn/Downloads/taglib/taglib/asf/asfattribute.h"
    "/home/phuongvn/Downloads/taglib/taglib/asf/asfpicture.h"
    "/home/phuongvn/Downloads/taglib/taglib/mp4/mp4file.h"
    "/home/phuongvn/Downloads/taglib/taglib/mp4/mp4atom.h"
    "/home/phuongvn/Downloads/taglib/taglib/mp4/mp4tag.h"
    "/home/phuongvn/Downloads/taglib/taglib/mp4/mp4item.h"
    "/home/phuongvn/Downloads/taglib/taglib/mp4/mp4properties.h"
    "/home/phuongvn/Downloads/taglib/taglib/mp4/mp4coverart.h"
    "/home/phuongvn/Downloads/taglib/taglib/mp4/mp4itemfactory.h"
    "/home/phuongvn/Downloads/taglib/taglib/mod/modfilebase.h"
    "/home/phuongvn/Downloads/taglib/taglib/mod/modfile.h"
    "/home/phuongvn/Downloads/taglib/taglib/mod/modtag.h"
    "/home/phuongvn/Downloads/taglib/taglib/mod/modproperties.h"
    "/home/phuongvn/Downloads/taglib/taglib/it/itfile.h"
    "/home/phuongvn/Downloads/taglib/taglib/it/itproperties.h"
    "/home/phuongvn/Downloads/taglib/taglib/s3m/s3mfile.h"
    "/home/phuongvn/Downloads/taglib/taglib/s3m/s3mproperties.h"
    "/home/phuongvn/Downloads/taglib/taglib/xm/xmfile.h"
    "/home/phuongvn/Downloads/taglib/taglib/xm/xmproperties.h"
    "/home/phuongvn/Downloads/taglib/taglib/dsf/dsffile.h"
    "/home/phuongvn/Downloads/taglib/taglib/dsf/dsfproperties.h"
    "/home/phuongvn/Downloads/taglib/taglib/dsdiff/dsdifffile.h"
    "/home/phuongvn/Downloads/taglib/taglib/dsdiff/dsdiffproperties.h"
    "/home/phuongvn/Downloads/taglib/taglib/dsdiff/dsdiffdiintag.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/taglib/taglib-targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/taglib/taglib-targets.cmake"
         "/home/phuongvn/Downloads/taglib/build/taglib/CMakeFiles/Export/398eef5e047a0959864f2888198961bf/taglib-targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/taglib/taglib-targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/taglib/taglib-targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/taglib" TYPE FILE FILES "/home/phuongvn/Downloads/taglib/build/taglib/CMakeFiles/Export/398eef5e047a0959864f2888198961bf/taglib-targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/taglib" TYPE FILE FILES "/home/phuongvn/Downloads/taglib/build/taglib/CMakeFiles/Export/398eef5e047a0959864f2888198961bf/taglib-targets-noconfig.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/taglib" TYPE FILE FILES
    "/home/phuongvn/Downloads/taglib/build/taglib-config.cmake"
    "/home/phuongvn/Downloads/taglib/build/taglib-config-version.cmake"
    )
endif()

