/* PORTABLE GHIDRA LIBCOSCOS HEADERS (c) 2024 
 * NOTE: THIS IS NOT READY FOR PRODUCTION YET!!! 
 * Still is under heavy bugfixing!
 * AUTHOR: Calloc 
 * Used for Resolving missing libcoscos fields inside of ghidra
 * If you borrow this header for your project be sure you give credit back to the author
 * He spent many days figuring this out for you 
 * NOTE: C++ Fields are currently commented out and not all 100% of the libcoscos 
 * class object fields are avalibe for use as of yet... 
 * However these ones should be the most commonly used in geometry dash. 
 * 
 * This File can be used to resolve Robtop's libcoscos Object fields 
 * 
 * How to use -> Open your project and go to File -> Parse C Source -> Select this Header File 
 * 
 * I will work on a file for class fields belonging to Geometry dash 2.204's or later versions with those class Objects soon - Calloc 
 *
 */

typedef unsigned char   undefined;
typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef long double    longdouble;
typedef long long    longlong;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined7;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef int    wchar_t;
typedef unsigned short    word;




/* OPENGL DEFINITIONS */
typedef unsigned int GLenum;
typedef unsigned int GLbitfield;
typedef unsigned int GLuint;
typedef int GLint;
typedef int GLsizei;
typedef unsigned char GLboolean;
typedef signed char GLbyte;
typedef short GLshort;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void GLvoid;
typedef unsigned char GLubyte;
typedef float GLfloat;
typedef unsigned int GLuint;



/* ENUMS */

typedef enum LanguageType
{
    kLanguageEnglish = 0,
    kLanguageChinese,
    kLanguageFrench,
    kLanguageItalian,
    kLanguageGerman,
    kLanguageSpanish,
    kLanguageDutch,
    kLanguageRussian,
    kLanguageKorean,
    kLanguageJapanese,
    kLanguageHungarian,
    kLanguagePortuguese,
    kLanguageArabic
} ccLanguageType;


typedef enum {
        kCCObjectTypePlayLayer = 5,
        kCCObjectTypeLevelEditorLayer = 6,
        kCCObjectTypeMenuLayer = 15,
} CCObjectType;

typedef enum {
// #line 63 "cocos2d/cocos-headers/cocos2dx/shaders/ccGLStateCache.h"
      CC_GL_ALL = 0,

} ccGLServerState;


enum ccScriptType {
    kScriptTypeNone = 0,
    kScriptTypeLua,
    kScriptTypeJavascript
};



enum ConfigType
{
    NONE,
    COCOSTUDIO,
};




typedef enum
{
    kCCVerticalTextAlignmentTop,
    kCCVerticalTextAlignmentCenter,
    kCCVerticalTextAlignmentBottom,
} CCVerticalTextAlignment;



enum CCDictType
{
    kCCDictUnknown = 0,
    kCCDictStr,
    kCCDictInt
};


typedef enum {

    kCCTexture2DPixelFormat_RGBA8888,

    kCCTexture2DPixelFormat_RGB888,

    kCCTexture2DPixelFormat_RGB565,

    kCCTexture2DPixelFormat_A8,

    kCCTexture2DPixelFormat_I8,

    kCCTexture2DPixelFormat_AI88,

    kCCTexture2DPixelFormat_RGBA4444,

    kCCTexture2DPixelFormat_RGB5A1,

    kCCTexture2DPixelFormat_PVRTC4,

    kCCTexture2DPixelFormat_PVRTC2,



    kCCTexture2DPixelFormat_Default = kCCTexture2DPixelFormat_RGBA8888,


    kTexture2DPixelFormat_RGBA8888 = kCCTexture2DPixelFormat_RGBA8888,
    kTexture2DPixelFormat_RGB888 = kCCTexture2DPixelFormat_RGB888,
    kTexture2DPixelFormat_RGB565 = kCCTexture2DPixelFormat_RGB565,
    kTexture2DPixelFormat_A8 = kCCTexture2DPixelFormat_A8,
    kTexture2DPixelFormat_RGBA4444 = kCCTexture2DPixelFormat_RGBA4444,
    kTexture2DPixelFormat_RGB5A1 = kCCTexture2DPixelFormat_RGB5A1,
    kTexture2DPixelFormat_Default = kCCTexture2DPixelFormat_Default

} CCTexture2DPixelFormat;



typedef enum _ccConfigurationType {
    ConfigurationError,
    ConfigurationString,
    ConfigurationInt,
    ConfigurationDouble,
    ConfigurationBoolean
} ccConfigurationType;

typedef enum {

    kCCDirectorProjection2D,


    kCCDirectorProjection3D,


    kCCDirectorProjectionCustom,


    kCCDirectorProjectionDefault = kCCDirectorProjection3D,
} ccDirectorProjection;

typedef enum {
    kTextureQualityLow = 1,
    kTextureQualityMedium,
    kTextureQualityHigh
} TextureQuality;
typedef enum {
    kPopTransitionFade,
    kPopTransitionMoveInT
} PopTransition;


typedef enum POINT_CLASSIFICATION {
    POINT_INFRONT_OF_PLANE = 0,
    POINT_BEHIND_PLANE,
    POINT_ON_PLANE,
} POINT_CLASSIFICATION;

typedef enum {

    kTypeBackClicked = 1,
    kTypeMenuClicked,
} ccKeypadMSGType;

typedef enum {
	kCCTouchesAllAtOnce,
	kCCTouchesOneByOne,
} ccTouchesMode;

typedef enum {

	kCCTransitionOrientationLeftOver = 0,

	kCCTransitionOrientationRightOver = 1,

	kCCTransitionOrientationUpOver = 0,

	kCCTransitionOrientationDownOver = 1,
// #line 76 "cocos2d/cocos-headers/cocos2dx/layers_scenes_transitions_nodes/CCTransition.h"
} tOrientation;

typedef enum
{
    kCCMenuStateWaiting,
    kCCMenuStateTrackingTouch
} tCCMenuState;

typedef enum {
    kCCProgressTimerTypeRadial,
    kCCProgressTimerTypeBar,
} CCProgressTimerType;

typedef enum eImageFormat
{
    kCCImageFormatJPEG      = 0,
    kCCImageFormatPNG       = 1,
} tCCImageFormat;


enum TargetPlatform
{
    kTargetWindows,
    kTargetLinux,
    kTargetMacOS,
    kTargetAndroid,
    kTargetIphone,
    kTargetIpad,
    kTargetBlackBerry,
    kTargetNaCl,
    kTargetEmscripten,
    kTargetTizen,
    kTargetWinRT,
    kTargetWP8
};

enum ResolutionPolicy
{


    kResolutionExactFit,


    kResolutionNoBorder,


    kResolutionShowAll,

    kResolutionFixedHeight,
    
    kResolutionFixedWidth,

    kResolutionUnKnown,
};



enum XMLError {
    XML_NO_ERROR = 0,
    XML_SUCCESS = 0,

    XML_NO_ATTRIBUTE,
    XML_WRONG_ATTRIBUTE_TYPE,

    XML_ERROR_FILE_NOT_FOUND,
    XML_ERROR_FILE_COULD_NOT_BE_OPENED,
    XML_ERROR_FILE_READ_ERROR,
    XML_ERROR_ELEMENT_MISMATCH,
    XML_ERROR_PARSING_ELEMENT,
    XML_ERROR_PARSING_ATTRIBUTE,
    XML_ERROR_IDENTIFYING_TAG,
    XML_ERROR_PARSING_TEXT,
    XML_ERROR_PARSING_CDATA,
    XML_ERROR_PARSING_COMMENT,
    XML_ERROR_PARSING_DECLARATION,
    XML_ERROR_PARSING_UNKNOWN,
    XML_ERROR_EMPTY_DOCUMENT,
    XML_ERROR_MISMATCHED_ELEMENT,
    XML_ERROR_PARSING,

    XML_CAN_NOT_CONVERT_TEXT,
    XML_NO_TEXT_NODE
};


enum Whitespace {
    PRESERVE_WHITESPACE,
    COLLAPSE_WHITESPACE
};


typedef enum ccTMXTileFlags_ {
    kCCTMXTileHorizontalFlag        = 0x80000000,
    kCCTMXTileVerticalFlag            = 0x40000000,
    kCCTMXTileDiagonalFlag            = 0x20000000,
    kCCFlipedAll                    = (kCCTMXTileHorizontalFlag|kCCTMXTileVerticalFlag|kCCTMXTileDiagonalFlag),
    kCCFlippedMask                    = ~(kCCFlipedAll)
} ccTMXTileFlags;

typedef enum
{
    ccTouchSelectorBeganBit = 1 << 0,
    ccTouchSelectorMovedBit = 1 << 1,
    ccTouchSelectorEndedBit = 1 << 2,
    ccTouchSelectorCancelledBit = 1 << 3,
    ccTouchSelectorAllBits = ( ccTouchSelectorBeganBit | ccTouchSelectorMovedBit | ccTouchSelectorEndedBit | ccTouchSelectorCancelledBit),
} ccTouchSelectorFlag;

typedef struct CCObject CCObject;

/* EXTERNAL FUNCTION METHODS */
typedef void (*SEL_MenuHandler)(CCObject*);


