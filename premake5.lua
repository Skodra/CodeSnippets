-- for every directory create a project within the solution
workspace "CodeSnippets"
    configurations { "Debug", "Release" }
    architecture "x64"
    startproject "SortingStrategy"  -- optional; replace with the name of a project you want to set as the default

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
    
    -- A table of directory names to exclude
    local excludedDirs = {
        "tools",
        "bin",
        "bin-int"
    }

    -- Checks if a value exists in a table
    local function contains(table, val)
       for i = 1, #table do
          if table[i] == val then
             return true
          end
       end
       return false
    end
    
    -- Iterates over each directory in the current directory
    local directories = os.matchdirs("*")
    for _, projects in ipairs(directories) do
        local dirName = path.getname(projects)
        -- Only add projects for directories not in the exclusion list
        if not contains(excludedDirs, dirName) then
            project(dirName)
            location(dirName)
            kind "ConsoleApp"
            language "C++"

            targetdir ("bin/" .. outputdir .. "/%{prj.name}")
            objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

            files
            {
                "%{prj.name}/**.h",
                "%{prj.name}/**.hpp",
                "%{prj.name}/**.cpp"
            }
            includedirs 
            { 
                "../includes"
            }

            -- Windows-specific settings
            filter "system:windows"
                cppdialect "C++17"
                staticruntime "On"
                systemversion "latest"

            -- Configurations
            filter "configurations:Debug"
                defines "DEBUG"
                symbols "On"

            filter "configurations:Release"
                defines "NDEBUG"
                optimize "On"
        end
    end
    
-- Clean Function --
newaction {
   trigger     = "clean",
   description = "Remove IDE and intermediate files, and binaries.",
   execute     = function ()
      print("Clean the build...")
      os.rmdir("./bin")
        print("Removing intermediate binaries...")
        os.rmdir("./bin-int")
        print("Removing project files...")
        os.rmdir("./.vs")
        os.remove("**.sln")
        os.remove("**.vcxproj")
        os.remove("**.vcxproj.filters")
        os.remove("**.vcxproj.user")
   end
}
