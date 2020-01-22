-- main workspace link to other individual projects
workspace "Echo"
	architecture "x64"
	configurations { "Debug", "Release" }
	flags { "MultiProcessorCompile" }
	startproject "osu!trainer"

-- output directory
outputdir = "%{cfg.buildcfg}-%{cfg.system}"

-- other vendor projects
include "Echo/vendor/glfw"
include "Echo/vendor/glad"

-- include directories
-- Echo
EchoInclude = {}
EchoInclude["glfw"] = "Echo/vendor/glfw/include"
EchoInclude["glad"] = "Echo/vendor/glad/include"

-- EchoGen
GenInclude = {}


-- Echo project
-- Echo engine handles all the gameplay setup and runtime
project "Echo"
	location "Echo"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	defines { "ECHO_WINDOWS", "ECHO_BUILD", "GLFW_INCLUDE_NONE" }

	-- precompiled header
	-- pchheader "EchoHeader.h"
	-- pchsource "/Echo/src/EchoHeader.cpp"

	-- include library
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	-- additional include directories
	includedirs
	{
		"vendor",
		"%{prj.name}/src",
		"%{prj.name}/vendor",
		"%{EchoInclude.glfw}",
		"%{EchoInclude.glad}"
	}

	-- links
	links
	{
		"glfw",
		"glad",
		"opengl32.lib"
	}

	-- linking options
	linkoptions { "/FORCE:MULTIPLE" }

	-- windows config
	filter "system:windows"
		staticruntime "on"
		systemversion "latest"
		postbuildcommands { "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/osu!trainer" }

	filter "configurations:Debug"
		runtime "Debug"
		defines { "ECHO_DEBUG" }
		optimize "Full"
	
	filter "configurations:Release"
		runtime "Release"
		defines { "ECHO_RELEASE" }
		optimize "Full"


-- osu!trainer project
project "osu!trainer"
	location "osu!trainer"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

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
		"vendor",
		"Echo/src",
		"Echo/vendor",
		"%{prj.name}/src",
		"%{prj.name}/vendor",
		"%{EchoInclude.glfw}",
		"%{EchoInclude.glad}"
	}

	-- linker
	links { "Echo" }
	
	-- linking options
	linkoptions { "/FORCE:MULTIPLE" }

	-- windows config
	filter "system:windows"
		staticruntime "on"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		defines { "ECHO_DEBUG" }
		optimize "Full"
	
	filter "configurations:Release"
		runtime "Release"
		defines { "ECHO_RELEASE" }
		optimize "Full"	


-- EchoGen project
-- EchoGen handles the beatmap generation and pre-launch settings
project "EchoGen"
	location "EchoGen"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	defines { "ECHO_GEN_WINDOWS", "ECHO_GEN_BUILD" }

	-- precompiled header
	-- pchheader "EchoGenHeader.h"
	-- pchsource "/EchoGen/src/EchoGenHeader.cpp"

	-- include library
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	-- additional include directories
	includedirs
	{
		"vendor",
		"%{prj.name}/src",
		"%{prj.name}/vendor",
	}

	-- windows config
	filter "system:windows"
		staticruntime "on"
		systemversion "latest"
		postbuildcommands { "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/osu!gen" }

	filter "configurations:Debug"
		runtime "Debug"
		defines { "ECHO_GEN_DEBUG" }
		optimize "Full"

	filter "configurations:Release"
		runtime "Release"
		defines { "ECHO_GEN_RELEASE" }
		optimize "Full"


-- osu!gen project
project "osu!gen"
	location "osu!gen"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	defines { "ECHO_GEN_WINDOWS" } 

	-- include library
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	-- additional include directories
	includedirs
	{
		"vendor",
		"EchoGen/src",
		"EchoGen/vendor",
		"%{prj.name}/src",
		"%{prj.name}/vendor"
	}

	-- linker
	links { "EchoGen" }

	-- windows config
	filter "system:windows"
		staticruntime "on"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		defines { "ECHO_GEN_DEBUG" }
		optimize "Full"
	
	filter "configurations:Release"
		runtime "Release"
		defines { "ECHO_GEN_RELEASE" }
		optimize "Full"		


-- -- osu!launcher project
-- project "osu!launcher"
-- 	location "osu!launcher"
-- 	kind "WindowedApp"
-- 	language "C#"
-- 	flags { "WPF" }
-- 	targetdir ("bin/" .. outputdir .. "/%{prj.name}")

-- 	files
-- 	{
-- 		"%{prj.name}/**.cs",
-- 		"%{prj.name}/**.xaml",
-- 		"%{prj.name}/**.xaml.cs",
-- 	}

-- 	filter "configurations:Debug"
-- 		runtime "Debug"

-- 	filter "configurations:Release"
-- 		runtime "Release"