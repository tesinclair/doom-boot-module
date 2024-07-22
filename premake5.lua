workspace "DoomBootModule"
    configurations { "Debug", "Release" }

project "DoomBoot"
    kind "ConsoleApp"
    language "C"
    targetdir "bin/%{cfg.buildcfg}"

    files {
        "src/game/**.h",
        "src/game/**.c",
        "src/game/lib/**.h",
        "src/game/lib/**.c"
    }

    includedirs {
        "src/game",
        "src/game/lib"
    }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

