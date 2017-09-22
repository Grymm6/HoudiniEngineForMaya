#ifndef __AssetNodeOptions_h__
#define __AssetNodeOptions_h__

#include "NodeOptions.h"

NODE_OPTIONS_BEGIN(AssetNodeOptions)

NODE_OPTION(syncWhenInputConnects, bool, true)
NODE_OPTION(autoSyncOutputs, bool, false)

NODE_OPTION(useAssetObjectTransform, bool, false)
NODE_OPTION(splitGeosByGroup, bool, false)
NODE_OPTION(outputHiddenObjects, bool, false)
NODE_OPTION(outputTemplatedGeometries, bool, false)

NODE_OPTION(useInstancerNode, bool, true)

NODE_OPTIONS_END()

extern AssetNodeOptions::Definition assetNodeOptionsDefinition;

#endif
