workspace "Echo"
	architecture "x64"
	configurations{"Debug", "Release", "Dist"}
	flags { "MultiProcessorCompile" }
	startproject "osu!trainer"

-- variables
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- glfw project	
include "Echo/vendor/glfw"

-- include directories
IncludeDir = {}
IncludeDir["glfw"] = "Echo/vendor/glfw/include"

-- precompiled header
pchheader "EchoHeader.h"
pchsource "Echo/EchoHeader.h"

-- echo engine solution
project "Echo"
	location "Echo"
	kind "SharedLib"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	defines { "ECHO_WINDOWS", "ECHO_BUILD" }

	-- include library
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	-- additional include directories
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor",
		"%{IncludeDir.glfw}"
	}

	-- links
	links
	{
		"glfw",
		"opengl32.lib"
	}

	-- windows config
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"
		postbuildcommands { "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/osu!trainer" }

	filter "configurations:Debug"
		defines {"ECHO_DEBUG"}
		optimize "On"
	
	filter "configurations:Release"
		defines {"ECHO_RELEASE"}
		optimize "On"
	
	filter "configurations:Dist"
		defines {"ECHO_DIST"}
		optimize "On"

-- osu!trainer solution
project "osu!trainer"
	location "osu!trainer"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	defines { "ECHO_WINDOWS" } 

	-- include library
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	-- additional include directories
	includedirs
	{
		"Echo/src",
		"Echo/vendor",
		"%{prj.name}/src",
		"%{prj.name}/vendor"
	}

	-- linker
	links { "Echo" }

	-- windows config
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

	filter "configurations:Debug"
		defines {"ECHO_DEBUG"}
		optimize "On"
	
	filter "configurations:Release"
		defines {"ECHO_RELEASE"}
		optimize "On"
	
	filter "configurations:Dist"
		defines {"ECHO_DIST"}
		optimize "On"