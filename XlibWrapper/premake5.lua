GOOGLE_BENCHMARK_LIBDIRS = {}

workspace "XlibWrapper"
    configurations { "Run"}
    targetdir "bin"


project "XlibWrapper"
    kind "SharedLib"
    targetdir "bin/lib"
    filename "wrapper"
    toolset "clang"
    language "C++"
    cppdialect "C++17"
    links { "X11" , "freetype" }
    files { "libsrc/*.cpp" , "libsrc/*.c"  }
--    filter {"files:**.c"}
  --      compileas "C"
    filter {}
    includedirs {"include",  "libsrc/include" }
    buildoptions { "-Wall", "-isystem /usr/include/freetype2"}
    filename "XlibWrapper"

project "XlibRunner"
    kind "ConsoleApp"
    filename "window"
    toolset "clang"
    language "C++"
    cppdialect "C++17"
    filename "windows"
    targetdir "bin/runner"
    includedirs {"include" , "/usr/include/freetype2" }
    links { "XlibWrapper","X11", "freetype"}
    buildoptions { "-Wall" } 
    files { "runsrc/*.cpp"}
