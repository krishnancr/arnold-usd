#include <ai.h>

#include <cstdio>
#include <cstring>
#include <iostream>

int main(int argc, char **argv)
{
    AiMsgSetConsoleFlags(AI_LOG_ALL);
    AiBegin();

    AtUniverse *proc_universe = AiUniverse();

    AiASSLoad("scene.ass");
    // load the usd procedural (containing a sphere) in a separate universe
    AtNode *proc_a = AiNode(proc_universe, "usd", "my_usd");
    AiNodeSetStr(proc_a, "filename", "scene.usda");
    // Call the viewport API on the usd procedural, and fill the main universe
    AiProceduralViewport(proc_a, nullptr, AI_PROC_POLYGONS);

    AiUniverseDestroy(proc_universe);
    AiRender();

    AiEnd();
    return 0;
}