typedef struct CCDataVisitor CCDataVisitor;
typedef struct CCPrettyPrinter CCPrettyPrinter;
typedef struct CCCopying CCCopying;
typedef struct CCObject CCObject;
typedef struct CCPoint CCPoint;
typedef struct CCSize CCSize;
typedef struct CCRect CCRect;
typedef struct CCAction CCAction;
typedef struct CCFiniteTimeAction CCFiniteTimeAction;
typedef struct CCSpeed CCSpeed;
typedef struct CCFollow CCFollow;
typedef struct CCAffineTransform CCAffineTransform;
typedef struct _ccArray _ccArray;
typedef struct _ccCArray _ccCArray;
typedef struct CCArray CCArray;
typedef struct CCGLProgram CCGLProgram;
typedef struct CCTouch CCTouch;
typedef struct CCEvent CCEvent;
typedef struct CCSet CCSet;
typedef struct CCScriptHandlerEntry CCScriptHandlerEntry;
typedef struct CCSchedulerScriptHandlerEntry CCSchedulerScriptHandlerEntry;
typedef struct CCTouchScriptHandlerEntry CCTouchScriptHandlerEntry;
typedef struct CCScriptEngineProtocol CCScriptEngineProtocol;
typedef struct CCScriptEngineManager CCScriptEngineManager;
typedef struct _ccColor3B _ccColor3B;
typedef struct _ccHSVValue _ccHSVValue;
typedef struct _ccColor4B _ccColor4B;
typedef struct _ccColor4F _ccColor4F;
typedef struct _ccVertex2F _ccVertex2F;
typedef struct _ccVertex3F _ccVertex3F;
typedef struct _ccTex2F _ccTex2F;
typedef struct _ccPointSprite _ccPointSprite;
typedef struct _ccQuad2 _ccQuad2;
typedef struct _ccQuad3 _ccQuad3;
typedef struct _ccV2F_C4B_T2F _ccV2F_C4B_T2F;
typedef struct _ccV2F_C4F_T2F _ccV2F_C4F_T2F;
typedef struct _ccV3F_C4B_T2F _ccV3F_C4B_T2F;
typedef struct _ccV2F_C4B_T2F_Triangle _ccV2F_C4B_T2F_Triangle;
typedef struct _ccV2F_C4B_T2F_Quad _ccV2F_C4B_T2F_Quad;
typedef struct _ccV3F_C4B_T2F_Quad _ccV3F_C4B_T2F_Quad;
typedef struct _ccV2F_C4F_T2F_Quad _ccV2F_C4F_T2F_Quad;
typedef struct _ccBlendFunc _ccBlendFunc;
typedef struct _ccT2F_Quad _ccT2F_Quad;
typedef struct _ccFontShadow _ccFontShadow;
typedef struct _ccFontStroke _ccFontStroke;
typedef struct _ccFontDefinition _ccFontDefinition;
typedef struct _ccTexParams _ccTexParams;
typedef struct CCTexture2D CCTexture2D;
typedef struct CCRGBAProtocol CCRGBAProtocol;
typedef struct CCBlendProtocol CCBlendProtocol;
typedef struct CCTextureProtocol CCTextureProtocol;
typedef struct CCLabelProtocol CCLabelProtocol;
typedef struct CCDirectorDelegate CCDirectorDelegate;
typedef struct CCNode CCNode;
typedef struct CCNodeRGBA CCNodeRGBA;
typedef struct CCSpriteFrame CCSpriteFrame;
typedef struct UT_hash_bucket UT_hash_bucket;
typedef struct UT_hash_table UT_hash_table;
typedef struct UT_hash_handle UT_hash_handle;
typedef struct CCString CCString;
typedef struct CCDictElement CCDictElement;
typedef struct CCDictionary CCDictionary;
typedef struct CCAnimationFrame CCAnimationFrame;
typedef struct CCAnimation CCAnimation;
typedef struct CCActionInterval CCActionInterval;
typedef struct CCSequence CCSequence;
typedef struct CCRepeat CCRepeat;
typedef struct CCRepeatForever CCRepeatForever;
typedef struct CCSpawn CCSpawn;
typedef struct CCRotateTo CCRotateTo;
typedef struct CCRotateBy CCRotateBy;
typedef struct CCMoveBy CCMoveBy;
typedef struct CCMoveTo CCMoveTo;
typedef struct CCSkewTo CCSkewTo;
typedef struct CCSkewBy CCSkewBy;
typedef struct CCJumpBy CCJumpBy;
typedef struct CCJumpTo CCJumpTo;
typedef struct _ccBezierConfig _ccBezierConfig;
typedef struct CCBezierBy CCBezierBy;
typedef struct CCBezierTo CCBezierTo;
typedef struct CCScaleTo CCScaleTo;
typedef struct CCScaleBy CCScaleBy;
typedef struct CCBlink CCBlink;
typedef struct CCFadeIn CCFadeIn;
typedef struct CCFadeOut CCFadeOut;
typedef struct CCFadeTo CCFadeTo;
typedef struct CCTintTo CCTintTo;
typedef struct CCTintBy CCTintBy;
typedef struct CCDelayTime CCDelayTime;
typedef struct CCReverseTime CCReverseTime;
typedef struct CCAnimate CCAnimate;
typedef struct CCTargetedAction CCTargetedAction;
typedef struct CCActionCamera CCActionCamera;
typedef struct CCOrbitCamera CCOrbitCamera;
typedef struct CCActionManager CCActionManager;
typedef struct CCActionEase CCActionEase;
typedef struct CCEaseRateAction CCEaseRateAction;
typedef struct CCEaseIn CCEaseIn;
typedef struct CCEaseOut CCEaseOut;
typedef struct CCEaseInOut CCEaseInOut;
typedef struct CCEaseExponentialIn CCEaseExponentialIn;
typedef struct CCEaseExponentialOut CCEaseExponentialOut;
typedef struct CCEaseExponentialInOut CCEaseExponentialInOut;
typedef struct CCEaseSineIn CCEaseSineIn;
typedef struct CCEaseSineOut CCEaseSineOut;
typedef struct CCEaseSineInOut CCEaseSineInOut;
typedef struct CCEaseElastic CCEaseElastic;
typedef struct CCEaseElasticIn CCEaseElasticIn;
typedef struct CCEaseElasticOut CCEaseElasticOut;
typedef struct CCEaseElasticInOut CCEaseElasticInOut;
typedef struct CCEaseBounce CCEaseBounce;
typedef struct CCEaseBounceIn CCEaseBounceIn;
typedef struct CCEaseBounceOut CCEaseBounceOut;
typedef struct CCEaseBounceInOut CCEaseBounceInOut;
typedef struct CCEaseBackIn CCEaseBackIn;
typedef struct CCEaseBackOut CCEaseBackOut;
typedef struct CCEaseBackInOut CCEaseBackInOut;
typedef struct TypeInfo TypeInfo;
typedef struct CCActionInstant CCActionInstant;
typedef struct CCShow CCShow;
typedef struct CCHide CCHide;
typedef struct CCToggleVisibility CCToggleVisibility;
typedef struct CCRemoveSelf CCRemoveSelf;
typedef struct CCFlipX CCFlipX;
typedef struct CCFlipY CCFlipY;
typedef struct CCPlace CCPlace;
typedef struct CCCallFunc CCCallFunc;
typedef struct CCCallFuncN CCCallFuncN;
typedef struct CCCallFuncND CCCallFuncND;
typedef struct CCCallFuncO CCCallFuncO;
typedef struct CCGridAction CCGridAction;
typedef struct CCGrid3DAction CCGrid3DAction;
typedef struct CCTiledGrid3DAction CCTiledGrid3DAction;
typedef struct CCAccelDeccelAmplitude CCAccelDeccelAmplitude;
typedef struct CCAccelAmplitude CCAccelAmplitude;
typedef struct CCDeccelAmplitude CCDeccelAmplitude;
typedef struct CCStopGrid CCStopGrid;
typedef struct CCReuseGrid CCReuseGrid;
typedef struct CCWaves3D CCWaves3D;
typedef struct CCFlipX3D CCFlipX3D;
typedef struct CCFlipY3D CCFlipY3D;
typedef struct CCLens3D CCLens3D;
typedef struct CCRipple3D CCRipple3D;
typedef struct CCShaky3D CCShaky3D;
typedef struct CCLiquid CCLiquid;
typedef struct CCWaves CCWaves;
typedef struct CCTwirl CCTwirl;
typedef struct CCPageTurn3D CCPageTurn3D;
typedef struct CCProgressTo CCProgressTo;
typedef struct CCProgressFromTo CCProgressFromTo;
typedef struct CCShakyTiles3D CCShakyTiles3D;
typedef struct CCShatteredTiles3D CCShatteredTiles3D;
typedef struct CCShuffleTiles CCShuffleTiles;
typedef struct CCFadeOutTRTiles CCFadeOutTRTiles;
typedef struct CCFadeOutBLTiles CCFadeOutBLTiles;
typedef struct CCFadeOutUpTiles CCFadeOutUpTiles;
typedef struct CCFadeOutDownTiles CCFadeOutDownTiles;
typedef struct CCTurnOffTiles CCTurnOffTiles;
typedef struct CCWavesTiles3D CCWavesTiles3D;
typedef struct CCJumpTiles3D CCJumpTiles3D;
typedef struct CCSplitRows CCSplitRows;
typedef struct CCSplitCols CCSplitCols;
typedef struct CCActionTweenDelegate CCActionTweenDelegate;
typedef struct CCActionTween CCActionTween;
typedef struct CCPointArray CCPointArray;
typedef struct CCCardinalSplineTo CCCardinalSplineTo;
typedef struct CCCardinalSplineBy CCCardinalSplineBy;
typedef struct CCCatmullRomTo CCCatmullRomTo;
typedef struct CCCatmullRomBy CCCatmullRomBy;
typedef struct CCAtlasNode CCAtlasNode;
typedef struct CCAutoreleasePool CCAutoreleasePool;
typedef struct CCPoolManager CCPoolManager;
typedef struct CCInteger CCInteger;
typedef struct CCFloat CCFloat;
typedef struct CCDouble CCDouble;
typedef struct CCBool CCBool;
typedef struct CCZone CCZone;
typedef struct CCDrawNode CCDrawNode;
typedef struct CCConfiguration CCConfiguration;
typedef struct CCGrabber CCGrabber;
typedef struct CCCamera CCCamera;
typedef struct CCLabelAtlas CCLabelAtlas;
typedef struct CCDirector CCDirector;
typedef struct CCDisplayLinkDirector CCDisplayLinkDirector;
typedef struct CCGridBase CCGridBase;
typedef struct CCGrid3D CCGrid3D;
typedef struct CCTiledGrid3D CCTiledGrid3D;
typedef struct kmVec2 kmVec2;
typedef struct kmVec3 kmVec3;
typedef struct kmMat3 kmMat3;
typedef struct kmMat4 kmMat4;
typedef struct kmQuaternion kmQuaternion;
typedef struct kmPlane kmPlane;
typedef struct kmAABB kmAABB;
typedef struct kmRay2 kmRay2;
typedef struct CCKeypadDelegate CCKeypadDelegate;
typedef struct CCKeypadHandler CCKeypadHandler;
typedef struct CCKeypadDispatcher CCKeypadDispatcher;
typedef struct CCTextureAtlas CCTextureAtlas;
typedef struct CCSprite CCSprite;
typedef struct CCLabelTTF CCLabelTTF;
typedef struct CCSpriteBatchNode CCSpriteBatchNode;
typedef struct _BMFontDef _BMFontDef;
typedef struct _BMFontPadding _BMFontPadding;
typedef struct _FontDefHashElement _FontDefHashElement;
typedef struct _KerningHashElement _KerningHashElement;
typedef struct CCBMFontConfiguration CCBMFontConfiguration;
typedef struct CCLabelBMFont CCLabelBMFont;
typedef struct CCTouchDelegate CCTouchDelegate;
typedef struct CCTargetedTouchDelegate CCTargetedTouchDelegate;
typedef struct CCStandardTouchDelegate CCStandardTouchDelegate;
typedef struct CCAcceleration CCAcceleration;
typedef struct CCAccelerometerDelegate CCAccelerometerDelegate;
typedef struct CCKeyboardDelegate CCKeyboardDelegate;
typedef struct CCKeyboardHandler CCKeyboardHandler;
typedef struct CCMouseDelegate CCMouseDelegate;
typedef struct CCMouseHandler CCMouseHandler;
typedef struct CCLayer CCLayer;
typedef struct CCLayerRGBA CCLayerRGBA;
typedef struct CCLayerColor CCLayerColor;
typedef struct CCLayerGradient CCLayerGradient;
typedef struct CCLayerMultiplex CCLayerMultiplex;
typedef struct CCScene CCScene;
typedef struct CCTransitionEaseScene CCTransitionEaseScene;
typedef struct CCTransitionScene CCTransitionScene;
typedef struct CCTransitionSceneOriented CCTransitionSceneOriented;
typedef struct CCTransitionRotoZoom CCTransitionRotoZoom;
typedef struct CCTransitionJumpZoom CCTransitionJumpZoom;
typedef struct CCTransitionMoveInL CCTransitionMoveInL;
typedef struct CCTransitionMoveInR CCTransitionMoveInR;
typedef struct CCTransitionMoveInT CCTransitionMoveInT;
typedef struct CCTransitionMoveInB CCTransitionMoveInB;
typedef struct CCTransitionSlideInL CCTransitionSlideInL;
typedef struct CCTransitionSlideInR CCTransitionSlideInR;
typedef struct CCTransitionSlideInB CCTransitionSlideInB;
typedef struct CCTransitionSlideInT CCTransitionSlideInT;
typedef struct CCTransitionShrinkGrow CCTransitionShrinkGrow;
typedef struct CCTransitionFlipX CCTransitionFlipX;
typedef struct CCTransitionFlipY CCTransitionFlipY;
typedef struct CCTransitionFlipAngular CCTransitionFlipAngular;
typedef struct CCTransitionZoomFlipX CCTransitionZoomFlipX;
typedef struct CCTransitionZoomFlipY CCTransitionZoomFlipY;
typedef struct CCTransitionZoomFlipAngular CCTransitionZoomFlipAngular;
typedef struct CCTransitionFade CCTransitionFade;
typedef struct CCTransitionCrossFade CCTransitionCrossFade;
typedef struct CCTransitionTurnOffTiles CCTransitionTurnOffTiles;
typedef struct CCTransitionSplitCols CCTransitionSplitCols;
typedef struct CCTransitionSplitRows CCTransitionSplitRows;
typedef struct CCTransitionFadeTR CCTransitionFadeTR;
typedef struct CCTransitionFadeBL CCTransitionFadeBL;
typedef struct CCTransitionFadeUp CCTransitionFadeUp;
typedef struct CCTransitionFadeDown CCTransitionFadeDown;
typedef struct CCTransitionPageTurn CCTransitionPageTurn;
typedef struct CCTransitionProgress CCTransitionProgress;
typedef struct CCTransitionProgressRadialCCW CCTransitionProgressRadialCCW;
typedef struct CCTransitionProgressRadialCW CCTransitionProgressRadialCW;
typedef struct CCTransitionProgressHorizontal CCTransitionProgressHorizontal;
typedef struct CCTransitionProgressVertical CCTransitionProgressVertical;
typedef struct CCTransitionProgressInOut CCTransitionProgressInOut;
typedef struct CCTransitionProgressOutIn CCTransitionProgressOutIn;
typedef struct CCMenuItem CCMenuItem;
typedef struct CCMenuItemLabel CCMenuItemLabel;
typedef struct CCMenuItemAtlasFont CCMenuItemAtlasFont;
typedef struct CCMenuItemFont CCMenuItemFont;
typedef struct CCMenuItemSprite CCMenuItemSprite;
typedef struct CCMenuItemImage CCMenuItemImage;
typedef struct CCMenuItemToggle CCMenuItemToggle;
typedef struct CCMenu CCMenu;
typedef struct CCClippingNode CCClippingNode;
typedef struct CCMotionStreak CCMotionStreak;
typedef struct CCProgressTimer CCProgressTimer;
typedef struct CCRenderTexture CCRenderTexture;
typedef struct CCDevice CCDevice;
typedef struct CCFileUtils CCFileUtils;
typedef struct CCImage CCImage;
typedef struct CCThread CCThread;
typedef struct cc_timeval cc_timeval;
typedef struct CCTime CCTime;
typedef struct CCAccelerometer CCAccelerometer;
typedef struct timezone timezone;
typedef struct CCApplicationProtocol CCApplicationProtocol;
typedef struct CCApplication CCApplication;
typedef struct CCEGLViewProtocol CCEGLViewProtocol;
typedef struct GLFWvidmode GLFWvidmode;
typedef struct GLFWgammaramp GLFWgammaramp;
typedef struct CCEGLView CCEGLView;
typedef struct CCShaderCache CCShaderCache;
typedef struct CCAnimationCache CCAnimationCache;
typedef struct CCSpriteFrameCache CCSpriteFrameCache;
typedef struct CCNotificationCenter CCNotificationCenter;
typedef struct CCNotificationObserver CCNotificationObserver;
typedef struct CCProfiler CCProfiler;
typedef struct CCProfilingTimer CCProfilingTimer;
typedef struct CCUserDefault CCUserDefault;
typedef struct CCIMEDelegate CCIMEDelegate;
typedef struct CCIMEDispatcher CCIMEDispatcher;
typedef struct CCTextFieldDelegate CCTextFieldDelegate;
typedef struct CCTextFieldTTF CCTextFieldTTF;
typedef struct CCTextureCache CCTextureCache;
typedef struct CCPVRMipmap CCPVRMipmap;
typedef struct _ccPVRTexturePixelFormatInfo _ccPVRTexturePixelFormatInfo;
typedef struct CCTexturePVR CCTexturePVR;
typedef struct CCParallaxNode CCParallaxNode;
typedef struct CCTMXObjectGroup CCTMXObjectGroup;
typedef struct CCTMXLayerInfo CCTMXLayerInfo;
typedef struct CCTMXTilesetInfo CCTMXTilesetInfo;
typedef struct CCTMXMapInfo CCTMXMapInfo;
typedef struct CCTMXLayer CCTMXLayer;
typedef struct CCTMXTiledMap CCTMXTiledMap;
typedef struct CCTileMapAtlas CCTileMapAtlas;
typedef struct ccTouchHandlerHelperData ccTouchHandlerHelperData;
typedef struct EGLTouchDelegate EGLTouchDelegate;
typedef struct CCTouchDispatcher CCTouchDispatcher;
typedef struct CCTouchHandler CCTouchHandler;
typedef struct CCStandardTouchHandler CCStandardTouchHandler;
typedef struct CCTargetedTouchHandler CCTargetedTouchHandler;
typedef struct CCTimer CCTimer;
typedef struct CCScheduler CCScheduler;
typedef struct CCComponent CCComponent;
typedef struct CCComponentContainer CCComponentContainer;
typedef struct CCKeyboardDispatcher CCKeyboardDispatcher;
typedef struct CCMouseDispatcher CCMouseDispatcher;
typedef struct CCSceneTransitionDelegate CCSceneTransitionDelegate;
typedef struct DS_Dictionary DS_Dictionary;
struct CCDataVisitor{
};

