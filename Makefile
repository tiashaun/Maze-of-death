#Explanation at:
#http://sites.google.com/site/michaelsafyan/coding/resources/how-to-guides/how-to-write-a-makefile
program_NAME := maze_of_death
program_CXX_SRCS := $(wildcard *.cpp)
program_CXX_OBJS := ${program_CXX_SRCS:.cpp=.o}
program_OBJS := ${program_CXX_OBJS}
program_INCLUDE_DIRS :=
program_LIBRARY_DIRS :=
#program_LIBARIES := SDL SDL_image SDL_ttf


CPPFLAGS += $(foreach includedir,$(program_INCLUDE_DIRS),-I$(includedir))
#LDFLAGS += $(foreach librarydir,$(program_LIBRARY_DIRS),-L$(librarydir))
LDFLAGS += -l SDL -l SDL_ttf -l SDL_image

.PHONY: all clean distclean

all: $(program_NAME)

$(program_NAME): $(program_OBJS)
	@echo $(LDFLAGS)
	$(LINK.cc) $(program_OBJS) -o $(program_NAME)

clean:
	@- $(RM) $(program_NAME)
	@- $(RM) $(program_OBJS)

distclean: clean

depend:
	makedepend -- $(CPPFLAGS) $(CFLAGS) -- $(program_CXX_SRCS)
# DO NOT DELETE

