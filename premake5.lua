workspace "Echo"
	architecture "x64"
	configurations{"Debug", "Release", "Dist"}
	flags { "MultiProcessorCompile" }
	startproject "osu!trainer"

-- variables
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- glfw project	
include "Echo/vendor/glfw"
include "Echo/vendor/glad"

-- include directories
includeDir = {}
includeDir["glfw"] = "Echo/vendor/glfw/include"
includeDir["glad"] = "Echo/vendor/glad/include"

-- echo engine solution
project "Echo"
	location "Echo"
	kind "SharedLib"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	defines { "ECHO_WINDOWS", "ECHO_BUILD", "GLFW_INCLUDE_NONE" }

	
	-- precompiled header
	-- pchheader "EchoHeader.h"
	-- pchsource "Echo/src/EchoHeader.cpp"

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
		"%{includeDir.glfw}",
		"%{includeDir.glad}"
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
		"%{prj.name}/vendor",
		"%{includeDir.glfw}",
		"%{includeDir.glad}"
	}

	-- linker
	links { "Echo" }
	
	-- linking options
	linkoptions { "/FORCE:MULTIPLE" }

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