typedef dword string;

struct CCPrettyPrinter{
	int _indentLevel;
	string _indentStr;
	string _result;
};

struct CCCopying{
};

struct CCObject{
	unsigned int m_uID;
	int m_nLuaID;
	int m_nTag;
	unsigned int m_uReference;
	unsigned int m_uAutoReleaseCount;
	int m_eObjType;
	unsigned int m_uObjectIdxInArray;
};

struct CCPoint{
	float x;
	float y;
};

struct CCSize{
	float width;
	float height;
};

struct CCRect{
	CCPoint origin;
	CCSize size;
};

struct CCAction{
	CCNode* m_pOriginalTarget;
	CCNode* m_pTarget;
	int m_nTag;
	float m_fSpeedMod;
};

struct CCFiniteTimeAction{
	float m_fDuration;
};

struct CCSpeed{
	float m_fSpeed;
	CCActionInterval* m_pInnerAction;
};

struct CCFollow{
	CCNode* m_pobFollowedNode;
	bool m_bBoundarySet;
	bool m_bBoundaryFullyCovered;
	CCPoint m_obHalfScreenSize;
	CCPoint m_obFullScreenSize;
	float m_fLeftBoundary;
	float m_fRightBoundary;
	float m_fTopBoundary;
	float m_fBottomBoundary;
};

