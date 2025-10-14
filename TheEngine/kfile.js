const path = require('path');
const fs = require('fs');
let project = new Project('engine');
 
project.addProvider = function(proj, isRoot=false){
    const sdl2 = true;//process.argv.indexOf("--sdl2") >= 0;
    if(sdl2){
        
        if(!isRoot){
            proj.addDefine("USE_SDL");
            proj.addIncludeDir(path.resolve("./Libraries/sdl/include"));
        }
        fs.copyFileSync("./Libraries/sdl/lib/SDL2.dll","./Deployment/SDL2.dll")
        proj.addLib("../Libraries/sdl/lib/SDL2");
        fs.copyFileSync("./Libraries/sdl/lib/SDL2_image.dll","./Deployment/SDL2_image.dll")
        fs.copyFileSync("./Libraries/sdl/lib/SDL2_ttf.dll","./Deployment/SDL2_ttf.dll")
        fs.copyFileSync("./Libraries/sdl/lib/SDL2_mixer.dll","./Deployment/SDL2_mixer.dll")
        proj.addLib("../Libraries/sdl/lib/SDL2_image");
        proj.addLib("../Libraries/sdl/lib/SDL2_ttf");
        proj.addLib("../Libraries/sdl/lib/SDL2_mixer");
        proj.addLib("../Libraries/sdl/lib/SDL2main");
        
        //proj.addLib("./TheEngine/sdl_image/lib/SDL_image");
    }
    proj.addIncludeDir("C:/Program Files (x86)/Visual Leak Detector/include")
    proj.addLib("C:/Program Files (x86)/Visual Leak Detector/lib/Win64/vld");
};
project.kore = false;


project.addDefine("KINC_STATIC_COMPILE");
project.isStaticLib = true;

project.addIncludeDir(path.resolve("./TheEngine/includes"));
project.addFiles('sources/**','includes/**');

project.addProvider(project,false);

resolve(project);