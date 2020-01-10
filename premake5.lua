workspace "Echo"
	architecture "x64"
	configurations{"Debug", "Release"}
	flags { "MultiProcessorCompile" }
	startproject "osu!trainer"

-- variables
outputdir = "%{cfg.buildcfg}-%{cfg.system}"

-- glfw project	
include "Echo/vendor/glfw"
include "Echo/vendor/glad"

-- include directories
includeDir = {}
includeDir["glfw"] = "Echo/vendor/glfw/include"
includeDir["glad"] = "Echo/vendor/glad/include"

-- precompiled header
-- pchheader "EchoHeader.h"
-- pchsource "../Echo/src/EchoHeader.cpp"

-- echo engine solution
project "Echo"
	location "Echo"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	defines { "ECHO_WINDOWS", "ECHO_BUILD", "GLFW_INCLUDE_NONE" }

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
		staticruntime "on"
		systemversion "latest"
		postbuildcommands { "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/osu!trainer" }

	filter "configurations:Debug"
		defines {"ECHO_DEBUG"}
		optimize "Full"
	
	filter "configurations:Release"
		defines {"ECHO_RELEASE"}
		optimize "Full"

-- osu!trainer solution
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
		staticruntime "on"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		defines {"ECHO_DEBUG"}
		optimize "Full"
	
	filter "configurations:Release"
		runtime "Release"
		defines {"ECHO_RELEASE"}
		optimize "Full"