struct CCAffineTransform{
	float a;
	float b;
	float c;
	float d;
	float tx;
	float ty;
};

typedef struct _ccArray{
	unsigned int num;
	unsigned int max;
	CCObject** arr;
} ccArray;

struct CCArray{
	ccArray* data;
};

// "Currently has definition problems free free to send a pull request if you've managed to fix this" - Calloc
struct CCGLProgram{
// 	GLuint m_uProgram;
// 	GLuint m_uVertShader;
// 	GLuint m_uFragShader;
// 	GLint[kCCUniform_MAX] m_uUniforms;
// 	struct _hashUniformEntry* m_pHashForUniforms;
// 	bool m_bUsesTime;
// 	bool m_hasShaderCompiler;
};

struct CCTouch{
	int m_nId;
	bool m_startPointCaptured;
	CCPoint m_startPoint;
	CCPoint m_point;
	CCPoint m_prevPoint;
};

struct CCEvent{
};

struct CCSet{
	// std::set<CCObject*>* m_pSet;
};

struct CCScriptHandlerEntry{
	int m_nHandler;
	int m_nEntryId;
};

struct CCSchedulerScriptHandlerEntry{
	CCTimer* m_pTimer;
	bool m_bPaused;
	bool m_bMarkedForDeletion;
};

struct CCTouchScriptHandlerEntry{
	bool m_bIsMultiTouches;
	int m_nPriority;
	bool m_bSwallowsTouches;
};

struct CCScriptEngineProtocol{
};

struct CCScriptEngineManager{
	CCScriptEngineProtocol* m_pScriptEngine;
};

typedef struct _ccColor3B{
	GLubyte r;
	GLubyte g;
	GLubyte b;
} ccColor3B;

typedef struct _ccHSVValue{
	float h;
	float s;
	float v;
	GLubyte absoluteSaturation;
	GLubyte absoluteBrightness;
	unsigned char __pad[2];
} ccHSVValue;

typedef struct _ccColor4B{
	GLubyte r;
	GLubyte g;
	GLubyte b;
	GLubyte a;
} ccColor4B;

typedef struct _ccColor4F{
	GLfloat r;
	GLfloat g;
	GLfloat b;
	GLfloat a;
} ccColor4F;

typedef struct _ccVertex2F{
	GLfloat x;
	GLfloat y;
} ccVertex2F;

typedef struct _ccVertex3F{
	GLfloat x;
	GLfloat y;
	GLfloat z;
} ccVertex3F;

typedef struct _ccTex2F{
	GLfloat u;
	GLfloat v;
} ccTex2F;



typedef struct _ccPointSprite{
	ccVertex2F pos;
	ccColor4B color;
	GLfloat size;
} ccPointSprite;

typedef struct _ccQuad2{
	ccVertex2F tl;
	ccVertex2F tr;
	ccVertex2F bl;
	ccVertex2F br;
} ccQuad2;

typedef struct _ccQuad3{
	ccVertex3F bl;
	ccVertex3F br;
	ccVertex3F tl;
	ccVertex3F tr;
} ccQuad3;

typedef struct _ccV2F_C4B_T2F{
	ccVertex2F vertices;
	ccColor4B colors;
	ccTex2F texCoords;
} ccV2F_C4B_T2F;

typedef struct _ccV2F_C4F_T2F{
	ccVertex2F vertices;
	ccColor4F colors;
	ccTex2F texCoords;
} ccV2F_C4F_T2F;

typedef struct _ccV3F_C4B_T2F{
	ccVertex3F vertices;
	ccColor4B colors;
	ccTex2F texCoords;
} ccV3F_C4B_T2F;

typedef struct _ccV2F_C4B_T2F_Triangle{
	ccV2F_C4B_T2F a;
	ccV2F_C4B_T2F b;
	ccV2F_C4B_T2F c;
} ccV2F_C4B_T2F_Triangle;

typedef struct _ccV2F_C4B_T2F_Quad{
	ccV2F_C4B_T2F bl;
	ccV2F_C4B_T2F br;
	ccV2F_C4B_T2F tl;
	ccV2F_C4B_T2F tr;
} ccV2F_C4B_T2F_Quad;

typedef struct _ccV3F_C4B_T2F_Quad{
	ccV3F_C4B_T2F tl;
	ccV3F_C4B_T2F bl;
	ccV3F_C4B_T2F tr;
	ccV3F_C4B_T2F br;
} ccV3F_C4B_T2F_Quad;

typedef struct _ccV2F_C4F_T2F_Quad{
	ccV2F_C4F_T2F bl;
	ccV2F_C4F_T2F br;
	ccV2F_C4F_T2F tl;
	ccV2F_C4F_T2F tr;
} ccV2F_C4F_T2F_Quad;

typedef struct _ccBlendFunc{
	GLenum src;
	GLenum dst;
} ccBlendFunc;

typedef struct _ccT2F_Quad{
	ccTex2F bl;
	ccTex2F br;
	ccTex2F tl;
	ccTex2F tr;
} ccT2F_Quad;



typedef struct _ccFontShadow{
	bool m_shadowEnabled;
	CCSize m_shadowOffset;
	float m_shadowBlur;
	float m_shadowOpacity;
} ccFontShadow;

typedef struct _ccFontStroke {
	bool m_strokeEnabled;
	ccColor3B m_strokeColor;
	float m_strokeSize;
} ccFontStroke;

typedef struct _ccFontDefinition{
    /* 2 Fields are Currenlty Broken Needs fixing! */
	// std::string m_fontName;
	int m_fontSize;
	// CCTextAlignment m_alignment;
	CCVerticalTextAlignment m_vertAlignment;
	CCSize m_dimensions;
	ccColor3B m_fontFillColor;
	ccFontShadow m_shadow;
	ccFontStroke m_stroke;
} ccFontDefinition;

typedef struct _ccTexParams{
	GLuint minFilter;
	GLuint magFilter;
	GLuint wrapS;
	GLuint wrapT;
} ccTextParams;

struct CCTexture2D{
	bool m_bPVRHaveAlphaPremultiplied;
	CCTexture2DPixelFormat m_ePixelFormat;
	unsigned int m_uPixelsWide;
	unsigned int m_uPixelsHigh;
	GLuint m_uName;
	GLfloat m_fMaxS;
	GLfloat m_fMaxT;
	CCSize m_tContentSize;
	bool m_bHasPremultipliedAlpha;
	bool m_bHasMipmaps;
	CCGLProgram* m_pShaderProgram;
};

struct CCRGBAProtocol{
};

struct CCBlendProtocol{
};

struct CCTextureProtocol{
};

struct CCLabelProtocol{
};

struct CCDirectorDelegate{
};

struct CCNode{
	float m_fRotationX;
	float m_fRotationY;
	float m_fScaleX;
	float m_fScaleY;
	float m_fVertexZ;
	CCPoint m_obPosition;
	float m_fSkewX;
	float m_fSkewY;
	CCPoint m_obAnchorPointInPoints;
	CCPoint m_obAnchorPoint;
	CCSize m_obContentSize;
	CCAffineTransform m_sAdditionalTransform;
	CCAffineTransform m_sTransform;
	CCAffineTransform m_sInverse;
	CCCamera* m_pCamera;
	CCGridBase* m_pGrid;
	int m_nZOrder;
	CCArray* m_pChildren;
	CCNode* m_pParent;
	void* m_pUserData;
	CCObject* m_pUserObject;
	CCGLProgram* m_pShaderProgram;
	ccGLServerState m_eGLServerState;
	unsigned int m_uOrderOfArrival;
	CCScheduler* m_pScheduler;
	CCActionManager* m_pActionManager;
	bool m_bRunning;
	bool m_bTransformDirty;
	bool m_bInverseDirty;
	bool m_bAdditionalTransformDirty;
	bool m_bVisible;
	bool m_bIgnoreAnchorPointForPosition;
	bool m_bReorderChildDirty;
	int m_nScriptHandler;
	int m_nUpdateScriptHandler;
	ccScriptType m_eScriptType;
	CCComponentContainer* m_pComponentContainer;
};

struct CCNodeRGBA{
	GLubyte _displayedOpacity;
	GLubyte _realOpacity;
	ccColor3B _displayedColor;
	ccColor3B _realColor;
	bool _cascadeColorEnabled;
	bool _cascadeOpacityEnabled;
};

struct CCSpriteFrame{
	CCPoint m_obOffset;
	CCSize m_obOriginalSize;
	CCRect m_obRectInPixels;
	bool m_bRotated;
	CCRect m_obRect;
	CCPoint m_obOffsetInPixels;
	CCSize m_obOriginalSizeInPixels;
	CCTexture2D* m_pobTexture;
	// std::string m_strTextureFilename;
};

struct UT_hash_bucket{
	struct UT_hash_handle* hh_head;
	unsigned count;
	unsigned expand_mult;
};

typedef unsigned int uint32_t;
typedef long long ptrdiff_t;
typedef long long intptr_t;

struct UT_hash_table{
	UT_hash_bucket* buckets;
	unsigned num_buckets;
	unsigned log2_num_buckets;
	unsigned num_items;
	struct UT_hash_handle* tail;
	ptrdiff_t hho;
	unsigned ideal_chain_maxlen;
	unsigned nonideal_items;
	unsigned ineff_expands;
	unsigned noexpand;
	uint32_t signature;
};

