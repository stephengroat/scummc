
// A define for the various print function families

#define PRINT(name,op) {                         \
    "print" name "At", 0x##op##41, 0, 2, 0,      \
    { SCC_FA_VAL, SCC_FA_VAL}                    \
  },{                                            \
    "print" name "Color", 0x##op##42, 0, 1, 0,   \
    { SCC_FA_VAL }                               \
  },{                                            \
    "print" name "Clipped", 0x##op##43, 0, 1, 0, \
    { SCC_FA_VAL }                               \
  },{                                            \
    "print" name "Center", 0x##op##45, 0, 0, 0,  \
    {}                                           \
  },{                                            \
    "print" name "Left", 0x##op##47, 0, 0, 0,    \
    {}                                           \
  },{                                            \
    "print" name "Overhead", 0x##op##48, 0, 0, 0,\
    {}                                           \
  },{                                            \
    "print" name "Mumble", 0x##op##4A, 0, 0, 0,  \
    {}                                           \
  },{                                            \
    "print" name , 0x##op##4B, 0, 1, 0,          \
    { SCC_FA_STR }                               \
  },{                                            \
    "print" name "Begin", 0x##op##FE, 0, 0, 0,   \
    {}                                           \
  },{                                            \
    "print" name "End", 0x##op##FF, 0, 0, 0,     \
    {} \
  }

#define PRINT2(name,op) {                        \
    "print" name "At", 0x##op##41, 0, 2, 0,      \
    { SCC_FA_VAL, SCC_FA_VAL}                    \
  },{                                            \
    "print" name "Color", 0x##op##42, 0, 1, 0,   \
    { SCC_FA_VAL }                               \
  },{                                            \
    "print" name "Clipped", 0x##op##43, 0, 1, 0, \
    { SCC_FA_VAL }                               \
  },{                                            \
    "print" name "Center", 0x##op##45, 0, 0, 0,  \
    {}                                           \
  },{                                            \
    "print" name "Left", 0x##op##47, 0, 0, 0,    \
    {}                                           \
  },{                                            \
    "print" name "Overhead", 0x##op##48, 0, 0, 0,\
    {}                                           \
  },{                                            \
    "print" name "Mumble", 0x##op##4A, 0, 0, 0,  \
    {}                                           \
  },{                                            \
    "print" name , 0x##op##4B, 0, 1, 0,          \
    { SCC_FA_STR }                               \
  },{                                            \
    "print" name "Begin", 0x##op##FE, 0, 1, 0,   \
    { SCC_FA_VAL }                               \
  },{                                            \
    "print" name "End", 0x##op##FF, 0, 0, 0,     \
    {} \
  }