Enemy.o: Enemy.h Moving_Sprite.h Sprite.h /usr/include/SDL/SDL.h
Enemy.o: /usr/include/SDL/SDL_main.h /usr/include/SDL/SDL_stdinc.h
Enemy.o: /usr/include/SDL/SDL_config.h /usr/include/SDL/SDL_platform.h
Enemy.o: /usr/include/sys/types.h /usr/include/features.h
Enemy.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
Enemy.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
Enemy.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
Enemy.o: /usr/include/bits/typesizes.h /usr/include/time.h
Enemy.o: /usr/include/endian.h /usr/include/bits/endian.h
Enemy.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
Enemy.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
Enemy.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
Enemy.o: /usr/include/bits/pthreadtypes.h /usr/include/stdio.h
Enemy.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
Enemy.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
Enemy.o: /usr/include/stdlib.h /usr/include/alloca.h /usr/include/string.h
Enemy.o: /usr/include/xlocale.h /usr/include/strings.h
Enemy.o: /usr/include/inttypes.h /usr/include/stdint.h
Enemy.o: /usr/include/bits/wchar.h /usr/include/ctype.h /usr/include/iconv.h
Enemy.o: /usr/include/SDL/begin_code.h /usr/include/SDL/close_code.h
Enemy.o: /usr/include/SDL/SDL_audio.h /usr/include/SDL/SDL_error.h
Enemy.o: /usr/include/SDL/SDL_endian.h /usr/include/SDL/SDL_mutex.h
Enemy.o: /usr/include/SDL/SDL_thread.h /usr/include/SDL/SDL_rwops.h
Enemy.o: /usr/include/SDL/SDL_cdrom.h /usr/include/SDL/SDL_cpuinfo.h
Enemy.o: /usr/include/SDL/SDL_events.h /usr/include/SDL/SDL_active.h
Enemy.o: /usr/include/SDL/SDL_keyboard.h /usr/include/SDL/SDL_keysym.h
Enemy.o: /usr/include/SDL/SDL_mouse.h /usr/include/SDL/SDL_video.h
Enemy.o: /usr/include/SDL/SDL_joystick.h /usr/include/SDL/SDL_quit.h
Enemy.o: /usr/include/SDL/SDL_loadso.h /usr/include/SDL/SDL_timer.h
Enemy.o: /usr/include/SDL/SDL_version.h /usr/include/c++/4.4.3/string
Enemy.o: /usr/include/c++/4.4.3/bits/stringfwd.h
Enemy.o: /usr/include/c++/4.4.3/bits/char_traits.h
Enemy.o: /usr/include/c++/4.4.3/bits/stl_algobase.h
Enemy.o: /usr/include/c++/4.4.3/cstddef
Enemy.o: /usr/include/c++/4.4.3/bits/functexcept.h
Enemy.o: /usr/include/c++/4.4.3/exception_defines.h
Enemy.o: /usr/include/c++/4.4.3/bits/cpp_type_traits.h
Enemy.o: /usr/include/c++/4.4.3/ext/type_traits.h
Enemy.o: /usr/include/c++/4.4.3/ext/numeric_traits.h
Enemy.o: /usr/include/c++/4.4.3/bits/stl_pair.h
Enemy.o: /usr/include/c++/4.4.3/bits/move.h
Enemy.o: /usr/include/c++/4.4.3/bits/concept_check.h
Enemy.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_types.h
Enemy.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_funcs.h
Enemy.o: /usr/include/c++/4.4.3/bits/stl_iterator.h
Enemy.o: /usr/include/c++/4.4.3/debug/debug.h
Enemy.o: /usr/include/c++/4.4.3/bits/postypes.h /usr/include/c++/4.4.3/cwchar
Enemy.o: /usr/include/c++/4.4.3/cstdio
Enemy.o: /usr/include/c++/4.4.3/bits/allocator.h
Enemy.o: /usr/include/c++/4.4.3/bits/localefwd.h
Enemy.o: /usr/include/c++/4.4.3/iosfwd /usr/include/c++/4.4.3/cctype
Enemy.o: /usr/include/c++/4.4.3/bits/ostream_insert.h
Enemy.o: /usr/include/c++/4.4.3/cxxabi-forced.h
Enemy.o: /usr/include/c++/4.4.3/bits/stl_function.h
Enemy.o: /usr/include/c++/4.4.3/backward/binders.h
Enemy.o: /usr/include/c++/4.4.3/bits/basic_string.h
Enemy.o: /usr/include/c++/4.4.3/ext/atomicity.h
Enemy.o: /usr/include/c++/4.4.3/initializer_list
Enemy.o: /usr/include/c++/4.4.3/bits/basic_string.tcc
Enemy.o: /usr/include/c++/4.4.3/vector
Enemy.o: /usr/include/c++/4.4.3/bits/stl_construct.h
Enemy.o: /usr/include/c++/4.4.3/new /usr/include/c++/4.4.3/exception
Enemy.o: /usr/include/c++/4.4.3/bits/stl_uninitialized.h
Enemy.o: /usr/include/c++/4.4.3/bits/stl_vector.h
Enemy.o: /usr/include/c++/4.4.3/bits/stl_bvector.h
Enemy.o: /usr/include/c++/4.4.3/bits/vector.tcc
Enemy.o: /usr/include/c++/4.4.3/iostream /usr/include/c++/4.4.3/ostream
Enemy.o: /usr/include/c++/4.4.3/ios /usr/include/c++/4.4.3/bits/ios_base.h
Enemy.o: /usr/include/c++/4.4.3/bits/locale_classes.h
Enemy.o: /usr/include/c++/4.4.3/bits/locale_classes.tcc
Enemy.o: /usr/include/c++/4.4.3/streambuf
Enemy.o: /usr/include/c++/4.4.3/bits/streambuf.tcc
Enemy.o: /usr/include/c++/4.4.3/bits/basic_ios.h
Enemy.o: /usr/include/c++/4.4.3/bits/locale_facets.h
Enemy.o: /usr/include/c++/4.4.3/cwctype
Enemy.o: /usr/include/c++/4.4.3/bits/streambuf_iterator.h
Enemy.o: /usr/include/c++/4.4.3/bits/locale_facets.tcc
Enemy.o: /usr/include/c++/4.4.3/bits/basic_ios.tcc
Enemy.o: /usr/include/c++/4.4.3/bits/ostream.tcc
Enemy.o: /usr/include/c++/4.4.3/istream
Enemy.o: /usr/include/c++/4.4.3/bits/istream.tcc
Enemy_Reactive.o: Enemy_Reactive.h Enemy.h Moving_Sprite.h Sprite.h
Enemy_Reactive.o: /usr/include/SDL/SDL.h /usr/include/SDL/SDL_main.h
Enemy_Reactive.o: /usr/include/SDL/SDL_stdinc.h /usr/include/SDL/SDL_config.h
Enemy_Reactive.o: /usr/include/SDL/SDL_platform.h /usr/include/sys/types.h
Enemy_Reactive.o: /usr/include/features.h /usr/include/bits/predefs.h
Enemy_Reactive.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Enemy_Reactive.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
Enemy_Reactive.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
Enemy_Reactive.o: /usr/include/time.h /usr/include/endian.h
Enemy_Reactive.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
Enemy_Reactive.o: /usr/include/sys/select.h /usr/include/bits/select.h
Enemy_Reactive.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
Enemy_Reactive.o: /usr/include/sys/sysmacros.h
Enemy_Reactive.o: /usr/include/bits/pthreadtypes.h /usr/include/stdio.h
Enemy_Reactive.o: /usr/include/libio.h /usr/include/_G_config.h
Enemy_Reactive.o: /usr/include/wchar.h /usr/include/bits/stdio_lim.h
Enemy_Reactive.o: /usr/include/bits/sys_errlist.h /usr/include/stdlib.h
Enemy_Reactive.o: /usr/include/alloca.h /usr/include/string.h
Enemy_Reactive.o: /usr/include/xlocale.h /usr/include/strings.h
Enemy_Reactive.o: /usr/include/inttypes.h /usr/include/stdint.h
Enemy_Reactive.o: /usr/include/bits/wchar.h /usr/include/ctype.h
Enemy_Reactive.o: /usr/include/iconv.h /usr/include/SDL/begin_code.h
Enemy_Reactive.o: /usr/include/SDL/close_code.h /usr/include/SDL/SDL_audio.h
Enemy_Reactive.o: /usr/include/SDL/SDL_error.h /usr/include/SDL/SDL_endian.h
Enemy_Reactive.o: /usr/include/SDL/SDL_mutex.h /usr/include/SDL/SDL_thread.h
Enemy_Reactive.o: /usr/include/SDL/SDL_rwops.h /usr/include/SDL/SDL_cdrom.h
Enemy_Reactive.o: /usr/include/SDL/SDL_cpuinfo.h
Enemy_Reactive.o: /usr/include/SDL/SDL_events.h /usr/include/SDL/SDL_active.h
Enemy_Reactive.o: /usr/include/SDL/SDL_keyboard.h
Enemy_Reactive.o: /usr/include/SDL/SDL_keysym.h /usr/include/SDL/SDL_mouse.h
Enemy_Reactive.o: /usr/include/SDL/SDL_video.h
Enemy_Reactive.o: /usr/include/SDL/SDL_joystick.h /usr/include/SDL/SDL_quit.h
Enemy_Reactive.o: /usr/include/SDL/SDL_loadso.h /usr/include/SDL/SDL_timer.h
Enemy_Reactive.o: /usr/include/SDL/SDL_version.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/string
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/stringfwd.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/char_traits.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/stl_algobase.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/cstddef
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/functexcept.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/exception_defines.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/cpp_type_traits.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/ext/type_traits.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/ext/numeric_traits.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/stl_pair.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/move.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/concept_check.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_types.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_funcs.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/stl_iterator.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/debug/debug.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/postypes.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/cwchar /usr/include/c++/4.4.3/cstdio
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/allocator.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/localefwd.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/iosfwd /usr/include/c++/4.4.3/cctype
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/ostream_insert.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/cxxabi-forced.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/stl_function.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/backward/binders.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/basic_string.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/ext/atomicity.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/initializer_list
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/basic_string.tcc
Enemy_Reactive.o: /usr/include/c++/4.4.3/vector
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/stl_construct.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/new /usr/include/c++/4.4.3/exception
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/stl_uninitialized.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/stl_vector.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/stl_bvector.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/vector.tcc Level.h Gamerules.h
Enemy_Reactive.o: Game.h /usr/include/SDL/SDL_ttf.h /usr/include/SDL/SDL.h
Enemy_Reactive.o: Player.h /usr/include/c++/4.4.3/iostream
Enemy_Reactive.o: /usr/include/c++/4.4.3/ostream /usr/include/c++/4.4.3/ios
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/ios_base.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/locale_classes.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/locale_classes.tcc
Enemy_Reactive.o: /usr/include/c++/4.4.3/streambuf
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/streambuf.tcc
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/basic_ios.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/locale_facets.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/cwctype
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/streambuf_iterator.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/locale_facets.tcc
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/basic_ios.tcc
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/ostream.tcc
Enemy_Reactive.o: /usr/include/c++/4.4.3/istream
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/istream.tcc
Enemy_Reactive.o: /usr/include/c++/4.4.3/cmath /usr/include/math.h
Enemy_Reactive.o: /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h
Enemy_Reactive.o: /usr/include/bits/huge_vall.h /usr/include/bits/inf.h
Enemy_Reactive.o: /usr/include/bits/nan.h /usr/include/bits/mathdef.h
Enemy_Reactive.o: /usr/include/bits/mathcalls.h
Enemy_Reactive.o: /usr/include/c++/4.4.3/bits/cmath.tcc
Enemy_Unreactive.o: Enemy_Unreactive.h Enemy.h Moving_Sprite.h Sprite.h
Enemy_Unreactive.o: /usr/include/SDL/SDL.h /usr/include/SDL/SDL_main.h
Enemy_Unreactive.o: /usr/include/SDL/SDL_stdinc.h
Enemy_Unreactive.o: /usr/include/SDL/SDL_config.h
Enemy_Unreactive.o: /usr/include/SDL/SDL_platform.h /usr/include/sys/types.h
Enemy_Unreactive.o: /usr/include/features.h /usr/include/bits/predefs.h
Enemy_Unreactive.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Enemy_Unreactive.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
Enemy_Unreactive.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
Enemy_Unreactive.o: /usr/include/time.h /usr/include/endian.h
Enemy_Unreactive.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
Enemy_Unreactive.o: /usr/include/sys/select.h /usr/include/bits/select.h
Enemy_Unreactive.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
Enemy_Unreactive.o: /usr/include/sys/sysmacros.h
Enemy_Unreactive.o: /usr/include/bits/pthreadtypes.h /usr/include/stdio.h
Enemy_Unreactive.o: /usr/include/libio.h /usr/include/_G_config.h
Enemy_Unreactive.o: /usr/include/wchar.h /usr/include/bits/stdio_lim.h
Enemy_Unreactive.o: /usr/include/bits/sys_errlist.h /usr/include/stdlib.h
Enemy_Unreactive.o: /usr/include/alloca.h /usr/include/string.h
Enemy_Unreactive.o: /usr/include/xlocale.h /usr/include/strings.h
Enemy_Unreactive.o: /usr/include/inttypes.h /usr/include/stdint.h
Enemy_Unreactive.o: /usr/include/bits/wchar.h /usr/include/ctype.h
Enemy_Unreactive.o: /usr/include/iconv.h /usr/include/SDL/begin_code.h
Enemy_Unreactive.o: /usr/include/SDL/close_code.h
Enemy_Unreactive.o: /usr/include/SDL/SDL_audio.h /usr/include/SDL/SDL_error.h
Enemy_Unreactive.o: /usr/include/SDL/SDL_endian.h
Enemy_Unreactive.o: /usr/include/SDL/SDL_mutex.h
Enemy_Unreactive.o: /usr/include/SDL/SDL_thread.h
Enemy_Unreactive.o: /usr/include/SDL/SDL_rwops.h /usr/include/SDL/SDL_cdrom.h
Enemy_Unreactive.o: /usr/include/SDL/SDL_cpuinfo.h
Enemy_Unreactive.o: /usr/include/SDL/SDL_events.h
Enemy_Unreactive.o: /usr/include/SDL/SDL_active.h
Enemy_Unreactive.o: /usr/include/SDL/SDL_keyboard.h
Enemy_Unreactive.o: /usr/include/SDL/SDL_keysym.h
Enemy_Unreactive.o: /usr/include/SDL/SDL_mouse.h /usr/include/SDL/SDL_video.h
Enemy_Unreactive.o: /usr/include/SDL/SDL_joystick.h
Enemy_Unreactive.o: /usr/include/SDL/SDL_quit.h /usr/include/SDL/SDL_loadso.h
Enemy_Unreactive.o: /usr/include/SDL/SDL_timer.h
Enemy_Unreactive.o: /usr/include/SDL/SDL_version.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/string
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/stringfwd.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/char_traits.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/stl_algobase.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/cstddef
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/functexcept.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/exception_defines.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/cpp_type_traits.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/ext/type_traits.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/ext/numeric_traits.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/stl_pair.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/move.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/concept_check.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_types.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_funcs.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/stl_iterator.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/debug/debug.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/postypes.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/cwchar
Enemy_Unreactive.o: /usr/include/c++/4.4.3/cstdio
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/allocator.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/localefwd.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/iosfwd
Enemy_Unreactive.o: /usr/include/c++/4.4.3/cctype
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/ostream_insert.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/cxxabi-forced.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/stl_function.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/backward/binders.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/basic_string.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/ext/atomicity.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/initializer_list
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/basic_string.tcc
Enemy_Unreactive.o: /usr/include/c++/4.4.3/vector
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/stl_construct.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/new
Enemy_Unreactive.o: /usr/include/c++/4.4.3/exception
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/stl_uninitialized.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/stl_vector.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/stl_bvector.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/vector.tcc Level.h
Enemy_Unreactive.o: Gamerules.h Game.h /usr/include/SDL/SDL_ttf.h
Enemy_Unreactive.o: /usr/include/SDL/SDL.h /usr/include/c++/4.4.3/iostream
Enemy_Unreactive.o: /usr/include/c++/4.4.3/ostream /usr/include/c++/4.4.3/ios
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/ios_base.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/locale_classes.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/locale_classes.tcc
Enemy_Unreactive.o: /usr/include/c++/4.4.3/streambuf
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/streambuf.tcc
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/basic_ios.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/locale_facets.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/cwctype
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/streambuf_iterator.h
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/locale_facets.tcc
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/basic_ios.tcc
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/ostream.tcc
Enemy_Unreactive.o: /usr/include/c++/4.4.3/istream
Enemy_Unreactive.o: /usr/include/c++/4.4.3/bits/istream.tcc
Exit.o: Exit.h Sprite.h /usr/include/SDL/SDL.h /usr/include/SDL/SDL_main.h
Exit.o: /usr/include/SDL/SDL_stdinc.h /usr/include/SDL/SDL_config.h
Exit.o: /usr/include/SDL/SDL_platform.h /usr/include/sys/types.h
Exit.o: /usr/include/features.h /usr/include/bits/predefs.h
Exit.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Exit.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
Exit.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
Exit.o: /usr/include/time.h /usr/include/endian.h /usr/include/bits/endian.h
Exit.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
Exit.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
Exit.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
Exit.o: /usr/include/bits/pthreadtypes.h /usr/include/stdio.h
Exit.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
Exit.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
Exit.o: /usr/include/stdlib.h /usr/include/alloca.h /usr/include/string.h
Exit.o: /usr/include/xlocale.h /usr/include/strings.h /usr/include/inttypes.h
Exit.o: /usr/include/stdint.h /usr/include/bits/wchar.h /usr/include/ctype.h
Exit.o: /usr/include/iconv.h /usr/include/SDL/begin_code.h
Exit.o: /usr/include/SDL/close_code.h /usr/include/SDL/SDL_audio.h
Exit.o: /usr/include/SDL/SDL_error.h /usr/include/SDL/SDL_endian.h
Exit.o: /usr/include/SDL/SDL_mutex.h /usr/include/SDL/SDL_thread.h
Exit.o: /usr/include/SDL/SDL_rwops.h /usr/include/SDL/SDL_cdrom.h
Exit.o: /usr/include/SDL/SDL_cpuinfo.h /usr/include/SDL/SDL_events.h
Exit.o: /usr/include/SDL/SDL_active.h /usr/include/SDL/SDL_keyboard.h
Exit.o: /usr/include/SDL/SDL_keysym.h /usr/include/SDL/SDL_mouse.h
Exit.o: /usr/include/SDL/SDL_video.h /usr/include/SDL/SDL_joystick.h
Exit.o: /usr/include/SDL/SDL_quit.h /usr/include/SDL/SDL_loadso.h
Exit.o: /usr/include/SDL/SDL_timer.h /usr/include/SDL/SDL_version.h
Exit.o: /usr/include/c++/4.4.3/string /usr/include/c++/4.4.3/bits/stringfwd.h
Exit.o: /usr/include/c++/4.4.3/bits/char_traits.h
Exit.o: /usr/include/c++/4.4.3/bits/stl_algobase.h
Exit.o: /usr/include/c++/4.4.3/cstddef
Exit.o: /usr/include/c++/4.4.3/bits/functexcept.h
Exit.o: /usr/include/c++/4.4.3/exception_defines.h
Exit.o: /usr/include/c++/4.4.3/bits/cpp_type_traits.h
Exit.o: /usr/include/c++/4.4.3/ext/type_traits.h
Exit.o: /usr/include/c++/4.4.3/ext/numeric_traits.h
Exit.o: /usr/include/c++/4.4.3/bits/stl_pair.h
Exit.o: /usr/include/c++/4.4.3/bits/move.h
Exit.o: /usr/include/c++/4.4.3/bits/concept_check.h
Exit.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_types.h
Exit.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_funcs.h
Exit.o: /usr/include/c++/4.4.3/bits/stl_iterator.h
Exit.o: /usr/include/c++/4.4.3/debug/debug.h
Exit.o: /usr/include/c++/4.4.3/bits/postypes.h /usr/include/c++/4.4.3/cwchar
Exit.o: /usr/include/c++/4.4.3/cstdio /usr/include/c++/4.4.3/bits/allocator.h
Exit.o: /usr/include/c++/4.4.3/bits/localefwd.h /usr/include/c++/4.4.3/iosfwd
Exit.o: /usr/include/c++/4.4.3/cctype
Exit.o: /usr/include/c++/4.4.3/bits/ostream_insert.h
Exit.o: /usr/include/c++/4.4.3/cxxabi-forced.h
Exit.o: /usr/include/c++/4.4.3/bits/stl_function.h
Exit.o: /usr/include/c++/4.4.3/backward/binders.h
Exit.o: /usr/include/c++/4.4.3/bits/basic_string.h
Exit.o: /usr/include/c++/4.4.3/ext/atomicity.h
Exit.o: /usr/include/c++/4.4.3/initializer_list
Exit.o: /usr/include/c++/4.4.3/bits/basic_string.tcc Level.h Gamerules.h
Exit.o: /usr/include/c++/4.4.3/vector
Exit.o: /usr/include/c++/4.4.3/bits/stl_construct.h
Exit.o: /usr/include/c++/4.4.3/new /usr/include/c++/4.4.3/exception
Exit.o: /usr/include/c++/4.4.3/bits/stl_uninitialized.h
Exit.o: /usr/include/c++/4.4.3/bits/stl_vector.h
Exit.o: /usr/include/c++/4.4.3/bits/stl_bvector.h
Exit.o: /usr/include/c++/4.4.3/bits/vector.tcc
Exit.o: /usr/include/c++/4.4.3/iostream /usr/include/c++/4.4.3/ostream
Exit.o: /usr/include/c++/4.4.3/ios /usr/include/c++/4.4.3/bits/ios_base.h
Exit.o: /usr/include/c++/4.4.3/bits/locale_classes.h
Exit.o: /usr/include/c++/4.4.3/bits/locale_classes.tcc
Exit.o: /usr/include/c++/4.4.3/streambuf
Exit.o: /usr/include/c++/4.4.3/bits/streambuf.tcc
Exit.o: /usr/include/c++/4.4.3/bits/basic_ios.h
Exit.o: /usr/include/c++/4.4.3/bits/locale_facets.h
Exit.o: /usr/include/c++/4.4.3/cwctype
Exit.o: /usr/include/c++/4.4.3/bits/streambuf_iterator.h
Exit.o: /usr/include/c++/4.4.3/bits/locale_facets.tcc
Exit.o: /usr/include/c++/4.4.3/bits/basic_ios.tcc
Exit.o: /usr/include/c++/4.4.3/bits/ostream.tcc
Exit.o: /usr/include/c++/4.4.3/istream
Exit.o: /usr/include/c++/4.4.3/bits/istream.tcc
Game.o: Game.h /usr/include/c++/4.4.3/string
Game.o: /usr/include/c++/4.4.3/bits/stringfwd.h
Game.o: /usr/include/c++/4.4.3/bits/char_traits.h
Game.o: /usr/include/c++/4.4.3/bits/stl_algobase.h
Game.o: /usr/include/c++/4.4.3/cstddef
Game.o: /usr/include/c++/4.4.3/bits/functexcept.h
Game.o: /usr/include/c++/4.4.3/exception_defines.h
Game.o: /usr/include/c++/4.4.3/bits/cpp_type_traits.h
Game.o: /usr/include/c++/4.4.3/ext/type_traits.h
Game.o: /usr/include/c++/4.4.3/ext/numeric_traits.h
Game.o: /usr/include/c++/4.4.3/bits/stl_pair.h
Game.o: /usr/include/c++/4.4.3/bits/move.h
Game.o: /usr/include/c++/4.4.3/bits/concept_check.h
Game.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_types.h
Game.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_funcs.h
Game.o: /usr/include/c++/4.4.3/bits/stl_iterator.h
Game.o: /usr/include/c++/4.4.3/debug/debug.h
Game.o: /usr/include/c++/4.4.3/bits/postypes.h /usr/include/c++/4.4.3/cwchar
Game.o: /usr/include/c++/4.4.3/cstdio /usr/include/stdio.h
Game.o: /usr/include/features.h /usr/include/bits/predefs.h
Game.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Game.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
Game.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
Game.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
Game.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
Game.o: /usr/include/c++/4.4.3/bits/allocator.h
Game.o: /usr/include/c++/4.4.3/bits/localefwd.h /usr/include/c++/4.4.3/iosfwd
Game.o: /usr/include/c++/4.4.3/cctype /usr/include/ctype.h
Game.o: /usr/include/endian.h /usr/include/bits/endian.h
Game.o: /usr/include/bits/byteswap.h /usr/include/xlocale.h
Game.o: /usr/include/c++/4.4.3/bits/ostream_insert.h
Game.o: /usr/include/c++/4.4.3/cxxabi-forced.h
Game.o: /usr/include/c++/4.4.3/bits/stl_function.h
Game.o: /usr/include/c++/4.4.3/backward/binders.h
Game.o: /usr/include/c++/4.4.3/bits/basic_string.h
Game.o: /usr/include/c++/4.4.3/ext/atomicity.h
Game.o: /usr/include/c++/4.4.3/initializer_list
Game.o: /usr/include/c++/4.4.3/bits/basic_string.tcc
Game.o: /usr/include/c++/4.4.3/vector
Game.o: /usr/include/c++/4.4.3/bits/stl_construct.h
Game.o: /usr/include/c++/4.4.3/new /usr/include/c++/4.4.3/exception
Game.o: /usr/include/c++/4.4.3/bits/stl_uninitialized.h
Game.o: /usr/include/c++/4.4.3/bits/stl_vector.h
Game.o: /usr/include/c++/4.4.3/bits/stl_bvector.h
Game.o: /usr/include/c++/4.4.3/bits/vector.tcc /usr/include/SDL/SDL.h
Game.o: /usr/include/SDL/SDL_main.h /usr/include/SDL/SDL_stdinc.h
Game.o: /usr/include/SDL/SDL_config.h /usr/include/SDL/SDL_platform.h
Game.o: /usr/include/sys/types.h /usr/include/time.h
Game.o: /usr/include/sys/select.h /usr/include/bits/select.h
Game.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
Game.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
Game.o: /usr/include/stdlib.h /usr/include/alloca.h /usr/include/string.h
Game.o: /usr/include/strings.h /usr/include/inttypes.h /usr/include/stdint.h
Game.o: /usr/include/bits/wchar.h /usr/include/iconv.h
Game.o: /usr/include/SDL/begin_code.h /usr/include/SDL/close_code.h
Game.o: /usr/include/SDL/SDL_audio.h /usr/include/SDL/SDL_error.h
Game.o: /usr/include/SDL/SDL_endian.h /usr/include/SDL/SDL_mutex.h
Game.o: /usr/include/SDL/SDL_thread.h /usr/include/SDL/SDL_rwops.h
Game.o: /usr/include/SDL/SDL_cdrom.h /usr/include/SDL/SDL_cpuinfo.h
Game.o: /usr/include/SDL/SDL_events.h /usr/include/SDL/SDL_active.h
Game.o: /usr/include/SDL/SDL_keyboard.h /usr/include/SDL/SDL_keysym.h
Game.o: /usr/include/SDL/SDL_mouse.h /usr/include/SDL/SDL_video.h
Game.o: /usr/include/SDL/SDL_joystick.h /usr/include/SDL/SDL_quit.h
Game.o: /usr/include/SDL/SDL_loadso.h /usr/include/SDL/SDL_timer.h
Game.o: /usr/include/SDL/SDL_version.h Gamerules.h /usr/include/SDL/SDL_ttf.h
Game.o: /usr/include/SDL/SDL.h Sprite.h Player.h Moving_Sprite.h Level.h
Game.o: Wall.h Timer.h Menu.h /usr/include/c++/4.4.3/iostream
Game.o: /usr/include/c++/4.4.3/ostream /usr/include/c++/4.4.3/ios
Game.o: /usr/include/c++/4.4.3/bits/ios_base.h
Game.o: /usr/include/c++/4.4.3/bits/locale_classes.h
Game.o: /usr/include/c++/4.4.3/bits/locale_classes.tcc
Game.o: /usr/include/c++/4.4.3/streambuf
Game.o: /usr/include/c++/4.4.3/bits/streambuf.tcc
Game.o: /usr/include/c++/4.4.3/bits/basic_ios.h
Game.o: /usr/include/c++/4.4.3/bits/locale_facets.h
Game.o: /usr/include/c++/4.4.3/cwctype
Game.o: /usr/include/c++/4.4.3/bits/streambuf_iterator.h
Game.o: /usr/include/c++/4.4.3/bits/locale_facets.tcc
Game.o: /usr/include/c++/4.4.3/bits/basic_ios.tcc
Game.o: /usr/include/c++/4.4.3/bits/ostream.tcc
Game.o: /usr/include/c++/4.4.3/istream
Game.o: /usr/include/c++/4.4.3/bits/istream.tcc
Gamerules.o: Gamerules.h /usr/include/c++/4.4.3/string
Gamerules.o: /usr/include/c++/4.4.3/bits/stringfwd.h
Gamerules.o: /usr/include/c++/4.4.3/bits/char_traits.h
Gamerules.o: /usr/include/c++/4.4.3/bits/stl_algobase.h
Gamerules.o: /usr/include/c++/4.4.3/cstddef
Gamerules.o: /usr/include/c++/4.4.3/bits/functexcept.h
Gamerules.o: /usr/include/c++/4.4.3/exception_defines.h
Gamerules.o: /usr/include/c++/4.4.3/bits/cpp_type_traits.h
Gamerules.o: /usr/include/c++/4.4.3/ext/type_traits.h
Gamerules.o: /usr/include/c++/4.4.3/ext/numeric_traits.h
Gamerules.o: /usr/include/c++/4.4.3/bits/stl_pair.h
Gamerules.o: /usr/include/c++/4.4.3/bits/move.h
Gamerules.o: /usr/include/c++/4.4.3/bits/concept_check.h
Gamerules.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_types.h
Gamerules.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_funcs.h
Gamerules.o: /usr/include/c++/4.4.3/bits/stl_iterator.h
Gamerules.o: /usr/include/c++/4.4.3/debug/debug.h
Gamerules.o: /usr/include/c++/4.4.3/bits/postypes.h
Gamerules.o: /usr/include/c++/4.4.3/cwchar /usr/include/c++/4.4.3/cstdio
Gamerules.o: /usr/include/stdio.h /usr/include/features.h
Gamerules.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
Gamerules.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
Gamerules.o: /usr/include/gnu/stubs-32.h /usr/include/bits/types.h
Gamerules.o: /usr/include/bits/typesizes.h /usr/include/libio.h
Gamerules.o: /usr/include/_G_config.h /usr/include/wchar.h
Gamerules.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
Gamerules.o: /usr/include/c++/4.4.3/bits/allocator.h
Gamerules.o: /usr/include/c++/4.4.3/bits/localefwd.h
Gamerules.o: /usr/include/c++/4.4.3/iosfwd /usr/include/c++/4.4.3/cctype
Gamerules.o: /usr/include/ctype.h /usr/include/endian.h
Gamerules.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
Gamerules.o: /usr/include/xlocale.h
Gamerules.o: /usr/include/c++/4.4.3/bits/ostream_insert.h
Gamerules.o: /usr/include/c++/4.4.3/cxxabi-forced.h
Gamerules.o: /usr/include/c++/4.4.3/bits/stl_function.h
Gamerules.o: /usr/include/c++/4.4.3/backward/binders.h
Gamerules.o: /usr/include/c++/4.4.3/bits/basic_string.h
Gamerules.o: /usr/include/c++/4.4.3/ext/atomicity.h
Gamerules.o: /usr/include/c++/4.4.3/initializer_list
Gamerules.o: /usr/include/c++/4.4.3/bits/basic_string.tcc
Gamerules.o: /usr/include/c++/4.4.3/vector
Gamerules.o: /usr/include/c++/4.4.3/bits/stl_construct.h
Gamerules.o: /usr/include/c++/4.4.3/new /usr/include/c++/4.4.3/exception
Gamerules.o: /usr/include/c++/4.4.3/bits/stl_uninitialized.h
Gamerules.o: /usr/include/c++/4.4.3/bits/stl_vector.h
Gamerules.o: /usr/include/c++/4.4.3/bits/stl_bvector.h
Gamerules.o: /usr/include/c++/4.4.3/bits/vector.tcc
Gamerules.o: /usr/include/c++/4.4.3/iostream /usr/include/c++/4.4.3/ostream
Gamerules.o: /usr/include/c++/4.4.3/ios
Gamerules.o: /usr/include/c++/4.4.3/bits/ios_base.h
Gamerules.o: /usr/include/c++/4.4.3/bits/locale_classes.h
Gamerules.o: /usr/include/c++/4.4.3/bits/locale_classes.tcc
Gamerules.o: /usr/include/c++/4.4.3/streambuf
Gamerules.o: /usr/include/c++/4.4.3/bits/streambuf.tcc
Gamerules.o: /usr/include/c++/4.4.3/bits/basic_ios.h
Gamerules.o: /usr/include/c++/4.4.3/bits/locale_facets.h
Gamerules.o: /usr/include/c++/4.4.3/cwctype
Gamerules.o: /usr/include/c++/4.4.3/bits/streambuf_iterator.h
Gamerules.o: /usr/include/c++/4.4.3/bits/locale_facets.tcc
Gamerules.o: /usr/include/c++/4.4.3/bits/basic_ios.tcc
Gamerules.o: /usr/include/c++/4.4.3/bits/ostream.tcc
Gamerules.o: /usr/include/c++/4.4.3/istream
Gamerules.o: /usr/include/c++/4.4.3/bits/istream.tcc
Level.o: Level.h Sprite.h /usr/include/SDL/SDL.h /usr/include/SDL/SDL_main.h
Level.o: /usr/include/SDL/SDL_stdinc.h /usr/include/SDL/SDL_config.h
Level.o: /usr/include/SDL/SDL_platform.h /usr/include/sys/types.h
Level.o: /usr/include/features.h /usr/include/bits/predefs.h
Level.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Level.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
Level.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
Level.o: /usr/include/time.h /usr/include/endian.h /usr/include/bits/endian.h
Level.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
Level.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
Level.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
Level.o: /usr/include/bits/pthreadtypes.h /usr/include/stdio.h
Level.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
Level.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
Level.o: /usr/include/stdlib.h /usr/include/alloca.h /usr/include/string.h
Level.o: /usr/include/xlocale.h /usr/include/strings.h
Level.o: /usr/include/inttypes.h /usr/include/stdint.h
Level.o: /usr/include/bits/wchar.h /usr/include/ctype.h /usr/include/iconv.h
Level.o: /usr/include/SDL/begin_code.h /usr/include/SDL/close_code.h
Level.o: /usr/include/SDL/SDL_audio.h /usr/include/SDL/SDL_error.h
Level.o: /usr/include/SDL/SDL_endian.h /usr/include/SDL/SDL_mutex.h
Level.o: /usr/include/SDL/SDL_thread.h /usr/include/SDL/SDL_rwops.h
Level.o: /usr/include/SDL/SDL_cdrom.h /usr/include/SDL/SDL_cpuinfo.h
Level.o: /usr/include/SDL/SDL_events.h /usr/include/SDL/SDL_active.h
Level.o: /usr/include/SDL/SDL_keyboard.h /usr/include/SDL/SDL_keysym.h
Level.o: /usr/include/SDL/SDL_mouse.h /usr/include/SDL/SDL_video.h
Level.o: /usr/include/SDL/SDL_joystick.h /usr/include/SDL/SDL_quit.h
Level.o: /usr/include/SDL/SDL_loadso.h /usr/include/SDL/SDL_timer.h
Level.o: /usr/include/SDL/SDL_version.h /usr/include/c++/4.4.3/string
Level.o: /usr/include/c++/4.4.3/bits/stringfwd.h
Level.o: /usr/include/c++/4.4.3/bits/char_traits.h
Level.o: /usr/include/c++/4.4.3/bits/stl_algobase.h
Level.o: /usr/include/c++/4.4.3/cstddef
Level.o: /usr/include/c++/4.4.3/bits/functexcept.h
Level.o: /usr/include/c++/4.4.3/exception_defines.h
Level.o: /usr/include/c++/4.4.3/bits/cpp_type_traits.h
Level.o: /usr/include/c++/4.4.3/ext/type_traits.h
Level.o: /usr/include/c++/4.4.3/ext/numeric_traits.h
Level.o: /usr/include/c++/4.4.3/bits/stl_pair.h
Level.o: /usr/include/c++/4.4.3/bits/move.h
Level.o: /usr/include/c++/4.4.3/bits/concept_check.h
Level.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_types.h
Level.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_funcs.h
Level.o: /usr/include/c++/4.4.3/bits/stl_iterator.h
Level.o: /usr/include/c++/4.4.3/debug/debug.h
Level.o: /usr/include/c++/4.4.3/bits/postypes.h /usr/include/c++/4.4.3/cwchar
Level.o: /usr/include/c++/4.4.3/cstdio
Level.o: /usr/include/c++/4.4.3/bits/allocator.h
Level.o: /usr/include/c++/4.4.3/bits/localefwd.h
Level.o: /usr/include/c++/4.4.3/iosfwd /usr/include/c++/4.4.3/cctype
Level.o: /usr/include/c++/4.4.3/bits/ostream_insert.h
Level.o: /usr/include/c++/4.4.3/cxxabi-forced.h
Level.o: /usr/include/c++/4.4.3/bits/stl_function.h
Level.o: /usr/include/c++/4.4.3/backward/binders.h
Level.o: /usr/include/c++/4.4.3/bits/basic_string.h
Level.o: /usr/include/c++/4.4.3/ext/atomicity.h
Level.o: /usr/include/c++/4.4.3/initializer_list
Level.o: /usr/include/c++/4.4.3/bits/basic_string.tcc Gamerules.h
Level.o: /usr/include/c++/4.4.3/vector
Level.o: /usr/include/c++/4.4.3/bits/stl_construct.h
Level.o: /usr/include/c++/4.4.3/new /usr/include/c++/4.4.3/exception
Level.o: /usr/include/c++/4.4.3/bits/stl_uninitialized.h
Level.o: /usr/include/c++/4.4.3/bits/stl_vector.h
Level.o: /usr/include/c++/4.4.3/bits/stl_bvector.h
Level.o: /usr/include/c++/4.4.3/bits/vector.tcc Moving_Sprite.h Wall.h Exit.h
Level.o: Player.h Enemy_Unreactive.h Enemy.h Enemy_Reactive.h
Level.o: /usr/include/c++/4.4.3/iostream /usr/include/c++/4.4.3/ostream
Level.o: /usr/include/c++/4.4.3/ios /usr/include/c++/4.4.3/bits/ios_base.h
Level.o: /usr/include/c++/4.4.3/bits/locale_classes.h
Level.o: /usr/include/c++/4.4.3/bits/locale_classes.tcc
Level.o: /usr/include/c++/4.4.3/streambuf
Level.o: /usr/include/c++/4.4.3/bits/streambuf.tcc
Level.o: /usr/include/c++/4.4.3/bits/basic_ios.h
Level.o: /usr/include/c++/4.4.3/bits/locale_facets.h
Level.o: /usr/include/c++/4.4.3/cwctype
Level.o: /usr/include/c++/4.4.3/bits/streambuf_iterator.h
Level.o: /usr/include/c++/4.4.3/bits/locale_facets.tcc
Level.o: /usr/include/c++/4.4.3/bits/basic_ios.tcc
Level.o: /usr/include/c++/4.4.3/bits/ostream.tcc
Level.o: /usr/include/c++/4.4.3/istream
Level.o: /usr/include/c++/4.4.3/bits/istream.tcc /usr/include/c++/4.4.3/cmath
Level.o: /usr/include/math.h /usr/include/bits/huge_val.h
Level.o: /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h
Level.o: /usr/include/bits/inf.h /usr/include/bits/nan.h
Level.o: /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h
Level.o: /usr/include/c++/4.4.3/bits/cmath.tcc
main.o: Game.h /usr/include/c++/4.4.3/string
main.o: /usr/include/c++/4.4.3/bits/stringfwd.h
main.o: /usr/include/c++/4.4.3/bits/char_traits.h
main.o: /usr/include/c++/4.4.3/bits/stl_algobase.h
main.o: /usr/include/c++/4.4.3/cstddef
main.o: /usr/include/c++/4.4.3/bits/functexcept.h
main.o: /usr/include/c++/4.4.3/exception_defines.h
main.o: /usr/include/c++/4.4.3/bits/cpp_type_traits.h
main.o: /usr/include/c++/4.4.3/ext/type_traits.h
main.o: /usr/include/c++/4.4.3/ext/numeric_traits.h
main.o: /usr/include/c++/4.4.3/bits/stl_pair.h
main.o: /usr/include/c++/4.4.3/bits/move.h
main.o: /usr/include/c++/4.4.3/bits/concept_check.h
main.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_types.h
main.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_funcs.h
main.o: /usr/include/c++/4.4.3/bits/stl_iterator.h
main.o: /usr/include/c++/4.4.3/debug/debug.h
main.o: /usr/include/c++/4.4.3/bits/postypes.h /usr/include/c++/4.4.3/cwchar
main.o: /usr/include/c++/4.4.3/cstdio /usr/include/stdio.h
main.o: /usr/include/features.h /usr/include/bits/predefs.h
main.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
main.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
main.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
main.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
main.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
main.o: /usr/include/c++/4.4.3/bits/allocator.h
main.o: /usr/include/c++/4.4.3/bits/localefwd.h /usr/include/c++/4.4.3/iosfwd
main.o: /usr/include/c++/4.4.3/cctype /usr/include/ctype.h
main.o: /usr/include/endian.h /usr/include/bits/endian.h
main.o: /usr/include/bits/byteswap.h /usr/include/xlocale.h
main.o: /usr/include/c++/4.4.3/bits/ostream_insert.h
main.o: /usr/include/c++/4.4.3/cxxabi-forced.h
main.o: /usr/include/c++/4.4.3/bits/stl_function.h
main.o: /usr/include/c++/4.4.3/backward/binders.h
main.o: /usr/include/c++/4.4.3/bits/basic_string.h
main.o: /usr/include/c++/4.4.3/ext/atomicity.h
main.o: /usr/include/c++/4.4.3/initializer_list
main.o: /usr/include/c++/4.4.3/bits/basic_string.tcc
main.o: /usr/include/c++/4.4.3/vector
main.o: /usr/include/c++/4.4.3/bits/stl_construct.h
main.o: /usr/include/c++/4.4.3/new /usr/include/c++/4.4.3/exception
main.o: /usr/include/c++/4.4.3/bits/stl_uninitialized.h
main.o: /usr/include/c++/4.4.3/bits/stl_vector.h
main.o: /usr/include/c++/4.4.3/bits/stl_bvector.h
main.o: /usr/include/c++/4.4.3/bits/vector.tcc /usr/include/SDL/SDL.h
main.o: /usr/include/SDL/SDL_main.h /usr/include/SDL/SDL_stdinc.h
main.o: /usr/include/SDL/SDL_config.h /usr/include/SDL/SDL_platform.h
main.o: /usr/include/sys/types.h /usr/include/time.h
main.o: /usr/include/sys/select.h /usr/include/bits/select.h
main.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
main.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
main.o: /usr/include/stdlib.h /usr/include/alloca.h /usr/include/string.h
main.o: /usr/include/strings.h /usr/include/inttypes.h /usr/include/stdint.h
main.o: /usr/include/bits/wchar.h /usr/include/iconv.h
main.o: /usr/include/SDL/begin_code.h /usr/include/SDL/close_code.h
main.o: /usr/include/SDL/SDL_audio.h /usr/include/SDL/SDL_error.h
main.o: /usr/include/SDL/SDL_endian.h /usr/include/SDL/SDL_mutex.h
main.o: /usr/include/SDL/SDL_thread.h /usr/include/SDL/SDL_rwops.h
main.o: /usr/include/SDL/SDL_cdrom.h /usr/include/SDL/SDL_cpuinfo.h
main.o: /usr/include/SDL/SDL_events.h /usr/include/SDL/SDL_active.h
main.o: /usr/include/SDL/SDL_keyboard.h /usr/include/SDL/SDL_keysym.h
main.o: /usr/include/SDL/SDL_mouse.h /usr/include/SDL/SDL_video.h
main.o: /usr/include/SDL/SDL_joystick.h /usr/include/SDL/SDL_quit.h
main.o: /usr/include/SDL/SDL_loadso.h /usr/include/SDL/SDL_timer.h
main.o: /usr/include/SDL/SDL_version.h Gamerules.h /usr/include/SDL/SDL_ttf.h
main.o: /usr/include/SDL/SDL.h Sprite.h /usr/include/c++/4.4.3/iostream
main.o: /usr/include/c++/4.4.3/ostream /usr/include/c++/4.4.3/ios
main.o: /usr/include/c++/4.4.3/bits/ios_base.h
main.o: /usr/include/c++/4.4.3/bits/locale_classes.h
main.o: /usr/include/c++/4.4.3/bits/locale_classes.tcc
main.o: /usr/include/c++/4.4.3/streambuf
main.o: /usr/include/c++/4.4.3/bits/streambuf.tcc
main.o: /usr/include/c++/4.4.3/bits/basic_ios.h
main.o: /usr/include/c++/4.4.3/bits/locale_facets.h
main.o: /usr/include/c++/4.4.3/cwctype
main.o: /usr/include/c++/4.4.3/bits/streambuf_iterator.h
main.o: /usr/include/c++/4.4.3/bits/locale_facets.tcc
main.o: /usr/include/c++/4.4.3/bits/basic_ios.tcc
main.o: /usr/include/c++/4.4.3/bits/ostream.tcc
main.o: /usr/include/c++/4.4.3/istream
main.o: /usr/include/c++/4.4.3/bits/istream.tcc
Menu.o: Menu.h /usr/include/SDL/SDL_ttf.h /usr/include/SDL/SDL.h
Menu.o: /usr/include/SDL/begin_code.h /usr/include/SDL/close_code.h
Menu.o: /usr/include/c++/4.4.3/string /usr/include/c++/4.4.3/bits/stringfwd.h
Menu.o: /usr/include/c++/4.4.3/bits/char_traits.h
Menu.o: /usr/include/c++/4.4.3/bits/stl_algobase.h
Menu.o: /usr/include/c++/4.4.3/cstddef
Menu.o: /usr/include/c++/4.4.3/bits/functexcept.h
Menu.o: /usr/include/c++/4.4.3/exception_defines.h
Menu.o: /usr/include/c++/4.4.3/bits/cpp_type_traits.h
Menu.o: /usr/include/c++/4.4.3/ext/type_traits.h
Menu.o: /usr/include/c++/4.4.3/ext/numeric_traits.h
Menu.o: /usr/include/c++/4.4.3/bits/stl_pair.h
Menu.o: /usr/include/c++/4.4.3/bits/move.h
Menu.o: /usr/include/c++/4.4.3/bits/concept_check.h
Menu.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_types.h
Menu.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_funcs.h
Menu.o: /usr/include/c++/4.4.3/bits/stl_iterator.h
Menu.o: /usr/include/c++/4.4.3/debug/debug.h
Menu.o: /usr/include/c++/4.4.3/bits/postypes.h /usr/include/c++/4.4.3/cwchar
Menu.o: /usr/include/c++/4.4.3/cstdio /usr/include/stdio.h
Menu.o: /usr/include/features.h /usr/include/bits/predefs.h
Menu.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Menu.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
Menu.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
Menu.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
Menu.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
Menu.o: /usr/include/c++/4.4.3/bits/allocator.h
Menu.o: /usr/include/c++/4.4.3/bits/localefwd.h /usr/include/c++/4.4.3/iosfwd
Menu.o: /usr/include/c++/4.4.3/cctype /usr/include/ctype.h
Menu.o: /usr/include/endian.h /usr/include/bits/endian.h
Menu.o: /usr/include/bits/byteswap.h /usr/include/xlocale.h
Menu.o: /usr/include/c++/4.4.3/bits/ostream_insert.h
Menu.o: /usr/include/c++/4.4.3/cxxabi-forced.h
Menu.o: /usr/include/c++/4.4.3/bits/stl_function.h
Menu.o: /usr/include/c++/4.4.3/backward/binders.h
Menu.o: /usr/include/c++/4.4.3/bits/basic_string.h
Menu.o: /usr/include/c++/4.4.3/ext/atomicity.h
Menu.o: /usr/include/c++/4.4.3/initializer_list
Menu.o: /usr/include/c++/4.4.3/bits/basic_string.tcc
Menu.o: /usr/include/c++/4.4.3/vector
Menu.o: /usr/include/c++/4.4.3/bits/stl_construct.h
Menu.o: /usr/include/c++/4.4.3/new /usr/include/c++/4.4.3/exception
Menu.o: /usr/include/c++/4.4.3/bits/stl_uninitialized.h
Menu.o: /usr/include/c++/4.4.3/bits/stl_vector.h
Menu.o: /usr/include/c++/4.4.3/bits/stl_bvector.h
Menu.o: /usr/include/c++/4.4.3/bits/vector.tcc Timer.h Level.h Sprite.h
Menu.o: /usr/include/SDL/SDL.h /usr/include/SDL/SDL_main.h
Menu.o: /usr/include/SDL/SDL_stdinc.h /usr/include/SDL/SDL_config.h
Menu.o: /usr/include/SDL/SDL_platform.h /usr/include/sys/types.h
Menu.o: /usr/include/time.h /usr/include/sys/select.h
Menu.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
Menu.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
Menu.o: /usr/include/bits/pthreadtypes.h /usr/include/stdlib.h
Menu.o: /usr/include/alloca.h /usr/include/string.h /usr/include/strings.h
Menu.o: /usr/include/inttypes.h /usr/include/stdint.h
Menu.o: /usr/include/bits/wchar.h /usr/include/iconv.h
Menu.o: /usr/include/SDL/SDL_audio.h /usr/include/SDL/SDL_error.h
Menu.o: /usr/include/SDL/SDL_endian.h /usr/include/SDL/SDL_mutex.h
Menu.o: /usr/include/SDL/SDL_thread.h /usr/include/SDL/SDL_rwops.h
Menu.o: /usr/include/SDL/SDL_cdrom.h /usr/include/SDL/SDL_cpuinfo.h
Menu.o: /usr/include/SDL/SDL_events.h /usr/include/SDL/SDL_active.h
Menu.o: /usr/include/SDL/SDL_keyboard.h /usr/include/SDL/SDL_keysym.h
Menu.o: /usr/include/SDL/SDL_mouse.h /usr/include/SDL/SDL_video.h
Menu.o: /usr/include/SDL/SDL_joystick.h /usr/include/SDL/SDL_quit.h
Menu.o: /usr/include/SDL/SDL_loadso.h /usr/include/SDL/SDL_timer.h
Menu.o: /usr/include/SDL/SDL_version.h Gamerules.h
Menu.o: /usr/include/SDL/SDL_image.h /usr/include/c++/4.4.3/iostream
Menu.o: /usr/include/c++/4.4.3/ostream /usr/include/c++/4.4.3/ios
Menu.o: /usr/include/c++/4.4.3/bits/ios_base.h
Menu.o: /usr/include/c++/4.4.3/bits/locale_classes.h
Menu.o: /usr/include/c++/4.4.3/bits/locale_classes.tcc
Menu.o: /usr/include/c++/4.4.3/streambuf
Menu.o: /usr/include/c++/4.4.3/bits/streambuf.tcc
Menu.o: /usr/include/c++/4.4.3/bits/basic_ios.h
Menu.o: /usr/include/c++/4.4.3/bits/locale_facets.h
Menu.o: /usr/include/c++/4.4.3/cwctype
Menu.o: /usr/include/c++/4.4.3/bits/streambuf_iterator.h
Menu.o: /usr/include/c++/4.4.3/bits/locale_facets.tcc
Menu.o: /usr/include/c++/4.4.3/bits/basic_ios.tcc
Menu.o: /usr/include/c++/4.4.3/bits/ostream.tcc
Menu.o: /usr/include/c++/4.4.3/istream
Menu.o: /usr/include/c++/4.4.3/bits/istream.tcc
Moving_Sprite.o: Moving_Sprite.h Sprite.h /usr/include/SDL/SDL.h
Moving_Sprite.o: /usr/include/SDL/SDL_main.h /usr/include/SDL/SDL_stdinc.h
Moving_Sprite.o: /usr/include/SDL/SDL_config.h
Moving_Sprite.o: /usr/include/SDL/SDL_platform.h /usr/include/sys/types.h
Moving_Sprite.o: /usr/include/features.h /usr/include/bits/predefs.h
Moving_Sprite.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Moving_Sprite.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
Moving_Sprite.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
Moving_Sprite.o: /usr/include/time.h /usr/include/endian.h
Moving_Sprite.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
Moving_Sprite.o: /usr/include/sys/select.h /usr/include/bits/select.h
Moving_Sprite.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
Moving_Sprite.o: /usr/include/sys/sysmacros.h
Moving_Sprite.o: /usr/include/bits/pthreadtypes.h /usr/include/stdio.h
Moving_Sprite.o: /usr/include/libio.h /usr/include/_G_config.h
Moving_Sprite.o: /usr/include/wchar.h /usr/include/bits/stdio_lim.h
Moving_Sprite.o: /usr/include/bits/sys_errlist.h /usr/include/stdlib.h
Moving_Sprite.o: /usr/include/alloca.h /usr/include/string.h
Moving_Sprite.o: /usr/include/xlocale.h /usr/include/strings.h
Moving_Sprite.o: /usr/include/inttypes.h /usr/include/stdint.h
Moving_Sprite.o: /usr/include/bits/wchar.h /usr/include/ctype.h
Moving_Sprite.o: /usr/include/iconv.h /usr/include/SDL/begin_code.h
Moving_Sprite.o: /usr/include/SDL/close_code.h /usr/include/SDL/SDL_audio.h
Moving_Sprite.o: /usr/include/SDL/SDL_error.h /usr/include/SDL/SDL_endian.h
Moving_Sprite.o: /usr/include/SDL/SDL_mutex.h /usr/include/SDL/SDL_thread.h
Moving_Sprite.o: /usr/include/SDL/SDL_rwops.h /usr/include/SDL/SDL_cdrom.h
Moving_Sprite.o: /usr/include/SDL/SDL_cpuinfo.h /usr/include/SDL/SDL_events.h
Moving_Sprite.o: /usr/include/SDL/SDL_active.h
Moving_Sprite.o: /usr/include/SDL/SDL_keyboard.h
Moving_Sprite.o: /usr/include/SDL/SDL_keysym.h /usr/include/SDL/SDL_mouse.h
Moving_Sprite.o: /usr/include/SDL/SDL_video.h /usr/include/SDL/SDL_joystick.h
Moving_Sprite.o: /usr/include/SDL/SDL_quit.h /usr/include/SDL/SDL_loadso.h
Moving_Sprite.o: /usr/include/SDL/SDL_timer.h /usr/include/SDL/SDL_version.h
Moving_Sprite.o: /usr/include/c++/4.4.3/string
Moving_Sprite.o: /usr/include/c++/4.4.3/bits/stringfwd.h
Moving_Sprite.o: /usr/include/c++/4.4.3/bits/char_traits.h
Moving_Sprite.o: /usr/include/c++/4.4.3/bits/stl_algobase.h
Moving_Sprite.o: /usr/include/c++/4.4.3/cstddef
Moving_Sprite.o: /usr/include/c++/4.4.3/bits/functexcept.h
Moving_Sprite.o: /usr/include/c++/4.4.3/exception_defines.h
Moving_Sprite.o: /usr/include/c++/4.4.3/bits/cpp_type_traits.h
Moving_Sprite.o: /usr/include/c++/4.4.3/ext/type_traits.h
Moving_Sprite.o: /usr/include/c++/4.4.3/ext/numeric_traits.h
Moving_Sprite.o: /usr/include/c++/4.4.3/bits/stl_pair.h
Moving_Sprite.o: /usr/include/c++/4.4.3/bits/move.h
Moving_Sprite.o: /usr/include/c++/4.4.3/bits/concept_check.h
Moving_Sprite.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_types.h
Moving_Sprite.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_funcs.h
Moving_Sprite.o: /usr/include/c++/4.4.3/bits/stl_iterator.h
Moving_Sprite.o: /usr/include/c++/4.4.3/debug/debug.h
Moving_Sprite.o: /usr/include/c++/4.4.3/bits/postypes.h
Moving_Sprite.o: /usr/include/c++/4.4.3/cwchar /usr/include/c++/4.4.3/cstdio
Moving_Sprite.o: /usr/include/c++/4.4.3/bits/allocator.h
Moving_Sprite.o: /usr/include/c++/4.4.3/bits/localefwd.h
Moving_Sprite.o: /usr/include/c++/4.4.3/iosfwd /usr/include/c++/4.4.3/cctype
Moving_Sprite.o: /usr/include/c++/4.4.3/bits/ostream_insert.h
Moving_Sprite.o: /usr/include/c++/4.4.3/cxxabi-forced.h
Moving_Sprite.o: /usr/include/c++/4.4.3/bits/stl_function.h
Moving_Sprite.o: /usr/include/c++/4.4.3/backward/binders.h
Moving_Sprite.o: /usr/include/c++/4.4.3/bits/basic_string.h
Moving_Sprite.o: /usr/include/c++/4.4.3/ext/atomicity.h
Moving_Sprite.o: /usr/include/c++/4.4.3/initializer_list
Moving_Sprite.o: /usr/include/c++/4.4.3/bits/basic_string.tcc
Moving_Sprite.o: /usr/include/c++/4.4.3/cmath /usr/include/math.h
Moving_Sprite.o: /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h
Moving_Sprite.o: /usr/include/bits/huge_vall.h /usr/include/bits/inf.h
Moving_Sprite.o: /usr/include/bits/nan.h /usr/include/bits/mathdef.h
Moving_Sprite.o: /usr/include/bits/mathcalls.h
Moving_Sprite.o: /usr/include/c++/4.4.3/bits/cmath.tcc
Player.o: Player.h /usr/include/SDL/SDL.h /usr/include/SDL/SDL_main.h
Player.o: /usr/include/SDL/SDL_stdinc.h /usr/include/SDL/SDL_config.h
Player.o: /usr/include/SDL/SDL_platform.h /usr/include/sys/types.h
Player.o: /usr/include/features.h /usr/include/bits/predefs.h
Player.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Player.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
Player.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
Player.o: /usr/include/time.h /usr/include/endian.h
Player.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
Player.o: /usr/include/sys/select.h /usr/include/bits/select.h
Player.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
Player.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
Player.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
Player.o: /usr/include/wchar.h /usr/include/bits/stdio_lim.h
Player.o: /usr/include/bits/sys_errlist.h /usr/include/stdlib.h
Player.o: /usr/include/alloca.h /usr/include/string.h /usr/include/xlocale.h
Player.o: /usr/include/strings.h /usr/include/inttypes.h
Player.o: /usr/include/stdint.h /usr/include/bits/wchar.h
Player.o: /usr/include/ctype.h /usr/include/iconv.h
Player.o: /usr/include/SDL/begin_code.h /usr/include/SDL/close_code.h
Player.o: /usr/include/SDL/SDL_audio.h /usr/include/SDL/SDL_error.h
Player.o: /usr/include/SDL/SDL_endian.h /usr/include/SDL/SDL_mutex.h
Player.o: /usr/include/SDL/SDL_thread.h /usr/include/SDL/SDL_rwops.h
Player.o: /usr/include/SDL/SDL_cdrom.h /usr/include/SDL/SDL_cpuinfo.h
Player.o: /usr/include/SDL/SDL_events.h /usr/include/SDL/SDL_active.h
Player.o: /usr/include/SDL/SDL_keyboard.h /usr/include/SDL/SDL_keysym.h
Player.o: /usr/include/SDL/SDL_mouse.h /usr/include/SDL/SDL_video.h
Player.o: /usr/include/SDL/SDL_joystick.h /usr/include/SDL/SDL_quit.h
Player.o: /usr/include/SDL/SDL_loadso.h /usr/include/SDL/SDL_timer.h
Player.o: /usr/include/SDL/SDL_version.h Moving_Sprite.h Sprite.h
Player.o: /usr/include/c++/4.4.3/string
Player.o: /usr/include/c++/4.4.3/bits/stringfwd.h
Player.o: /usr/include/c++/4.4.3/bits/char_traits.h
Player.o: /usr/include/c++/4.4.3/bits/stl_algobase.h
Player.o: /usr/include/c++/4.4.3/cstddef
Player.o: /usr/include/c++/4.4.3/bits/functexcept.h
Player.o: /usr/include/c++/4.4.3/exception_defines.h
Player.o: /usr/include/c++/4.4.3/bits/cpp_type_traits.h
Player.o: /usr/include/c++/4.4.3/ext/type_traits.h
Player.o: /usr/include/c++/4.4.3/ext/numeric_traits.h
Player.o: /usr/include/c++/4.4.3/bits/stl_pair.h
Player.o: /usr/include/c++/4.4.3/bits/move.h
Player.o: /usr/include/c++/4.4.3/bits/concept_check.h
Player.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_types.h
Player.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_funcs.h
Player.o: /usr/include/c++/4.4.3/bits/stl_iterator.h
Player.o: /usr/include/c++/4.4.3/debug/debug.h
Player.o: /usr/include/c++/4.4.3/bits/postypes.h
Player.o: /usr/include/c++/4.4.3/cwchar /usr/include/c++/4.4.3/cstdio
Player.o: /usr/include/c++/4.4.3/bits/allocator.h
Player.o: /usr/include/c++/4.4.3/bits/localefwd.h
Player.o: /usr/include/c++/4.4.3/iosfwd /usr/include/c++/4.4.3/cctype
Player.o: /usr/include/c++/4.4.3/bits/ostream_insert.h
Player.o: /usr/include/c++/4.4.3/cxxabi-forced.h
Player.o: /usr/include/c++/4.4.3/bits/stl_function.h
Player.o: /usr/include/c++/4.4.3/backward/binders.h
Player.o: /usr/include/c++/4.4.3/bits/basic_string.h
Player.o: /usr/include/c++/4.4.3/ext/atomicity.h
Player.o: /usr/include/c++/4.4.3/initializer_list
Player.o: /usr/include/c++/4.4.3/bits/basic_string.tcc Gamerules.h
Player.o: /usr/include/c++/4.4.3/vector
Player.o: /usr/include/c++/4.4.3/bits/stl_construct.h
Player.o: /usr/include/c++/4.4.3/new /usr/include/c++/4.4.3/exception
Player.o: /usr/include/c++/4.4.3/bits/stl_uninitialized.h
Player.o: /usr/include/c++/4.4.3/bits/stl_vector.h
Player.o: /usr/include/c++/4.4.3/bits/stl_bvector.h
Player.o: /usr/include/c++/4.4.3/bits/vector.tcc Level.h Game.h
Player.o: /usr/include/SDL/SDL_ttf.h /usr/include/SDL/SDL.h
Player.o: /usr/include/c++/4.4.3/iostream /usr/include/c++/4.4.3/ostream
Player.o: /usr/include/c++/4.4.3/ios /usr/include/c++/4.4.3/bits/ios_base.h
Player.o: /usr/include/c++/4.4.3/bits/locale_classes.h
Player.o: /usr/include/c++/4.4.3/bits/locale_classes.tcc
Player.o: /usr/include/c++/4.4.3/streambuf
Player.o: /usr/include/c++/4.4.3/bits/streambuf.tcc
Player.o: /usr/include/c++/4.4.3/bits/basic_ios.h
Player.o: /usr/include/c++/4.4.3/bits/locale_facets.h
Player.o: /usr/include/c++/4.4.3/cwctype
Player.o: /usr/include/c++/4.4.3/bits/streambuf_iterator.h
Player.o: /usr/include/c++/4.4.3/bits/locale_facets.tcc
Player.o: /usr/include/c++/4.4.3/bits/basic_ios.tcc
Player.o: /usr/include/c++/4.4.3/bits/ostream.tcc
Player.o: /usr/include/c++/4.4.3/istream
Player.o: /usr/include/c++/4.4.3/bits/istream.tcc
Sprite.o: Sprite.h /usr/include/SDL/SDL.h /usr/include/SDL/SDL_main.h
Sprite.o: /usr/include/SDL/SDL_stdinc.h /usr/include/SDL/SDL_config.h
Sprite.o: /usr/include/SDL/SDL_platform.h /usr/include/sys/types.h
Sprite.o: /usr/include/features.h /usr/include/bits/predefs.h
Sprite.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Sprite.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
Sprite.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
Sprite.o: /usr/include/time.h /usr/include/endian.h
Sprite.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
Sprite.o: /usr/include/sys/select.h /usr/include/bits/select.h
Sprite.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
Sprite.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
Sprite.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
Sprite.o: /usr/include/wchar.h /usr/include/bits/stdio_lim.h
Sprite.o: /usr/include/bits/sys_errlist.h /usr/include/stdlib.h
Sprite.o: /usr/include/alloca.h /usr/include/string.h /usr/include/xlocale.h
Sprite.o: /usr/include/strings.h /usr/include/inttypes.h
Sprite.o: /usr/include/stdint.h /usr/include/bits/wchar.h
Sprite.o: /usr/include/ctype.h /usr/include/iconv.h
Sprite.o: /usr/include/SDL/begin_code.h /usr/include/SDL/close_code.h
Sprite.o: /usr/include/SDL/SDL_audio.h /usr/include/SDL/SDL_error.h
Sprite.o: /usr/include/SDL/SDL_endian.h /usr/include/SDL/SDL_mutex.h
Sprite.o: /usr/include/SDL/SDL_thread.h /usr/include/SDL/SDL_rwops.h
Sprite.o: /usr/include/SDL/SDL_cdrom.h /usr/include/SDL/SDL_cpuinfo.h
Sprite.o: /usr/include/SDL/SDL_events.h /usr/include/SDL/SDL_active.h
Sprite.o: /usr/include/SDL/SDL_keyboard.h /usr/include/SDL/SDL_keysym.h
Sprite.o: /usr/include/SDL/SDL_mouse.h /usr/include/SDL/SDL_video.h
Sprite.o: /usr/include/SDL/SDL_joystick.h /usr/include/SDL/SDL_quit.h
Sprite.o: /usr/include/SDL/SDL_loadso.h /usr/include/SDL/SDL_timer.h
Sprite.o: /usr/include/SDL/SDL_version.h /usr/include/c++/4.4.3/string
Sprite.o: /usr/include/c++/4.4.3/bits/stringfwd.h
Sprite.o: /usr/include/c++/4.4.3/bits/char_traits.h
Sprite.o: /usr/include/c++/4.4.3/bits/stl_algobase.h
Sprite.o: /usr/include/c++/4.4.3/cstddef
Sprite.o: /usr/include/c++/4.4.3/bits/functexcept.h
Sprite.o: /usr/include/c++/4.4.3/exception_defines.h
Sprite.o: /usr/include/c++/4.4.3/bits/cpp_type_traits.h
Sprite.o: /usr/include/c++/4.4.3/ext/type_traits.h
Sprite.o: /usr/include/c++/4.4.3/ext/numeric_traits.h
Sprite.o: /usr/include/c++/4.4.3/bits/stl_pair.h
Sprite.o: /usr/include/c++/4.4.3/bits/move.h
Sprite.o: /usr/include/c++/4.4.3/bits/concept_check.h
Sprite.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_types.h
Sprite.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_funcs.h
Sprite.o: /usr/include/c++/4.4.3/bits/stl_iterator.h
Sprite.o: /usr/include/c++/4.4.3/debug/debug.h
Sprite.o: /usr/include/c++/4.4.3/bits/postypes.h
Sprite.o: /usr/include/c++/4.4.3/cwchar /usr/include/c++/4.4.3/cstdio
Sprite.o: /usr/include/c++/4.4.3/bits/allocator.h
Sprite.o: /usr/include/c++/4.4.3/bits/localefwd.h
Sprite.o: /usr/include/c++/4.4.3/iosfwd /usr/include/c++/4.4.3/cctype
Sprite.o: /usr/include/c++/4.4.3/bits/ostream_insert.h
Sprite.o: /usr/include/c++/4.4.3/cxxabi-forced.h
Sprite.o: /usr/include/c++/4.4.3/bits/stl_function.h
Sprite.o: /usr/include/c++/4.4.3/backward/binders.h
Sprite.o: /usr/include/c++/4.4.3/bits/basic_string.h
Sprite.o: /usr/include/c++/4.4.3/ext/atomicity.h
Sprite.o: /usr/include/c++/4.4.3/initializer_list
Sprite.o: /usr/include/c++/4.4.3/bits/basic_string.tcc Level.h Gamerules.h
Sprite.o: /usr/include/c++/4.4.3/vector
Sprite.o: /usr/include/c++/4.4.3/bits/stl_construct.h
Sprite.o: /usr/include/c++/4.4.3/new /usr/include/c++/4.4.3/exception
Sprite.o: /usr/include/c++/4.4.3/bits/stl_uninitialized.h
Sprite.o: /usr/include/c++/4.4.3/bits/stl_vector.h
Sprite.o: /usr/include/c++/4.4.3/bits/stl_bvector.h
Sprite.o: /usr/include/c++/4.4.3/bits/vector.tcc /usr/include/SDL/SDL_image.h
Sprite.o: /usr/include/SDL/SDL.h /usr/include/c++/4.4.3/iostream
Sprite.o: /usr/include/c++/4.4.3/ostream /usr/include/c++/4.4.3/ios
Sprite.o: /usr/include/c++/4.4.3/bits/ios_base.h
Sprite.o: /usr/include/c++/4.4.3/bits/locale_classes.h
Sprite.o: /usr/include/c++/4.4.3/bits/locale_classes.tcc
Sprite.o: /usr/include/c++/4.4.3/streambuf
Sprite.o: /usr/include/c++/4.4.3/bits/streambuf.tcc
Sprite.o: /usr/include/c++/4.4.3/bits/basic_ios.h
Sprite.o: /usr/include/c++/4.4.3/bits/locale_facets.h
Sprite.o: /usr/include/c++/4.4.3/cwctype
Sprite.o: /usr/include/c++/4.4.3/bits/streambuf_iterator.h
Sprite.o: /usr/include/c++/4.4.3/bits/locale_facets.tcc
Sprite.o: /usr/include/c++/4.4.3/bits/basic_ios.tcc
Sprite.o: /usr/include/c++/4.4.3/bits/ostream.tcc
Sprite.o: /usr/include/c++/4.4.3/istream
Sprite.o: /usr/include/c++/4.4.3/bits/istream.tcc
Timer.o: Timer.h /usr/include/SDL/SDL.h /usr/include/SDL/SDL_main.h
Timer.o: /usr/include/SDL/SDL_stdinc.h /usr/include/SDL/SDL_config.h
Timer.o: /usr/include/SDL/SDL_platform.h /usr/include/sys/types.h
Timer.o: /usr/include/features.h /usr/include/bits/predefs.h
Timer.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Timer.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
Timer.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
Timer.o: /usr/include/time.h /usr/include/endian.h /usr/include/bits/endian.h
Timer.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
Timer.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
Timer.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
Timer.o: /usr/include/bits/pthreadtypes.h /usr/include/stdio.h
Timer.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
Timer.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
Timer.o: /usr/include/stdlib.h /usr/include/alloca.h /usr/include/string.h
Timer.o: /usr/include/xlocale.h /usr/include/strings.h
Timer.o: /usr/include/inttypes.h /usr/include/stdint.h
Timer.o: /usr/include/bits/wchar.h /usr/include/ctype.h /usr/include/iconv.h
Timer.o: /usr/include/SDL/begin_code.h /usr/include/SDL/close_code.h
Timer.o: /usr/include/SDL/SDL_audio.h /usr/include/SDL/SDL_error.h
Timer.o: /usr/include/SDL/SDL_endian.h /usr/include/SDL/SDL_mutex.h
Timer.o: /usr/include/SDL/SDL_thread.h /usr/include/SDL/SDL_rwops.h
Timer.o: /usr/include/SDL/SDL_cdrom.h /usr/include/SDL/SDL_cpuinfo.h
Timer.o: /usr/include/SDL/SDL_events.h /usr/include/SDL/SDL_active.h
Timer.o: /usr/include/SDL/SDL_keyboard.h /usr/include/SDL/SDL_keysym.h
Timer.o: /usr/include/SDL/SDL_mouse.h /usr/include/SDL/SDL_video.h
Timer.o: /usr/include/SDL/SDL_joystick.h /usr/include/SDL/SDL_quit.h
Timer.o: /usr/include/SDL/SDL_loadso.h /usr/include/SDL/SDL_timer.h
Timer.o: /usr/include/SDL/SDL_version.h
Wall.o: Wall.h Sprite.h /usr/include/SDL/SDL.h /usr/include/SDL/SDL_main.h
Wall.o: /usr/include/SDL/SDL_stdinc.h /usr/include/SDL/SDL_config.h
Wall.o: /usr/include/SDL/SDL_platform.h /usr/include/sys/types.h
Wall.o: /usr/include/features.h /usr/include/bits/predefs.h
Wall.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
Wall.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h
Wall.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
Wall.o: /usr/include/time.h /usr/include/endian.h /usr/include/bits/endian.h
Wall.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
Wall.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
Wall.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
Wall.o: /usr/include/bits/pthreadtypes.h /usr/include/stdio.h
Wall.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
Wall.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
Wall.o: /usr/include/stdlib.h /usr/include/alloca.h /usr/include/string.h
Wall.o: /usr/include/xlocale.h /usr/include/strings.h /usr/include/inttypes.h
Wall.o: /usr/include/stdint.h /usr/include/bits/wchar.h /usr/include/ctype.h
Wall.o: /usr/include/iconv.h /usr/include/SDL/begin_code.h
Wall.o: /usr/include/SDL/close_code.h /usr/include/SDL/SDL_audio.h
Wall.o: /usr/include/SDL/SDL_error.h /usr/include/SDL/SDL_endian.h
Wall.o: /usr/include/SDL/SDL_mutex.h /usr/include/SDL/SDL_thread.h
Wall.o: /usr/include/SDL/SDL_rwops.h /usr/include/SDL/SDL_cdrom.h
Wall.o: /usr/include/SDL/SDL_cpuinfo.h /usr/include/SDL/SDL_events.h
Wall.o: /usr/include/SDL/SDL_active.h /usr/include/SDL/SDL_keyboard.h
Wall.o: /usr/include/SDL/SDL_keysym.h /usr/include/SDL/SDL_mouse.h
Wall.o: /usr/include/SDL/SDL_video.h /usr/include/SDL/SDL_joystick.h
Wall.o: /usr/include/SDL/SDL_quit.h /usr/include/SDL/SDL_loadso.h
Wall.o: /usr/include/SDL/SDL_timer.h /usr/include/SDL/SDL_version.h
Wall.o: /usr/include/c++/4.4.3/string /usr/include/c++/4.4.3/bits/stringfwd.h
Wall.o: /usr/include/c++/4.4.3/bits/char_traits.h
Wall.o: /usr/include/c++/4.4.3/bits/stl_algobase.h
Wall.o: /usr/include/c++/4.4.3/cstddef
Wall.o: /usr/include/c++/4.4.3/bits/functexcept.h
Wall.o: /usr/include/c++/4.4.3/exception_defines.h
Wall.o: /usr/include/c++/4.4.3/bits/cpp_type_traits.h
Wall.o: /usr/include/c++/4.4.3/ext/type_traits.h
Wall.o: /usr/include/c++/4.4.3/ext/numeric_traits.h
Wall.o: /usr/include/c++/4.4.3/bits/stl_pair.h
Wall.o: /usr/include/c++/4.4.3/bits/move.h
Wall.o: /usr/include/c++/4.4.3/bits/concept_check.h
Wall.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_types.h
Wall.o: /usr/include/c++/4.4.3/bits/stl_iterator_base_funcs.h
Wall.o: /usr/include/c++/4.4.3/bits/stl_iterator.h
Wall.o: /usr/include/c++/4.4.3/debug/debug.h
Wall.o: /usr/include/c++/4.4.3/bits/postypes.h /usr/include/c++/4.4.3/cwchar
Wall.o: /usr/include/c++/4.4.3/cstdio /usr/include/c++/4.4.3/bits/allocator.h
Wall.o: /usr/include/c++/4.4.3/bits/localefwd.h /usr/include/c++/4.4.3/iosfwd
Wall.o: /usr/include/c++/4.4.3/cctype
Wall.o: /usr/include/c++/4.4.3/bits/ostream_insert.h
Wall.o: /usr/include/c++/4.4.3/cxxabi-forced.h
Wall.o: /usr/include/c++/4.4.3/bits/stl_function.h
Wall.o: /usr/include/c++/4.4.3/backward/binders.h
Wall.o: /usr/include/c++/4.4.3/bits/basic_string.h
Wall.o: /usr/include/c++/4.4.3/ext/atomicity.h
Wall.o: /usr/include/c++/4.4.3/initializer_list
Wall.o: /usr/include/c++/4.4.3/bits/basic_string.tcc Level.h Gamerules.h
Wall.o: /usr/include/c++/4.4.3/vector
Wall.o: /usr/include/c++/4.4.3/bits/stl_construct.h
Wall.o: /usr/include/c++/4.4.3/new /usr/include/c++/4.4.3/exception
Wall.o: /usr/include/c++/4.4.3/bits/stl_uninitialized.h
Wall.o: /usr/include/c++/4.4.3/bits/stl_vector.h
Wall.o: /usr/include/c++/4.4.3/bits/stl_bvector.h
Wall.o: /usr/include/c++/4.4.3/bits/vector.tcc