struct UT_hash_handle{
	struct UT_hash_table* tbl;
	void* prev;
	void* next;
	struct UT_hash_handle* hh_prev;
	struct UT_hash_handle* hh_next;
	void* key;
	unsigned keylen;
	unsigned hashv;
};

struct CCString{
    /* C++ Strings are currently broken in ghidra */
	// std::string m_sString;
};

struct CCDictElement{
	char m_szKey [256];
	intptr_t m_iKey;
	CCObject* m_pObject;
	UT_hash_handle hh;
};

struct CCDictionary{
	CCDictElement* m_pElements;
	CCDictType m_eDictType;
};

struct CCAnimationFrame{
	CCSpriteFrame* m_pSpriteFrame;
	float m_fDelayUnits;
	CCDictionary* m_pUserInfo;
};

struct CCAnimation{
	float m_fTotalDelayUnits;
	float m_fDelayPerUnit;
	float m_fDuration;
	CCArray* m_pFrames;
	bool m_bRestoreOriginalFrame;
	unsigned int m_uLoops;
};

struct CCActionInterval{
	float m_elapsed;
	bool m_bFirstTick;
};

struct CCSequence{
	CCFiniteTimeAction* m_pActions[2];
	float m_split;
	int m_last;
};

struct CCRepeat{
	unsigned int m_uTimes;
	unsigned int m_uTotal;
	float m_fNextDt;
	bool m_bActionInstant;
	CCFiniteTimeAction* m_pInnerAction;
};

struct CCRepeatForever{
	CCActionInterval* m_pInnerAction;
};

struct CCSpawn{
	CCFiniteTimeAction* m_pOne;
	CCFiniteTimeAction* m_pTwo;
};

struct CCRotateTo{
	float m_fDstAngleX;
	float m_fStartAngleX;
	float m_fDiffAngleX;
	float m_fDstAngleY;
	float m_fStartAngleY;
	float m_fDiffAngleY;
};

struct CCRotateBy{
	float m_fAngleX;
	float m_fStartAngleX;
	float m_fAngleY;
	float m_fStartAngleY;
};

struct CCMoveBy{
	CCPoint m_positionDelta;
	CCPoint m_startPosition;
	CCPoint m_previousPosition;
};

struct CCMoveTo{
	CCPoint m_endPosition;
};

struct CCSkewTo{
	float m_fSkewX;
	float m_fSkewY;
	float m_fStartSkewX;
	float m_fStartSkewY;
	float m_fEndSkewX;
	float m_fEndSkewY;
	float m_fDeltaX;
	float m_fDeltaY;
};

struct CCSkewBy{
};

struct CCJumpBy{
	CCPoint m_startPosition;
	CCPoint m_delta;
	float m_height;
	unsigned int m_nJumps;
	CCPoint m_previousPos;
};

struct CCJumpTo{
};

struct _ccBezierConfig{
	CCPoint endPosition;
	CCPoint controlPoint_1;
	CCPoint controlPoint_2;
};

struct CCBezierBy{
	// ccBezierConfig m_sConfig;
	CCPoint m_startPosition;
	CCPoint m_previousPosition;
};

struct CCBezierTo{
	// ccBezierConfig m_sToConfig;
};

struct CCScaleTo{
	float m_fScaleX;
	float m_fScaleY;
	float m_fStartScaleX;
	float m_fStartScaleY;
	float m_fEndScaleX;
	float m_fEndScaleY;
	float m_fDeltaX;
	float m_fDeltaY;
};

struct CCScaleBy{
};

struct CCBlink{
	unsigned int m_nTimes;
	bool m_bOriginalState;
};

struct CCFadeIn{
};

struct CCFadeOut{
};

struct CCFadeTo{
	GLubyte m_toOpacity;
	GLubyte m_fromOpacity;
};

struct CCTintTo{
	ccColor3B m_to;
	ccColor3B m_from;
};

struct CCTintBy{
	GLshort m_deltaR;
	GLshort m_deltaG;
	GLshort m_deltaB;
	GLshort m_fromR;
	GLshort m_fromG;
	GLshort m_fromB;
};

struct CCDelayTime{
};

struct CCReverseTime{
	CCFiniteTimeAction* m_pOther;
};

struct CCAnimate{
	CCAnimation* m_pAnimation;
	// std::vector<float>* m_pSplitTimes; vectors are broken as far as I am aware...
	int m_nNextFrame;
	CCSpriteFrame* m_pOrigFrame;
	unsigned int m_uExecutedLoops;
};

struct CCTargetedAction{
	CCNode* m_pForcedTarget;
	CCFiniteTimeAction* m_pAction;
};

struct CCActionCamera{
	float m_fCenterXOrig;
	float m_fCenterYOrig;
	float m_fCenterZOrig;
	float m_fEyeXOrig;
	float m_fEyeYOrig;
	float m_fEyeZOrig;
	float m_fUpXOrig;
	float m_fUpYOrig;
	float m_fUpZOrig;
};

struct CCOrbitCamera{
	float m_fRadius;
	float m_fDeltaRadius;
	float m_fAngleZ;
	float m_fDeltaAngleZ;
	float m_fAngleX;
	float m_fDeltaAngleX;
	float m_fRadZ;
	float m_fRadDeltaZ;
	float m_fRadX;
	float m_fRadDeltaX;
};

struct CCActionManager{
	struct _hashElement* m_pTargets;
	struct _hashElement* m_pCurrentTarget;
	bool m_bCurrentTargetSalvaged;
};

struct CCActionEase{
	CCActionInterval* m_pInner;
};

struct CCEaseRateAction{
	float m_fRate;
};

struct CCEaseIn{
};

struct CCEaseOut{
};

struct CCEaseInOut{
};

struct CCEaseExponentialIn{
};

struct CCEaseExponentialOut{
};

struct CCEaseExponentialInOut{
};

struct CCEaseSineIn{
};

struct CCEaseSineOut{
};

struct CCEaseSineInOut{
};

struct CCEaseElastic{
	float m_fPeriod;
};

struct CCEaseElasticIn{
};

struct CCEaseElasticOut{
};

struct CCEaseElasticInOut{
};

struct CCEaseBounce{
};

struct CCEaseBounceIn{
};

struct CCEaseBounceOut{
};

struct CCEaseBounceInOut{
};

struct CCEaseBackIn{
};

struct CCEaseBackOut{
};

struct CCEaseBackInOut{
};

struct TypeInfo{
};

struct CCActionInstant{
};

struct CCShow{
};

struct CCHide{
};

struct CCToggleVisibility{
};

struct CCRemoveSelf{
	bool m_bIsNeedCleanUp;
};

struct CCFlipX{
	bool m_bFlipX;
};

struct CCFlipY{
	bool m_bFlipY;
};

struct CCPlace{
	CCPoint m_tPosition;
};

struct CCCallFunc{
	CCObject* m_pSelectorTarget;
	int m_nScriptHandler;
	// SEL_CallFunc m_pCallFunc;
	// SEL_CallFuncN m_pCallFuncN;
	// SEL_CallFuncND m_pCallFuncND;
	// SEL_CallFuncO m_pCallFuncO;
};

struct CCCallFuncN{
};

struct CCCallFuncND{
	void* m_pData;
};

struct CCCallFuncO{
	CCObject* m_pObject;
};

struct CCGridAction{
	CCSize m_sGridSize;
};

struct CCGrid3DAction{
};

struct CCTiledGrid3DAction{
};

struct CCAccelDeccelAmplitude{
	float m_fRate;
	CCActionInterval* m_pOther;
};

struct CCAccelAmplitude{
	float m_fRate;
	CCActionInterval* m_pOther;
};

struct CCDeccelAmplitude{
	float m_fRate;
	CCActionInterval* m_pOther;
};

struct CCStopGrid{
};

struct CCReuseGrid{
	int m_nTimes;
};

struct CCWaves3D{
	unsigned int m_nWaves;
	float m_fAmplitude;
	float m_fAmplitudeRate;
};

struct CCFlipX3D{
};

struct CCFlipY3D{
};

struct CCLens3D{
	CCPoint m_position;
	float m_fRadius;
	float m_fLensEffect;
	bool m_bConcave;
	bool m_bDirty;
};

struct CCRipple3D{
	CCPoint m_position;
	float m_fRadius;
	unsigned int m_nWaves;
	float m_fAmplitude;
	float m_fAmplitudeRate;
};

struct CCShaky3D{
	int m_nRandrange;
	bool m_bShakeZ;
};

struct CCLiquid{
	unsigned int m_nWaves;
	float m_fAmplitude;
	float m_fAmplitudeRate;
};

struct CCWaves{
	unsigned int m_nWaves;
	float m_fAmplitude;
	float m_fAmplitudeRate;
	bool m_bVertical;
	bool m_bHorizontal;
};

struct CCTwirl{
	CCPoint m_position;
	unsigned int m_nTwirls;
	float m_fAmplitude;
	float m_fAmplitudeRate;
};

struct CCPageTurn3D{
};

struct CCProgressTo{
	float m_fTo;
	float m_fFrom;
};

struct CCProgressFromTo{
	float m_fTo;
	float m_fFrom;
};

struct CCShakyTiles3D{
	int m_nRandrange;
	bool m_bShakeZ;
};

struct CCShatteredTiles3D{
	int m_nRandrange;
	bool m_bOnce;
	bool m_bShatterZ;
};

struct CCShuffleTiles{
	unsigned int m_nSeed;
	unsigned int m_nTilesCount;
	unsigned int* m_pTilesOrder;
	// Tile* m_pTiles;
};

struct CCFadeOutTRTiles{
};

struct CCFadeOutBLTiles{
};

struct CCFadeOutUpTiles{
};

struct CCFadeOutDownTiles{
};