static scc_func_t scc_func[] = {
  {
    "startScript", 0x5E, 0, 3, 0,
    { SCC_FA_VAL, SCC_FA_VAL, SCC_FA_LIST }
  },{
    "startScriptQuick", 0x5F, 0, 2, 0,
    { SCC_FA_VAL, SCC_FA_LIST }
  },{
    "startObject", 060, 0, 4, 0,
    // flags,     script,     entryp,     args
    { SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL, SCC_FA_LIST }
  },{
    "drawObject", 0x61, 0, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "drawObjectAt", 0x62, 0, 3, 0,
    { SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL }
  },{
    "stopObjectCodeA", 0x65, 0, 0, 0,
    {}
  },{
    "stopObjectCodeB", 0x66, 0, 0, 0,
    {}
  },{
    "endCutscene", 0x67, 0, 0, 0,
    {}
  },{
    "beginCutscene", 0x68, 0, 1, 0,
    { SCC_FA_LIST }
  },{
    "stopMusic", 0x69, 0, 0, 0,
    {}
  },{
    "freezeUnfreeze", 0x6A, 0, 1, 0,
    { SCC_FA_VAL }
  },{

    "cursorOn",0x6B90, 0, 0, 0,
    {}
  },{
    "cursorOff",0x6B91, 0, 0, 0,
    {}
  },{
    "userPutOn",0x6B92, 0, 0, 0,
    {}
  },{
    "userPutOff",0x6B93, 0, 0, 0,
    {}
  },{
    "softCursorOn", 0x6B94, 0, 0, 0,
    {}
  },{
    "softCursorOff", 0x6B95, 0, 0, 0,
    {}
  },{
    "softUserputOn", 0x6B96, 0, 0, 0,
    {}
  },{
    "softUserputOff", 0x6B97, 0, 0, 0,
    {}
  },{
    "setCursorImg", 0x6B99, 0, 2, 0, // z
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "setCursorHotspot", 0x6B9A, 0, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "initCharset", 0x6B9C, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "charsetColors", 0x6B9D, 0, 1, 0,
    { SCC_FA_LIST }
  },{
    "makeCursorColorTransparent", 0x6BD6, 0, 1, 0,
    { SCC_FA_VAL }

  },{
    "breakScript", 0x6C, 0, 0, 0,
    {}
  },{
    "ifClassOfIs", 0x6D, 1, 2, 0,
    { SCC_FA_VAL, SCC_FA_LIST }
  },{
    "setClass", 0x6E, 0, 2, 0,
    { SCC_FA_VAL, SCC_FA_LIST }
  },{
    "getState", 0x6F, 1, 1, 0,
    { SCC_FA_VAL }
  },{
    "setState", 0x70, 0, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "setOwner", 0x71, 0, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "getOwner", 0x72, 1, 1, 0,
    { SCC_FA_VAL }
  },{
    "startSound", 0x74, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "stopSound", 0x75, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "startMusic", 0x76, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "stopObjectScript", 0x77, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "panCameraTo", 0x78, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "actorFollowCamera", 0x79, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "setCameraAt", 0x7A, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "loadRoom", 0x7B, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "stopScript", 0x7C, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "walkActorToObj", 0x7D, 0, 3, 0,
    { SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL }
  },{
    "walkActorTo", 0x7E, 0, 3, 0,
    { SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL }
  },{
    "putActorInXY", 0x7F, 0, 4, 0,
    { SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL }
  },{
    "putActorAtObject", 0x80, 0, 3, 0, // z
    { SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL }
  },{
    "faceActor", 0x81, 0, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "animateActor", 0x82, 0, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "doSentence", 0x83, 0, 4, 0,
    { SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL }
  },{
    "pickupObject", 0x84, 0, 2, 0,  // z
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "loadRoomWithEgo", 0x85, 0, 3, 0,
    { SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL }
  },{
    "getRandomNumber", 0x87, 1, 1, 0,
    { SCC_FA_VAL }
  },{
    "getRandomNumberRange", 0x88, 1, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "getActorMoving",0x8A, 1, 1, 0,
    { SCC_FA_VAL }
  },{
    "isScriptRunning", 0x8B, 1, 1, 0,
    { SCC_FA_VAL }
  },{
    "getActorRoom", 0x8C, 1, 1, 0,
    { SCC_FA_VAL }
  },{
    "getObjectX", 0x8D, 1, 1, 0,
    { SCC_FA_VAL }
  },{
    "getObjectY", 0x8E, 1, 1, 0,
    { SCC_FA_VAL }
  },{
    "getObjectDir", 0x8F, 1, 1, 0,
    { SCC_FA_VAL }
  },{
    "getActorWalkBox", 0x90, 1, 1, 0,
    { SCC_FA_VAL }
  },{
    "getActorCostume", 0x91, 1, 1, 0,
    { SCC_FA_VAL }
  },{
    "findInventory", 0x92, 1, 2, 0,
    { SCC_FA_VAL, SCC_FA_STR }
  },{
    "getInventoryCount", 0x93, 1, 1, 0,
    { SCC_FA_VAL }
  },{
    "getVerbFromXY", 0x94, 1, 2, 0,
    { SCC_FA_VAL, SCC_FA_STR }
  },{ // TODO: begin/endOverride

    // set the object name in the _newNames table.
    "setObjectName", 0x97, 0, 2, 0,
    { SCC_FA_VAL, SCC_FA_STR }
  },{
    "isSoundRunning", 0x98, 1, 1, 0,
    { SCC_FA_VAL }
  },{
    "setBoxFlags", 0x99, 0, 2, 0,
    { SCC_FA_LIST, SCC_FA_VAL }
  },{
    "createBoxMatrix", 0x9A, 0, 0, 0,
    {}
  },{

    "loadScript", 0x9B64, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "loadSound", 0x9B65, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "loadCostume", 0x9B66, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "loadRoom", 0x9B67, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "nukeScript", 0x9B68, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "nukeSound", 0x9B69, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "nukeCostume", 0x9B6A, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "nukeRoom", 0x9B6B, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "lockScript", 0x9B6C, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "lockSound", 0x9B6D, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "lockCostume", 0x9B6E, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "lockRoom", 0x9B6F, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "unlockScript", 0x9B70, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "unlockSound", 0x9B71, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "unlockCostume", 0x9B72, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "unlockRoom", 0x9B73, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "loadCharset", 0x9B75, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "nukeCharset", 0x9B76, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "loadFlObject", 0x9B77, 0, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }

  },{
    "roomScroll", 0x9CAC, 0, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "setScreen", 0x9CAE, 0, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "setPalColor", 0x9CAF, 0, 4, 0,
    { SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL }
  },{
    "shakeOn", 0x9CB0, 0, 0, 0,
    {}
  },{
    "shakeOff", 0x9CB1, 0, 0, 0,
    {}
  },{
    "darkenPalette", 0x9CB3, 0, 3, 0,
    { SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL }
  },{
    "saveLoadThing", 0x9CB4, 0, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "screenEffect", 0x9CB5, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "darkenPalette2", 0x9CB6, 0, 5, 0,
    { SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL }
  },{
    "setupShadowPalette", 0x9CB7, 0, 5, 0,
    { SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL }
  },{
    "palManipulate", 0x9CBA, 0, 4, 0,
    { SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL }
  },{
    "colorCycleDelay", 0x9CBB, 0, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "setPalette", 0x9CD5, 0, 1, 0,
    { SCC_FA_VAL }
  },{

    "actorSetCur", 0x9DC5, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "actorSetCostume", 0x9D4C, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "actorSetWalkSpeed", 0x9D4D, 0, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "actorSetSound", 0x9D4E, 0, 1, 0,
    { SCC_FA_LIST }
  },{
    "actorSetWalkFrame", 0x9D4F, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "actorSetTalkFrame", 0x9D50, 0, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "actorSetStandFrame", 0x9D51, 0, 1, 0,
    { SCC_FA_VAL }
  },{
#if 0
    // Dummy func in vm 0.6.1
    "actorSet", 0x9D52, 0, 3, 0,
    { SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL }
  },{
#endif
    "actorInit", 0x9D53, 0, 0, 0,
    {}
  },{
    "actorSetElevation", 0x9D54, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "actorSetDefAnim", 0x9D55, 0, 0, 0,
    {}
  },{
    "actorSetPalette", 0x9D56, 0, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "actorSetTalkColor", 0x9D57, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "actorSetName", 0x9D58, 0, 1, 0,
    { SCC_FA_STR }
  },{
    "actorSetInitFrame", 0x9D59, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "actorSetWidth", 0x9D5B, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "actorSetScale", 0x9D5C, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "actorSetNeverZClip", 0x9D5D, 0, 0, 0,
    {}
  },{
    "actorSetAlwayZClip2", 0x9DE1, 0, 0, 0,
    {}
  },{
    "actorSetIgnoreBoxes", 0x9D5F, 0, 0, 0,
    {}
  },{
    "actorSetFollowBoxes", 0x9D60, 0, 0, 0,
    {}
  },{
    "actorSetAnimSpeed", 0x9D61, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "actorSetShadowMode", 0x9D62, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "actorSetTalkPos", 0x9D63, 0, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "actorSetAnimVar", 0x9DC6, 0, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "actorSetIgnoreTurnsOn", 0x9DD7, 0, 0, 0,
    {}
  },{
    "actorSetIgnoreTurnsOff", 0x9DD8, 0, 0, 0,
    {}
  },{
    "actorInitLittle", 0x9DD9, 0, 0, 0,
    {}
  },{
    "actorDrawVirScr", 0x9DDA, 0, 0, 0,
    {}
  },{
    "actorSetLayer", 0x9DE3, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "actorSetWalkScript", 0x9DE4, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "actorSetStanding", 0x9DE5, 0, 0, 0,
    {}
  },{
    "actorSetDirection", 0x9DE6, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "actorTurnToDirection", 0x9DE7, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "actorFreeze", 0x9DE9, 0, 0, 0,
    {}
  },{
    "actorUnfreeze", 0x9DEA, 0, 0, 0,
    {}
  },{
    "actorSetTalkScript", 0x9DEB, 0, 1, 0,
    { SCC_FA_VAL }
  },{

    "verbSetCur", 0x9EC4, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "verbLoadImg", 0x9E7C, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "verbLoadString", 0x9E7D, 0, 1, 0,
    { SCC_FA_STR }
  },{
    "verbSetColor", 0x9E7E, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "verbSetHiColor", 0x9E7F, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "verbSetXY", 0x9E80, 0, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "verbSetOn", 0x9E81, 0, 0, 0,
    {}
  },{
    "verbSetOff", 0x9E82, 0, 0, 0,
    {}
  },{
    "verbKill", 0x9E83, 0, 0, 0,
    {}
  },{
    "verbInit", 0x9E84, 0, 0, 0,
    {}
  },{
    "verbSetDimColor", 0x9E85, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "verbSetDimmed", 0x9E86, 0, 0, 0,
    {}
  },{
    "verbSetKey", 0x9E87, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "verbSetCenter", 0x9E88, 0, 0, 0,
    {}
  },{
    "verbSetToString", 0x9E89, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "verbSetToObject", 0x9E8B, 0, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "verbSetBkColor", 0x9E8C, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "verbRedraw", 0x9EFF, 0, 0, 0,
    {}
  },{

    "getActorFromXY", 0x9F, 1, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "findObject", 0xA0, 1, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    // This call allow to map the pseudo room index (idx > 0x7F) to
    // real room id. This call set all pseudo index in the list point
    // to VAL. idx < 0x80 are simply ignored.
    "pseudoRoom", 0xA1, 0, 2, 0,
    { SCC_FA_VAL, SCC_FA_LIST }
  },{
    "getActorElevation", 0xA2, 1, 1, 0,
    { SCC_FA_VAL }
  },{
    "getVerbEntrypoint", 0xA3, 1, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{

    "saveVerbs", 0xA58D, 0, 3, 0,
    { SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL }
  },{
    "restoreVerbs", 0xA58E, 0, 3, 0,
    { SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL }
  },{
    "deleteVerbs", 0xA58F, 0, 3, 0,
    { SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL }
  },{

    "drawBox", 0xA6, 0, 5, 0,
    { SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL  }
  },{
    "getActorWidth", 0xA8, 1, 1, 0,
    { SCC_FA_VAL }
  },{

    "waitForActor", 0xA9A8, 0, 1, 1,
    { SCC_FA_VAL, SCC_FA_SELF_OFF }
  },{

    "waitForMessage", 0xA9A9, 0, 0, 0,
    {}
  },{
    "waitForCamera", 0xA9AA, 0, 0, 0,
    {}
  },{
    "waitForSentence", 0xA9AB, 0, 0, 0,
    {}
  },{
    // TODO "waitUntilActorDrawn", 0xA9E2
    // TODO "waitUntilActorTurned", 0xA9E8

    "getActorScaleX", 0xAA, 1, 1, 0,
    { SCC_FA_VAL }
  },{
    "getActorAnimCounter1", 0xAB, 1, 1, 0,
    { SCC_FA_VAL }
  },{
    "soundKludge", 0xAC, 0, 1, 0,
    { SCC_FA_LIST }
  },{
    "isAnyOf", 0xAD, 1, 2, 0,
    { SCC_FA_VAL, SCC_FA_LIST }
  },{

    "restartGame", 0xAE9E, 0, 0, 0,
    {}
  },{
    "pauseGame", 0xAE9F, 0, 0, 0,
    {}
  },{
    "shutdown", 0xAEA0, 0, 0, 0,
    {}
  },{

    "isActorInBox", 0xAF, 1, 1, 0,
    { SCC_FA_VAL }
  },{
    "delay", 0xB0, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "delaySeconds", 0xB1, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "delayMinutes", 0xB2, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "stopSentence", 0xB3,0, 0, 0,
    {}
  },
  
  PRINT("",B4),
  PRINT("Cur",B5),
  PRINT("Dbg",B6),
  PRINT("Sys",B7),
  PRINT2("Actor",B8),
  PRINT("Ego",B9)

  ,{
    "talkActor", 0xBA, 0, 2, 0,
    { SCC_FA_VAL, SCC_FA_STR }
  },{
    "talkEgo", 0xBB, 0, 1, 0,
    { SCC_FA_STR }
  },{
    
    // TODO dim array

    // this one still need special care i think
    "startObjectQuick", 0xBE, 0, 3, 0,
    // script,    entryp,     args
    { SCC_FA_VAL, SCC_FA_VAL, SCC_FA_LIST }
  },{

    "startScriptQuick2", 0xBF, 0, 2, 0,
    // script,    args
    { SCC_FA_VAL, SCC_FA_LIST }
  },{
    
    // TODO dim2 array
    
    "abs", 0xC4, 1, 1, 0,
    { SCC_FA_VAL }
  },{
    "getDistObjObj", 0xC5, 1, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "getDistObjPt", 0xC6, 1, 3, 0,
    { SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL }
  },{
    "getDistPtPt", 0xC7, 1, 4, 0,
    { SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL }
  },{

    // TODO "kernelGetFunctions", 0xC8, 0, 1,
    
    "breakXTimes", 0xCA, 0, 1, 0,
    { SCC_FA_VAL }
  },{
    "pickOneOf", 0xCB, 1, 2, 0,
    { SCC_FA_VAL, SCC_FA_LIST }
  },{
    "pickOneOfDefault", 0xCC, 1, 3, 0,
    { SCC_FA_VAL, SCC_FA_LIST, SCC_FA_VAL }
  },{
    "stampObject", 0xCD, 0, 4, 0,
    { SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL, SCC_FA_VAL }
  },{
    "getDateTime", 0xD0, 0, 0, 0,
    {}
  },{
    "stopTalking", 0xD1,0, 0, 0,
    {}
  },{
    "getAnimateVariable", 0xD2, 1, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "shuffle", 0xD4, 0, 3, 0,
    { SCC_FA_PTR, SCC_FA_VAL, SCC_FA_VAL }
  },{
    "jumpToScript", 0xD5, 0, 3, 0,
    { SCC_FA_VAL, SCC_FA_VAL, SCC_FA_LIST }
  },{
    "bAnd", 0xD6, 1, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "bOr", 0xD7, 1, 2, 0,
    { SCC_FA_VAL, SCC_FA_VAL }
  },{
    "isRoomScriptRunning", 0xD8, 1, 1, 0,
    { SCC_FA_VAL }
  },{
    "findAllObjects", 0xDD, 1, 1, 0,
    { SCC_FA_VAL }
  },{
    // this opcode check ground area in minigame "Asteroid Lander" in the dig
    "unknownE1", 0xE1, 1, 1, 0,
    { SCC_FA_VAL }
  },{
#if 0
    // very strange func. First it look at the ptr, if the value there
    // is 0 it then allocate an array at the same address and pick a
    // random value out of it.
    // If the value pointed to by the ptr is not 0, it's interpreted
    // as an array address. The first value in this array is read as
    // a string ressourse num. and finnaly some strange operation is
    // done with the string and the array.
    // need more investigation
    "pickVarRandom", 0xE3, 1, 2, 0,
    { SCC_FA_PTR, SCC_FA_LIST }
  },{
    // do nothing in vm 0.6.1
    "setBoxSet", 0xE4, 0, 1, 0,
    { SCC_FA_VAL }
#endif
  },{
    "getActorLayer", 0xEC, 1, 1, 0,
    { SCC_FA_VAL }
  },{
    "getObjectNewDir", 0xED, 1, 1, 0,
    { SCC_FA_VAL }

  },{
    NULL, 0, 0, 0, 0, {}
  }
};

