GOOGLE_BENCHMARK_LIBDIRS = {}

workspace "XlibWrapper"
    configurations { "Run"}
    targetdir "bin"


project "XlibWrapper"
    kind "StaticLib"
    targetdir "bin/lib"
    filename "wrapper"
    toolset "clang"
    language "C++"
    cppdialect "C++17"
    links { "X11" }
    files { "libsrc/*.cpp"  }
    includedirs {"include",  "libsrc/include"}
    buildoptions { "-Wall", }
    filename "XlibWrapper"

project "XlibRunner"
    kind "ConsoleApp"
    filename "window"
    toolset "clang"
    language "C++"
    cppdialect "C++17"
    filename "windows"
    targetdir "bin/runner"
    includedirs {"include"}
    links { "XlibWrapper","X11"}
    files { "runsrc/*.cpp"}