struct CCTurnOffTiles{
	unsigned int m_nSeed;
	unsigned int m_nTilesCount;
	unsigned int* m_pTilesOrder;
};

struct CCWavesTiles3D{
	unsigned int m_nWaves;
	float m_fAmplitude;
	float m_fAmplitudeRate;
};

struct CCJumpTiles3D{
	unsigned int m_nJumps;
	float m_fAmplitude;
	float m_fAmplitudeRate;
};

struct CCSplitRows{
	unsigned int m_nRows;
	CCSize m_winSize;
};

struct CCSplitCols{
	unsigned int m_nCols;
	CCSize m_winSize;
};

struct CCActionTweenDelegate{
};

struct CCActionTween{
	// std::string m_strKey;
	float m_fFrom;
	float m_fTo;
	float m_fDelta;
};

struct CCPointArray{
	// std::vector<CCPoint*>* m_pControlPoints;
};

struct CCCardinalSplineTo{
	CCPointArray* m_pPoints;
	float m_fDeltaT;
	float m_fTension;
	CCPoint m_previousPosition;
	CCPoint m_accumulatedDiff;
};

struct CCCardinalSplineBy{
	CCPoint m_startPosition;
};

struct CCCatmullRomTo{
};

struct CCCatmullRomBy{
};

struct CCAtlasNode{
	unsigned int m_uItemsPerRow;
	unsigned int m_uItemsPerColumn;
	unsigned int m_uItemWidth;
	unsigned int m_uItemHeight;
	ccColor3B m_tColorUnmodified;
	CCTextureAtlas* m_pTextureAtlas;
	bool m_bIsOpacityModifyRGB;
	ccBlendFunc m_tBlendFunc;
	unsigned int m_uQuadsToDraw;
	GLint m_nUniformColor;
	bool m_bIgnoreContentScaleFactor;
};

struct CCAutoreleasePool{
	CCArray* m_pManagedObjectArray;
};

struct CCPoolManager{
	CCArray* m_pReleasePoolStack;
	CCAutoreleasePool* m_pCurReleasePool;
};

struct CCInteger{
	int m_nValue;
};

struct CCFloat{
	float m_fValue;
};

struct CCDouble{
	double m_dValue;
};

struct CCBool{
	bool m_bValue;
};

struct CCZone{
	CCObject* m_pCopyObject;
};

struct CCDrawNode{
	GLuint m_uVao;
	GLuint m_uVbo;
	unsigned int m_uBufferCapacity;
	GLsizei m_nBufferCount;
	ccV2F_C4B_T2F* m_pBuffer;
	ccBlendFunc m_sBlendFunc;
	bool m_bDirty;
};

struct CCConfiguration{
	CCConfiguration* s_gSharedConfiguration;
	// std::string s_sConfigfile;
	GLint m_nMaxTextureSize;
	GLint m_nMaxModelviewStackDepth;
	bool m_bSupportsPVRTC;
	bool m_bSupportsNPOT;
	bool m_bSupportsBGRA8888;
	bool m_bSupportsDiscardFramebuffer;
	bool m_bSupportsShareableVAO;
	GLint m_nMaxSamplesAllowed;
	GLint m_nMaxTextureUnits;
	char* m_pGlExtensions;
	CCDictionary* m_pValueDict;
};

struct CCGrabber{
	GLuint m_FBO;
	GLint m_oldFBO;
	GLfloat m_oldClearColor[4];
};

struct CCCamera{
	float m_fEyeX;
	float m_fEyeY;
	float m_fEyeZ;
	float m_fCenterX;
	float m_fCenterY;
	float m_fCenterZ;
	float m_fUpX;
	float m_fUpY;
	float m_fUpZ;
	bool m_bDirty;
	kmMat4 m_lookupMatrix;
};

struct CCLabelAtlas{
	// std::string m_sString;
	unsigned int m_uMapStartChar;
};

struct CCDirector{
	float m_fScreenScaleFactor;
	float m_fScreenScaleFactorMax;
	float m_fScreenScaleFactorW;
	float m_fScreenScaleFactorH;
	float m_fScreenTop;
	float m_fScreenBottom;
	float m_fScreenLeft;
	float m_fScreenRight;
	CCScene* m_pSceneReference;
	CCScheduler* m_pScheduler;
	CCActionManager* m_pActionManager;
	CCTouchDispatcher* m_pTouchDispatcher;
	CCKeypadDispatcher* m_pKeypadDispatcher;
	CCKeyboardDispatcher* m_pKeyboardDispatcher;
	CCMouseDispatcher* m_pMouseDispatcher;
	CCAccelerometer* m_pAccelerometer;
	float m_fDeltaTime;
	float m_fActualDeltaTime;
	bool m_bIsTransitioning;
	bool m_bSmoothFix;
	bool m_bSmoothFixCheck;
	bool m_bForceSmoothFix;
	int m_nSmoothFixCounter;
	bool m_bPurgeDirecotorInNextLoop;
	CCEGLView* m_pobOpenGLView;
	char pad463[0x4];
	double m_dAnimationInterval;
	double m_dOldAnimationInterval;
	bool m_bLandscape;
	bool m_bDisplayStats;
	float m_fAccumDt;
	float m_fFrameRate;
	CCLabelAtlas* m_pFPSLabel;
	CCLabelAtlas* m_pSPFLabel;
	CCLabelAtlas* m_pDrawsLabel;
	bool m_bPaused;
	unsigned int m_uTotalFrames;
	unsigned int m_uFrames;
	float m_fSecondsPerFrame;
	CCScene* m_pRunningScene;
	CCScene* m_pNextScene;
	bool m_bSendCleanupToScene;
	CCArray* m_pobScenesStack;
	struct cc_timeval* m_pLastUpdate;
	bool m_bNextDeltaTimeZero;
	ccDirectorProjection m_eProjection;
	CCSize m_obWinSizeInPoints;
	float m_fContentScaleFactor;
	char* m_pszFPS;
	CCNode* m_pNotificationNode;
	CCDirectorDelegate* m_pProjectionDelegate;
	// CCSceneDelegate* m_pAppDelegate; I Forgot CCSeneDelegate As of Currently will need fixing later....
	CCSize m_obScaleFactor;
	CCSize m_obResolutionInPixels;
	TextureQuality m_eTextureQuality;
	bool m_bDontCallWillSwitch;
};

struct CCDisplayLinkDirector{
	bool m_bInvalid;
};

struct CCGridBase{
	bool m_bActive;
	int m_nReuseGrid;
	CCSize m_sGridSize;
	CCTexture2D* m_pTexture;
	CCPoint m_obStep;
	CCGrabber* m_pGrabber;
	bool m_bIsTextureFlipped;
	CCGLProgram* m_pShaderProgram;
	ccDirectorProjection m_directorProjection;
};

struct CCGrid3D{
	GLvoid* m_pTexCoordinates;
	GLvoid* m_pVertices;
	GLvoid* m_pOriginalVertices;
	GLushort* m_pIndices;
};

struct CCTiledGrid3D{
	GLvoid* m_pTexCoordinates;
	GLvoid* m_pVertices;
	GLvoid* m_pOriginalVertices;
	GLushort* m_pIndices;
};

struct kmVec2{
	float x;
	float y;
};

struct kmVec3{
	float x;
	float y;
	float z;
};

struct kmMat3{
	float mat[9];
};

struct kmMat4{
	float mat[16];
};

struct kmQuaternion{
	float x;
	float y;
	float z;
	float w;
};

struct kmPlane{
	float a;
	float b;
	float c;
	float d;
};

struct kmAABB{
	kmVec3 min;
	kmVec3 max;
};

struct kmRay2{
	kmVec2 start;
	kmVec2 dir;
};

struct CCKeypadDelegate{
};

struct CCKeypadHandler{
	CCKeypadDelegate* m_pDelegate;
};

struct CCKeypadDispatcher{
	CCArray* m_pDelegates;
	bool m_bLocked;
	bool m_bToAdd;
	bool m_bToRemove;
	struct _ccCArray* m_pHandlersToAdd;
	struct _ccCArray* m_pHandlersToRemove;
};

struct CCTextureAtlas{
	GLushort* m_pIndices;
	GLuint m_pBuffersVBO[2] ;
	bool m_bDirty;
	unsigned int m_uTotalQuads;
	unsigned int m_uCapacity;
	CCTexture2D* m_pTexture;
	ccV3F_C4B_T2F_Quad* m_pQuads;
};

struct CCSprite{
	CCTextureAtlas* m_pobTextureAtlas;
	unsigned int m_uAtlasIndex;
	CCSpriteBatchNode* m_pobBatchNode;
	bool m_bDirty;
	bool m_bRecursiveDirty;
	bool m_bHasChildren;
	bool m_bShouldBeHidden;
	CCAffineTransform m_transformToBatch;
	ccBlendFunc m_sBlendFunc;
	CCTexture2D* m_pobTexture;
	CCRect m_obRect;
	bool m_bRectRotated;
	CCPoint m_obOffsetPosition;
	CCPoint m_obUnflippedOffsetPositionFromCenter;
	ccV3F_C4B_T2F_Quad m_sQuad;
	bool m_bOpacityModifyRGB;
	bool m_bFlipX;
	bool m_bFlipY;
	bool m_bDontDraw;
	float m_fTlVertexMod;
	float m_fTrVertexMod;
	float m_fBlVertexMod;
	float m_fBrVertexMod;
	char pad561[16];
	bool m_bUnknown;
	int m_nUnknown;
};

struct CCLabelTTF{
	CCSize m_tDimensions;
	// CCTextAlignment m_hAlignment;
	CCVerticalTextAlignment m_vAlignment;
	// std::string* m_pFontName;
	float m_fFontSize;
	// std::string m_string;
	bool m_shadowEnabled;
	CCSize m_shadowOffset;
	float m_shadowOpacity;
	float m_shadowBlur;
	bool m_strokeEnabled;
	ccColor3B m_strokeColor;
	float m_strokeSize;
	ccColor3B m_textFillColor;
};

