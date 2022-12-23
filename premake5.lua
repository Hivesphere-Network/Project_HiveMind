workspace "Project HiveMind"
    configurations { "Debug", "Release" }

project "BaseAgent"
    kind "ConsoleApp"
    language "C++"       
    cppdialect "C++17"
    staticruntime "on"
    targetdir "bin/%{cfg.buildcfg}"
    
	files {"src/**.h", "src/**.cpp"}

    ilter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"