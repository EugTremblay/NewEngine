
let project = new Project('engine');
 
await project.addProject("./TheEngine");

project.setDebugDir("Deployment");
project.addIncludeDir("./TheEngine/includes");
project.addIncludeDir("./TheGame/includes");
project.addFiles('TheGame/sources/**','TheGame/includes/**');
project.setCppStd("c++20");

project.flatten();


resolve(project);