struct CCSpriteBatchNode{
	CCTextureAtlas* m_pobTextureAtlas;
	ccBlendFunc m_blendFunc;
	CCArray* m_pobDescendants;
	bool m_bManualSortChildren;
	bool m_bManualSortAllChildrenDirty;
};

typedef struct _BMFontDef{
	unsigned int charID;
	CCRect rect;
	short xOffset;
	short yOffset;
	short xAdvance;
} BMFontDef;

typedef struct _BMFontPadding{
	int left;
	int top;
	int right;
	int bottom;
} BMFontPadding;

typedef struct _FontDefHashElement{
	unsigned int key;
	// ccBMFontDef fontDef;
	UT_hash_handle hh;
} FontDefHashElement;

struct _KerningHashElement{
	int key;
	int amount;
	UT_hash_handle hh;
};

/* CURRENTLY BROKEN */
struct CCBMFontConfiguration{
	// tCCFontDefHashElement* m_pFontDefDictionary;
	int m_nCommonHeight;
	// ccBMFontPadding m_tPadding;
	// std::string m_sAtlasName;
	// tCCKerningHashElement* m_pKerningDictionary;
	// std::set<unsigned int>* m_pCharacterSet;
};

struct CCLabelBMFont{
	unsigned short* m_sString;
	// std::string m_sFntFile;
	unsigned short* m_sInitialString;
	// std::string m_sInitialStringUTF8;
	// CCTextAlignment m_pAlignment;
	float m_fWidth;
	CCBMFontConfiguration* m_pConfiguration;
	bool m_bLineBreakWithoutSpaces;
	CCPoint m_tImageOffset;
	CCSprite* m_pReusedChar;
	GLubyte m_cDisplayedOpacity;
	GLubyte m_cRealOpacity;
	ccColor3B m_tDisplayedColor;
	ccColor3B m_tRealColor;
	bool m_bCascadeColorEnabled;
	bool m_bCascadeOpacityEnabled;
	bool m_bIsOpacityModifyRGB;
	bool m_bIsBatched;
	CCArray* m_pTargetArray;
	CCTexture2D* m_pSomeTexture;
};

struct CCTouchDelegate{
};

struct CCTargetedTouchDelegate{
};

struct CCStandardTouchDelegate{
};

struct CCAcceleration{
	double x;
	double y;
	double z;
	double timestamp;
};

struct CCAccelerometerDelegate{
};

struct CCKeyboardDelegate{
};

struct CCKeyboardHandler{
	CCKeyboardDelegate* m_pDelegate;
};

struct CCMouseDelegate{
};

struct CCMouseHandler{
	CCMouseDelegate* m_pDelegate;
};

struct CCLayer{
	bool m_bTouchEnabled;
	bool m_bAccelerometerEnabled;
	bool m_bKeypadEnabled;
	bool m_bKeyboardEnabled;
	bool m_bMouseEnabled;
	CCTouchScriptHandlerEntry* m_pScriptTouchHandlerEntry;
	CCScriptHandlerEntry* m_pScriptKeypadHandlerEntry;
	CCScriptHandlerEntry* m_pScriptAccelerateHandlerEntry;
	int m_nTouchPriority;
	ccTouchesMode m_eTouchMode;
};

struct CCLayerRGBA{
	GLubyte _displayedOpacity;
	GLubyte _realOpacity;
	ccColor3B _displayedColor;
	ccColor3B _realColor;
	bool _cascadeOpacityEnabled;
	bool _cascadeColorEnabled;
};

struct CCLayerColor{
	ccVertex2F m_pSquareVertices[4];
	ccColor4F m_pSquareColors[4];
	ccBlendFunc m_tBlendFunc;
};

struct CCLayerGradient{
	ccColor3B m_startColor;
	ccColor3B m_endColor;
	GLubyte m_cStartOpacity;
	GLubyte m_cEndOpacity;
	CCPoint m_AlongVector;
	bool m_bCompressedInterpolation;
};

struct CCLayerMultiplex{
	unsigned int m_nEnabledLayer;
	CCArray* m_pLayers;
};

struct CCScene{
	void* m_pIDK;
};

struct CCTransitionEaseScene{
};

struct CCTransitionScene{
	CCScene* m_pInScene;
	CCScene* m_pOutScene;
	float m_fDuration;
	bool m_bIsInSceneOnTop;
	bool m_bIsSendCleanupToScene;
};

struct CCTransitionSceneOriented{
	tOrientation m_eOrientation;
};

struct CCTransitionRotoZoom{
};

struct CCTransitionJumpZoom{
};

struct CCTransitionMoveInL{
};

struct CCTransitionMoveInR{
};

struct CCTransitionMoveInT{
};

struct CCTransitionMoveInB{
};

struct CCTransitionSlideInL{
};

struct CCTransitionSlideInR{
};

struct CCTransitionSlideInB{
};

struct CCTransitionSlideInT{
};

struct CCTransitionShrinkGrow{
};

struct CCTransitionFlipX{
};

struct CCTransitionFlipY{
};

struct CCTransitionFlipAngular{
};

struct CCTransitionZoomFlipX{
};

struct CCTransitionZoomFlipY{
};

struct CCTransitionZoomFlipAngular{
};

struct CCTransitionFade{
	ccColor4B m_tColor;
};

struct CCTransitionCrossFade{
};

struct CCTransitionTurnOffTiles{
};

struct CCTransitionSplitCols{
};

struct CCTransitionSplitRows{
};

struct CCTransitionFadeTR{
};

struct CCTransitionFadeBL{
};

struct CCTransitionFadeUp{
};

struct CCTransitionFadeDown{
};

struct CCTransitionPageTurn{
	bool m_bBack;
};

struct CCTransitionProgress{
	float m_fTo;
	float m_fFrom;
	CCScene* m_pSceneToBeModified;
};

struct CCTransitionProgressRadialCCW{
};

struct CCTransitionProgressRadialCW{
};

struct CCTransitionProgressHorizontal{
};

struct CCTransitionProgressVertical{
};

struct CCTransitionProgressInOut{
};

struct CCTransitionProgressOutIn{
};

struct CCMenuItem{
	bool m_bSelected;
	bool m_bEnabled;
	CCObject* m_pListener;
	SEL_MenuHandler m_pfnSelector;
	int m_nScriptTapHandler;
};

struct CCMenuItemLabel{
	ccColor3B m_tDisabledColor;
	CCNode* m_pLabel;
	ccColor3B m_tColorBackup;
	float m_fOriginalScale;
};

struct CCMenuItemAtlasFont{
};

struct CCMenuItemFont{
	unsigned int m_uFontSize;
	// std::string m_strFontName;
};

struct CCMenuItemSprite{
	CCNode* m_pNormalImage;
	CCNode* m_pSelectedImage;
	CCNode* m_pDisabledImage;
};

struct CCMenuItemImage{
};

struct CCMenuItemToggle{
	unsigned int m_uSelectedIndex;
	CCArray* m_pSubItems;
};

struct CCMenu{
	bool m_bEnabled;
	tCCMenuState m_eState;
	CCMenuItem* m_pSelectedItem;
};

struct CCClippingNode{
	CCNode* m_pStencil;
	GLfloat m_fAlphaThreshold;
	bool m_bInverted;
};

struct CCMotionStreak{
	bool m_bFastMode;
	bool m_bStartingPositionInitialized;
	CCTexture2D* m_pTexture;
	ccBlendFunc m_tBlendFunc;
	CCPoint m_tPositionR;
	float m_fStroke;
	float m_fFadeDelta;
	float m_fMinSeg;
	unsigned int m_uMaxPoints;
	unsigned int m_uNuPoints;
	unsigned int m_uPreviousNuPoints;
	CCPoint* m_pPointVertexes;
	float* m_pPointState;
	ccVertex2F* m_pVertices;
	GLubyte* m_pColorPointer;
	ccTex2F* m_pTexCoords;
};

struct CCProgressTimer{
	CCProgressTimerType m_eType;
	float m_fPercentage;
	CCSprite* m_pSprite;
	int m_nVertexDataCount;
	ccV2F_C4B_T2F* m_pVertexData;
	CCPoint m_tMidpoint;
	CCPoint m_tBarChangeRate;
	bool m_bReverseDirection;
};

struct CCRenderTexture{
	CCSprite* m_pSprite;
	GLuint m_uFBO;
	GLuint m_uDepthRenderBufffer;
	GLint m_nOldFBO;
	CCTexture2D* m_pTexture;
	CCTexture2D* m_pTextureCopy;
	CCImage* m_pUITextureImage;
	GLenum m_ePixelFormat;
	GLbitfield m_uClearFlags;
	ccColor4F m_sClearColor;
	GLclampf m_fClearDepth;
	GLint m_nClearStencil;
	bool m_bAutoDraw;
};

struct CCDevice{
};

struct CCFileUtils{
	CCDictionary* m_pFilenameLookupDict;
	// std::vector<std::string> m_searchResolutionsOrderArray;
	// std::vector<std::string> m_searchPathArray;
	// std::string m_strDefaultResRootPath;
	// std::map<std::string, std::string> m_fullPathCache;
	CCFileUtils* s_sharedFileUtils;
};

struct CCImage{
	unsigned short m_nWidth;
	unsigned short m_nHeight;
	int m_nBitsPerComponent;
	unsigned char* m_pData;
	bool m_bHasAlpha;
	bool m_bPreMulti;
};

struct CCThread{
	void* m_pAutoreasePool;
};

struct cc_timeval{
	long tv_sec;
	int tv_usec;
};

struct CCTime{
};

struct CCAccelerometer{
	CCAcceleration m_obAccelerationValue;
	CCAccelerometerDelegate* m_pAccelDelegate;
};

