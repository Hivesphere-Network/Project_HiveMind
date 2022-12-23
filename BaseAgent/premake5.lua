project "BaseAgent"
    kind "ConsoleApp"
    language "C++"       
    cppdialect "C++17"
    staticruntime "on"
    targetdir "bin/%{cfg.buildcfg}"
    
	files {"src/**.h", "src/**.cpp"}

    filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "RELEASE" }
      optimize "On"