struct timezone{
	int tz_minuteswest;
	int tz_dsttime;
};

struct CCApplicationProtocol{
};

struct CCApplication{
	// HINSTANCE m_hInstance;
	// HACCEL m_hAccelTable;
	// LARGE_INTEGER m_nAnimationInterval;
	// std::string m_resourceRootPath;
	// std::string m_startupScriptFilename;
	CCApplication* sm_pSharedApplication;
};

struct CCEGLViewProtocol{
	EGLTouchDelegate* m_pDelegate;
	CCSize m_obScreenSize;
	CCSize m_obDesignResolutionSize;
	CCRect m_obViewPortRect;
	char m_szViewName[50];
	float m_fScaleX;
	float m_fScaleY;
	ResolutionPolicy m_eResolutionPolicy;
};

struct GLFWvidmode{
	int width;
	int height;
	int redBits;
	int greenBits;
	int blueBits;
	int refreshRate;
};

struct GLFWgammaramp{
	unsigned short* red;
	unsigned short* green;
	unsigned short* blue;
	unsigned int size;
};

struct CCEGLView{
	CCEGLView* s_pEglView;
	bool m_bCaptured;
	bool m_bSupportTouch;
	bool m_bInRetinaMonitor;
	bool m_bRetinaEnabled;
	int m_nRetinaFactor;
	bool m_bCursorHidden;
	float m_fFrameZoomFactor;
	// GLFWwindow* m_pMainWindow;
	// GLFWmonitor* m_pPrimaryMonitor;
	CCSize m_obWindowedSize;
	float m_fMouseX;
	float m_fMouseY;
	bool m_bIsFullscreen;
	bool m_bShouldHideCursor;
	bool m_bShouldCallGLFinish;
};

struct CCShaderCache{
	CCDictionary* m_pPrograms;
};

struct CCAnimationCache{
	CCDictionary* m_pAnimations;
	CCAnimationCache* s_pSharedAnimationCache;
};

struct CCSpriteFrameCache{
	CCDictionary* m_pSpriteFrames;
	CCDictionary* m_pSpriteFramesAliases;
	// std::set<std::string>* m_pLoadedFileNames;
};

struct CCNotificationCenter{
	CCArray* m_observers;
	int m_scriptHandler;
};

struct CCNotificationObserver{
	CCObject* m_target;
	// SEL_CallFuncO m_selector;
	char* m_name;
	CCObject* m_object;
	int m_nHandler;
};

struct CCProfiler{
	CCDictionary* m_pActiveTimers;
};

struct CCProfilingTimer{
	// std::string m_NameStr;
	int numberOfCalls;
	int m_dAverageTime1;
	int m_dAverageTime2;
	long long totalTime;
	int minTime;
	int maxTime;
	struct cc_timeval m_sStartTime;
};

struct CCUserDefault{
	CCUserDefault* m_spUserDefault;
	// std::string m_sFilePath;
	bool m_sbIsFilePathInitialized;
};



struct CCIMEDelegate{
};

struct CCIMEDispatcher{
	// Impl* m_pImpl;
};

struct CCTextFieldDelegate{
};

struct CCTextFieldTTF{
	CCTextFieldDelegate* m_pDelegate;
	int m_nCharCount;
	// std::string* m_pInputText;
	// std::string* m_pPlaceHolder;
	ccColor3B m_ColorSpaceHolder;
	bool m_bSecureTextEntry;
	// LengthStack* m_pLens;
};

struct CCTextureCache{
	CCDictionary* m_pTextures;
};

struct CCPVRMipmap{
	unsigned char* address;
	unsigned int len;
};

struct _ccPVRTexturePixelFormatInfo{
	GLenum internalFormat;
	GLenum format;
	GLenum type;
	uint32_t bpp;
	bool compressed;
	bool alpha;
	CCTexture2DPixelFormat ccPixelFormat;
};

struct CCTexturePVR{
	// struct CCPVRMipmap[CC_PVRMIPMAP_MAX] m_asMipmaps;
	unsigned int m_uNumberOfMipmaps;
	unsigned int m_uWidth;
	unsigned int m_uHeight;
	GLuint m_uName;
	bool m_bHasAlpha;
	bool m_bHasPremultipliedAlpha;
	bool m_bForcePremultipliedAlpha;
	bool m_bRetainName;
	CCTexture2DPixelFormat m_eFormat;
	// const ccPVRTexturePixelFormatInfo* m_pPixelFormatInfo;
};

struct CCParallaxNode{
	struct _ccArray* m_pParallaxArray;
	CCPoint m_tLastPosition;
};

struct CCTMXObjectGroup{
	CCPoint m_tPositionOffset;
	CCDictionary* m_pProperties;
	CCArray* m_pObjects;
	// std::string m_sGroupName;
};

struct CCTMXLayerInfo{
	CCDictionary* m_pProperties;
	// std::string m_sName;
	CCSize m_tLayerSize;
	unsigned int* m_pTiles;
	bool m_bVisible;
	unsigned char m_cOpacity;
	bool m_bOwnTiles;
	unsigned int m_uMinGID;
	unsigned int m_uMaxGID;
	CCPoint m_tOffset;
};

struct CCTMXTilesetInfo{
	// std::string m_sName;
	unsigned int m_uFirstGid;
	CCSize m_tTileSize;
	unsigned int m_uSpacing;
	unsigned int m_uMargin;
	// std::string m_sSourceImage;
	CCSize m_tImageSize;
};

struct CCTMXMapInfo{
	int m_nOrientation;
	CCSize m_tMapSize;
	CCSize m_tTileSize;
	CCArray* m_pLayers;
	CCArray* m_pTilesets;
	CCArray* m_pObjectGroups;
	int m_nParentElement;
	unsigned int m_uParentGID;
	int m_nLayerAttribs;
	bool m_bStoringCharacters;
	CCDictionary* m_pProperties;
	// std::string m_sTMXFileName;
	// std::string m_sResources;
	// std::string m_sCurrentString;
	CCDictionary* m_pTileProperties;
	unsigned int m_uCurrentFirstGID;
};

struct CCTMXLayer{
	CCSize m_tLayerSize;
	CCSize m_tMapTileSize;
	unsigned int* m_pTiles;
	CCTMXTilesetInfo* m_pTileSet;
	unsigned int m_uLayerOrientation;
	CCDictionary* m_pProperties;
	// std::string m_sLayerName;
	unsigned char m_cOpacity;
	unsigned int m_uMinGID;
	unsigned int m_uMaxGID;
	int m_nVertexZvalue;
	bool m_bUseAutomaticVertexZ;
	CCSprite* m_pReusedTile;
	// _ccCArray* m_pAtlasIndexArray;
	float m_fContentScaleFactor;
};

struct CCTMXTiledMap{
	CCSize m_tMapSize;
	CCSize m_tTileSize;
	int m_nMapOrientation;
	CCArray* m_pObjectGroups;
	CCDictionary* m_pProperties;
	CCDictionary* m_pTileProperties;
};

struct CCTileMapAtlas{
	struct sImageTGA* m_pTGAInfo;
	CCDictionary* m_pPosToAtlasIndex;
	int m_nItemsToRender;
};

struct ccTouchHandlerHelperData{
	int m_type;
};

struct EGLTouchDelegate{
};

struct CCTouchDispatcher{
	CCArray* m_pTargetedHandlers;
	CCArray* m_pStandardHandlers;
	bool m_bLocked;
	bool m_bToAdd;
	bool m_bToRemove;
	CCArray* m_pHandlersToAdd;
	struct _ccCArray* m_pHandlersToRemove;
	bool m_bToQuit;
	bool m_bDispatchEvents;
	// struct ccTouchHandlerHelperData[ccTouchMax] m_sHandlerHelperData;
	bool m_bForcePrio;
	int m_nTargetPrio;
};

struct CCTouchHandler{
	CCTouchDelegate* m_pDelegate;
	int m_nPriority;
	int m_nEnabledSelectors;
};

struct CCStandardTouchHandler{
};

struct CCTargetedTouchHandler{
	bool m_bSwallowsTouches;
	CCSet* m_pClaimedTouches;
};

struct CCTimer{
	CCObject* m_pTarget;
	float m_fElapsed;
	bool m_bRunForever;
	bool m_bUseDelay;
	unsigned int m_uTimesExecuted;
	unsigned int m_uRepeat;
	float m_fDelay;
	float m_fInterval;
	// SEL_SCHEDULE m_pfnSelector;
	int m_nScriptHandler;
};

struct CCScheduler{
	float m_fTimeScale;
	struct _listEntry* m_pUpdatesNegList;
	struct _listEntry* m_pUpdates0List;
	struct _listEntry* m_pUpdatesPosList;
	struct _hashUpdateEntry* m_pHashForUpdates;
	struct _hashSelectorEntry* m_pHashForTimers;
	struct _hashSelectorEntry* m_pCurrentTarget;
	bool m_bCurrentTargetSalvaged;
	bool m_bUpdateHashLocked;
	CCArray* m_pScriptHandlerEntries;
};

struct CCComponent{
	CCNode* m_pOwner;
	// std::string m_strName;
	bool m_bEnabled;
};

struct CCComponentContainer{
	CCDictionary* m_pComponents;
	CCNode* m_pOwner;
};

struct CCKeyboardDispatcher{
	CCArray* m_pDelegates;
	bool m_bUnknown24;
	bool m_bUnknown25;
	char pad7[2];
	_ccCArray* m_pUnknown28;
	_ccCArray* m_pUnknown2c;
	bool m_bShiftPressed;
	bool m_bControlPressed;
	bool m_bAltPressed;
	bool m_bCommandPressed;
};

struct CCMouseDispatcher{
	CCArray* m_pDelegates;
};

struct CCSceneTransitionDelegate{
};

struct DS_Dictionary{
	bool compatible;
};



