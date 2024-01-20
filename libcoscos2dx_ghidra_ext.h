/* This file is mostly used as a viewing reference incase something is missing or a function definition needs correcting However this file is becoming obsoltete thanks to the geode-sdk bindings... */



struct CCDataVisitor{
};

void CCDataVisitor::visitObject(this *CCDataVisitor,const CCObject* p);
void CCDataVisitor::visit(this *CCDataVisitor,const CCBool* p);
void CCDataVisitor::visit(this *CCDataVisitor,const CCInteger* p);
void CCDataVisitor::visit(this *CCDataVisitor,const CCFloat* p);
void CCDataVisitor::visit(this *CCDataVisitor,const CCDouble* p);
void CCDataVisitor::visit(this *CCDataVisitor,const CCString* p);
void CCDataVisitor::visit(this *CCDataVisitor,const CCArray* p);
void CCDataVisitor::visit(this *CCDataVisitor,const CCDictionary* p);
void CCDataVisitor::visit(this *CCDataVisitor,const CCSet* p);
struct CCPrettyPrinter{
	int _indentLevel;
	basic_string _indentStr;
	basic_string _result;
};

void CCPrettyPrinter::clear(this *CCPrettyPrinter);
basic_string CCPrettyPrinter::getResult(this *CCPrettyPrinter);
void CCPrettyPrinter::visitObject(this *CCPrettyPrinter,const CCObject* p);
void CCPrettyPrinter::visit(this *CCPrettyPrinter,const CCBool* p);
void CCPrettyPrinter::visit(this *CCPrettyPrinter,const CCInteger* p);
void CCPrettyPrinter::visit(this *CCPrettyPrinter,const CCFloat* p);
void CCPrettyPrinter::visit(this *CCPrettyPrinter,const CCDouble* p);
void CCPrettyPrinter::visit(this *CCPrettyPrinter,const CCString* p);
void CCPrettyPrinter::visit(this *CCPrettyPrinter,const CCArray* p);
void CCPrettyPrinter::visit(this *CCPrettyPrinter,const CCDictionary* p);
void CCPrettyPrinter::visit(this *CCPrettyPrinter,const CCSet* p);
void CCPrettyPrinter::setIndentLevel(this *CCPrettyPrinter,int indentLevel);
struct CCCopying{
};
CCObject* CCCopying::copyWithZone(this *CCCopying,CCZone* pZone);
struct CCObject{
	unsigned int m_uID;
	int m_nLuaID;
	int m_nTag;
	unsigned int m_uReference;
	unsigned int m_uAutoReleaseCount;
	int m_eObjType;
	unsigned int m_uObjectIdxInArray;
};



CCObject& CCObject::operator=(this *CCObject);
void CCObject::release(this *CCObject);
void CCObject::retain(this *CCObject);
CCObject* CCObject::autorelease(this *CCObject);
CCObject* CCObject::copy(this *CCObject);
bool CCObject::isSingleReference(this *CCObject);
unsigned int CCObject::retainCount(this *CCObject);
bool CCObject::isEqual(this *CCObject,const CCObject* pObject);
void CCObject::acceptVisitor(this *CCObject,CCDataVisitor& visitor);
void CCObject::update(this *CCObject,float dt);
void CCObject::encodeWithCoder(this *CCObject);
CCObject* CCObject::createWithCoder();
bool CCObject::canEncode(this *CCObject);
CCObjectType CCObject::getObjType(this *CCObject);
int CCObject::getTag(this *CCObject);
void CCObject::setTag(this *CCObject,int nTag);
void CCObject::setObjType(this *CCObject);
struct CCPoint{
	float x;
	float y;
};




CCPoint& CCPoint::operator=(this *CCPoint,const CCPoint& other);
CCPoint& CCPoint::operator=(this *CCPoint,const CCSize& size);
CCPoint CCPoint::operator+(this *CCPoint,const CCPoint& right);
CCPoint CCPoint::operator-(this *CCPoint,const CCPoint& right);
CCPoint CCPoint::operator-(this *CCPoint);
CCPoint CCPoint::operator*(this *CCPoint,float a);
CCPoint CCPoint::operator/(this *CCPoint,float a);
CCPoint CCPoint::operator*(this *CCPoint,const CCPoint& right);
CCPoint CCPoint::operator/(this *CCPoint,const CCPoint& right);
void CCPoint::setPoint(this *CCPoint,float x,float y);
bool CCPoint::equals(this *CCPoint,const CCPoint& target);
bool CCPoint::fuzzyEquals(this *CCPoint,const CCPoint& target,float variance);
float CCPoint::getLength(this *CCPoint);
float CCPoint::getLengthSq(this *CCPoint);
float CCPoint::getDistanceSq(this *CCPoint,const CCPoint& other);
float CCPoint::getDistance(this *CCPoint,const CCPoint& other);
float CCPoint::getAngle(this *CCPoint);
float CCPoint::getAngle(this *CCPoint,const CCPoint& other);
float CCPoint::dot(this *CCPoint,const CCPoint& other);
float CCPoint::cross(this *CCPoint,const CCPoint& other);
CCPoint CCPoint::getPerp(this *CCPoint);
CCPoint CCPoint::getRPerp(this *CCPoint);
CCPoint CCPoint::project(this *CCPoint,const CCPoint& other);
CCPoint CCPoint::rotate(this *CCPoint,const CCPoint& other);
CCPoint CCPoint::unrotate(this *CCPoint,const CCPoint& other);
CCPoint CCPoint::normalize(this *CCPoint);
CCPoint CCPoint::lerp(this *CCPoint,const CCPoint& other,float alpha);
CCPoint CCPoint::rotateByAngle(this *CCPoint,const CCPoint& pivot,float angle);
CCPoint CCPoint::forAngle(const float a);
struct CCSize{
	float width;
	float height;
};




CCSize& CCSize::operator=(this *CCSize,const CCSize& other);
CCSize& CCSize::operator=(this *CCSize,const CCPoint& point);
CCSize CCSize::operator+(this *CCSize,const CCSize& right);
CCSize CCSize::operator-(this *CCSize,const CCSize& right);
CCSize CCSize::operator*(this *CCSize,float a);
CCSize CCSize::operator/(this *CCSize,float a);
void CCSize::setSize(this *CCSize,float width,float height);
bool CCSize::equals(this *CCSize,const CCSize& target);
struct CCRect{
	CCPoint origin;
	CCSize size;
};



CCRect& CCRect::operator=(this *CCRect,const CCRect& other);
void CCRect::setRect(this *CCRect,float x,float y,float width,float height);
float CCRect::getMinX(this *CCRect);
float CCRect::getMidX(this *CCRect);
float CCRect::getMaxX(this *CCRect);
float CCRect::getMinY(this *CCRect);
float CCRect::getMidY(this *CCRect);
float CCRect::getMaxY(this *CCRect);
bool CCRect::equals(this *CCRect,const CCRect& rect);
bool CCRect::containsPoint(this *CCRect,const CCPoint& point);
bool CCRect::intersectsRect(this *CCRect,const CCRect& rect);
struct CCAction{
	CCNode* m_pOriginalTarget;
	CCNode* m_pTarget;
	int m_nTag;
	float m_fSpeedMod;
};


const char* CCAction::description(this *CCAction);
CCObject* CCAction::copyWithZone(this *CCAction,CCZone* pZone);
bool CCAction::isDone(this *CCAction);
void CCAction::startWithTarget(this *CCAction,CCNode* pTarget);
void CCAction::stop(this *CCAction);
void CCAction::step(this *CCAction,float dt);
void CCAction::update(this *CCAction,float time);
CCNode* CCAction::getTarget(this *CCAction);
void CCAction::setTarget(this *CCAction,CCNode* pTarget);
CCNode* CCAction::getOriginalTarget(this *CCAction);
void CCAction::setOriginalTarget(this *CCAction,CCNode* pOriginalTarget);
int CCAction::getTag(this *CCAction);
void CCAction::setTag(this *CCAction,int nTag);
void CCAction::setSpeedMod(this *CCAction,float mod);
CCAction* CCAction::create();
struct CCFiniteTimeAction{
	float m_fDuration;
};


float CCFiniteTimeAction::getDuration(this *CCFiniteTimeAction);
void CCFiniteTimeAction::setDuration(this *CCFiniteTimeAction,float duration);
CCFiniteTimeAction* CCFiniteTimeAction::reverse(this *CCFiniteTimeAction);
struct CCSpeed{
	float m_fSpeed;
	CCActionInterval* m_pInnerAction;
};


float CCSpeed::getSpeed(this *CCSpeed);
void CCSpeed::setSpeed(this *CCSpeed,float fSpeed);
bool CCSpeed::initWithAction(this *CCSpeed,CCActionInterval* pAction,float fSpeed);
CCObject* CCSpeed::copyWithZone(this *CCSpeed,CCZone* pZone);
void CCSpeed::startWithTarget(this *CCSpeed,CCNode* pTarget);
void CCSpeed::stop(this *CCSpeed);
void CCSpeed::step(this *CCSpeed,float dt);
bool CCSpeed::isDone(this *CCSpeed);
CCActionInterval* CCSpeed::reverse(this *CCSpeed);
void CCSpeed::setInnerAction(this *CCSpeed,CCActionInterval* pAction);
CCActionInterval* CCSpeed::getInnerAction(this *CCSpeed);
CCSpeed* CCSpeed::create(CCActionInterval* pAction,float fSpeed);
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


bool CCFollow::isBoundarySet(this *CCFollow);
void CCFollow::setBoudarySet(this *CCFollow,bool bValue);
bool CCFollow::initWithTarget(this *CCFollow,CCNode* pFollowedNode,const CCRect& rect);
CCObject* CCFollow::copyWithZone(this *CCFollow,CCZone* pZone);
void CCFollow::step(this *CCFollow,float dt);
bool CCFollow::isDone(this *CCFollow);
void CCFollow::stop(this *CCFollow);
CCFollow* CCFollow::create(CCNode* pFollowedNode,const CCRect& rect);
struct CCAffineTransform{
	float a;
	float b;
	float c;
	float d;
	float tx;
	float ty;
};
struct _ccArray{
	unsigned int num;
	unsigned int max;
	CCObject** arr;
};
struct _ccCArray{
	unsigned int num;
	unsigned int max;
	void** arr;
};
struct CCArray{
	ccArray* data;
};

CCArray* CCArray::create();
CCArray* CCArray::create(CCObject* pObject);
CCArray* CCArray::createWithObject(CCObject* pObject);
CCArray* CCArray::createWithCapacity(unsigned int capacity);
CCArray* CCArray::createWithArray(CCArray* otherArray);
CCArray* CCArray::createWithContentsOfFile(const char* pFileName);
CCArray* CCArray::createWithContentsOfFileThreadSafe(const char* pFileName);
bool CCArray::init(this *CCArray);
bool CCArray::initWithObject(this *CCArray,CCObject* pObject);
bool CCArray::initWithObjects(this *CCArray,CCObject* pObject);
bool CCArray::initWithCapacity(this *CCArray,unsigned int capacity);
bool CCArray::initWithArray(this *CCArray,CCArray* otherArray);
unsigned int CCArray::count(this *CCArray);
unsigned int CCArray::capacity(this *CCArray);
unsigned int CCArray::indexOfObject(this *CCArray,CCObject* object);
CCObject* CCArray::objectAtIndex(this *CCArray,unsigned int index);
CCObject* CCArray::lastObject(this *CCArray);
CCObject* CCArray::randomObject(this *CCArray);
bool CCArray::containsObject(this *CCArray,CCObject* object);
bool CCArray::isEqualToArray(this *CCArray,CCArray* pOtherArray);
void CCArray::addObject(this *CCArray,CCObject* object);
void CCArray::addObjectsFromArray(this *CCArray,CCArray* otherArray);
void CCArray::insertObject(this *CCArray,CCObject* object,unsigned int index);
void CCArray::removeLastObject(this *CCArray,bool bReleaseObj);
void CCArray::removeObject(this *CCArray,CCObject* object,bool bReleaseObj);
void CCArray::removeObjectAtIndex(this *CCArray,unsigned int index,bool bReleaseObj);
void CCArray::removeObjectsInArray(this *CCArray,CCArray* otherArray);
void CCArray::removeAllObjects(this *CCArray);
void CCArray::fastRemoveObject(this *CCArray,CCObject* object);
void CCArray::fastRemoveObjectAtIndex(this *CCArray,unsigned int index);
void CCArray::exchangeObject(this *CCArray,CCObject* object1,CCObject* object2);
void CCArray::exchangeObjectAtIndex(this *CCArray,unsigned int index1,unsigned int index2);
void CCArray::replaceObjectAtIndex(this *CCArray,unsigned int uIndex,CCObject* pObject,bool bReleaseObject);
void CCArray::reverseObjects(this *CCArray);
void CCArray::reduceMemoryFootprint(this *CCArray);
CCObject* CCArray::copyWithZone(this *CCArray,CCZone* pZone);
void CCArray::acceptVisitor(this *CCArray,CCDataVisitor& visitor);


struct CCGLProgram{
	GLuint m_uProgram;
	GLuint m_uVertShader;
	GLuint m_uFragShader;
	GLint[kCCUniform_MAX] m_uUniforms;
	struct _hashUniformEntry* m_pHashForUniforms;
	bool m_bUsesTime;
	bool m_hasShaderCompiler;
};


bool CCGLProgram::initWithVertexShaderByteArray(this *CCGLProgram,const GLchar* vShaderByteArray,const GLchar* fShaderByteArray);
bool CCGLProgram::initWithVertexShaderFilename(this *CCGLProgram,const char* vShaderFilename,const char* fShaderFilename);
void CCGLProgram::addAttribute(this *CCGLProgram,const char* attributeName,GLuint index);
bool CCGLProgram::link(this *CCGLProgram);
void CCGLProgram::use(this *CCGLProgram);
void CCGLProgram::updateUniforms(this *CCGLProgram);
GLint CCGLProgram::getUniformLocationForName(this *CCGLProgram,const char* name);
void CCGLProgram::setUniformLocationWith1i(this *CCGLProgram,GLint location,GLint i1);
void CCGLProgram::setUniformLocationWith2i(this *CCGLProgram,GLint location,GLint i1,GLint i2);
void CCGLProgram::setUniformLocationWith3i(this *CCGLProgram,GLint location,GLint i1,GLint i2,GLint i3);
void CCGLProgram::setUniformLocationWith4i(this *CCGLProgram,GLint location,GLint i1,GLint i2,GLint i3,GLint i4);
void CCGLProgram::setUniformLocationWith2iv(this *CCGLProgram,GLint location,GLint* ints,unsigned int numberOfArrays);
void CCGLProgram::setUniformLocationWith3iv(this *CCGLProgram,GLint location,GLint* ints,unsigned int numberOfArrays);
void CCGLProgram::setUniformLocationWith4iv(this *CCGLProgram,GLint location,GLint* ints,unsigned int numberOfArrays);
void CCGLProgram::setUniformLocationWith1f(this *CCGLProgram,GLint location,GLfloat f1);
void CCGLProgram::setUniformLocationWith2f(this *CCGLProgram,GLint location,GLfloat f1,GLfloat f2);
void CCGLProgram::setUniformLocationWith3f(this *CCGLProgram,GLint location,GLfloat f1,GLfloat f2,GLfloat f3);
void CCGLProgram::setUniformLocationWith4f(this *CCGLProgram,GLint location,GLfloat f1,GLfloat f2,GLfloat f3,GLfloat f4);
void CCGLProgram::setUniformLocationWith2fv(this *CCGLProgram,GLint location,GLfloat* floats,unsigned int numberOfArrays);
void CCGLProgram::setUniformLocationWith3fv(this *CCGLProgram,GLint location,GLfloat* floats,unsigned int numberOfArrays);
void CCGLProgram::setUniformLocationWith4fv(this *CCGLProgram,GLint location,GLfloat* floats,unsigned int numberOfArrays);
void CCGLProgram::setUniformLocationWithMatrix4fv(this *CCGLProgram,GLint location,GLfloat* matrixArray,unsigned int numberOfMatrices);
void CCGLProgram::setUniformsForBuiltins(this *CCGLProgram);
const char* CCGLProgram::vertexShaderLog(this *CCGLProgram);
const char* CCGLProgram::fragmentShaderLog(this *CCGLProgram);
const char* CCGLProgram::programLog(this *CCGLProgram);
void CCGLProgram::reset(this *CCGLProgram);
const GLuint CCGLProgram::getProgram(this *CCGLProgram);
bool CCGLProgram::updateUniformLocation(this *CCGLProgram,GLint location,GLvoid* data,unsigned int bytes);
const char* CCGLProgram::description(this *CCGLProgram);
bool CCGLProgram::compileShader(this *CCGLProgram,GLuint* shader,GLenum type,const GLchar* source);
const char* CCGLProgram::logForOpenGLObject(this *CCGLProgram,GLuint object,GLInfoFunction infoFunc,GLLogFunction logFunc);
struct CCTouch{
	int m_nId;
	bool m_startPointCaptured;
	CCPoint m_startPoint;
	CCPoint m_point;
	CCPoint m_prevPoint;
};

CCPoint CCTouch::getLocation(this *CCTouch);
CCPoint CCTouch::getPreviousLocation(this *CCTouch);
CCPoint CCTouch::getStartLocation(this *CCTouch);
CCPoint CCTouch::getDelta(this *CCTouch);
CCPoint CCTouch::getLocationInView(this *CCTouch);
CCPoint CCTouch::getPreviousLocationInView(this *CCTouch);
CCPoint CCTouch::getStartLocationInView(this *CCTouch);
void CCTouch::setTouchInfo(this *CCTouch,int id,float x,float y);
int CCTouch::getID(this *CCTouch);
struct CCEvent{
};
struct CCSet{
	std::set<CCObject*>* m_pSet;
};



CCSet* CCSet::create();
CCSet* CCSet::copy(this *CCSet);
CCSet* CCSet::mutableCopy(this *CCSet);
int CCSet::count(this *CCSet);
void CCSet::addObject(this *CCSet,CCObject* pObject);
void CCSet::removeObject(this *CCSet,CCObject* pObject);
void CCSet::removeAllObjects(this *CCSet);
bool CCSet::containsObject(this *CCSet,CCObject* pObject);
CCSetIterator CCSet::begin(this *CCSet);
CCSetIterator CCSet::end(this *CCSet);
CCObject* CCSet::anyObject(this *CCSet);
void CCSet::acceptVisitor(this *CCSet,CCDataVisitor& visitor);
struct CCScriptHandlerEntry{
	int m_nHandler;
	int m_nEntryId;
};
CCScriptHandlerEntry* CCScriptHandlerEntry::create(int nHandler);

int CCScriptHandlerEntry::getHandler(this *CCScriptHandlerEntry);
int CCScriptHandlerEntry::getEntryId(this *CCScriptHandlerEntry);

struct CCSchedulerScriptHandlerEntry{
	CCTimer* m_pTimer;
	bool m_bPaused;
	bool m_bMarkedForDeletion;
};
CCSchedulerScriptHandlerEntry* CCSchedulerScriptHandlerEntry::create(int nHandler,float fInterval,bool bPaused);

CCTimer* CCSchedulerScriptHandlerEntry::getTimer(this *CCSchedulerScriptHandlerEntry);
bool CCSchedulerScriptHandlerEntry::isPaused(this *CCSchedulerScriptHandlerEntry);
void CCSchedulerScriptHandlerEntry::markedForDeletion(this *CCSchedulerScriptHandlerEntry);
bool CCSchedulerScriptHandlerEntry::isMarkedForDeletion(this *CCSchedulerScriptHandlerEntry);

bool CCSchedulerScriptHandlerEntry::init(this *CCSchedulerScriptHandlerEntry,float fInterval,bool bPaused);
struct CCTouchScriptHandlerEntry{
	bool m_bIsMultiTouches;
	int m_nPriority;
	bool m_bSwallowsTouches;
};
CCTouchScriptHandlerEntry* CCTouchScriptHandlerEntry::create(int nHandler,bool bIsMultiTouches,int nPriority,bool bSwallowsTouches);

bool CCTouchScriptHandlerEntry::isMultiTouches(this *CCTouchScriptHandlerEntry);
int CCTouchScriptHandlerEntry::getPriority(this *CCTouchScriptHandlerEntry);
bool CCTouchScriptHandlerEntry::getSwallowsTouches(this *CCTouchScriptHandlerEntry);

bool CCTouchScriptHandlerEntry::init(this *CCTouchScriptHandlerEntry,bool bIsMultiTouches,int nPriority,bool bSwallowsTouches);
struct CCScriptEngineProtocol{
};

ccScriptType CCScriptEngineProtocol::getScriptType(this *CCScriptEngineProtocol);
void CCScriptEngineProtocol::removeScriptObjectByCCObject(this *CCScriptEngineProtocol,CCObject* pObj);
void CCScriptEngineProtocol::removeScriptHandler(this *CCScriptEngineProtocol,int nHandler);
int CCScriptEngineProtocol::reallocateScriptHandler(this *CCScriptEngineProtocol,int nHandler);
int CCScriptEngineProtocol::executeString(this *CCScriptEngineProtocol,const char* codes);
int CCScriptEngineProtocol::executeScriptFile(this *CCScriptEngineProtocol,const char* filename);
int CCScriptEngineProtocol::executeGlobalFunction(this *CCScriptEngineProtocol,const char* functionName);
int CCScriptEngineProtocol::executeNodeEvent(this *CCScriptEngineProtocol,CCNode* pNode,int nAction);
int CCScriptEngineProtocol::executeMenuItemEvent(this *CCScriptEngineProtocol,CCMenuItem* pMenuItem);
int CCScriptEngineProtocol::executeNotificationEvent(this *CCScriptEngineProtocol,CCNotificationCenter* pNotificationCenter,const char* pszName);
int CCScriptEngineProtocol::executeCallFuncActionEvent(this *CCScriptEngineProtocol,CCCallFunc* pAction,CCObject* pTarget);
int CCScriptEngineProtocol::executeSchedule(this *CCScriptEngineProtocol,int nHandler,float dt,CCNode* pNode);
int CCScriptEngineProtocol::executeLayerTouchesEvent(this *CCScriptEngineProtocol,CCLayer* pLayer,int eventType,CCSet* pTouches);
int CCScriptEngineProtocol::executeLayerTouchEvent(this *CCScriptEngineProtocol,CCLayer* pLayer,int eventType,CCTouch* pTouch);
int CCScriptEngineProtocol::executeLayerKeypadEvent(this *CCScriptEngineProtocol,CCLayer* pLayer,int eventType);
int CCScriptEngineProtocol::executeAccelerometerEvent(this *CCScriptEngineProtocol,CCLayer* pLayer,CCAcceleration* pAccelerationValue);
int CCScriptEngineProtocol::executeEvent(this *CCScriptEngineProtocol,int nHandler,const char* pEventName,CCObject* pEventSource,const char* pEventSourceClassName);
int CCScriptEngineProtocol::executeEventWithArgs(this *CCScriptEngineProtocol,int nHandler,CCArray* pArgs);
bool CCScriptEngineProtocol::handleAssert(this *CCScriptEngineProtocol,const char* msg);
bool CCScriptEngineProtocol::parseConfig(this *CCScriptEngineProtocol,ConfigType type,const basic_string& str);
struct CCScriptEngineManager{
	CCScriptEngineProtocol* m_pScriptEngine;
};

CCScriptEngineProtocol* CCScriptEngineManager::getScriptEngine(this *CCScriptEngineManager);
void CCScriptEngineManager::setScriptEngine(this *CCScriptEngineManager,CCScriptEngineProtocol* pScriptEngine);
void CCScriptEngineManager::removeScriptEngine(this *CCScriptEngineManager);
CCScriptEngineManager* CCScriptEngineManager::sharedManager();
void CCScriptEngineManager::purgeSharedManager();

struct _ccColor3B{
	GLubyte r;
	GLubyte g;
	GLubyte b;
};
struct _ccHSVValue{
	float h;
	float s;
	float v;
	GLubyte absoluteSaturation;
	GLubyte absoluteBrightness;
	unsigned char[2] __pad;
};
struct _ccColor4B{
	GLubyte r;
	GLubyte g;
	GLubyte b;
	GLubyte a;
};
struct _ccColor4F{
	GLfloat r;
	GLfloat g;
	GLfloat b;
	GLfloat a;
};
struct _ccVertex2F{
	GLfloat x;
	GLfloat y;
};
struct _ccVertex3F{
	GLfloat x;
	GLfloat y;
	GLfloat z;
};
struct _ccTex2F{
	GLfloat u;
	GLfloat v;
};
struct _ccPointSprite{
	ccVertex2F pos;
	ccColor4B color;
	GLfloat size;
};
struct _ccQuad2{
	ccVertex2F tl;
	ccVertex2F tr;
	ccVertex2F bl;
	ccVertex2F br;
};
struct _ccQuad3{
	ccVertex3F bl;
	ccVertex3F br;
	ccVertex3F tl;
	ccVertex3F tr;
};
struct _ccV2F_C4B_T2F{
	ccVertex2F vertices;
	ccColor4B colors;
	ccTex2F texCoords;
};
struct _ccV2F_C4F_T2F{
	ccVertex2F vertices;
	ccColor4F colors;
	ccTex2F texCoords;
};
struct _ccV3F_C4B_T2F{
	ccVertex3F vertices;
	ccColor4B colors;
	ccTex2F texCoords;
};
struct _ccV2F_C4B_T2F_Triangle{
	ccV2F_C4B_T2F a;
	ccV2F_C4B_T2F b;
	ccV2F_C4B_T2F c;
};
struct _ccV2F_C4B_T2F_Quad{
	ccV2F_C4B_T2F bl;
	ccV2F_C4B_T2F br;
	ccV2F_C4B_T2F tl;
	ccV2F_C4B_T2F tr;
};
struct _ccV3F_C4B_T2F_Quad{
	ccV3F_C4B_T2F tl;
	ccV3F_C4B_T2F bl;
	ccV3F_C4B_T2F tr;
	ccV3F_C4B_T2F br;
};
struct _ccV2F_C4F_T2F_Quad{
	ccV2F_C4F_T2F bl;
	ccV2F_C4F_T2F br;
	ccV2F_C4F_T2F tl;
	ccV2F_C4F_T2F tr;
};
struct _ccBlendFunc{
	GLenum src;
	GLenum dst;
};
struct _ccT2F_Quad{
	ccTex2F bl;
	ccTex2F br;
	ccTex2F tl;
	ccTex2F tr;
};

struct _ccFontShadow{
	bool m_shadowEnabled;
	CCSize m_shadowOffset;
	float m_shadowBlur;
	float m_shadowOpacity;
};

struct _ccFontStroke{
	bool m_strokeEnabled;
	ccColor3B m_strokeColor;
	float m_strokeSize;
};

struct _ccFontDefinition{
	basic_string m_fontName;
	int m_fontSize;
	CCTextAlignment m_alignment;
	CCVerticalTextAlignment m_vertAlignment;
	CCSize m_dimensions;
	ccColor3B m_fontFillColor;
	ccFontShadow m_shadow;
	ccFontStroke m_stroke;
};

struct _ccTexParams{
	GLuint minFilter;
	GLuint magFilter;
	GLuint wrapS;
	GLuint wrapT;
};
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


const char* CCTexture2D::description(this *CCTexture2D);
void CCTexture2D::releaseData(this *CCTexture2D,void* data);
void* CCTexture2D::keepData(this *CCTexture2D,void* data,unsigned int length);
bool CCTexture2D::initWithData(this *CCTexture2D,const void* data,CCTexture2DPixelFormat pixelFormat,unsigned int pixelsWide,unsigned int pixelsHigh,const CCSize& contentSize);
void CCTexture2D::drawAtPoint(this *CCTexture2D,const CCPoint& point);
void CCTexture2D::drawInRect(this *CCTexture2D,const CCRect& rect);
bool CCTexture2D::initWithImage(this *CCTexture2D,CCImage* uiImage);
bool CCTexture2D::initWithString(this *CCTexture2D,const char* text,const char* fontName,float fontSize,const CCSize& dimensions,CCTextAlignment hAlignment,CCVerticalTextAlignment vAlignment);
bool CCTexture2D::initWithString(this *CCTexture2D,const char* text,const char* fontName,float fontSize);
bool CCTexture2D::initWithString(this *CCTexture2D,const char* text,ccFontDefinition* textDefinition);
bool CCTexture2D::initWithPVRFile(this *CCTexture2D,const char* file);
bool CCTexture2D::initWithETCFile(this *CCTexture2D,const char* file);
void CCTexture2D::setTexParameters(this *CCTexture2D,ccTexParams* texParams);
void CCTexture2D::setAntiAliasTexParameters(this *CCTexture2D);
void CCTexture2D::setAliasTexParameters(this *CCTexture2D);
void CCTexture2D::generateMipmap(this *CCTexture2D);
const char* CCTexture2D::stringForFormat(this *CCTexture2D);
unsigned int CCTexture2D::bitsPerPixelForFormat(this *CCTexture2D);
unsigned int CCTexture2D::bitsPerPixelForFormat(this *CCTexture2D,CCTexture2DPixelFormat format);
void CCTexture2D::setDefaultAlphaPixelFormat(CCTexture2DPixelFormat format);
CCTexture2DPixelFormat CCTexture2D::defaultAlphaPixelFormat();
void CCTexture2D::PVRImagesHavePremultipliedAlpha(bool haveAlphaPremultiplied);
const CCSize& CCTexture2D::getContentSizeInPixels(this *CCTexture2D);
bool CCTexture2D::hasPremultipliedAlpha(this *CCTexture2D);
bool CCTexture2D::hasMipmaps(this *CCTexture2D);
bool CCTexture2D::initPremultipliedATextureWithImage(this *CCTexture2D,CCImage* image,unsigned int pixelsWide,unsigned int pixelsHigh);
CCTexture2DPixelFormat CCTexture2D::getPixelFormat(this *CCTexture2D);
unsigned int CCTexture2D::getPixelsWide(this *CCTexture2D);
unsigned int CCTexture2D::getPixelsHigh(this *CCTexture2D);
GLuint CCTexture2D::getName(this *CCTexture2D);
GLfloat CCTexture2D::getMaxS(this *CCTexture2D);
void CCTexture2D::setMaxS(this *CCTexture2D,GLfloat var);
GLfloat CCTexture2D::getMaxT(this *CCTexture2D);
void CCTexture2D::setMaxT(this *CCTexture2D,GLfloat var);
CCSize CCTexture2D::getContentSize(this *CCTexture2D);
CCGLProgram* CCTexture2D::getShaderProgram(this *CCTexture2D);
void CCTexture2D::setShaderProgram(this *CCTexture2D,CCGLProgram* var);
struct CCRGBAProtocol{
};
void CCRGBAProtocol::setColor(this *CCRGBAProtocol,const ccColor3B& color);
const ccColor3B& CCRGBAProtocol::getColor(this *CCRGBAProtocol);
const ccColor3B& CCRGBAProtocol::getDisplayedColor(this *CCRGBAProtocol);
GLubyte CCRGBAProtocol::getDisplayedOpacity(this *CCRGBAProtocol);
GLubyte CCRGBAProtocol::getOpacity(this *CCRGBAProtocol);
void CCRGBAProtocol::setOpacity(this *CCRGBAProtocol,GLubyte opacity);
void CCRGBAProtocol::setOpacityModifyRGB(this *CCRGBAProtocol,bool bValue);
bool CCRGBAProtocol::isOpacityModifyRGB(this *CCRGBAProtocol);
bool CCRGBAProtocol::isCascadeColorEnabled(this *CCRGBAProtocol);
void CCRGBAProtocol::setCascadeColorEnabled(this *CCRGBAProtocol,bool cascadeColorEnabled);
void CCRGBAProtocol::updateDisplayedColor(this *CCRGBAProtocol,const ccColor3B& color);
bool CCRGBAProtocol::isCascadeOpacityEnabled(this *CCRGBAProtocol);
void CCRGBAProtocol::setCascadeOpacityEnabled(this *CCRGBAProtocol,bool cascadeOpacityEnabled);
void CCRGBAProtocol::updateDisplayedOpacity(this *CCRGBAProtocol,GLubyte opacity);
struct CCBlendProtocol{
};
void CCBlendProtocol::setBlendFunc(this *CCBlendProtocol,ccBlendFunc blendFunc);
ccBlendFunc CCBlendProtocol::getBlendFunc(this *CCBlendProtocol);
struct CCTextureProtocol{
};
CCTexture2D* CCTextureProtocol::getTexture(this *CCTextureProtocol);
void CCTextureProtocol::setTexture(this *CCTextureProtocol,CCTexture2D* texture);
struct CCLabelProtocol{
};
void CCLabelProtocol::setString(this *CCLabelProtocol,const char* label);
const char* CCLabelProtocol::getString(this *CCLabelProtocol);
struct CCDirectorDelegate{
};
void CCDirectorDelegate::updateProjection(this *CCDirectorDelegate);
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



bool CCNode::init(this *CCNode);
CCNode* CCNode::create();
const char* CCNode::description(this *CCNode);
void CCNode::setZOrder(this *CCNode,int zOrder);
void CCNode::_setZOrder(this *CCNode,int z);
int CCNode::getZOrder(this *CCNode);
void CCNode::setVertexZ(this *CCNode,float vertexZ);
float CCNode::getVertexZ(this *CCNode);
void CCNode::setScaleX(this *CCNode,float fScaleX);
float CCNode::getScaleX(this *CCNode);
void CCNode::setScaleY(this *CCNode,float fScaleY);
float CCNode::getScaleY(this *CCNode);
void CCNode::setScale(this *CCNode,float scale);
float CCNode::getScale(this *CCNode);
void CCNode::setScale(this *CCNode,float fScaleX,float fScaleY);
void CCNode::setPosition(this *CCNode,const CCPoint& position);
const CCPoint& CCNode::getPosition(this *CCNode);
void CCNode::setPosition(this *CCNode,float x,float y);
void CCNode::getPosition(this *CCNode,float* x,float* y);
void CCNode::setPositionX(this *CCNode,float x);
float CCNode::getPositionX(this *CCNode);
void CCNode::setPositionY(this *CCNode,float y);
float CCNode::getPositionY(this *CCNode);
void CCNode::setSkewX(this *CCNode,float fSkewX);
float CCNode::getSkewX(this *CCNode);
void CCNode::setSkewY(this *CCNode,float fSkewY);
float CCNode::getSkewY(this *CCNode);
void CCNode::setAnchorPoint(this *CCNode,const CCPoint& anchorPoint);
const CCPoint& CCNode::getAnchorPoint(this *CCNode);
const CCPoint& CCNode::getAnchorPointInPoints(this *CCNode);
void CCNode::setContentSize(this *CCNode,const CCSize& contentSize);
const CCSize& CCNode::getContentSize(this *CCNode);
CCSize CCNode::getScaledContentSize(this *CCNode);
void CCNode::setVisible(this *CCNode,bool visible);
bool CCNode::isVisible(this *CCNode);
void CCNode::setRotation(this *CCNode,float fRotation);
float CCNode::getRotation(this *CCNode);
void CCNode::setRotationX(this *CCNode,float fRotaionX);
float CCNode::getRotationX(this *CCNode);
void CCNode::setRotationY(this *CCNode,float fRotationY);
float CCNode::getRotationY(this *CCNode);
void CCNode::setOrderOfArrival(this *CCNode,unsigned int uOrderOfArrival);
unsigned int CCNode::getOrderOfArrival(this *CCNode);
void CCNode::setGLServerState(this *CCNode,ccGLServerState glServerState);
ccGLServerState CCNode::getGLServerState(this *CCNode);
void CCNode::ignoreAnchorPointForPosition(this *CCNode,bool ignore);
bool CCNode::isIgnoreAnchorPointForPosition(this *CCNode);
void CCNode::addChild(this *CCNode,CCNode* child);
void CCNode::addChild(this *CCNode,CCNode* child,int zOrder);
void CCNode::addChild(this *CCNode,CCNode* child,int zOrder,int tag);
CCNode* CCNode::getChildByTag(this *CCNode,int tag);
CCArray* CCNode::getChildren(this *CCNode);
unsigned int CCNode::getChildrenCount(this *CCNode);
void CCNode::setParent(this *CCNode,CCNode* parent);
CCNode* CCNode::getParent(this *CCNode);
void CCNode::removeFromParent(this *CCNode);
void CCNode::removeFromParentAndCleanup(this *CCNode,bool cleanup);
void CCNode::removeMeAndCleanup(this *CCNode);
void CCNode::removeChild(this *CCNode,CCNode* child);
void CCNode::removeChild(this *CCNode,CCNode* child,bool cleanup);
void CCNode::removeChildByTag(this *CCNode,int tag);
void CCNode::removeChildByTag(this *CCNode,int tag,bool cleanup);
void CCNode::removeAllChildren(this *CCNode);
void CCNode::removeAllChildrenWithCleanup(this *CCNode,bool cleanup);
void CCNode::reorderChild(this *CCNode,CCNode* child,int zOrder);
void CCNode::sortAllChildren(this *CCNode);
CCGridBase* CCNode::getGrid(this *CCNode);
void CCNode::setGrid(this *CCNode,CCGridBase* pGrid);
void* CCNode::getUserData(this *CCNode);
void CCNode::setUserData(this *CCNode,void* pUserData);
CCObject* CCNode::getUserObject(this *CCNode);
void CCNode::setUserObject(this *CCNode,CCObject* pUserObject);
CCGLProgram* CCNode::getShaderProgram(this *CCNode);
void CCNode::setShaderProgram(this *CCNode,CCGLProgram* pShaderProgram);
CCCamera* CCNode::getCamera(this *CCNode);
bool CCNode::isRunning(this *CCNode);
void CCNode::registerScriptHandler(this *CCNode,int handler);
void CCNode::unregisterScriptHandler(this *CCNode);
int CCNode::getScriptHandler(this *CCNode);
void CCNode::scheduleUpdateWithPriorityLua(this *CCNode,int nHandler,int priority);
void CCNode::onEnter(this *CCNode);
void CCNode::onEnterTransitionDidFinish(this *CCNode);
void CCNode::onExit(this *CCNode);
void CCNode::onExitTransitionDidStart(this *CCNode);
void CCNode::cleanup(this *CCNode);
void CCNode::draw(this *CCNode);
void CCNode::visit(this *CCNode);
CCRect CCNode::boundingBox(this *CCNode);
void CCNode::setActionManager(this *CCNode,CCActionManager* actionManager);
CCActionManager* CCNode::getActionManager(this *CCNode);
CCAction* CCNode::runAction(this *CCNode,CCAction* action);
void CCNode::stopAllActions(this *CCNode);
void CCNode::stopAction(this *CCNode,CCAction* action);
void CCNode::stopActionByTag(this *CCNode,int tag);
CCAction* CCNode::getActionByTag(this *CCNode,int tag);
unsigned int CCNode::numberOfRunningActions(this *CCNode);
void CCNode::setScheduler(this *CCNode,CCScheduler* scheduler);
CCScheduler* CCNode::getScheduler(this *CCNode);
bool CCNode::isScheduled(this *CCNode,SEL_SCHEDULE selector);
void CCNode::scheduleUpdate(this *CCNode);
void CCNode::scheduleUpdateWithPriority(this *CCNode,int priority);
void CCNode::unscheduleUpdate(this *CCNode);
void CCNode::schedule(this *CCNode,SEL_SCHEDULE selector,float interval,unsigned int repeat,float delay);
void CCNode::schedule(this *CCNode,SEL_SCHEDULE selector,float interval);
void CCNode::scheduleOnce(this *CCNode,SEL_SCHEDULE selector,float delay);
void CCNode::schedule(this *CCNode,SEL_SCHEDULE selector);
void CCNode::unschedule(this *CCNode,SEL_SCHEDULE selector);
void CCNode::unscheduleAllSelectors(this *CCNode);
void CCNode::resumeSchedulerAndActions(this *CCNode);
void CCNode::pauseSchedulerAndActions(this *CCNode);
void CCNode::update(this *CCNode,float delta);
void CCNode::transform(this *CCNode);
void CCNode::transformAncestors(this *CCNode);
void CCNode::updateTransform(this *CCNode);
const CCAffineTransform CCNode::nodeToParentTransform(this *CCNode);
const CCAffineTransform CCNode::parentToNodeTransform(this *CCNode);
CCAffineTransform CCNode::nodeToWorldTransform(this *CCNode);
CCAffineTransform CCNode::worldToNodeTransform(this *CCNode);
CCPoint CCNode::convertToNodeSpace(this *CCNode,const CCPoint& worldPoint);
CCPoint CCNode::convertToWorldSpace(this *CCNode,const CCPoint& nodePoint);
CCPoint CCNode::convertToNodeSpaceAR(this *CCNode,const CCPoint& worldPoint);
CCPoint CCNode::convertToWorldSpaceAR(this *CCNode,const CCPoint& nodePoint);
CCPoint CCNode::convertTouchToNodeSpace(this *CCNode,CCTouch* touch);
CCPoint CCNode::convertTouchToNodeSpaceAR(this *CCNode,CCTouch* touch);
void CCNode::setAdditionalTransform(this *CCNode,const CCAffineTransform& additionalTransform);
CCComponent* CCNode::getComponent(this *CCNode,const char* pName);
bool CCNode::addComponent(this *CCNode,CCComponent* pComponent);
bool CCNode::removeComponent(this *CCNode,const char* pName);
bool CCNode::removeComponent(this *CCNode,CCComponent* pComponent);
void CCNode::removeAllComponents(this *CCNode);
void CCNode::updateTweenAction(this *CCNode);
CCNode& CCNode::operator=(this *CCNode);
void CCNode::childrenAlloc(this *CCNode);
void CCNode::insertChild(this *CCNode,CCNode* child,int z);
void CCNode::detachChild(this *CCNode,CCNode* child,bool doCleanup);
CCPoint CCNode::convertToWindowSpace(this *CCNode,const CCPoint& nodePoint);
struct CCNodeRGBA{
	GLubyte _displayedOpacity;
	GLubyte _realOpacity;
	ccColor3B _displayedColor;
	ccColor3B _realColor;
	bool _cascadeColorEnabled;
	bool _cascadeOpacityEnabled;
};


bool CCNodeRGBA::init(this *CCNodeRGBA);
CCNodeRGBA* CCNodeRGBA::create();
GLubyte CCNodeRGBA::getOpacity(this *CCNodeRGBA);
GLubyte CCNodeRGBA::getDisplayedOpacity(this *CCNodeRGBA);
void CCNodeRGBA::setOpacity(this *CCNodeRGBA,GLubyte opacity);
void CCNodeRGBA::updateDisplayedOpacity(this *CCNodeRGBA,GLubyte parentOpacity);
bool CCNodeRGBA::isCascadeOpacityEnabled(this *CCNodeRGBA);
void CCNodeRGBA::setCascadeOpacityEnabled(this *CCNodeRGBA,bool cascadeOpacityEnabled);
const ccColor3B& CCNodeRGBA::getColor(this *CCNodeRGBA);
const ccColor3B& CCNodeRGBA::getDisplayedColor(this *CCNodeRGBA);
void CCNodeRGBA::setColor(this *CCNodeRGBA,const ccColor3B& color);
void CCNodeRGBA::updateDisplayedColor(this *CCNodeRGBA,const ccColor3B& parentColor);
bool CCNodeRGBA::isCascadeColorEnabled(this *CCNodeRGBA);
void CCNodeRGBA::setCascadeColorEnabled(this *CCNodeRGBA,bool cascadeColorEnabled);
void CCNodeRGBA::setOpacityModifyRGB(this *CCNodeRGBA,bool bValue);
bool CCNodeRGBA::isOpacityModifyRGB(this *CCNodeRGBA);
struct CCSpriteFrame{
	CCPoint m_obOffset;
	CCSize m_obOriginalSize;
	CCRect m_obRectInPixels;
	bool m_bRotated;
	CCRect m_obRect;
	CCPoint m_obOffsetInPixels;
	CCSize m_obOriginalSizeInPixels;
	CCTexture2D* m_pobTexture;
	basic_string m_strTextureFilename;
};
const CCRect& CCSpriteFrame::getRectInPixels(this *CCSpriteFrame);
void CCSpriteFrame::setRectInPixels(this *CCSpriteFrame,const CCRect& rectInPixels);
bool CCSpriteFrame::isRotated(this *CCSpriteFrame);
void CCSpriteFrame::setRotated(this *CCSpriteFrame,bool bRotated);
const CCRect& CCSpriteFrame::getRect(this *CCSpriteFrame);
void CCSpriteFrame::setRect(this *CCSpriteFrame,const CCRect& rect);
const CCPoint& CCSpriteFrame::getOffsetInPixels(this *CCSpriteFrame);
void CCSpriteFrame::setOffsetInPixels(this *CCSpriteFrame,const CCPoint& offsetInPixels);
const CCSize& CCSpriteFrame::getOriginalSizeInPixels(this *CCSpriteFrame);
void CCSpriteFrame::setOriginalSizeInPixels(this *CCSpriteFrame,const CCSize& sizeInPixels);
const CCSize& CCSpriteFrame::getOriginalSize(this *CCSpriteFrame);
void CCSpriteFrame::setOriginalSize(this *CCSpriteFrame,const CCSize& sizeInPixels);
CCTexture2D* CCSpriteFrame::getTexture(this *CCSpriteFrame);
void CCSpriteFrame::setTexture(this *CCSpriteFrame,CCTexture2D* pobTexture);
const CCPoint& CCSpriteFrame::getOffset(this *CCSpriteFrame);
void CCSpriteFrame::setOffset(this *CCSpriteFrame,const CCPoint& offsets);

CCObject* CCSpriteFrame::copyWithZone(this *CCSpriteFrame,CCZone* pZone);
CCSpriteFrame* CCSpriteFrame::create(const char* filename,const CCRect& rect);
CCSpriteFrame* CCSpriteFrame::create(const char* filename,const CCRect& rect,bool rotated,const CCPoint& offset,const CCSize& originalSize);
CCSpriteFrame* CCSpriteFrame::createWithTexture(CCTexture2D* pobTexture,const CCRect& rect);
CCSpriteFrame* CCSpriteFrame::createWithTexture(CCTexture2D* pobTexture,const CCRect& rect,bool rotated,const CCPoint& offset,const CCSize& originalSize);
bool CCSpriteFrame::initWithTexture(this *CCSpriteFrame,CCTexture2D* pobTexture,const CCRect& rect);
bool CCSpriteFrame::initWithTextureFilename(this *CCSpriteFrame,const char* filename,const CCRect& rect);
bool CCSpriteFrame::initWithTexture(this *CCSpriteFrame,CCTexture2D* pobTexture,const CCRect& rect,bool rotated,const CCPoint& offset,const CCSize& originalSize);
bool CCSpriteFrame::initWithTextureFilename(this *CCSpriteFrame,const char* filename,const CCRect& rect,bool rotated,const CCPoint& offset,const CCSize& originalSize);
struct UT_hash_bucket{
	struct UT_hash_handle* hh_head;
	unsigned count;
	unsigned expand_mult;
};
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
	basic_string m_sString;
};





CCString& CCString::operator=(this *CCString,const CCString& other);
bool CCString::initWithFormat(this *CCString,const char* format);
int CCString::intValue(this *CCString);
unsigned int CCString::uintValue(this *CCString);
float CCString::floatValue(this *CCString);
double CCString::doubleValue(this *CCString);
bool CCString::boolValue(this *CCString);
const char* CCString::getCString(this *CCString);
unsigned int CCString::length(this *CCString);
int CCString::compare(this *CCString);
CCObject* CCString::copyWithZone(this *CCString,CCZone* pZone);
bool CCString::isEqual(this *CCString,const CCObject* pObject);
CCString* CCString::create(const basic_string& str);
CCString* CCString::createWithFormat(const char* format);
CCString* CCString::createWithData(const unsigned char* pData,unsigned long nLen);
CCString* CCString::createWithContentsOfFile(const char* pszFileName);
void CCString::acceptVisitor(this *CCString,CCDataVisitor& visitor);
bool CCString::initWithFormatAndValist(this *CCString,const char* format,va_list ap);
struct CCDictElement{
	char[256] m_szKey;
	intptr_t m_iKey;
	CCObject* m_pObject;
	UT_hash_handle hh;
};



const char* CCDictElement::getStrKey(this *CCDictElement);
intptr_t CCDictElement::getIntKey(this *CCDictElement);
CCObject* CCDictElement::getObject(this *CCDictElement);
struct CCDictionary{
	CCDictElement* m_pElements;
	CCDictType m_eDictType;
};


unsigned int CCDictionary::count(this *CCDictionary);
CCArray* CCDictionary::allKeys(this *CCDictionary);
CCArray* CCDictionary::allKeysForObject(this *CCDictionary,CCObject* object);
CCObject* CCDictionary::objectForKey(this *CCDictionary,const basic_string& key);
CCObject* CCDictionary::objectForKey(this *CCDictionary,intptr_t key);
const CCString* CCDictionary::valueForKey(this *CCDictionary,const basic_string& key);
const CCString* CCDictionary::valueForKey(this *CCDictionary,intptr_t key);
void CCDictionary::setObject(this *CCDictionary,CCObject* pObject,const basic_string& key);
void CCDictionary::setObject(this *CCDictionary,CCObject* pObject,intptr_t key);
void CCDictionary::removeObjectForKey(this *CCDictionary,const basic_string& key);
void CCDictionary::removeObjectForKey(this *CCDictionary,intptr_t key);
void CCDictionary::removeObjectsForKeys(this *CCDictionary,CCArray* pKeyArray);
void CCDictionary::removeObjectForElememt(this *CCDictionary,CCDictElement* pElement);
void CCDictionary::removeAllObjects(this *CCDictionary);
CCObject* CCDictionary::copyWithZone(this *CCDictionary,CCZone* pZone);
CCObject* CCDictionary::randomObject(this *CCDictionary);
CCDictionary* CCDictionary::create();
CCDictionary* CCDictionary::createWithDictionary(CCDictionary* srcDict);
CCDictionary* CCDictionary::createWithContentsOfFile(const char* pFileName);
bool CCDictionary::writeToFile(this *CCDictionary,const char* fullPath);
CCDictionary* CCDictionary::createWithContentsOfFileThreadSafe(const char* pFileName);
void CCDictionary::acceptVisitor(this *CCDictionary,CCDataVisitor& visitor);
void CCDictionary::setObjectUnSafe(this *CCDictionary,CCObject* pObject,const basic_string& key);
void CCDictionary::setObjectUnSafe(this *CCDictionary,CCObject* pObject,const intptr_t key);
struct CCAnimationFrame{
	CCSpriteFrame* m_pSpriteFrame;
	float m_fDelayUnits;
	CCDictionary* m_pUserInfo;
};


CCObject* CCAnimationFrame::copyWithZone(this *CCAnimationFrame,CCZone* pZone);
bool CCAnimationFrame::initWithSpriteFrame(this *CCAnimationFrame,CCSpriteFrame* spriteFrame,float delayUnits,CCDictionary* userInfo);
CCSpriteFrame* CCAnimationFrame::getSpriteFrame(this *CCAnimationFrame);
void CCAnimationFrame::setSpriteFrame(this *CCAnimationFrame,CCSpriteFrame* var);
float CCAnimationFrame::getDelayUnits(this *CCAnimationFrame);
void CCAnimationFrame::setDelayUnits(this *CCAnimationFrame,float var);
CCDictionary* CCAnimationFrame::getUserInfo(this *CCAnimationFrame);
void CCAnimationFrame::setUserInfo(this *CCAnimationFrame,CCDictionary* var);
struct CCAnimation{
	float m_fTotalDelayUnits;
	float m_fDelayPerUnit;
	float m_fDuration;
	CCArray* m_pFrames;
	bool m_bRestoreOriginalFrame;
	unsigned int m_uLoops;
};


CCAnimation* CCAnimation::create();
CCAnimation* CCAnimation::createWithSpriteFrames(CCArray* arrayOfSpriteFrameNames,float delay);
CCAnimation* CCAnimation::create(CCArray* arrayOfAnimationFrameNames,float delayPerUnit,unsigned int loops);
CCAnimation* CCAnimation::create(CCArray* arrayOfAnimationFrameNames,float delayPerUnit);
void CCAnimation::addSpriteFrame(this *CCAnimation,CCSpriteFrame* pFrame);
void CCAnimation::addSpriteFrameWithFileName(this *CCAnimation,const char* pszFileName);
void CCAnimation::addSpriteFrameWithTexture(this *CCAnimation,CCTexture2D* pobTexture,const CCRect& rect);
bool CCAnimation::init(this *CCAnimation);
bool CCAnimation::initWithSpriteFrames(this *CCAnimation,CCArray* pFrames,float delay);
bool CCAnimation::initWithAnimationFrames(this *CCAnimation,CCArray* arrayOfAnimationFrames,float delayPerUnit,unsigned int loops);
CCObject* CCAnimation::copyWithZone(this *CCAnimation,CCZone* pZone);
float CCAnimation::getTotalDelayUnits(this *CCAnimation);
float CCAnimation::getDelayPerUnit(this *CCAnimation);
void CCAnimation::setDelayPerUnit(this *CCAnimation,float var);
float CCAnimation::getDuration(this *CCAnimation);
CCArray* CCAnimation::getFrames(this *CCAnimation);
void CCAnimation::setFrames(this *CCAnimation,CCArray* var);
bool CCAnimation::getRestoreOriginalFrame(this *CCAnimation);
void CCAnimation::setRestoreOriginalFrame(this *CCAnimation,bool var);
unsigned int CCAnimation::getLoops(this *CCAnimation);
void CCAnimation::setLoops(this *CCAnimation,unsigned int var);
struct CCActionInterval{
	float m_elapsed;
	bool m_bFirstTick;
};
float CCActionInterval::getElapsed(this *CCActionInterval);
bool CCActionInterval::initWithDuration(this *CCActionInterval,float d);
bool CCActionInterval::isDone(this *CCActionInterval);
CCObject* CCActionInterval::copyWithZone(this *CCActionInterval,CCZone* pZone);
void CCActionInterval::step(this *CCActionInterval,float dt);
void CCActionInterval::startWithTarget(this *CCActionInterval,CCNode* pTarget);
CCActionInterval* CCActionInterval::reverse(this *CCActionInterval);
CCActionInterval* CCActionInterval::create(float d);
void CCActionInterval::setAmplitudeRate(this *CCActionInterval,float amp);
float CCActionInterval::getAmplitudeRate(this *CCActionInterval);
struct CCSequence{
	CCFiniteTimeAction*[2] m_pActions;
	float m_split;
	int m_last;
};

bool CCSequence::initWithTwoActions(this *CCSequence,CCFiniteTimeAction* pActionOne,CCFiniteTimeAction* pActionTwo);
CCObject* CCSequence::copyWithZone(this *CCSequence,CCZone* pZone);
void CCSequence::startWithTarget(this *CCSequence,CCNode* pTarget);
void CCSequence::stop(this *CCSequence);
void CCSequence::update(this *CCSequence,float t);
CCActionInterval* CCSequence::reverse(this *CCSequence);
CCSequence* CCSequence::create(CCFiniteTimeAction* pAction1);
CCSequence* CCSequence::create(CCArray* arrayOfActions);
CCSequence* CCSequence::createWithVariableList(CCFiniteTimeAction* pAction1,va_list args);
CCSequence* CCSequence::createWithTwoActions(CCFiniteTimeAction* pActionOne,CCFiniteTimeAction* pActionTwo);
struct CCRepeat{
	unsigned int m_uTimes;
	unsigned int m_uTotal;
	float m_fNextDt;
	bool m_bActionInstant;
	CCFiniteTimeAction* m_pInnerAction;
};

bool CCRepeat::initWithAction(this *CCRepeat,CCFiniteTimeAction* pAction,unsigned int times);
CCObject* CCRepeat::copyWithZone(this *CCRepeat,CCZone* pZone);
void CCRepeat::startWithTarget(this *CCRepeat,CCNode* pTarget);
void CCRepeat::stop(this *CCRepeat);
void CCRepeat::update(this *CCRepeat,float dt);
bool CCRepeat::isDone(this *CCRepeat);
CCActionInterval* CCRepeat::reverse(this *CCRepeat);
void CCRepeat::setInnerAction(this *CCRepeat,CCFiniteTimeAction* pAction);
CCFiniteTimeAction* CCRepeat::getInnerAction(this *CCRepeat);
CCRepeat* CCRepeat::create(CCFiniteTimeAction* pAction,unsigned int times);
struct CCRepeatForever{
	CCActionInterval* m_pInnerAction;
};


bool CCRepeatForever::initWithAction(this *CCRepeatForever,CCActionInterval* pAction);
CCObject* CCRepeatForever::copyWithZone(this *CCRepeatForever,CCZone* pZone);
void CCRepeatForever::startWithTarget(this *CCRepeatForever,CCNode* pTarget);
void CCRepeatForever::step(this *CCRepeatForever,float dt);
bool CCRepeatForever::isDone(this *CCRepeatForever);
CCActionInterval* CCRepeatForever::reverse(this *CCRepeatForever);
void CCRepeatForever::setInnerAction(this *CCRepeatForever,CCActionInterval* pAction);
CCActionInterval* CCRepeatForever::getInnerAction(this *CCRepeatForever);
CCRepeatForever* CCRepeatForever::create(CCActionInterval* pAction);
struct CCSpawn{
	CCFiniteTimeAction* m_pOne;
	CCFiniteTimeAction* m_pTwo;
};

bool CCSpawn::initWithTwoActions(this *CCSpawn,CCFiniteTimeAction* pAction1,CCFiniteTimeAction* pAction2);
CCObject* CCSpawn::copyWithZone(this *CCSpawn,CCZone* pZone);
void CCSpawn::startWithTarget(this *CCSpawn,CCNode* pTarget);
void CCSpawn::stop(this *CCSpawn);
void CCSpawn::update(this *CCSpawn,float time);
CCActionInterval* CCSpawn::reverse(this *CCSpawn);
CCSpawn* CCSpawn::create(CCFiniteTimeAction* pAction1);
CCSpawn* CCSpawn::createWithVariableList(CCFiniteTimeAction* pAction1,va_list args);
CCSpawn* CCSpawn::create(CCArray* arrayOfActions);
CCSpawn* CCSpawn::createWithTwoActions(CCFiniteTimeAction* pAction1,CCFiniteTimeAction* pAction2);
struct CCRotateTo{
	float m_fDstAngleX;
	float m_fStartAngleX;
	float m_fDiffAngleX;
	float m_fDstAngleY;
	float m_fStartAngleY;
	float m_fDiffAngleY;
};
CCRotateTo* CCRotateTo::create(float fDuration,float fDeltaAngle);
bool CCRotateTo::initWithDuration(this *CCRotateTo,float fDuration,float fDeltaAngle);
CCRotateTo* CCRotateTo::create(float fDuration,float fDeltaAngleX,float fDeltaAngleY);
bool CCRotateTo::initWithDuration(this *CCRotateTo,float fDuration,float fDeltaAngleX,float fDeltaAngleY);
CCObject* CCRotateTo::copyWithZone(this *CCRotateTo,CCZone* pZone);
void CCRotateTo::startWithTarget(this *CCRotateTo,CCNode* pTarget);
void CCRotateTo::update(this *CCRotateTo,float time);
struct CCRotateBy{
	float m_fAngleX;
	float m_fStartAngleX;
	float m_fAngleY;
	float m_fStartAngleY;
};
CCRotateBy* CCRotateBy::create(float fDuration,float fDeltaAngle);
bool CCRotateBy::initWithDuration(this *CCRotateBy,float fDuration,float fDeltaAngle);
CCRotateBy* CCRotateBy::create(float fDuration,float fDeltaAngleX,float fDeltaAngleY);
bool CCRotateBy::initWithDuration(this *CCRotateBy,float fDuration,float fDeltaAngleX,float fDeltaAngleY);
CCObject* CCRotateBy::copyWithZone(this *CCRotateBy,CCZone* pZone);
void CCRotateBy::startWithTarget(this *CCRotateBy,CCNode* pTarget);
void CCRotateBy::update(this *CCRotateBy,float time);
CCActionInterval* CCRotateBy::reverse(this *CCRotateBy);
struct CCMoveBy{
	CCPoint m_positionDelta;
	CCPoint m_startPosition;
	CCPoint m_previousPosition;
};
bool CCMoveBy::initWithDuration(this *CCMoveBy,float duration,const CCPoint& deltaPosition);
CCObject* CCMoveBy::copyWithZone(this *CCMoveBy,CCZone* pZone);
void CCMoveBy::startWithTarget(this *CCMoveBy,CCNode* pTarget);
CCActionInterval* CCMoveBy::reverse(this *CCMoveBy);
void CCMoveBy::update(this *CCMoveBy,float time);
CCMoveBy* CCMoveBy::create(float duration,const CCPoint& deltaPosition);
struct CCMoveTo{
	CCPoint m_endPosition;
};
bool CCMoveTo::initWithDuration(this *CCMoveTo,float duration,const CCPoint& position);
CCObject* CCMoveTo::copyWithZone(this *CCMoveTo,CCZone* pZone);
void CCMoveTo::startWithTarget(this *CCMoveTo,CCNode* pTarget);
CCMoveTo* CCMoveTo::create(float duration,const CCPoint& position);
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

bool CCSkewTo::initWithDuration(this *CCSkewTo,float t,float sx,float sy);
CCObject* CCSkewTo::copyWithZone(this *CCSkewTo,CCZone* pZone);
void CCSkewTo::startWithTarget(this *CCSkewTo,CCNode* pTarget);
void CCSkewTo::update(this *CCSkewTo,float time);
CCSkewTo* CCSkewTo::create(float t,float sx,float sy);
struct CCSkewBy{
};
bool CCSkewBy::initWithDuration(this *CCSkewBy,float t,float sx,float sy);
void CCSkewBy::startWithTarget(this *CCSkewBy,CCNode* pTarget);
CCActionInterval* CCSkewBy::reverse(this *CCSkewBy);
CCSkewBy* CCSkewBy::create(float t,float deltaSkewX,float deltaSkewY);
struct CCJumpBy{
	CCPoint m_startPosition;
	CCPoint m_delta;
	float m_height;
	unsigned int m_nJumps;
	CCPoint m_previousPos;
};
bool CCJumpBy::initWithDuration(this *CCJumpBy,float duration,const CCPoint& position,float height,unsigned int jumps);
CCObject* CCJumpBy::copyWithZone(this *CCJumpBy,CCZone* pZone);
void CCJumpBy::startWithTarget(this *CCJumpBy,CCNode* pTarget);
void CCJumpBy::update(this *CCJumpBy,float time);
CCActionInterval* CCJumpBy::reverse(this *CCJumpBy);
CCJumpBy* CCJumpBy::create(float duration,const CCPoint& position,float height,unsigned int jumps);
struct CCJumpTo{
};
void CCJumpTo::startWithTarget(this *CCJumpTo,CCNode* pTarget);
CCObject* CCJumpTo::copyWithZone(this *CCJumpTo,CCZone* pZone);
CCJumpTo* CCJumpTo::create(float duration,const CCPoint& position,float height,int jumps);
struct _ccBezierConfig{
	CCPoint endPosition;
	CCPoint controlPoint_1;
	CCPoint controlPoint_2;
};
struct CCBezierBy{
	ccBezierConfig m_sConfig;
	CCPoint m_startPosition;
	CCPoint m_previousPosition;
};
bool CCBezierBy::initWithDuration(this *CCBezierBy,float t,const ccBezierConfig& c);
CCObject* CCBezierBy::copyWithZone(this *CCBezierBy,CCZone* pZone);
void CCBezierBy::startWithTarget(this *CCBezierBy,CCNode* pTarget);
void CCBezierBy::update(this *CCBezierBy,float time);
CCActionInterval* CCBezierBy::reverse(this *CCBezierBy);
CCBezierBy* CCBezierBy::create(float t,const ccBezierConfig& c);
struct CCBezierTo{
	ccBezierConfig m_sToConfig;
};
void CCBezierTo::startWithTarget(this *CCBezierTo,CCNode* pTarget);
CCObject* CCBezierTo::copyWithZone(this *CCBezierTo,CCZone* pZone);
CCBezierTo* CCBezierTo::create(float t,const ccBezierConfig& c);
bool CCBezierTo::initWithDuration(this *CCBezierTo,float t,const ccBezierConfig& c);
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
bool CCScaleTo::initWithDuration(this *CCScaleTo,float duration,float s);
bool CCScaleTo::initWithDuration(this *CCScaleTo,float duration,float sx,float sy);
CCObject* CCScaleTo::copyWithZone(this *CCScaleTo,CCZone* pZone);
void CCScaleTo::startWithTarget(this *CCScaleTo,CCNode* pTarget);
void CCScaleTo::update(this *CCScaleTo,float time);
CCScaleTo* CCScaleTo::create(float duration,float s);
CCScaleTo* CCScaleTo::create(float duration,float sx,float sy);
struct CCScaleBy{
};
void CCScaleBy::startWithTarget(this *CCScaleBy,CCNode* pTarget);
CCActionInterval* CCScaleBy::reverse(this *CCScaleBy);
CCObject* CCScaleBy::copyWithZone(this *CCScaleBy,CCZone* pZone);
CCScaleBy* CCScaleBy::create(float duration,float s);
CCScaleBy* CCScaleBy::create(float duration,float sx,float sy);
struct CCBlink{
	unsigned int m_nTimes;
	bool m_bOriginalState;
};
bool CCBlink::initWithDuration(this *CCBlink,float duration,unsigned int uBlinks);
CCObject* CCBlink::copyWithZone(this *CCBlink,CCZone* pZone);
void CCBlink::update(this *CCBlink,float time);
CCActionInterval* CCBlink::reverse(this *CCBlink);
CCBlink* CCBlink::create(float duration,unsigned int uBlinks);
void CCBlink::startWithTarget(this *CCBlink,CCNode* pTarget);
void CCBlink::stop(this *CCBlink);
struct CCFadeIn{
};
void CCFadeIn::update(this *CCFadeIn,float time);
CCActionInterval* CCFadeIn::reverse(this *CCFadeIn);
CCObject* CCFadeIn::copyWithZone(this *CCFadeIn,CCZone* pZone);
CCFadeIn* CCFadeIn::create(float d);
struct CCFadeOut{
};
void CCFadeOut::update(this *CCFadeOut,float time);
CCActionInterval* CCFadeOut::reverse(this *CCFadeOut);
CCObject* CCFadeOut::copyWithZone(this *CCFadeOut,CCZone* pZone);
CCFadeOut* CCFadeOut::create(float d);
struct CCFadeTo{
	GLubyte m_toOpacity;
	GLubyte m_fromOpacity;
};
bool CCFadeTo::initWithDuration(this *CCFadeTo,float duration,GLubyte opacity);
CCObject* CCFadeTo::copyWithZone(this *CCFadeTo,CCZone* pZone);
void CCFadeTo::startWithTarget(this *CCFadeTo,CCNode* pTarget);
void CCFadeTo::update(this *CCFadeTo,float time);
CCFadeTo* CCFadeTo::create(float duration,GLubyte opacity);
struct CCTintTo{
	ccColor3B m_to;
	ccColor3B m_from;
};
bool CCTintTo::initWithDuration(this *CCTintTo,float duration,GLubyte red,GLubyte green,GLubyte blue);
CCObject* CCTintTo::copyWithZone(this *CCTintTo,CCZone* pZone);
void CCTintTo::startWithTarget(this *CCTintTo,CCNode* pTarget);
void CCTintTo::update(this *CCTintTo,float time);
CCTintTo* CCTintTo::create(float duration,GLubyte red,GLubyte green,GLubyte blue);
struct CCTintBy{
	GLshort m_deltaR;
	GLshort m_deltaG;
	GLshort m_deltaB;
	GLshort m_fromR;
	GLshort m_fromG;
	GLshort m_fromB;
};
bool CCTintBy::initWithDuration(this *CCTintBy,float duration,GLshort deltaRed,GLshort deltaGreen,GLshort deltaBlue);
CCObject* CCTintBy::copyWithZone(this *CCTintBy,CCZone* pZone);
void CCTintBy::startWithTarget(this *CCTintBy,CCNode* pTarget);
void CCTintBy::update(this *CCTintBy,float time);
CCActionInterval* CCTintBy::reverse(this *CCTintBy);
CCTintBy* CCTintBy::create(float duration,GLshort deltaRed,GLshort deltaGreen,GLshort deltaBlue);
struct CCDelayTime{
};
void CCDelayTime::update(this *CCDelayTime,float time);
CCActionInterval* CCDelayTime::reverse(this *CCDelayTime);
CCObject* CCDelayTime::copyWithZone(this *CCDelayTime,CCZone* pZone);
CCDelayTime* CCDelayTime::create(float d);
struct CCReverseTime{
	CCFiniteTimeAction* m_pOther;
};


bool CCReverseTime::initWithAction(this *CCReverseTime,CCFiniteTimeAction* pAction);
CCObject* CCReverseTime::copyWithZone(this *CCReverseTime,CCZone* pZone);
void CCReverseTime::startWithTarget(this *CCReverseTime,CCNode* pTarget);
void CCReverseTime::stop(this *CCReverseTime);
void CCReverseTime::update(this *CCReverseTime,float time);
CCActionInterval* CCReverseTime::reverse(this *CCReverseTime);
CCReverseTime* CCReverseTime::create(CCFiniteTimeAction* pAction);
struct CCAnimate{
	CCAnimation* m_pAnimation;
	std::vector<float>* m_pSplitTimes;
	int m_nNextFrame;
	CCSpriteFrame* m_pOrigFrame;
	unsigned int m_uExecutedLoops;
};


bool CCAnimate::initWithAnimation(this *CCAnimate,CCAnimation* pAnimation);
CCObject* CCAnimate::copyWithZone(this *CCAnimate,CCZone* pZone);
void CCAnimate::startWithTarget(this *CCAnimate,CCNode* pTarget);
void CCAnimate::stop(this *CCAnimate);
void CCAnimate::update(this *CCAnimate,float t);
CCActionInterval* CCAnimate::reverse(this *CCAnimate);
CCAnimate* CCAnimate::create(CCAnimation* pAnimation);
CCAnimation* CCAnimate::getAnimation(this *CCAnimate);
void CCAnimate::setAnimation(this *CCAnimate,CCAnimation* var);
struct CCTargetedAction{
	CCNode* m_pForcedTarget;
	CCFiniteTimeAction* m_pAction;
};


CCTargetedAction* CCTargetedAction::create(CCNode* pTarget,CCFiniteTimeAction* pAction);
bool CCTargetedAction::initWithTarget(this *CCTargetedAction,CCNode* pTarget,CCFiniteTimeAction* pAction);
CCObject* CCTargetedAction::copyWithZone(this *CCTargetedAction,CCZone* pZone);
void CCTargetedAction::startWithTarget(this *CCTargetedAction,CCNode* pTarget);
void CCTargetedAction::stop(this *CCTargetedAction);
void CCTargetedAction::update(this *CCTargetedAction,float time);
CCNode* CCTargetedAction::getForcedTarget(this *CCTargetedAction);
void CCTargetedAction::setForcedTarget(this *CCTargetedAction,CCNode* var);
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


void CCActionCamera::startWithTarget(this *CCActionCamera,CCNode* pTarget);
CCActionInterval* CCActionCamera::reverse(this *CCActionCamera);
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


CCOrbitCamera* CCOrbitCamera::create(float t,float radius,float deltaRadius,float angleZ,float deltaAngleZ,float angleX,float deltaAngleX);
bool CCOrbitCamera::initWithDuration(this *CCOrbitCamera,float t,float radius,float deltaRadius,float angleZ,float deltaAngleZ,float angleX,float deltaAngleX);
void CCOrbitCamera::sphericalRadius(this *CCOrbitCamera,float* r,float* zenith,float* azimuth);
CCObject* CCOrbitCamera::copyWithZone(this *CCOrbitCamera,CCZone* pZone);
void CCOrbitCamera::startWithTarget(this *CCOrbitCamera,CCNode* pTarget);
void CCOrbitCamera::update(this *CCOrbitCamera,float time);
struct CCActionManager{
	struct _hashElement* m_pTargets;
	struct _hashElement* m_pCurrentTarget;
	bool m_bCurrentTargetSalvaged;
};


void CCActionManager::addAction(this *CCActionManager,CCAction* pAction,CCNode* pTarget,bool paused);
void CCActionManager::removeAllActions(this *CCActionManager);
void CCActionManager::removeAllActionsFromTarget(this *CCActionManager,CCObject* pTarget);
void CCActionManager::removeAction(this *CCActionManager,CCAction* pAction);
void CCActionManager::removeActionByTag(this *CCActionManager,unsigned int tag,CCObject* pTarget);
CCAction* CCActionManager::getActionByTag(this *CCActionManager,unsigned int tag,CCObject* pTarget);
unsigned int CCActionManager::numberOfRunningActionsInTarget(this *CCActionManager,CCObject* pTarget);
void CCActionManager::pauseTarget(this *CCActionManager,CCObject* pTarget);
void CCActionManager::resumeTarget(this *CCActionManager,CCObject* pTarget);
CCSet* CCActionManager::pauseAllRunningActions(this *CCActionManager);
void CCActionManager::resumeTargets(this *CCActionManager,CCSet* targetsToResume);
void CCActionManager::removeActionAtIndex(this *CCActionManager,unsigned int uIndex,struct _hashElement* pElement);
void CCActionManager::deleteHashElement(this *CCActionManager,struct _hashElement* pElement);
void CCActionManager::actionAllocWithHashElement(this *CCActionManager,struct _hashElement* pElement);
void CCActionManager::update(this *CCActionManager,float dt);
struct CCActionEase{
	CCActionInterval* m_pInner;
};

bool CCActionEase::initWithAction(this *CCActionEase,CCActionInterval* pAction);
CCObject* CCActionEase::copyWithZone(this *CCActionEase,CCZone* pZone);
void CCActionEase::startWithTarget(this *CCActionEase,CCNode* pTarget);
void CCActionEase::stop(this *CCActionEase);
void CCActionEase::update(this *CCActionEase,float time);
CCActionInterval* CCActionEase::reverse(this *CCActionEase);
CCActionInterval* CCActionEase::getInnerAction(this *CCActionEase);
CCActionEase* CCActionEase::create(CCActionInterval* pAction);
struct CCEaseRateAction{
	float m_fRate;
};

void CCEaseRateAction::setRate(this *CCEaseRateAction,float rate);
float CCEaseRateAction::getRate(this *CCEaseRateAction);
bool CCEaseRateAction::initWithAction(this *CCEaseRateAction,CCActionInterval* pAction,float fRate);
CCObject* CCEaseRateAction::copyWithZone(this *CCEaseRateAction,CCZone* pZone);
CCActionInterval* CCEaseRateAction::reverse(this *CCEaseRateAction);
CCEaseRateAction* CCEaseRateAction::create(CCActionInterval* pAction,float fRate);
struct CCEaseIn{
};
void CCEaseIn::update(this *CCEaseIn,float time);
CCActionInterval* CCEaseIn::reverse(this *CCEaseIn);
CCObject* CCEaseIn::copyWithZone(this *CCEaseIn,CCZone* pZone);
CCEaseIn* CCEaseIn::create(CCActionInterval* pAction,float fRate);
struct CCEaseOut{
};
void CCEaseOut::update(this *CCEaseOut,float time);
CCActionInterval* CCEaseOut::reverse(this *CCEaseOut);
CCObject* CCEaseOut::copyWithZone(this *CCEaseOut,CCZone* pZone);
CCEaseOut* CCEaseOut::create(CCActionInterval* pAction,float fRate);
struct CCEaseInOut{
};
void CCEaseInOut::update(this *CCEaseInOut,float time);
CCObject* CCEaseInOut::copyWithZone(this *CCEaseInOut,CCZone* pZone);
CCActionInterval* CCEaseInOut::reverse(this *CCEaseInOut);
CCEaseInOut* CCEaseInOut::create(CCActionInterval* pAction,float fRate);
struct CCEaseExponentialIn{
};
void CCEaseExponentialIn::update(this *CCEaseExponentialIn,float time);
CCActionInterval* CCEaseExponentialIn::reverse(this *CCEaseExponentialIn);
CCObject* CCEaseExponentialIn::copyWithZone(this *CCEaseExponentialIn,CCZone* pZone);
CCEaseExponentialIn* CCEaseExponentialIn::create(CCActionInterval* pAction);
struct CCEaseExponentialOut{
};
void CCEaseExponentialOut::update(this *CCEaseExponentialOut,float time);
CCActionInterval* CCEaseExponentialOut::reverse(this *CCEaseExponentialOut);
CCObject* CCEaseExponentialOut::copyWithZone(this *CCEaseExponentialOut,CCZone* pZone);
CCEaseExponentialOut* CCEaseExponentialOut::create(CCActionInterval* pAction);
struct CCEaseExponentialInOut{
};
void CCEaseExponentialInOut::update(this *CCEaseExponentialInOut,float time);
CCObject* CCEaseExponentialInOut::copyWithZone(this *CCEaseExponentialInOut,CCZone* pZone);
CCActionInterval* CCEaseExponentialInOut::reverse(this *CCEaseExponentialInOut);
CCEaseExponentialInOut* CCEaseExponentialInOut::create(CCActionInterval* pAction);
struct CCEaseSineIn{
};
void CCEaseSineIn::update(this *CCEaseSineIn,float time);
CCActionInterval* CCEaseSineIn::reverse(this *CCEaseSineIn);
CCObject* CCEaseSineIn::copyWithZone(this *CCEaseSineIn,CCZone* pZone);
CCEaseSineIn* CCEaseSineIn::create(CCActionInterval* pAction);
struct CCEaseSineOut{
};
void CCEaseSineOut::update(this *CCEaseSineOut,float time);
CCActionInterval* CCEaseSineOut::reverse(this *CCEaseSineOut);
CCObject* CCEaseSineOut::copyWithZone(this *CCEaseSineOut,CCZone* pZone);
CCEaseSineOut* CCEaseSineOut::create(CCActionInterval* pAction);
struct CCEaseSineInOut{
};
void CCEaseSineInOut::update(this *CCEaseSineInOut,float time);
CCObject* CCEaseSineInOut::copyWithZone(this *CCEaseSineInOut,CCZone* pZone);
CCActionInterval* CCEaseSineInOut::reverse(this *CCEaseSineInOut);
CCEaseSineInOut* CCEaseSineInOut::create(CCActionInterval* pAction);
struct CCEaseElastic{
	float m_fPeriod;
};
float CCEaseElastic::getPeriod(this *CCEaseElastic);
void CCEaseElastic::setPeriod(this *CCEaseElastic,float fPeriod);
bool CCEaseElastic::initWithAction(this *CCEaseElastic,CCActionInterval* pAction,float fPeriod);
CCActionInterval* CCEaseElastic::reverse(this *CCEaseElastic);
CCObject* CCEaseElastic::copyWithZone(this *CCEaseElastic,CCZone* pZone);
CCEaseElastic* CCEaseElastic::create(CCActionInterval* pAction,float fPeriod);
CCEaseElastic* CCEaseElastic::create(CCActionInterval* pAction);
struct CCEaseElasticIn{
};
void CCEaseElasticIn::update(this *CCEaseElasticIn,float time);
CCActionInterval* CCEaseElasticIn::reverse(this *CCEaseElasticIn);
CCObject* CCEaseElasticIn::copyWithZone(this *CCEaseElasticIn,CCZone* pZone);
CCEaseElasticIn* CCEaseElasticIn::create(CCActionInterval* pAction,float fPeriod);
CCEaseElasticIn* CCEaseElasticIn::create(CCActionInterval* pAction);
struct CCEaseElasticOut{
};
void CCEaseElasticOut::update(this *CCEaseElasticOut,float time);
CCActionInterval* CCEaseElasticOut::reverse(this *CCEaseElasticOut);
CCObject* CCEaseElasticOut::copyWithZone(this *CCEaseElasticOut,CCZone* pZone);
CCEaseElasticOut* CCEaseElasticOut::create(CCActionInterval* pAction,float fPeriod);
CCEaseElasticOut* CCEaseElasticOut::create(CCActionInterval* pAction);
struct CCEaseElasticInOut{
};
void CCEaseElasticInOut::update(this *CCEaseElasticInOut,float time);
CCActionInterval* CCEaseElasticInOut::reverse(this *CCEaseElasticInOut);
CCObject* CCEaseElasticInOut::copyWithZone(this *CCEaseElasticInOut,CCZone* pZone);
CCEaseElasticInOut* CCEaseElasticInOut::create(CCActionInterval* pAction,float fPeriod);
CCEaseElasticInOut* CCEaseElasticInOut::create(CCActionInterval* pAction);
struct CCEaseBounce{
};
float CCEaseBounce::bounceTime(this *CCEaseBounce,float time);
CCObject* CCEaseBounce::copyWithZone(this *CCEaseBounce,CCZone* pZone);
CCActionInterval* CCEaseBounce::reverse(this *CCEaseBounce);
CCEaseBounce* CCEaseBounce::create(CCActionInterval* pAction);
struct CCEaseBounceIn{
};
void CCEaseBounceIn::update(this *CCEaseBounceIn,float time);
CCActionInterval* CCEaseBounceIn::reverse(this *CCEaseBounceIn);
CCObject* CCEaseBounceIn::copyWithZone(this *CCEaseBounceIn,CCZone* pZone);
CCEaseBounceIn* CCEaseBounceIn::create(CCActionInterval* pAction);
struct CCEaseBounceOut{
};
void CCEaseBounceOut::update(this *CCEaseBounceOut,float time);
CCActionInterval* CCEaseBounceOut::reverse(this *CCEaseBounceOut);
CCObject* CCEaseBounceOut::copyWithZone(this *CCEaseBounceOut,CCZone* pZone);
CCEaseBounceOut* CCEaseBounceOut::create(CCActionInterval* pAction);
struct CCEaseBounceInOut{
};
void CCEaseBounceInOut::update(this *CCEaseBounceInOut,float time);
CCObject* CCEaseBounceInOut::copyWithZone(this *CCEaseBounceInOut,CCZone* pZone);
CCActionInterval* CCEaseBounceInOut::reverse(this *CCEaseBounceInOut);
CCEaseBounceInOut* CCEaseBounceInOut::create(CCActionInterval* pAction);
struct CCEaseBackIn{
};
void CCEaseBackIn::update(this *CCEaseBackIn,float time);
CCActionInterval* CCEaseBackIn::reverse(this *CCEaseBackIn);
CCObject* CCEaseBackIn::copyWithZone(this *CCEaseBackIn,CCZone* pZone);
CCEaseBackIn* CCEaseBackIn::create(CCActionInterval* pAction);
struct CCEaseBackOut{
};
void CCEaseBackOut::update(this *CCEaseBackOut,float time);
CCActionInterval* CCEaseBackOut::reverse(this *CCEaseBackOut);
CCObject* CCEaseBackOut::copyWithZone(this *CCEaseBackOut,CCZone* pZone);
CCEaseBackOut* CCEaseBackOut::create(CCActionInterval* pAction);
struct CCEaseBackInOut{
};
void CCEaseBackInOut::update(this *CCEaseBackInOut,float time);
CCObject* CCEaseBackInOut::copyWithZone(this *CCEaseBackInOut,CCZone* pZone);
CCActionInterval* CCEaseBackInOut::reverse(this *CCEaseBackInOut);
CCEaseBackInOut* CCEaseBackInOut::create(CCActionInterval* pAction);
struct TypeInfo{
};
long TypeInfo::getClassTypeInfo(this *TypeInfo);
struct CCActionInstant{
};


CCObject* CCActionInstant::copyWithZone(this *CCActionInstant,CCZone* pZone);
bool CCActionInstant::isDone(this *CCActionInstant);
void CCActionInstant::step(this *CCActionInstant,float dt);
void CCActionInstant::update(this *CCActionInstant,float time);
CCFiniteTimeAction* CCActionInstant::reverse(this *CCActionInstant);
struct CCShow{
};


void CCShow::update(this *CCShow,float time);
CCFiniteTimeAction* CCShow::reverse(this *CCShow);
CCObject* CCShow::copyWithZone(this *CCShow,CCZone* pZone);
CCShow* CCShow::create();
struct CCHide{
};


void CCHide::update(this *CCHide,float time);
CCFiniteTimeAction* CCHide::reverse(this *CCHide);
CCObject* CCHide::copyWithZone(this *CCHide,CCZone* pZone);
CCHide* CCHide::create();
struct CCToggleVisibility{
};


void CCToggleVisibility::update(this *CCToggleVisibility,float time);
CCObject* CCToggleVisibility::copyWithZone(this *CCToggleVisibility,CCZone* pZone);
CCToggleVisibility* CCToggleVisibility::create();
struct CCRemoveSelf{
	bool m_bIsNeedCleanUp;
};


void CCRemoveSelf::update(this *CCRemoveSelf,float time);
CCFiniteTimeAction* CCRemoveSelf::reverse(this *CCRemoveSelf);
CCObject* CCRemoveSelf::copyWithZone(this *CCRemoveSelf,CCZone* pZone);
CCRemoveSelf* CCRemoveSelf::create(bool isNeedCleanUp);
bool CCRemoveSelf::init(this *CCRemoveSelf,bool isNeedCleanUp);
struct CCFlipX{
	bool m_bFlipX;
};


CCFlipX* CCFlipX::create(bool x);
bool CCFlipX::initWithFlipX(this *CCFlipX,bool x);
void CCFlipX::update(this *CCFlipX,float time);
CCFiniteTimeAction* CCFlipX::reverse(this *CCFlipX);
CCObject* CCFlipX::copyWithZone(this *CCFlipX,CCZone* pZone);
struct CCFlipY{
	bool m_bFlipY;
};


CCFlipY* CCFlipY::create(bool y);
bool CCFlipY::initWithFlipY(this *CCFlipY,bool y);
void CCFlipY::update(this *CCFlipY,float time);
CCFiniteTimeAction* CCFlipY::reverse(this *CCFlipY);
CCObject* CCFlipY::copyWithZone(this *CCFlipY,CCZone* pZone);
struct CCPlace{
	CCPoint m_tPosition;
};


CCPlace* CCPlace::create(const CCPoint& pos);
bool CCPlace::initWithPosition(this *CCPlace,const CCPoint& pos);
void CCPlace::update(this *CCPlace,float time);
CCObject* CCPlace::copyWithZone(this *CCPlace,CCZone* pZone);
struct CCCallFunc{
	CCObject* m_pSelectorTarget;
	int m_nScriptHandler;
	SEL_CallFunc m_pCallFunc;
	SEL_CallFuncN m_pCallFuncN;
	SEL_CallFuncND m_pCallFuncND;
	SEL_CallFuncO m_pCallFuncO;
};


CCCallFunc* CCCallFunc::create(CCObject* pSelectorTarget,SEL_CallFunc selector);
CCCallFunc* CCCallFunc::create(int nHandler);
bool CCCallFunc::initWithTarget(this *CCCallFunc,CCObject* pSelectorTarget);
void CCCallFunc::execute(this *CCCallFunc);
void CCCallFunc::update(this *CCCallFunc,float time);
CCObject* CCCallFunc::copyWithZone(this *CCCallFunc,CCZone* pZone);
CCObject* CCCallFunc::getTargetCallback(this *CCCallFunc);
void CCCallFunc::setTargetCallback(this *CCCallFunc,CCObject* pSel);
int CCCallFunc::getScriptHandler(this *CCCallFunc);
struct CCCallFuncN{
};


long CCCallFuncN::getClassTypeInfo(this *CCCallFuncN);
CCCallFuncN* CCCallFuncN::create(CCObject* pSelectorTarget,SEL_CallFuncN selector);
CCCallFuncN* CCCallFuncN::create(int nHandler);
bool CCCallFuncN::initWithTarget(this *CCCallFuncN,CCObject* pSelectorTarget,SEL_CallFuncN selector);
CCObject* CCCallFuncN::copyWithZone(this *CCCallFuncN,CCZone* pZone);
void CCCallFuncN::execute(this *CCCallFuncN);
struct CCCallFuncND{
	void* m_pData;
};
long CCCallFuncND::getClassTypeInfo(this *CCCallFuncND);
CCCallFuncND* CCCallFuncND::create(CCObject* pSelectorTarget,SEL_CallFuncND selector,void* d);
bool CCCallFuncND::initWithTarget(this *CCCallFuncND,CCObject* pSelectorTarget,SEL_CallFuncND selector,void* d);
CCObject* CCCallFuncND::copyWithZone(this *CCCallFuncND,CCZone* pZone);
void CCCallFuncND::execute(this *CCCallFuncND);
struct CCCallFuncO{
	CCObject* m_pObject;
};


long CCCallFuncO::getClassTypeInfo(this *CCCallFuncO);
CCCallFuncO* CCCallFuncO::create(CCObject* pSelectorTarget,SEL_CallFuncO selector,CCObject* pObject);
bool CCCallFuncO::initWithTarget(this *CCCallFuncO,CCObject* pSelectorTarget,SEL_CallFuncO selector,CCObject* pObject);
CCObject* CCCallFuncO::copyWithZone(this *CCCallFuncO,CCZone* pZone);
void CCCallFuncO::execute(this *CCCallFuncO);
CCObject* CCCallFuncO::getObject(this *CCCallFuncO);
void CCCallFuncO::setObject(this *CCCallFuncO,CCObject* pObj);
struct CCGridAction{
	CCSize m_sGridSize;
};
CCObject* CCGridAction::copyWithZone(this *CCGridAction,CCZone* pZone);
void CCGridAction::startWithTarget(this *CCGridAction,CCNode* pTarget);
CCActionInterval* CCGridAction::reverse(this *CCGridAction);
bool CCGridAction::initWithDuration(this *CCGridAction,float duration,const CCSize& gridSize);
CCGridBase* CCGridAction::getGrid(this *CCGridAction);
CCGridAction* CCGridAction::create(float duration,const CCSize& gridSize);
struct CCGrid3DAction{
};
CCGridBase* CCGrid3DAction::getGrid(this *CCGrid3DAction);
ccVertex3F CCGrid3DAction::vertex(this *CCGrid3DAction,const CCPoint& position);
ccVertex3F CCGrid3DAction::originalVertex(this *CCGrid3DAction,const CCPoint& position);
void CCGrid3DAction::setVertex(this *CCGrid3DAction,const CCPoint& position,const ccVertex3F& vertex);
CCGrid3DAction* CCGrid3DAction::create(float duration,const CCSize& gridSize);
struct CCTiledGrid3DAction{
};
ccQuad3 CCTiledGrid3DAction::tile(this *CCTiledGrid3DAction,const CCPoint& position);
ccQuad3 CCTiledGrid3DAction::originalTile(this *CCTiledGrid3DAction,const CCPoint& position);
void CCTiledGrid3DAction::setTile(this *CCTiledGrid3DAction,const CCPoint& position,const ccQuad3& coords);
CCGridBase* CCTiledGrid3DAction::getGrid(this *CCTiledGrid3DAction);
CCTiledGrid3DAction* CCTiledGrid3DAction::create(float duration,const CCSize& gridSize);
struct CCAccelDeccelAmplitude{
	float m_fRate;
	CCActionInterval* m_pOther;
};

bool CCAccelDeccelAmplitude::initWithAction(this *CCAccelDeccelAmplitude,CCAction* pAction,float duration);
void CCAccelDeccelAmplitude::startWithTarget(this *CCAccelDeccelAmplitude,CCNode* pTarget);
void CCAccelDeccelAmplitude::update(this *CCAccelDeccelAmplitude,float time);
CCActionInterval* CCAccelDeccelAmplitude::reverse(this *CCAccelDeccelAmplitude);
float CCAccelDeccelAmplitude::getRate(this *CCAccelDeccelAmplitude);
void CCAccelDeccelAmplitude::setRate(this *CCAccelDeccelAmplitude,float fRate);
CCAccelDeccelAmplitude* CCAccelDeccelAmplitude::create(CCAction* pAction,float duration);
struct CCAccelAmplitude{
	float m_fRate;
	CCActionInterval* m_pOther;
};

bool CCAccelAmplitude::initWithAction(this *CCAccelAmplitude,CCAction* pAction,float duration);
float CCAccelAmplitude::getRate(this *CCAccelAmplitude);
void CCAccelAmplitude::setRate(this *CCAccelAmplitude,float fRate);
void CCAccelAmplitude::startWithTarget(this *CCAccelAmplitude,CCNode* pTarget);
void CCAccelAmplitude::update(this *CCAccelAmplitude,float time);
CCActionInterval* CCAccelAmplitude::reverse(this *CCAccelAmplitude);
CCAccelAmplitude* CCAccelAmplitude::create(CCAction* pAction,float duration);
struct CCDeccelAmplitude{
	float m_fRate;
	CCActionInterval* m_pOther;
};

bool CCDeccelAmplitude::initWithAction(this *CCDeccelAmplitude,CCAction* pAction,float duration);
float CCDeccelAmplitude::getRate(this *CCDeccelAmplitude);
void CCDeccelAmplitude::setRate(this *CCDeccelAmplitude,float fRate);
void CCDeccelAmplitude::startWithTarget(this *CCDeccelAmplitude,CCNode* pTarget);
void CCDeccelAmplitude::update(this *CCDeccelAmplitude,float time);
CCActionInterval* CCDeccelAmplitude::reverse(this *CCDeccelAmplitude);
CCDeccelAmplitude* CCDeccelAmplitude::create(CCAction* pAction,float duration);
struct CCStopGrid{
};
void CCStopGrid::startWithTarget(this *CCStopGrid,CCNode* pTarget);
CCStopGrid* CCStopGrid::create();
struct CCReuseGrid{
	int m_nTimes;
};
bool CCReuseGrid::initWithTimes(this *CCReuseGrid,int times);
void CCReuseGrid::startWithTarget(this *CCReuseGrid,CCNode* pTarget);
CCReuseGrid* CCReuseGrid::create(int times);
struct CCWaves3D{
	unsigned int m_nWaves;
	float m_fAmplitude;
	float m_fAmplitudeRate;
};
float CCWaves3D::getAmplitude(this *CCWaves3D);
void CCWaves3D::setAmplitude(this *CCWaves3D,float fAmplitude);
float CCWaves3D::getAmplitudeRate(this *CCWaves3D);
void CCWaves3D::setAmplitudeRate(this *CCWaves3D,float fAmplitudeRate);
bool CCWaves3D::initWithDuration(this *CCWaves3D,float duration,const CCSize& gridSize,unsigned int waves,float amplitude);
CCObject* CCWaves3D::copyWithZone(this *CCWaves3D,CCZone* pZone);
void CCWaves3D::update(this *CCWaves3D,float time);
CCWaves3D* CCWaves3D::create(float duration,const CCSize& gridSize,unsigned int waves,float amplitude);
struct CCFlipX3D{
};
bool CCFlipX3D::initWithDuration(this *CCFlipX3D,float duration);
bool CCFlipX3D::initWithSize(this *CCFlipX3D,const CCSize& gridSize,float duration);
CCObject* CCFlipX3D::copyWithZone(this *CCFlipX3D,CCZone* pZone);
void CCFlipX3D::update(this *CCFlipX3D,float time);
CCFlipX3D* CCFlipX3D::create(float duration);
struct CCFlipY3D{
};
void CCFlipY3D::update(this *CCFlipY3D,float time);
CCObject* CCFlipY3D::copyWithZone(this *CCFlipY3D,CCZone* pZone);
CCFlipY3D* CCFlipY3D::create(float duration);
struct CCLens3D{
	CCPoint m_position;
	float m_fRadius;
	float m_fLensEffect;
	bool m_bConcave;
	bool m_bDirty;
};
float CCLens3D::getLensEffect(this *CCLens3D);
void CCLens3D::setLensEffect(this *CCLens3D,float fLensEffect);
void CCLens3D::setConcave(this *CCLens3D,bool bConcave);
const CCPoint& CCLens3D::getPosition(this *CCLens3D);
void CCLens3D::setPosition(this *CCLens3D,const CCPoint& position);
bool CCLens3D::initWithDuration(this *CCLens3D,float duration,const CCSize& gridSize,const CCPoint& position,float radius);
CCObject* CCLens3D::copyWithZone(this *CCLens3D,CCZone* pZone);
void CCLens3D::update(this *CCLens3D,float time);
CCLens3D* CCLens3D::create(float duration,const CCSize& gridSize,const CCPoint& position,float radius);
struct CCRipple3D{
	CCPoint m_position;
	float m_fRadius;
	unsigned int m_nWaves;
	float m_fAmplitude;
	float m_fAmplitudeRate;
};
const CCPoint& CCRipple3D::getPosition(this *CCRipple3D);
void CCRipple3D::setPosition(this *CCRipple3D,const CCPoint& position);
float CCRipple3D::getAmplitude(this *CCRipple3D);
void CCRipple3D::setAmplitude(this *CCRipple3D,float fAmplitude);
float CCRipple3D::getAmplitudeRate(this *CCRipple3D);
void CCRipple3D::setAmplitudeRate(this *CCRipple3D,float fAmplitudeRate);
bool CCRipple3D::initWithDuration(this *CCRipple3D,float duration,const CCSize& gridSize,const CCPoint& position,float radius,unsigned int waves,float amplitude);
CCObject* CCRipple3D::copyWithZone(this *CCRipple3D,CCZone* pZone);
void CCRipple3D::update(this *CCRipple3D,float time);
CCRipple3D* CCRipple3D::create(float duration,const CCSize& gridSize,const CCPoint& position,float radius,unsigned int waves,float amplitude);
struct CCShaky3D{
	int m_nRandrange;
	bool m_bShakeZ;
};
bool CCShaky3D::initWithDuration(this *CCShaky3D,float duration,const CCSize& gridSize,int range,bool shakeZ);
CCObject* CCShaky3D::copyWithZone(this *CCShaky3D,CCZone* pZone);
void CCShaky3D::update(this *CCShaky3D,float time);
CCShaky3D* CCShaky3D::create(float duration,const CCSize& gridSize,int range,bool shakeZ);
struct CCLiquid{
	unsigned int m_nWaves;
	float m_fAmplitude;
	float m_fAmplitudeRate;
};
float CCLiquid::getAmplitude(this *CCLiquid);
void CCLiquid::setAmplitude(this *CCLiquid,float fAmplitude);
float CCLiquid::getAmplitudeRate(this *CCLiquid);
void CCLiquid::setAmplitudeRate(this *CCLiquid,float fAmplitudeRate);
bool CCLiquid::initWithDuration(this *CCLiquid,float duration,const CCSize& gridSize,unsigned int waves,float amplitude);
CCObject* CCLiquid::copyWithZone(this *CCLiquid,CCZone* pZone);
void CCLiquid::update(this *CCLiquid,float time);
CCLiquid* CCLiquid::create(float duration,const CCSize& gridSize,unsigned int waves,float amplitude);
struct CCWaves{
	unsigned int m_nWaves;
	float m_fAmplitude;
	float m_fAmplitudeRate;
	bool m_bVertical;
	bool m_bHorizontal;
};
float CCWaves::getAmplitude(this *CCWaves);
void CCWaves::setAmplitude(this *CCWaves,float fAmplitude);
float CCWaves::getAmplitudeRate(this *CCWaves);
void CCWaves::setAmplitudeRate(this *CCWaves,float fAmplitudeRate);
bool CCWaves::initWithDuration(this *CCWaves,float duration,const CCSize& gridSize,unsigned int waves,float amplitude,bool horizontal,bool vertical);
CCObject* CCWaves::copyWithZone(this *CCWaves,CCZone* pZone);
void CCWaves::update(this *CCWaves,float time);
CCWaves* CCWaves::create(float duration,const CCSize& gridSize,unsigned int waves,float amplitude,bool horizontal,bool vertical);
struct CCTwirl{
	CCPoint m_position;
	unsigned int m_nTwirls;
	float m_fAmplitude;
	float m_fAmplitudeRate;
};
const CCPoint& CCTwirl::getPosition(this *CCTwirl);
void CCTwirl::setPosition(this *CCTwirl,const CCPoint& position);
float CCTwirl::getAmplitude(this *CCTwirl);
void CCTwirl::setAmplitude(this *CCTwirl,float fAmplitude);
float CCTwirl::getAmplitudeRate(this *CCTwirl);
void CCTwirl::setAmplitudeRate(this *CCTwirl,float fAmplitudeRate);
bool CCTwirl::initWithDuration(this *CCTwirl,float duration,const CCSize& gridSize,CCPoint position,unsigned int twirls,float amplitude);
CCObject* CCTwirl::copyWithZone(this *CCTwirl,CCZone* pZone);
void CCTwirl::update(this *CCTwirl,float time);
CCTwirl* CCTwirl::create(float duration,const CCSize& gridSize,CCPoint position,unsigned int twirls,float amplitude);
struct CCPageTurn3D{
};
void CCPageTurn3D::update(this *CCPageTurn3D,float time);
CCPageTurn3D* CCPageTurn3D::create(float duration,const CCSize& gridSize);
struct CCProgressTo{
	float m_fTo;
	float m_fFrom;
};
bool CCProgressTo::initWithDuration(this *CCProgressTo,float duration,float fPercent);
CCObject* CCProgressTo::copyWithZone(this *CCProgressTo,CCZone* pZone);
void CCProgressTo::startWithTarget(this *CCProgressTo,CCNode* pTarget);
void CCProgressTo::update(this *CCProgressTo,float time);
CCProgressTo* CCProgressTo::create(float duration,float fPercent);
struct CCProgressFromTo{
	float m_fTo;
	float m_fFrom;
};
bool CCProgressFromTo::initWithDuration(this *CCProgressFromTo,float duration,float fFromPercentage,float fToPercentage);
CCObject* CCProgressFromTo::copyWithZone(this *CCProgressFromTo,CCZone* pZone);
CCActionInterval* CCProgressFromTo::reverse(this *CCProgressFromTo);
void CCProgressFromTo::startWithTarget(this *CCProgressFromTo,CCNode* pTarget);
void CCProgressFromTo::update(this *CCProgressFromTo,float time);
CCProgressFromTo* CCProgressFromTo::create(float duration,float fFromPercentage,float fToPercentage);
struct CCShakyTiles3D{
	int m_nRandrange;
	bool m_bShakeZ;
};
bool CCShakyTiles3D::initWithDuration(this *CCShakyTiles3D,float duration,const CCSize& gridSize,int nRange,bool bShakeZ);
CCObject* CCShakyTiles3D::copyWithZone(this *CCShakyTiles3D,CCZone* pZone);
void CCShakyTiles3D::update(this *CCShakyTiles3D,float time);
CCShakyTiles3D* CCShakyTiles3D::create(float duration,const CCSize& gridSize,int nRange,bool bShakeZ);
struct CCShatteredTiles3D{
	int m_nRandrange;
	bool m_bOnce;
	bool m_bShatterZ;
};
bool CCShatteredTiles3D::initWithDuration(this *CCShatteredTiles3D,float duration,const CCSize& gridSize,int nRange,bool bShatterZ);
CCObject* CCShatteredTiles3D::copyWithZone(this *CCShatteredTiles3D,CCZone* pZone);
void CCShatteredTiles3D::update(this *CCShatteredTiles3D,float time);
CCShatteredTiles3D* CCShatteredTiles3D::create(float duration,const CCSize& gridSize,int nRange,bool bShatterZ);
struct CCShuffleTiles{
	unsigned int m_nSeed;
	unsigned int m_nTilesCount;
	unsigned int* m_pTilesOrder;
	Tile* m_pTiles;
};

bool CCShuffleTiles::initWithDuration(this *CCShuffleTiles,float duration,const CCSize& gridSize,unsigned int seed);
void CCShuffleTiles::shuffle(this *CCShuffleTiles,unsigned int* pArray,unsigned int nLen);
CCSize CCShuffleTiles::getDelta(this *CCShuffleTiles,const CCSize& pos);
void CCShuffleTiles::placeTile(this *CCShuffleTiles,const CCPoint& pos,Tile* t);
void CCShuffleTiles::startWithTarget(this *CCShuffleTiles,CCNode* pTarget);
void CCShuffleTiles::update(this *CCShuffleTiles,float time);
CCObject* CCShuffleTiles::copyWithZone(this *CCShuffleTiles,CCZone* pZone);
CCShuffleTiles* CCShuffleTiles::create(float duration,const CCSize& gridSize,unsigned int seed);
struct CCFadeOutTRTiles{
};
float CCFadeOutTRTiles::testFunc(this *CCFadeOutTRTiles,const CCSize& pos,float time);
void CCFadeOutTRTiles::turnOnTile(this *CCFadeOutTRTiles,const CCPoint& pos);
void CCFadeOutTRTiles::turnOffTile(this *CCFadeOutTRTiles,const CCPoint& pos);
void CCFadeOutTRTiles::transformTile(this *CCFadeOutTRTiles,const CCPoint& pos,float distance);
void CCFadeOutTRTiles::update(this *CCFadeOutTRTiles,float time);
CCFadeOutTRTiles* CCFadeOutTRTiles::create(float duration,const CCSize& gridSize);
struct CCFadeOutBLTiles{
};
float CCFadeOutBLTiles::testFunc(this *CCFadeOutBLTiles,const CCSize& pos,float time);
CCFadeOutBLTiles* CCFadeOutBLTiles::create(float duration,const CCSize& gridSize);
struct CCFadeOutUpTiles{
};
float CCFadeOutUpTiles::testFunc(this *CCFadeOutUpTiles,const CCSize& pos,float time);
void CCFadeOutUpTiles::transformTile(this *CCFadeOutUpTiles,const CCPoint& pos,float distance);
CCFadeOutUpTiles* CCFadeOutUpTiles::create(float duration,const CCSize& gridSize);
struct CCFadeOutDownTiles{
};
float CCFadeOutDownTiles::testFunc(this *CCFadeOutDownTiles,const CCSize& pos,float time);
CCFadeOutDownTiles* CCFadeOutDownTiles::create(float duration,const CCSize& gridSize);
struct CCTurnOffTiles{
	unsigned int m_nSeed;
	unsigned int m_nTilesCount;
	unsigned int* m_pTilesOrder;
};

bool CCTurnOffTiles::initWithDuration(this *CCTurnOffTiles,float duration,const CCSize& gridSize,unsigned int seed);
void CCTurnOffTiles::shuffle(this *CCTurnOffTiles,unsigned int* pArray,unsigned int nLen);
void CCTurnOffTiles::turnOnTile(this *CCTurnOffTiles,const CCPoint& pos);
void CCTurnOffTiles::turnOffTile(this *CCTurnOffTiles,const CCPoint& pos);
CCObject* CCTurnOffTiles::copyWithZone(this *CCTurnOffTiles,CCZone* pZone);
void CCTurnOffTiles::startWithTarget(this *CCTurnOffTiles,CCNode* pTarget);
void CCTurnOffTiles::update(this *CCTurnOffTiles,float time);
CCTurnOffTiles* CCTurnOffTiles::create(float duration,const CCSize& gridSize);
CCTurnOffTiles* CCTurnOffTiles::create(float duration,const CCSize& gridSize,unsigned int seed);
struct CCWavesTiles3D{
	unsigned int m_nWaves;
	float m_fAmplitude;
	float m_fAmplitudeRate;
};
float CCWavesTiles3D::getAmplitude(this *CCWavesTiles3D);
void CCWavesTiles3D::setAmplitude(this *CCWavesTiles3D,float fAmplitude);
float CCWavesTiles3D::getAmplitudeRate(this *CCWavesTiles3D);
void CCWavesTiles3D::setAmplitudeRate(this *CCWavesTiles3D,float fAmplitudeRate);
bool CCWavesTiles3D::initWithDuration(this *CCWavesTiles3D,float duration,const CCSize& gridSize,unsigned int waves,float amplitude);
CCObject* CCWavesTiles3D::copyWithZone(this *CCWavesTiles3D,CCZone* pZone);
void CCWavesTiles3D::update(this *CCWavesTiles3D,float time);
CCWavesTiles3D* CCWavesTiles3D::create(float duration,const CCSize& gridSize,unsigned int waves,float amplitude);
struct CCJumpTiles3D{
	unsigned int m_nJumps;
	float m_fAmplitude;
	float m_fAmplitudeRate;
};
float CCJumpTiles3D::getAmplitude(this *CCJumpTiles3D);
void CCJumpTiles3D::setAmplitude(this *CCJumpTiles3D,float fAmplitude);
float CCJumpTiles3D::getAmplitudeRate(this *CCJumpTiles3D);
void CCJumpTiles3D::setAmplitudeRate(this *CCJumpTiles3D,float fAmplitudeRate);
bool CCJumpTiles3D::initWithDuration(this *CCJumpTiles3D,float duration,const CCSize& gridSize,unsigned int numberOfJumps,float amplitude);
CCObject* CCJumpTiles3D::copyWithZone(this *CCJumpTiles3D,CCZone* pZone);
void CCJumpTiles3D::update(this *CCJumpTiles3D,float time);
CCJumpTiles3D* CCJumpTiles3D::create(float duration,const CCSize& gridSize,unsigned int numberOfJumps,float amplitude);
struct CCSplitRows{
	unsigned int m_nRows;
	CCSize m_winSize;
};
bool CCSplitRows::initWithDuration(this *CCSplitRows,float duration,unsigned int nRows);
CCObject* CCSplitRows::copyWithZone(this *CCSplitRows,CCZone* pZone);
void CCSplitRows::update(this *CCSplitRows,float time);
void CCSplitRows::startWithTarget(this *CCSplitRows,CCNode* pTarget);
CCSplitRows* CCSplitRows::create(float duration,unsigned int nRows);
struct CCSplitCols{
	unsigned int m_nCols;
	CCSize m_winSize;
};
bool CCSplitCols::initWithDuration(this *CCSplitCols,float duration,unsigned int nCols);
CCObject* CCSplitCols::copyWithZone(this *CCSplitCols,CCZone* pZone);
void CCSplitCols::update(this *CCSplitCols,float time);
void CCSplitCols::startWithTarget(this *CCSplitCols,CCNode* pTarget);
CCSplitCols* CCSplitCols::create(float duration,unsigned int nCols);
struct CCActionTweenDelegate{
};

void CCActionTweenDelegate::updateTweenAction(this *CCActionTweenDelegate,float value,const char* key);
struct CCActionTween{
	basic_string m_strKey;
	float m_fFrom;
	float m_fTo;
	float m_fDelta;
};
CCActionTween* CCActionTween::create(float aDuration,const char* key,float from,float to);
bool CCActionTween::initWithDuration(this *CCActionTween,float aDuration,const char* key,float from,float to);
void CCActionTween::startWithTarget(this *CCActionTween,CCNode* pTarget);
void CCActionTween::update(this *CCActionTween,float dt);
CCActionInterval* CCActionTween::reverse(this *CCActionTween);
struct CCPointArray{
	std::vector<CCPoint*>* m_pControlPoints;
};
CCPointArray* CCPointArray::create(unsigned int capacity);


bool CCPointArray::initWithCapacity(this *CCPointArray,unsigned int capacity);
void CCPointArray::addControlPoint(this *CCPointArray,CCPoint controlPoint);
void CCPointArray::insertControlPoint(this *CCPointArray,CCPoint& controlPoint,unsigned int index);
void CCPointArray::replaceControlPoint(this *CCPointArray,CCPoint& controlPoint,unsigned int index);
CCPoint CCPointArray::getControlPointAtIndex(this *CCPointArray,unsigned int index);
void CCPointArray::removeControlPointAtIndex(this *CCPointArray,unsigned int index);
unsigned int CCPointArray::count(this *CCPointArray);
CCPointArray* CCPointArray::reverse(this *CCPointArray);
void CCPointArray::reverseInline(this *CCPointArray);
CCObject* CCPointArray::copyWithZone(this *CCPointArray,CCZone* zone);
const std::vector<CCPoint*>* CCPointArray::getControlPoints(this *CCPointArray);
void CCPointArray::setControlPoints(this *CCPointArray,std::vector<CCPoint*>* controlPoints);
struct CCCardinalSplineTo{
	CCPointArray* m_pPoints;
	float m_fDeltaT;
	float m_fTension;
	CCPoint m_previousPosition;
	CCPoint m_accumulatedDiff;
};
CCCardinalSplineTo* CCCardinalSplineTo::create(float duration,CCPointArray* points,float tension);


bool CCCardinalSplineTo::initWithDuration(this *CCCardinalSplineTo,float duration,CCPointArray* points,float tension);
CCCardinalSplineTo* CCCardinalSplineTo::copyWithZone(this *CCCardinalSplineTo,CCZone* pZone);
void CCCardinalSplineTo::startWithTarget(this *CCCardinalSplineTo,CCNode* pTarget);
void CCCardinalSplineTo::update(this *CCCardinalSplineTo,float time);
CCActionInterval* CCCardinalSplineTo::reverse(this *CCCardinalSplineTo);
void CCCardinalSplineTo::updatePosition(this *CCCardinalSplineTo,CCPoint& newPos);
CCPointArray* CCCardinalSplineTo::getPoints(this *CCCardinalSplineTo);
void CCCardinalSplineTo::setPoints(this *CCCardinalSplineTo,CCPointArray* points);
struct CCCardinalSplineBy{
	CCPoint m_startPosition;
};
CCCardinalSplineBy* CCCardinalSplineBy::create(float duration,CCPointArray* points,float tension);

void CCCardinalSplineBy::startWithTarget(this *CCCardinalSplineBy,CCNode* pTarget);
CCActionInterval* CCCardinalSplineBy::reverse(this *CCCardinalSplineBy);
void CCCardinalSplineBy::updatePosition(this *CCCardinalSplineBy,CCPoint& newPos);
struct CCCatmullRomTo{
};
CCCatmullRomTo* CCCatmullRomTo::create(float dt,CCPointArray* points);
bool CCCatmullRomTo::initWithDuration(this *CCCatmullRomTo,float dt,CCPointArray* points);
struct CCCatmullRomBy{
};
CCCatmullRomBy* CCCatmullRomBy::create(float dt,CCPointArray* points);
bool CCCatmullRomBy::initWithDuration(this *CCCatmullRomBy,float dt,CCPointArray* points);
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
CCTextureAtlas* CCAtlasNode::getTextureAtlas(this *CCAtlasNode);
void CCAtlasNode::setTextureAtlas(this *CCAtlasNode,CCTextureAtlas* var);
ccBlendFunc CCAtlasNode::getBlendFunc(this *CCAtlasNode);
void CCAtlasNode::setBlendFunc(this *CCAtlasNode,ccBlendFunc var);
unsigned int CCAtlasNode::getQuadsToDraw(this *CCAtlasNode);
void CCAtlasNode::setQuadsToDraw(this *CCAtlasNode,unsigned int var);


CCAtlasNode* CCAtlasNode::create(const char* tile,unsigned int tileWidth,unsigned int tileHeight,unsigned int itemsToRender);
bool CCAtlasNode::initWithTileFile(this *CCAtlasNode,const char* tile,unsigned int tileWidth,unsigned int tileHeight,unsigned int itemsToRender);
bool CCAtlasNode::initWithTexture(this *CCAtlasNode,CCTexture2D* texture,unsigned int tileWidth,unsigned int tileHeight,unsigned int itemsToRender);
void CCAtlasNode::updateAtlasValues(this *CCAtlasNode);
void CCAtlasNode::draw(this *CCAtlasNode);
CCTexture2D* CCAtlasNode::getTexture(this *CCAtlasNode);
void CCAtlasNode::setTexture(this *CCAtlasNode,CCTexture2D* texture);
bool CCAtlasNode::isOpacityModifyRGB(this *CCAtlasNode);
void CCAtlasNode::setOpacityModifyRGB(this *CCAtlasNode,bool isOpacityModifyRGB);
const ccColor3B& CCAtlasNode::getColor(this *CCAtlasNode);
void CCAtlasNode::setColor(this *CCAtlasNode,const ccColor3B& color);
void CCAtlasNode::setOpacity(this *CCAtlasNode,GLubyte opacity);
void CCAtlasNode::calculateMaxItems(this *CCAtlasNode);
void CCAtlasNode::updateBlendFunc(this *CCAtlasNode);
void CCAtlasNode::updateOpacityModifyRGB(this *CCAtlasNode);
void CCAtlasNode::setIgnoreContentScaleFactor(this *CCAtlasNode,bool bIgnoreContentScaleFactor);
struct CCAutoreleasePool{
	CCArray* m_pManagedObjectArray;
};


void CCAutoreleasePool::addObject(this *CCAutoreleasePool,CCObject* pObject);
void CCAutoreleasePool::removeObject(this *CCAutoreleasePool,CCObject* pObject);
void CCAutoreleasePool::clear(this *CCAutoreleasePool);
struct CCPoolManager{
	CCArray* m_pReleasePoolStack;
	CCAutoreleasePool* m_pCurReleasePool;
};
CCAutoreleasePool* CCPoolManager::getCurReleasePool(this *CCPoolManager);


void CCPoolManager::finalize(this *CCPoolManager);
void CCPoolManager::push(this *CCPoolManager);
void CCPoolManager::pop(this *CCPoolManager);
void CCPoolManager::removeObject(this *CCPoolManager,CCObject* pObject);
void CCPoolManager::addObject(this *CCPoolManager,CCObject* pObject);
CCPoolManager* CCPoolManager::sharedPoolManager();
void CCPoolManager::purgePoolManager();
struct CCInteger{
	int m_nValue;
};

int CCInteger::getValue(this *CCInteger);
CCInteger* CCInteger::create(int v);
void CCInteger::acceptVisitor(this *CCInteger,CCDataVisitor& visitor);
struct CCFloat{
	float m_fValue;
};

float CCFloat::getValue(this *CCFloat);
CCFloat* CCFloat::create(float v);
void CCFloat::acceptVisitor(this *CCFloat,CCDataVisitor& visitor);
struct CCDouble{
	double m_dValue;
};

double CCDouble::getValue(this *CCDouble);
CCDouble* CCDouble::create(double v);
void CCDouble::acceptVisitor(this *CCDouble,CCDataVisitor& visitor);
struct CCBool{
	bool m_bValue;
};

bool CCBool::getValue(this *CCBool);
CCBool* CCBool::create(bool v);
void CCBool::acceptVisitor(this *CCBool,CCDataVisitor& visitor);
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
CCDrawNode* CCDrawNode::create();

bool CCDrawNode::init(this *CCDrawNode);
void CCDrawNode::draw(this *CCDrawNode);
void CCDrawNode::drawDot(this *CCDrawNode,const CCPoint& pos,float radius,const ccColor4F& color);
void CCDrawNode::drawSegment(this *CCDrawNode,const CCPoint& from,const CCPoint& to,float radius,const ccColor4F& color);
void CCDrawNode::drawPolygon(this *CCDrawNode,CCPoint* verts,unsigned int count,const ccColor4F& fillColor,float borderWidth,const ccColor4F& borderColor);
void CCDrawNode::clear(this *CCDrawNode);
ccBlendFunc CCDrawNode::getBlendFunc(this *CCDrawNode);
void CCDrawNode::setBlendFunc(this *CCDrawNode,const ccBlendFunc& blendFunc);

void CCDrawNode::listenBackToForeground(this *CCDrawNode,CCObject* obj);
void CCDrawNode::ensureCapacity(this *CCDrawNode,unsigned int count);
void CCDrawNode::render(this *CCDrawNode);
struct CCConfiguration{
	CCConfiguration* s_gSharedConfiguration;
	basic_string s_sConfigfile;
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
CCConfiguration* CCConfiguration::sharedConfiguration();
void CCConfiguration::purgeConfiguration();

int CCConfiguration::getMaxTextureSize(this *CCConfiguration);
int CCConfiguration::getMaxModelviewStackDepth(this *CCConfiguration);
int CCConfiguration::getMaxTextureUnits(this *CCConfiguration);
bool CCConfiguration::supportsNPOT(this *CCConfiguration);
bool CCConfiguration::supportsPVRTC(this *CCConfiguration);
bool CCConfiguration::supportsBGRA8888(this *CCConfiguration);
bool CCConfiguration::supportsDiscardFramebuffer(this *CCConfiguration);
bool CCConfiguration::supportsShareableVAO(this *CCConfiguration);
bool CCConfiguration::checkForGLExtension(this *CCConfiguration,const basic_string& searchName);
bool CCConfiguration::init(this *CCConfiguration);
const char* CCConfiguration::getCString(this *CCConfiguration,const char* key,const char* default_value);
bool CCConfiguration::getBool(this *CCConfiguration,const char* key,bool default_value);
double CCConfiguration::getNumber(this *CCConfiguration,const char* key,double default_value);
CCObject* CCConfiguration::getObject(this *CCConfiguration,const char* key);
void CCConfiguration::setObject(this *CCConfiguration,const char* key,CCObject* value);
void CCConfiguration::dumpInfo(this *CCConfiguration);
void CCConfiguration::gatherGPUInfo(this *CCConfiguration);
void CCConfiguration::loadConfigFile(this *CCConfiguration,const char* filename);

struct CCGrabber{
	GLuint m_FBO;
	GLint m_oldFBO;
	GLfloat[4] m_oldClearColor;
};


void CCGrabber::grab(this *CCGrabber,CCTexture2D* pTexture);
void CCGrabber::beforeRender(this *CCGrabber,CCTexture2D* pTexture);
void CCGrabber::afterRender(this *CCGrabber,CCTexture2D* pTexture);
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


void CCCamera::init(this *CCCamera);
const char* CCCamera::description(this *CCCamera);
void CCCamera::setDirty(this *CCCamera,bool bValue);
bool CCCamera::isDirty(this *CCCamera);
void CCCamera::restore(this *CCCamera);
void CCCamera::locate(this *CCCamera);
void CCCamera::setEyeXYZ(this *CCCamera,float fEyeX,float fEyeY,float fEyeZ);
void CCCamera::setCenterXYZ(this *CCCamera,float fCenterX,float fCenterY,float fCenterZ);
void CCCamera::setUpXYZ(this *CCCamera,float fUpX,float fUpY,float fUpZ);
void CCCamera::getEyeXYZ(this *CCCamera,float* pEyeX,float* pEyeY,float* pEyeZ);
void CCCamera::getCenterXYZ(this *CCCamera,float* pCenterX,float* pCenterY,float* pCenterZ);
void CCCamera::getUpXYZ(this *CCCamera,float* pUpX,float* pUpY,float* pUpZ);
float CCCamera::getZEye();

void CCCamera::operator=(this *CCCamera);
struct CCLabelAtlas{
	basic_string m_sString;
	unsigned int m_uMapStartChar;
};


CCLabelAtlas* CCLabelAtlas::create(const char* string,const char* charMapFile,unsigned int itemWidth,unsigned int itemHeight,unsigned int startCharMap);
CCLabelAtlas* CCLabelAtlas::create(const char* string,const char* fntFile);
bool CCLabelAtlas::initWithString(this *CCLabelAtlas,const char* string,const char* charMapFile,unsigned int itemWidth,unsigned int itemHeight,unsigned int startCharMap);
bool CCLabelAtlas::initWithString(this *CCLabelAtlas,const char* string,const char* fntFile);
bool CCLabelAtlas::initWithString(this *CCLabelAtlas,const char* string,CCTexture2D* texture,unsigned int itemWidth,unsigned int itemHeight,unsigned int startCharMap);
void CCLabelAtlas::updateAtlasValues(this *CCLabelAtlas);
void CCLabelAtlas::setString(this *CCLabelAtlas,const char* label);
const char* CCLabelAtlas::getString(this *CCLabelAtlas);
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
	char[0x4] pad463;
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
	CCSceneDelegate* m_pAppDelegate;
	CCSize m_obScaleFactor;
	CCSize m_obResolutionInPixels;
	TextureQuality m_eTextureQuality;
	bool m_bDontCallWillSwitch;
};


bool CCDirector::init(this *CCDirector);
long CCDirector::getClassTypeInfo(this *CCDirector);
CCScene* CCDirector::getRunningScene(this *CCDirector);
double CCDirector::getAnimationInterval(this *CCDirector);
void CCDirector::setAnimationInterval(this *CCDirector,double dValue);
bool CCDirector::isDisplayStats(this *CCDirector);
void CCDirector::setDisplayStats(this *CCDirector,bool bDisplayStats);
float CCDirector::getSecondsPerFrame(this *CCDirector);
CCEGLView* CCDirector::getOpenGLView(this *CCDirector);
void CCDirector::setOpenGLView(this *CCDirector,CCEGLView* pobOpenGLView);
bool CCDirector::isNextDeltaTimeZero(this *CCDirector);
void CCDirector::setNextDeltaTimeZero(this *CCDirector,bool bNextDeltaTimeZero);
bool CCDirector::isPaused(this *CCDirector);
unsigned int CCDirector::getTotalFrames(this *CCDirector);
ccDirectorProjection CCDirector::getProjection(this *CCDirector);
void CCDirector::setProjection(this *CCDirector,ccDirectorProjection kProjection);
void CCDirector::reshapeProjection(this *CCDirector,const CCSize& newWindowSize);
void CCDirector::setViewport(this *CCDirector);
bool CCDirector::isSendCleanupToScene(this *CCDirector);
CCNode* CCDirector::getNotificationNode(this *CCDirector);
void CCDirector::setNotificationNode(this *CCDirector,CCNode* node);
CCDirectorDelegate* CCDirector::getDelegate(this *CCDirector);
void CCDirector::setDelegate(this *CCDirector,CCDirectorDelegate* pDelegate);
CCSize CCDirector::getWinSize(this *CCDirector);
CCSize CCDirector::getWinSizeInPixels(this *CCDirector);
CCSize CCDirector::getVisibleSize(this *CCDirector);
CCPoint CCDirector::getVisibleOrigin(this *CCDirector);
CCPoint CCDirector::convertToGL(this *CCDirector,const CCPoint& obPoint);
CCPoint CCDirector::convertToUI(this *CCDirector,const CCPoint& obPoint);
float CCDirector::getZEye(this *CCDirector);
void CCDirector::runWithScene(this *CCDirector,CCScene* pScene);
bool CCDirector::pushScene(this *CCDirector,CCScene* pScene);
void CCDirector::popScene(this *CCDirector);
void CCDirector::popToRootScene(this *CCDirector);
void CCDirector::popToSceneStackLevel(this *CCDirector,int level);
bool CCDirector::replaceScene(this *CCDirector,CCScene* pScene);
void CCDirector::end(this *CCDirector);
void CCDirector::pause(this *CCDirector);
void CCDirector::resume(this *CCDirector);
void CCDirector::stopAnimation(this *CCDirector);
void CCDirector::startAnimation(this *CCDirector);
void CCDirector::drawScene(this *CCDirector);
void CCDirector::purgeCachedData(this *CCDirector);
void CCDirector::setDefaultValues(this *CCDirector);
void CCDirector::setGLDefaultValues(this *CCDirector);
void CCDirector::setAlphaBlending(this *CCDirector,bool bOn);
void CCDirector::setDepthTest(this *CCDirector,bool bOn);
void CCDirector::mainLoop(this *CCDirector);
void CCDirector::setContentScaleFactor(this *CCDirector,float scaleFactor);
float CCDirector::getContentScaleFactor(this *CCDirector);

CCDirector& CCDirector::operator=(this *CCDirector);
void CCDirector::checkSceneReference(this *CCDirector);
CCScene* CCDirector::getNextScene(this *CCDirector);
int CCDirector::levelForSceneInStack(this *CCDirector);
bool CCDirector::popSceneWithTransition(this *CCDirector);
void CCDirector::popToSceneInStack(this *CCDirector);
int CCDirector::sceneCount(this *CCDirector);
void CCDirector::willSwitchToScene(this *CCDirector);
void CCDirector::removeStatsLabel(this *CCDirector);
void CCDirector::resetSmoothFixCounter(this *CCDirector);
void CCDirector::setDeltaTime(this *CCDirector);
void CCDirector::setupScreenScale(this *CCDirector);
void CCDirector::updateContentScale(this *CCDirector);
void CCDirector::updateScreenScale(this *CCDirector);
TextureQuality CCDirector::getLoadedTextureQuality(this *CCDirector);
float CCDirector::getScreenScaleFactor(this *CCDirector);
float CCDirector::getScreenScaleFactorMax(this *CCDirector);
float CCDirector::getScreenScaleFactorW(this *CCDirector);
float CCDirector::getScreenScaleFactorH(this *CCDirector);
float CCDirector::getScreenTop(this *CCDirector);
float CCDirector::getScreenBottom(this *CCDirector);
float CCDirector::getScreenLeft(this *CCDirector);
float CCDirector::getScreenRight(this *CCDirector);
CCScene* CCDirector::getSceneReference(this *CCDirector);
void CCDirector::setSceneReference(this *CCDirector,CCScene* var);
CCScheduler* CCDirector::getScheduler(this *CCDirector);
void CCDirector::setScheduler(this *CCDirector,CCScheduler* var);
CCActionManager* CCDirector::getActionManager(this *CCDirector);
void CCDirector::setActionManager(this *CCDirector,CCActionManager* var);
CCTouchDispatcher* CCDirector::getTouchDispatcher(this *CCDirector);
void CCDirector::setTouchDispatcher(this *CCDirector,CCTouchDispatcher* var);
CCKeypadDispatcher* CCDirector::getKeypadDispatcher(this *CCDirector);
void CCDirector::setKeypadDispatcher(this *CCDirector,CCKeypadDispatcher* var);
CCKeyboardDispatcher* CCDirector::getKeyboardDispatcher(this *CCDirector);
void CCDirector::setKeyboardDispatcher(this *CCDirector,CCKeyboardDispatcher* var);
CCMouseDispatcher* CCDirector::getMouseDispatcher(this *CCDirector);
void CCDirector::setMouseDispatcher(this *CCDirector,CCMouseDispatcher* var);
CCAccelerometer* CCDirector::getAccelerometer(this *CCDirector);
void CCDirector::setAccelerometer(this *CCDirector,CCAccelerometer* var);
float CCDirector::getDeltaTime(this *CCDirector);
float CCDirector::getActualDeltaTime(this *CCDirector);
void CCDirector::setActualDeltaTime(this *CCDirector,float var);
CCDirector* CCDirector::sharedDirector();
void CCDirector::purgeDirector(this *CCDirector);
bool CCDirector::getIsTransitioning(this *CCDirector);
bool CCDirector::getSmoothFix(this *CCDirector);
void CCDirector::setSmoothFix(this *CCDirector,bool var);
bool CCDirector::getSmoothFixCheck(this *CCDirector);
void CCDirector::setSmoothFixCheck(this *CCDirector,bool var);
bool CCDirector::getForceSmoothFix(this *CCDirector);
void CCDirector::setForceSmoothFix(this *CCDirector,bool var);
int CCDirector::getSmoothFixCounter(this *CCDirector);
void CCDirector::setNextScene(this *CCDirector);
void CCDirector::showStats(this *CCDirector);
void CCDirector::createStatsLabel(this *CCDirector);
void CCDirector::calculateMPF(this *CCDirector);
void CCDirector::getFPSImageData(this *CCDirector,unsigned char** datapointer,unsigned int* length);
void CCDirector::calculateDeltaTime(this *CCDirector);
CCSceneDelegate* CCDirector::getSceneDelegate(this *CCDirector);
void CCDirector::setSceneDelegate(this *CCDirector,CCSceneDelegate* var);
bool CCDirector::getDontCallWillSwitch(this *CCDirector);
void CCDirector::setDontCallWillSwitch(this *CCDirector,bool var);
struct CCDisplayLinkDirector{
	bool m_bInvalid;
};

void CCDisplayLinkDirector::mainLoop(this *CCDisplayLinkDirector);
void CCDisplayLinkDirector::setAnimationInterval(this *CCDisplayLinkDirector,double dValue);
void CCDisplayLinkDirector::startAnimation(this *CCDisplayLinkDirector);
void CCDisplayLinkDirector::stopAnimation(this *CCDisplayLinkDirector);
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

bool CCGridBase::isActive(this *CCGridBase);
void CCGridBase::setActive(this *CCGridBase,bool bActive);
int CCGridBase::getReuseGrid(this *CCGridBase);
void CCGridBase::setReuseGrid(this *CCGridBase,int nReuseGrid);
const CCSize& CCGridBase::getGridSize(this *CCGridBase);
void CCGridBase::setGridSize(this *CCGridBase,const CCSize& gridSize);
const CCPoint& CCGridBase::getStep(this *CCGridBase);
void CCGridBase::setStep(this *CCGridBase,const CCPoint& step);
bool CCGridBase::isTextureFlipped(this *CCGridBase);
void CCGridBase::setTextureFlipped(this *CCGridBase,bool bFlipped);
bool CCGridBase::initWithSize(this *CCGridBase,const CCSize& gridSize,CCTexture2D* pTexture,bool bFlipped);
bool CCGridBase::initWithSize(this *CCGridBase,const CCSize& gridSize);
void CCGridBase::beforeDraw(this *CCGridBase);
void CCGridBase::afterDraw(this *CCGridBase,CCNode* pTarget);
void CCGridBase::blit(this *CCGridBase);
void CCGridBase::reuse(this *CCGridBase);
void CCGridBase::calculateVertexPoints(this *CCGridBase);
CCGridBase* CCGridBase::create(const CCSize& gridSize,CCTexture2D* texture,bool flipped);
CCGridBase* CCGridBase::create(const CCSize& gridSize);
void CCGridBase::set2DProjection(this *CCGridBase);
struct CCGrid3D{
	GLvoid* m_pTexCoordinates;
	GLvoid* m_pVertices;
	GLvoid* m_pOriginalVertices;
	GLushort* m_pIndices;
};


ccVertex3F CCGrid3D::vertex(this *CCGrid3D,const CCPoint& pos);
ccVertex3F CCGrid3D::originalVertex(this *CCGrid3D,const CCPoint& pos);
void CCGrid3D::setVertex(this *CCGrid3D,const CCPoint& pos,const ccVertex3F& vertex);
void CCGrid3D::blit(this *CCGrid3D);
void CCGrid3D::reuse(this *CCGrid3D);
void CCGrid3D::calculateVertexPoints(this *CCGrid3D);
CCGrid3D* CCGrid3D::create(const CCSize& gridSize,CCTexture2D* pTexture,bool bFlipped);
CCGrid3D* CCGrid3D::create(const CCSize& gridSize);
struct CCTiledGrid3D{
	GLvoid* m_pTexCoordinates;
	GLvoid* m_pVertices;
	GLvoid* m_pOriginalVertices;
	GLushort* m_pIndices;
};


ccQuad3 CCTiledGrid3D::tile(this *CCTiledGrid3D,const CCPoint& pos);
ccQuad3 CCTiledGrid3D::originalTile(this *CCTiledGrid3D,const CCPoint& pos);
void CCTiledGrid3D::setTile(this *CCTiledGrid3D,const CCPoint& pos,const ccQuad3& coords);
void CCTiledGrid3D::blit(this *CCTiledGrid3D);
void CCTiledGrid3D::reuse(this *CCTiledGrid3D);
void CCTiledGrid3D::calculateVertexPoints(this *CCTiledGrid3D);
CCTiledGrid3D* CCTiledGrid3D::create(const CCSize& gridSize,CCTexture2D* pTexture,bool bFlipped);
CCTiledGrid3D* CCTiledGrid3D::create(const CCSize& gridSize);
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
	float[9] mat;
};
struct kmMat4{
	float[16] mat;
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
void CCKeypadDelegate::keyBackClicked(this *CCKeypadDelegate);
void CCKeypadDelegate::keyMenuClicked(this *CCKeypadDelegate);
struct CCKeypadHandler{
	CCKeypadDelegate* m_pDelegate;
};

CCKeypadDelegate* CCKeypadHandler::getDelegate(this *CCKeypadHandler);
void CCKeypadHandler::setDelegate(this *CCKeypadHandler,CCKeypadDelegate* pDelegate);
bool CCKeypadHandler::initWithDelegate(this *CCKeypadHandler,CCKeypadDelegate* pDelegate);
CCKeypadHandler* CCKeypadHandler::handlerWithDelegate(CCKeypadDelegate* pDelegate);
struct CCKeypadDispatcher{
	CCArray* m_pDelegates;
	bool m_bLocked;
	bool m_bToAdd;
	bool m_bToRemove;
	struct _ccCArray* m_pHandlersToAdd;
	struct _ccCArray* m_pHandlersToRemove;
};


void CCKeypadDispatcher::addDelegate(this *CCKeypadDispatcher,CCKeypadDelegate* pDelegate);
void CCKeypadDispatcher::removeDelegate(this *CCKeypadDispatcher,CCKeypadDelegate* pDelegate);
void CCKeypadDispatcher::forceAddDelegate(this *CCKeypadDispatcher,CCKeypadDelegate* pDelegate);
void CCKeypadDispatcher::forceRemoveDelegate(this *CCKeypadDispatcher,CCKeypadDelegate* pDelegate);
bool CCKeypadDispatcher::dispatchKeypadMSG(this *CCKeypadDispatcher,ccKeypadMSGType nMsgType);
struct CCTextureAtlas{
	GLushort* m_pIndices;
	GLuint[2] m_pBuffersVBO;
	bool m_bDirty;
	unsigned int m_uTotalQuads;
	unsigned int m_uCapacity;
	CCTexture2D* m_pTexture;
	ccV3F_C4B_T2F_Quad* m_pQuads;
};
unsigned int CCTextureAtlas::getTotalQuads(this *CCTextureAtlas);
unsigned int CCTextureAtlas::getCapacity(this *CCTextureAtlas);
CCTexture2D* CCTextureAtlas::getTexture(this *CCTextureAtlas);
void CCTextureAtlas::setTexture(this *CCTextureAtlas,CCTexture2D* var);
ccV3F_C4B_T2F_Quad* CCTextureAtlas::getQuads(this *CCTextureAtlas);
void CCTextureAtlas::setQuads(this *CCTextureAtlas,ccV3F_C4B_T2F_Quad* var);


const char* CCTextureAtlas::description(this *CCTextureAtlas);
CCTextureAtlas* CCTextureAtlas::create(const char* file,unsigned int capacity);
bool CCTextureAtlas::initWithFile(this *CCTextureAtlas,const char* file,unsigned int capacity);
CCTextureAtlas* CCTextureAtlas::createWithTexture(CCTexture2D* texture,unsigned int capacity);
bool CCTextureAtlas::initWithTexture(this *CCTextureAtlas,CCTexture2D* texture,unsigned int capacity);
void CCTextureAtlas::updateQuad(this *CCTextureAtlas,ccV3F_C4B_T2F_Quad* quad,unsigned int index);
void CCTextureAtlas::insertQuad(this *CCTextureAtlas,ccV3F_C4B_T2F_Quad* quad,unsigned int index);
void CCTextureAtlas::insertQuads(this *CCTextureAtlas,ccV3F_C4B_T2F_Quad* quads,unsigned int index,unsigned int amount);
void CCTextureAtlas::insertQuadFromIndex(this *CCTextureAtlas,unsigned int fromIndex,unsigned int newIndex);
void CCTextureAtlas::removeQuadAtIndex(this *CCTextureAtlas,unsigned int index);
void CCTextureAtlas::removeQuadsAtIndex(this *CCTextureAtlas,unsigned int index,unsigned int amount);
void CCTextureAtlas::removeAllQuads(this *CCTextureAtlas);
bool CCTextureAtlas::resizeCapacity(this *CCTextureAtlas,unsigned int n);
void CCTextureAtlas::increaseTotalQuadsWith(this *CCTextureAtlas,unsigned int amount);
void CCTextureAtlas::moveQuadsFromIndex(this *CCTextureAtlas,unsigned int oldIndex,unsigned int amount,unsigned int newIndex);
void CCTextureAtlas::moveQuadsFromIndex(this *CCTextureAtlas,unsigned int index,unsigned int newIndex);
void CCTextureAtlas::fillWithEmptyQuadsFromIndex(this *CCTextureAtlas,unsigned int index,unsigned int amount);
void CCTextureAtlas::drawNumberOfQuads(this *CCTextureAtlas,unsigned int n);
void CCTextureAtlas::drawNumberOfQuads(this *CCTextureAtlas,unsigned int n,unsigned int start);
void CCTextureAtlas::drawQuads(this *CCTextureAtlas);
void CCTextureAtlas::listenBackToForeground(this *CCTextureAtlas,CCObject* obj);
bool CCTextureAtlas::isDirty(this *CCTextureAtlas);
void CCTextureAtlas::setDirty(this *CCTextureAtlas,bool bDirty);
void CCTextureAtlas::setupIndices(this *CCTextureAtlas);
void CCTextureAtlas::mapBuffers(this *CCTextureAtlas);
void CCTextureAtlas::setupVBO(this *CCTextureAtlas);
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
	char[16] pad561;
	bool m_bUnknown;
	int m_nUnknown;
};
CCSprite* CCSprite::create();
CCSprite* CCSprite::create(const char* pszFileName);
CCSprite* CCSprite::create(const char* pszFileName,const CCRect& rect);
CCSprite* CCSprite::createWithTexture(CCTexture2D* pTexture);
CCSprite* CCSprite::createWithTexture(CCTexture2D* pTexture,const CCRect& rect);
CCSprite* CCSprite::createWithSpriteFrame(CCSpriteFrame* pSpriteFrame);
CCSprite* CCSprite::createWithSpriteFrameName(const char* pszSpriteFrameName);


bool CCSprite::init(this *CCSprite);
bool CCSprite::initWithTexture(this *CCSprite,CCTexture2D* pTexture);
bool CCSprite::initWithTexture(this *CCSprite,CCTexture2D* pTexture,const CCRect& rect);
bool CCSprite::initWithTexture(this *CCSprite,CCTexture2D* pTexture,const CCRect& rect,bool rotated);
bool CCSprite::initWithSpriteFrame(this *CCSprite,CCSpriteFrame* pSpriteFrame);
bool CCSprite::initWithSpriteFrameName(this *CCSprite,const char* pszSpriteFrameName);
bool CCSprite::initWithFile(this *CCSprite,const char* pszFilename);
bool CCSprite::initWithFile(this *CCSprite,const char* pszFilename,const CCRect& rect);
void CCSprite::setChildColor(this *CCSprite);
void CCSprite::setChildOpacity(this *CCSprite);
void CCSprite::setTexture(this *CCSprite,CCTexture2D* texture);
CCTexture2D* CCSprite::getTexture(this *CCSprite);
void CCSprite::setBlendFunc(this *CCSprite,ccBlendFunc blendFunc);
ccBlendFunc CCSprite::getBlendFunc(this *CCSprite);
void CCSprite::setScaleX(this *CCSprite,float fScaleX);
void CCSprite::setScaleY(this *CCSprite,float fScaleY);
void CCSprite::setPosition(this *CCSprite,const CCPoint& pos);
void CCSprite::setRotation(this *CCSprite,float fRotation);
void CCSprite::setRotationX(this *CCSprite,float fRotationX);
void CCSprite::setRotationY(this *CCSprite,float fRotationY);
void CCSprite::setSkewX(this *CCSprite,float sx);
void CCSprite::setSkewY(this *CCSprite,float sy);
void CCSprite::removeChild(this *CCSprite,CCNode* pChild,bool bCleanup);
void CCSprite::removeAllChildrenWithCleanup(this *CCSprite,bool bCleanup);
void CCSprite::reorderChild(this *CCSprite,CCNode* pChild,int zOrder);
void CCSprite::addChild(this *CCSprite,CCNode* pChild);
void CCSprite::addChild(this *CCSprite,CCNode* pChild,int zOrder);
void CCSprite::addChild(this *CCSprite,CCNode* pChild,int zOrder,int tag);
void CCSprite::sortAllChildren(this *CCSprite);
void CCSprite::setScale(this *CCSprite,float fScale);
void CCSprite::setVertexZ(this *CCSprite,float fVertexZ);
void CCSprite::setAnchorPoint(this *CCSprite,const CCPoint& anchor);
void CCSprite::ignoreAnchorPointForPosition(this *CCSprite,bool value);
void CCSprite::setVisible(this *CCSprite,bool bVisible);
void CCSprite::draw(this *CCSprite);
void CCSprite::setColor(this *CCSprite,const ccColor3B& color3);
void CCSprite::updateDisplayedColor(this *CCSprite,const ccColor3B& parentColor);
void CCSprite::setOpacity(this *CCSprite,GLubyte opacity);
void CCSprite::setOpacityModifyRGB(this *CCSprite,bool modify);
bool CCSprite::isOpacityModifyRGB(this *CCSprite);
void CCSprite::updateDisplayedOpacity(this *CCSprite,GLubyte parentOpacity);
void CCSprite::updateTransform(this *CCSprite);
CCSpriteBatchNode* CCSprite::getBatchNode(this *CCSprite);
void CCSprite::setBatchNode(this *CCSprite,CCSpriteBatchNode* pobSpriteBatchNode);
void CCSprite::refreshTextureRect(this *CCSprite);
void CCSprite::setTextureRect(this *CCSprite,const CCRect& rect);
void CCSprite::setTextureRect(this *CCSprite,const CCRect& rect,bool rotated,const CCSize& untrimmedSize);
void CCSprite::setVertexRect(this *CCSprite,const CCRect& rect);
void CCSprite::setDisplayFrame(this *CCSprite,CCSpriteFrame* pNewFrame);
bool CCSprite::isFrameDisplayed(this *CCSprite,CCSpriteFrame* pFrame);
CCSpriteFrame* CCSprite::displayFrame(this *CCSprite);
void CCSprite::setDisplayFrameWithAnimationName(this *CCSprite,const char* animationName,int frameIndex);
bool CCSprite::isDirty(this *CCSprite);
void CCSprite::setDirty(this *CCSprite,bool bDirty);
ccV3F_C4B_T2F_Quad CCSprite::getQuad(this *CCSprite);
bool CCSprite::isTextureRectRotated(this *CCSprite);
unsigned int CCSprite::getAtlasIndex(this *CCSprite);
void CCSprite::setAtlasIndex(this *CCSprite,unsigned int uAtlasIndex);
const CCRect& CCSprite::getTextureRect(this *CCSprite);
CCTextureAtlas* CCSprite::getTextureAtlas(this *CCSprite);
void CCSprite::setTextureAtlas(this *CCSprite,CCTextureAtlas* pobTextureAtlas);
const CCPoint& CCSprite::getOffsetPosition(this *CCSprite);
bool CCSprite::isFlipX(this *CCSprite);
void CCSprite::setFlipX(this *CCSprite,bool bFlipX);
bool CCSprite::isFlipY(this *CCSprite);
void CCSprite::setFlipY(this *CCSprite,bool bFlipY);
void CCSprite::updateColor(this *CCSprite);
void CCSprite::setTextureCoords(this *CCSprite,const CCRect& rect);
void CCSprite::updateBlendFunc(this *CCSprite);
void CCSprite::setReorderChildDirtyRecursively(this *CCSprite);
void CCSprite::setDirtyRecursively(this *CCSprite,bool bValue);
bool CCSprite::getDontDraw(this *CCSprite);
void CCSprite::setDontDraw(this *CCSprite,bool var);
float CCSprite::getTlVertexMod(this *CCSprite);
void CCSprite::setTlVertexMod(this *CCSprite,float var);
float CCSprite::getTrVertexMod(this *CCSprite);
void CCSprite::setTrVertexMod(this *CCSprite,float var);
float CCSprite::getBlVertexMod(this *CCSprite);
void CCSprite::setBlVertexMod(this *CCSprite,float var);
float CCSprite::getBrVertexMod(this *CCSprite);
void CCSprite::setBrVertexMod(this *CCSprite,float var);
struct CCLabelTTF{
	CCSize m_tDimensions;
	CCTextAlignment m_hAlignment;
	CCVerticalTextAlignment m_vAlignment;
	basic_string* m_pFontName;
	float m_fFontSize;
	basic_string m_string;
	bool m_shadowEnabled;
	CCSize m_shadowOffset;
	float m_shadowOpacity;
	float m_shadowBlur;
	bool m_strokeEnabled;
	ccColor3B m_strokeColor;
	float m_strokeSize;
	ccColor3B m_textFillColor;
};


const char* CCLabelTTF::description(this *CCLabelTTF);
CCLabelTTF* CCLabelTTF::create(const char* string,const char* fontName,float fontSize);
CCLabelTTF* CCLabelTTF::create(const char* string,const char* fontName,float fontSize,const CCSize& dimensions,CCTextAlignment hAlignment);
CCLabelTTF* CCLabelTTF::create(const char* string,const char* fontName,float fontSize,const CCSize& dimensions,CCTextAlignment hAlignment,CCVerticalTextAlignment vAlignment);
CCLabelTTF* CCLabelTTF::createWithFontDefinition(const char* string,ccFontDefinition& textDefinition);
bool CCLabelTTF::initWithString(this *CCLabelTTF,const char* string,const char* fontName,float fontSize);
bool CCLabelTTF::initWithString(this *CCLabelTTF,const char* string,const char* fontName,float fontSize,const CCSize& dimensions,CCTextAlignment hAlignment);
bool CCLabelTTF::initWithString(this *CCLabelTTF,const char* string,const char* fontName,float fontSize,const CCSize& dimensions,CCTextAlignment hAlignment,CCVerticalTextAlignment vAlignment);
bool CCLabelTTF::initWithStringAndTextDefinition(this *CCLabelTTF,const char* string,ccFontDefinition& textDefinition);
void CCLabelTTF::setTextDefinition(this *CCLabelTTF,ccFontDefinition* theDefinition);
ccFontDefinition* CCLabelTTF::getTextDefinition(this *CCLabelTTF);
void CCLabelTTF::enableShadow(this *CCLabelTTF,const CCSize& shadowOffset,float shadowOpacity,float shadowBlur,bool mustUpdateTexture);
void CCLabelTTF::disableShadow(this *CCLabelTTF,bool mustUpdateTexture);
void CCLabelTTF::enableStroke(this *CCLabelTTF,const ccColor3B& strokeColor,float strokeSize,bool mustUpdateTexture);
void CCLabelTTF::disableStroke(this *CCLabelTTF,bool mustUpdateTexture);
void CCLabelTTF::setFontFillColor(this *CCLabelTTF,const ccColor3B& tintColor,bool mustUpdateTexture);
bool CCLabelTTF::init(this *CCLabelTTF);
CCLabelTTF* CCLabelTTF::create();
void CCLabelTTF::setString(this *CCLabelTTF,const char* label);
const char* CCLabelTTF::getString(this *CCLabelTTF);
CCTextAlignment CCLabelTTF::getHorizontalAlignment(this *CCLabelTTF);
void CCLabelTTF::setHorizontalAlignment(this *CCLabelTTF,CCTextAlignment alignment);
CCVerticalTextAlignment CCLabelTTF::getVerticalAlignment(this *CCLabelTTF);
void CCLabelTTF::setVerticalAlignment(this *CCLabelTTF,CCVerticalTextAlignment verticalAlignment);
CCSize CCLabelTTF::getDimensions(this *CCLabelTTF);
void CCLabelTTF::setDimensions(this *CCLabelTTF,const CCSize& dim);
float CCLabelTTF::getFontSize(this *CCLabelTTF);
void CCLabelTTF::setFontSize(this *CCLabelTTF,float fontSize);
const char* CCLabelTTF::getFontName(this *CCLabelTTF);
void CCLabelTTF::setFontName(this *CCLabelTTF,const char* fontName);
bool CCLabelTTF::updateTexture(this *CCLabelTTF);
void CCLabelTTF::_updateWithTextDefinition(this *CCLabelTTF,ccFontDefinition& textDefinition,bool mustUpdateTexture);
ccFontDefinition CCLabelTTF::_prepareTextDefinition(this *CCLabelTTF,bool adjustForResolution);
struct CCSpriteBatchNode{
	CCTextureAtlas* m_pobTextureAtlas;
	ccBlendFunc m_blendFunc;
	CCArray* m_pobDescendants;
	bool m_bManualSortChildren;
	bool m_bManualSortAllChildrenDirty;
};


CCTextureAtlas* CCSpriteBatchNode::getTextureAtlas(this *CCSpriteBatchNode);
void CCSpriteBatchNode::setTextureAtlas(this *CCSpriteBatchNode,CCTextureAtlas* textureAtlas);
CCArray* CCSpriteBatchNode::getDescendants(this *CCSpriteBatchNode);
CCSpriteBatchNode* CCSpriteBatchNode::createWithTexture(CCTexture2D* tex,unsigned int capacity);
CCSpriteBatchNode* CCSpriteBatchNode::createWithTexture(CCTexture2D* tex);
CCSpriteBatchNode* CCSpriteBatchNode::create(const char* fileImage,unsigned int capacity);
CCSpriteBatchNode* CCSpriteBatchNode::create(const char* fileImage);
bool CCSpriteBatchNode::initWithTexture(this *CCSpriteBatchNode,CCTexture2D* tex,unsigned int capacity);
bool CCSpriteBatchNode::initWithFile(this *CCSpriteBatchNode,const char* fileImage,unsigned int capacity);
bool CCSpriteBatchNode::init(this *CCSpriteBatchNode);
void CCSpriteBatchNode::increaseAtlasCapacity(this *CCSpriteBatchNode);
void CCSpriteBatchNode::removeChildAtIndex(this *CCSpriteBatchNode,unsigned int index,bool doCleanup);
void CCSpriteBatchNode::insertChild(this *CCSpriteBatchNode,CCSprite* child,unsigned int index);
void CCSpriteBatchNode::appendChild(this *CCSpriteBatchNode,CCSprite* sprite);
void CCSpriteBatchNode::removeSpriteFromAtlas(this *CCSpriteBatchNode,CCSprite* sprite);
unsigned int CCSpriteBatchNode::rebuildIndexInOrder(this *CCSpriteBatchNode,CCSprite* parent,unsigned int index);
unsigned int CCSpriteBatchNode::highestAtlasIndexInChild(this *CCSpriteBatchNode,CCSprite* sprite);
unsigned int CCSpriteBatchNode::lowestAtlasIndexInChild(this *CCSpriteBatchNode,CCSprite* sprite);
unsigned int CCSpriteBatchNode::atlasIndexForChild(this *CCSpriteBatchNode,CCSprite* sprite,int z);
void CCSpriteBatchNode::reorderBatch(this *CCSpriteBatchNode,bool reorder);
CCTexture2D* CCSpriteBatchNode::getTexture(this *CCSpriteBatchNode);
void CCSpriteBatchNode::setTexture(this *CCSpriteBatchNode,CCTexture2D* texture);
void CCSpriteBatchNode::setBlendFunc(this *CCSpriteBatchNode,ccBlendFunc blendFunc);
ccBlendFunc CCSpriteBatchNode::getBlendFunc(this *CCSpriteBatchNode);
void CCSpriteBatchNode::visit(this *CCSpriteBatchNode);
void CCSpriteBatchNode::addChild(this *CCSpriteBatchNode,CCNode* child);
void CCSpriteBatchNode::addChild(this *CCSpriteBatchNode,CCNode* child,int zOrder);
void CCSpriteBatchNode::addChild(this *CCSpriteBatchNode,CCNode* child,int zOrder,int tag);
void CCSpriteBatchNode::reorderChild(this *CCSpriteBatchNode,CCNode* child,int zOrder);
void CCSpriteBatchNode::removeChild(this *CCSpriteBatchNode,CCNode* child,bool cleanup);
void CCSpriteBatchNode::removeAllChildrenWithCleanup(this *CCSpriteBatchNode,bool cleanup);
void CCSpriteBatchNode::sortAllChildren(this *CCSpriteBatchNode);
void CCSpriteBatchNode::draw(this *CCSpriteBatchNode);
void CCSpriteBatchNode::insertQuadFromSprite(this *CCSpriteBatchNode,CCSprite* sprite,unsigned int index);
void CCSpriteBatchNode::updateQuadFromSprite(this *CCSpriteBatchNode,CCSprite* sprite,unsigned int index);
CCSpriteBatchNode* CCSpriteBatchNode::addSpriteWithoutQuad(this *CCSpriteBatchNode,CCSprite* child,unsigned int z,int aTag);
void CCSpriteBatchNode::updateAtlasIndex(this *CCSpriteBatchNode,CCSprite* sprite,int* curIndex);
void CCSpriteBatchNode::swap(this *CCSpriteBatchNode,int oldIndex,int newIndex);
void CCSpriteBatchNode::updateBlendFunc(this *CCSpriteBatchNode);
struct _BMFontDef{
	unsigned int charID;
	CCRect rect;
	short xOffset;
	short yOffset;
	short xAdvance;
};
struct _BMFontPadding{
	int left;
	int top;
	int right;
	int bottom;
};
struct _FontDefHashElement{
	unsigned int key;
	ccBMFontDef fontDef;
	UT_hash_handle hh;
};
struct _KerningHashElement{
	int key;
	int amount;
	UT_hash_handle hh;
};
struct CCBMFontConfiguration{
	tCCFontDefHashElement* m_pFontDefDictionary;
	int m_nCommonHeight;
	ccBMFontPadding m_tPadding;
	basic_string m_sAtlasName;
	tCCKerningHashElement* m_pKerningDictionary;
	std::set<unsigned int>* m_pCharacterSet;
};


const char* CCBMFontConfiguration::description(this *CCBMFontConfiguration);
CCBMFontConfiguration* CCBMFontConfiguration::create(const char* FNTfile);
bool CCBMFontConfiguration::initWithFNTfile(this *CCBMFontConfiguration,const char* FNTfile);
const char* CCBMFontConfiguration::getAtlasName(this *CCBMFontConfiguration);
void CCBMFontConfiguration::setAtlasName(this *CCBMFontConfiguration,const char* atlasName);
std::set<unsigned int>* CCBMFontConfiguration::getCharacterSet(this *CCBMFontConfiguration);
std::set<unsigned int>* CCBMFontConfiguration::parseConfigFile(this *CCBMFontConfiguration,const char* controlFile);
void CCBMFontConfiguration::parseCharacterDefinition(this *CCBMFontConfiguration,basic_string line,ccBMFontDef* characterDefinition);
void CCBMFontConfiguration::parseInfoArguments(this *CCBMFontConfiguration,basic_string line);
void CCBMFontConfiguration::parseCommonArguments(this *CCBMFontConfiguration,basic_string line);
void CCBMFontConfiguration::parseImageFileName(this *CCBMFontConfiguration,basic_string line,const char* fntFile);
void CCBMFontConfiguration::parseKerningEntry(this *CCBMFontConfiguration,basic_string line);
void CCBMFontConfiguration::purgeKerningDictionary(this *CCBMFontConfiguration);
void CCBMFontConfiguration::purgeFontDefDictionary(this *CCBMFontConfiguration);
struct CCLabelBMFont{
	unsigned short* m_sString;
	basic_string m_sFntFile;
	unsigned short* m_sInitialString;
	basic_string m_sInitialStringUTF8;
	CCTextAlignment m_pAlignment;
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


void CCLabelBMFont::purgeCachedData();
CCLabelBMFont* CCLabelBMFont::create(const char* str,const char* fntFile,float width,CCTextAlignment alignment,CCPoint imageOffset);
CCLabelBMFont* CCLabelBMFont::create(const char* str,const char* fntFile,float width,CCTextAlignment alignment);
CCLabelBMFont* CCLabelBMFont::create(const char* str,const char* fntFile,float width);
CCLabelBMFont* CCLabelBMFont::create(const char* str,const char* fntFile);
CCLabelBMFont* CCLabelBMFont::create();
bool CCLabelBMFont::init(this *CCLabelBMFont);
bool CCLabelBMFont::initWithString(this *CCLabelBMFont,const char* str,const char* fntFile,float width,CCTextAlignment alignment,CCPoint imageOffset);
void CCLabelBMFont::createFontChars(this *CCLabelBMFont);
void CCLabelBMFont::setString(this *CCLabelBMFont,const char* newString);
void CCLabelBMFont::setString(this *CCLabelBMFont,const char* newString,bool needUpdateLabel);
const char* CCLabelBMFont::getString(this *CCLabelBMFont);
void CCLabelBMFont::setCString(this *CCLabelBMFont,const char* label);
void CCLabelBMFont::setAnchorPoint(this *CCLabelBMFont,const CCPoint& var);
void CCLabelBMFont::updateLabel(this *CCLabelBMFont);
void CCLabelBMFont::setAlignment(this *CCLabelBMFont,CCTextAlignment alignment);
void CCLabelBMFont::setWidth(this *CCLabelBMFont,float width);
void CCLabelBMFont::setLineBreakWithoutSpace(this *CCLabelBMFont,bool breakWithoutSpace);
void CCLabelBMFont::setScale(this *CCLabelBMFont,float scale);
void CCLabelBMFont::setScaleX(this *CCLabelBMFont,float scaleX);
void CCLabelBMFont::setScaleY(this *CCLabelBMFont,float scaleY);
bool CCLabelBMFont::isOpacityModifyRGB(this *CCLabelBMFont);
void CCLabelBMFont::setOpacityModifyRGB(this *CCLabelBMFont,bool isOpacityModifyRGB);
GLubyte CCLabelBMFont::getOpacity(this *CCLabelBMFont);
GLubyte CCLabelBMFont::getDisplayedOpacity(this *CCLabelBMFont);
void CCLabelBMFont::setOpacity(this *CCLabelBMFont,GLubyte opacity);
void CCLabelBMFont::updateDisplayedOpacity(this *CCLabelBMFont,GLubyte parentOpacity);
bool CCLabelBMFont::isCascadeOpacityEnabled(this *CCLabelBMFont);
void CCLabelBMFont::setCascadeOpacityEnabled(this *CCLabelBMFont,bool cascadeOpacityEnabled);
const ccColor3B& CCLabelBMFont::getColor(this *CCLabelBMFont);
const ccColor3B& CCLabelBMFont::getDisplayedColor(this *CCLabelBMFont);
void CCLabelBMFont::setColor(this *CCLabelBMFont,const ccColor3B& color);
void CCLabelBMFont::updateDisplayedColor(this *CCLabelBMFont,const ccColor3B& parentColor);
bool CCLabelBMFont::isCascadeColorEnabled(this *CCLabelBMFont);
void CCLabelBMFont::setCascadeColorEnabled(this *CCLabelBMFont,bool cascadeColorEnabled);
void CCLabelBMFont::setFntFile(this *CCLabelBMFont,const char* fntFile);
const char* CCLabelBMFont::getFntFile(this *CCLabelBMFont);
CCBMFontConfiguration* CCLabelBMFont::getConfiguration(this *CCLabelBMFont);
CCLabelBMFont* CCLabelBMFont::createBatched(const char* str,const char* fntFile);
void CCLabelBMFont::limitLabelWidth(this *CCLabelBMFont,float width,float defaultScale,float minScale);
char* CCLabelBMFont::atlasNameFromFntFile(this *CCLabelBMFont,const char* fntFile);
int CCLabelBMFont::kerningAmountForFirst(this *CCLabelBMFont,unsigned short first,unsigned short second);
float CCLabelBMFont::getLetterPosXLeft(this *CCLabelBMFont,CCSprite* characterSprite);
float CCLabelBMFont::getLetterPosXRight(this *CCLabelBMFont,CCSprite* characterSprite);
void CCLabelBMFont::setString(this *CCLabelBMFont,unsigned short* newString,bool needUpdateLabel);
struct CCTouchDelegate{
};


bool CCTouchDelegate::ccTouchBegan(this *CCTouchDelegate,CCTouch* pTouch,CCEvent* pEvent);
void CCTouchDelegate::ccTouchMoved(this *CCTouchDelegate,CCTouch* pTouch,CCEvent* pEvent);
void CCTouchDelegate::ccTouchEnded(this *CCTouchDelegate,CCTouch* pTouch,CCEvent* pEvent);
void CCTouchDelegate::ccTouchCancelled(this *CCTouchDelegate,CCTouch* pTouch,CCEvent* pEvent);
void CCTouchDelegate::ccTouchesBegan(this *CCTouchDelegate,CCSet* pTouches,CCEvent* pEvent);
void CCTouchDelegate::ccTouchesMoved(this *CCTouchDelegate,CCSet* pTouches,CCEvent* pEvent);
void CCTouchDelegate::ccTouchesEnded(this *CCTouchDelegate,CCSet* pTouches,CCEvent* pEvent);
void CCTouchDelegate::ccTouchesCancelled(this *CCTouchDelegate,CCSet* pTouches,CCEvent* pEvent);
struct CCTargetedTouchDelegate{
};
bool CCTargetedTouchDelegate::ccTouchBegan(this *CCTargetedTouchDelegate,CCTouch* pTouch,CCEvent* pEvent);
void CCTargetedTouchDelegate::ccTouchMoved(this *CCTargetedTouchDelegate,CCTouch* pTouch,CCEvent* pEvent);
void CCTargetedTouchDelegate::ccTouchEnded(this *CCTargetedTouchDelegate,CCTouch* pTouch,CCEvent* pEvent);
void CCTargetedTouchDelegate::ccTouchCancelled(this *CCTargetedTouchDelegate,CCTouch* pTouch,CCEvent* pEvent);
struct CCStandardTouchDelegate{
};
void CCStandardTouchDelegate::ccTouchesBegan(this *CCStandardTouchDelegate,CCSet* pTouches,CCEvent* pEvent);
void CCStandardTouchDelegate::ccTouchesMoved(this *CCStandardTouchDelegate,CCSet* pTouches,CCEvent* pEvent);
void CCStandardTouchDelegate::ccTouchesEnded(this *CCStandardTouchDelegate,CCSet* pTouches,CCEvent* pEvent);
void CCStandardTouchDelegate::ccTouchesCancelled(this *CCStandardTouchDelegate,CCSet* pTouches,CCEvent* pEvent);
struct CCAcceleration{
	double x;
	double y;
	double z;
	double timestamp;
};
struct CCAccelerometerDelegate{
};
void CCAccelerometerDelegate::didAccelerate(this *CCAccelerometerDelegate,CCAcceleration* pAccelerationValue);
struct CCKeyboardDelegate{
};


CCKeyboardDelegate& CCKeyboardDelegate::operator=(this *CCKeyboardDelegate);
void CCKeyboardDelegate::keyDown(this *CCKeyboardDelegate,enumKeyCodes key);
void CCKeyboardDelegate::keyUp(this *CCKeyboardDelegate,enumKeyCodes key);
struct CCKeyboardHandler{
	CCKeyboardDelegate* m_pDelegate;
};



CCKeyboardHandler& CCKeyboardHandler::operator=(this *CCKeyboardHandler);
CCKeyboardDelegate* CCKeyboardHandler::getDelegate(this *CCKeyboardHandler);
CCKeyboardHandler* CCKeyboardHandler::handlerWithDelegate(CCKeyboardDelegate* pDelegate);
bool CCKeyboardHandler::initWithDelegate(this *CCKeyboardHandler,CCKeyboardDelegate* pDelegate);
void CCKeyboardHandler::setDelegate(this *CCKeyboardHandler,CCKeyboardDelegate* pDelegate);
struct CCMouseDelegate{
};


CCMouseDelegate& CCMouseDelegate::operator=(this *CCMouseDelegate);
void CCMouseDelegate::rightKeyDown(this *CCMouseDelegate);
void CCMouseDelegate::rightKeyUp(this *CCMouseDelegate);
void CCMouseDelegate::scrollWheel(this *CCMouseDelegate,float x,float y);
struct CCMouseHandler{
	CCMouseDelegate* m_pDelegate;
};



CCMouseHandler& CCMouseHandler::operator=(this *CCMouseHandler);
CCMouseDelegate* CCMouseHandler::getDelegate(this *CCMouseHandler);
CCMouseHandler* CCMouseHandler::handlerWithDelegate(CCMouseDelegate* pDelegate);
bool CCMouseHandler::initWithDelegate(this *CCMouseHandler,CCMouseDelegate* pDelegate);
void CCMouseHandler::setDelegate(this *CCMouseHandler,CCMouseDelegate* pDelegate);
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


bool CCLayer::init(this *CCLayer);
CCLayer* CCLayer::create();
void CCLayer::onEnter(this *CCLayer);
void CCLayer::onExit(this *CCLayer);
void CCLayer::onEnterTransitionDidFinish(this *CCLayer);
bool CCLayer::ccTouchBegan(this *CCLayer,CCTouch* pTouch,CCEvent* pEvent);
void CCLayer::ccTouchMoved(this *CCLayer,CCTouch* pTouch,CCEvent* pEvent);
void CCLayer::ccTouchEnded(this *CCLayer,CCTouch* pTouch,CCEvent* pEvent);
void CCLayer::ccTouchCancelled(this *CCLayer,CCTouch* pTouch,CCEvent* pEvent);
void CCLayer::ccTouchesBegan(this *CCLayer,CCSet* pTouches,CCEvent* pEvent);
void CCLayer::ccTouchesMoved(this *CCLayer,CCSet* pTouches,CCEvent* pEvent);
void CCLayer::ccTouchesEnded(this *CCLayer,CCSet* pTouches,CCEvent* pEvent);
void CCLayer::ccTouchesCancelled(this *CCLayer,CCSet* pTouches,CCEvent* pEvent);
void CCLayer::didAccelerate(this *CCLayer,CCAcceleration* pAccelerationValue);
void CCLayer::registerScriptAccelerateHandler(this *CCLayer,int nHandler);
void CCLayer::unregisterScriptAccelerateHandler(this *CCLayer);
void CCLayer::registerWithTouchDispatcher(this *CCLayer);
void CCLayer::registerScriptTouchHandler(this *CCLayer,int nHandler,bool bIsMultiTouches,int nPriority,bool bSwallowsTouches);
void CCLayer::unregisterScriptTouchHandler(this *CCLayer);
bool CCLayer::isTouchEnabled(this *CCLayer);
void CCLayer::setTouchEnabled(this *CCLayer,bool value);
void CCLayer::setTouchMode(this *CCLayer,ccTouchesMode mode);
int CCLayer::getTouchMode(this *CCLayer);
void CCLayer::setTouchPriority(this *CCLayer,int priority);
int CCLayer::getTouchPriority(this *CCLayer);
bool CCLayer::isAccelerometerEnabled(this *CCLayer);
void CCLayer::setAccelerometerEnabled(this *CCLayer,bool value);
void CCLayer::setAccelerometerInterval(this *CCLayer,double interval);
bool CCLayer::isKeypadEnabled(this *CCLayer);
void CCLayer::setKeypadEnabled(this *CCLayer,bool value);
bool CCLayer::isKeyboardEnabled(this *CCLayer);
void CCLayer::setKeyboardEnabled(this *CCLayer,bool value);
bool CCLayer::isMouseEnabled(this *CCLayer);
void CCLayer::setMouseEnabled(this *CCLayer,bool value);
void CCLayer::registerScriptKeypadHandler(this *CCLayer,int nHandler);
void CCLayer::unregisterScriptKeypadHandler(this *CCLayer);
void CCLayer::keyBackClicked(this *CCLayer);
void CCLayer::keyMenuClicked(this *CCLayer);
void CCLayer::keyDown(this *CCLayer);
CCTouchScriptHandlerEntry* CCLayer::getScriptTouchHandlerEntry(this *CCLayer);
CCScriptHandlerEntry* CCLayer::getScriptKeypadHandlerEntry(this *CCLayer);
CCScriptHandlerEntry* CCLayer::getScriptAccelerateHandlerEntry(this *CCLayer);
int CCLayer::excuteScriptTouchHandler(this *CCLayer,int nEventType,CCTouch* pTouch);
int CCLayer::excuteScriptTouchHandler(this *CCLayer,int nEventType,CCSet* pTouches);
struct CCLayerRGBA{
	GLubyte _displayedOpacity;
	GLubyte _realOpacity;
	ccColor3B _displayedColor;
	ccColor3B _realColor;
	bool _cascadeOpacityEnabled;
	bool _cascadeColorEnabled;
};
CCLayerRGBA* CCLayerRGBA::create();


bool CCLayerRGBA::init(this *CCLayerRGBA);
GLubyte CCLayerRGBA::getOpacity(this *CCLayerRGBA);
GLubyte CCLayerRGBA::getDisplayedOpacity(this *CCLayerRGBA);
void CCLayerRGBA::setOpacity(this *CCLayerRGBA,GLubyte opacity);
void CCLayerRGBA::updateDisplayedOpacity(this *CCLayerRGBA,GLubyte parentOpacity);
bool CCLayerRGBA::isCascadeOpacityEnabled(this *CCLayerRGBA);
void CCLayerRGBA::setCascadeOpacityEnabled(this *CCLayerRGBA,bool cascadeOpacityEnabled);
const ccColor3B& CCLayerRGBA::getColor(this *CCLayerRGBA);
const ccColor3B& CCLayerRGBA::getDisplayedColor(this *CCLayerRGBA);
void CCLayerRGBA::setColor(this *CCLayerRGBA,const ccColor3B& color);
void CCLayerRGBA::updateDisplayedColor(this *CCLayerRGBA,const ccColor3B& parentColor);
bool CCLayerRGBA::isCascadeColorEnabled(this *CCLayerRGBA);
void CCLayerRGBA::setCascadeColorEnabled(this *CCLayerRGBA,bool cascadeColorEnabled);
void CCLayerRGBA::setOpacityModifyRGB(this *CCLayerRGBA,bool bValue);
bool CCLayerRGBA::isOpacityModifyRGB(this *CCLayerRGBA);
struct CCLayerColor{
	ccVertex2F[4] m_pSquareVertices;
	ccColor4F[4] m_pSquareColors;
	ccBlendFunc m_tBlendFunc;
};


void CCLayerColor::draw(this *CCLayerColor);
void CCLayerColor::setContentSize(this *CCLayerColor,const CCSize& var);
CCLayerColor* CCLayerColor::create();
CCLayerColor* CCLayerColor::create(const ccColor4B& color,GLfloat width,GLfloat height);
CCLayerColor* CCLayerColor::create(const ccColor4B& color);
bool CCLayerColor::init(this *CCLayerColor);
bool CCLayerColor::initWithColor(this *CCLayerColor,const ccColor4B& color,GLfloat width,GLfloat height);
bool CCLayerColor::initWithColor(this *CCLayerColor,const ccColor4B& color);
void CCLayerColor::changeWidth(this *CCLayerColor,GLfloat w);
void CCLayerColor::changeHeight(this *CCLayerColor,GLfloat h);
void CCLayerColor::changeWidthAndHeight(this *CCLayerColor,GLfloat w,GLfloat h);
ccBlendFunc CCLayerColor::getBlendFunc(this *CCLayerColor);
void CCLayerColor::setBlendFunc(this *CCLayerColor,ccBlendFunc var);
void CCLayerColor::setColor(this *CCLayerColor,const ccColor3B& color);
void CCLayerColor::setOpacity(this *CCLayerColor,GLubyte opacity);
void CCLayerColor::updateColor(this *CCLayerColor);
struct CCLayerGradient{
	ccColor3B m_startColor;
	ccColor3B m_endColor;
	GLubyte m_cStartOpacity;
	GLubyte m_cEndOpacity;
	CCPoint m_AlongVector;
	bool m_bCompressedInterpolation;
};
CCLayerGradient* CCLayerGradient::create(const ccColor4B& start,const ccColor4B& end);
CCLayerGradient* CCLayerGradient::create(const ccColor4B& start,const ccColor4B& end,const CCPoint& v);
bool CCLayerGradient::init(this *CCLayerGradient);
bool CCLayerGradient::initWithColor(this *CCLayerGradient,const ccColor4B& start,const ccColor4B& end);
bool CCLayerGradient::initWithColor(this *CCLayerGradient,const ccColor4B& start,const ccColor4B& end,const CCPoint& v);
const ccColor3B& CCLayerGradient::getStartColor(this *CCLayerGradient);
void CCLayerGradient::setStartColor(this *CCLayerGradient,const ccColor3B& var);
const ccColor3B& CCLayerGradient::getEndColor(this *CCLayerGradient);
void CCLayerGradient::setEndColor(this *CCLayerGradient,const ccColor3B& var);
GLubyte CCLayerGradient::getStartOpacity(this *CCLayerGradient);
void CCLayerGradient::setStartOpacity(this *CCLayerGradient,GLubyte var);
GLubyte CCLayerGradient::getEndOpacity(this *CCLayerGradient);
void CCLayerGradient::setEndOpacity(this *CCLayerGradient,GLubyte var);
const CCPoint& CCLayerGradient::getVector(this *CCLayerGradient);
void CCLayerGradient::setVector(this *CCLayerGradient,const CCPoint& var);
void CCLayerGradient::setCompressedInterpolation(this *CCLayerGradient,bool bCompressedInterpolation);
bool CCLayerGradient::isCompressedInterpolation(this *CCLayerGradient);
CCLayerGradient* CCLayerGradient::create();
void CCLayerGradient::updateColor(this *CCLayerGradient);
struct CCLayerMultiplex{
	unsigned int m_nEnabledLayer;
	CCArray* m_pLayers;
};


CCLayerMultiplex* CCLayerMultiplex::create();
CCLayerMultiplex* CCLayerMultiplex::createWithArray(CCArray* arrayOfLayers);
CCLayerMultiplex* CCLayerMultiplex::create(CCLayer* layer);
CCLayerMultiplex* CCLayerMultiplex::createWithLayer(CCLayer* layer);
void CCLayerMultiplex::addLayer(this *CCLayerMultiplex,CCLayer* layer);
bool CCLayerMultiplex::initWithLayers(this *CCLayerMultiplex,CCLayer* layer,va_list params);
bool CCLayerMultiplex::initWithArray(this *CCLayerMultiplex,CCArray* arrayOfLayers);
void CCLayerMultiplex::switchTo(this *CCLayerMultiplex,unsigned int n);
void CCLayerMultiplex::switchToAndReleaseMe(this *CCLayerMultiplex,unsigned int n);
struct CCScene{
	void* m_pIDK;
};


bool CCScene::init(this *CCScene);
CCScene* CCScene::create();

CCScene& CCScene::operator=(this *CCScene);
int CCScene::getHighestChildZ(this *CCScene);
struct CCTransitionEaseScene{
};
CCActionInterval* CCTransitionEaseScene::easeActionWithAction(this *CCTransitionEaseScene,CCActionInterval* action);
struct CCTransitionScene{
	CCScene* m_pInScene;
	CCScene* m_pOutScene;
	float m_fDuration;
	bool m_bIsInSceneOnTop;
	bool m_bIsSendCleanupToScene;
};


void CCTransitionScene::draw(this *CCTransitionScene);
void CCTransitionScene::onEnter(this *CCTransitionScene);
void CCTransitionScene::onExit(this *CCTransitionScene);
void CCTransitionScene::cleanup(this *CCTransitionScene);
CCTransitionScene* CCTransitionScene::create(float t,CCScene* scene);
bool CCTransitionScene::initWithDuration(this *CCTransitionScene,float t,CCScene* scene);
void CCTransitionScene::finish(this *CCTransitionScene);
void CCTransitionScene::hideOutShowIn(this *CCTransitionScene);
void CCTransitionScene::sceneOrder(this *CCTransitionScene);
void CCTransitionScene::setNewScene(this *CCTransitionScene,float dt);
struct CCTransitionSceneOriented{
	tOrientation m_eOrientation;
};


CCTransitionSceneOriented* CCTransitionSceneOriented::create(float t,CCScene* scene,tOrientation orientation);
bool CCTransitionSceneOriented::initWithDuration(this *CCTransitionSceneOriented,float t,CCScene* scene,tOrientation orientation);
struct CCTransitionRotoZoom{
};


void CCTransitionRotoZoom::onEnter(this *CCTransitionRotoZoom);
CCTransitionRotoZoom* CCTransitionRotoZoom::create(float t,CCScene* scene);
struct CCTransitionJumpZoom{
};


void CCTransitionJumpZoom::onEnter(this *CCTransitionJumpZoom);
CCTransitionJumpZoom* CCTransitionJumpZoom::create(float t,CCScene* scene);
struct CCTransitionMoveInL{
};


void CCTransitionMoveInL::initScenes(this *CCTransitionMoveInL);
CCActionInterval* CCTransitionMoveInL::action(this *CCTransitionMoveInL);
CCActionInterval* CCTransitionMoveInL::easeActionWithAction(this *CCTransitionMoveInL,CCActionInterval* action);
void CCTransitionMoveInL::onEnter(this *CCTransitionMoveInL);
CCTransitionMoveInL* CCTransitionMoveInL::create(float t,CCScene* scene);
struct CCTransitionMoveInR{
};


void CCTransitionMoveInR::initScenes(this *CCTransitionMoveInR);
CCTransitionMoveInR* CCTransitionMoveInR::create(float t,CCScene* scene);
struct CCTransitionMoveInT{
};


void CCTransitionMoveInT::initScenes(this *CCTransitionMoveInT);
CCTransitionMoveInT* CCTransitionMoveInT::create(float t,CCScene* scene);
struct CCTransitionMoveInB{
};


void CCTransitionMoveInB::initScenes(this *CCTransitionMoveInB);
CCTransitionMoveInB* CCTransitionMoveInB::create(float t,CCScene* scene);
struct CCTransitionSlideInL{
};


void CCTransitionSlideInL::initScenes(this *CCTransitionSlideInL);
CCActionInterval* CCTransitionSlideInL::action(this *CCTransitionSlideInL);
void CCTransitionSlideInL::onEnter(this *CCTransitionSlideInL);
CCActionInterval* CCTransitionSlideInL::easeActionWithAction(this *CCTransitionSlideInL,CCActionInterval* action);
CCTransitionSlideInL* CCTransitionSlideInL::create(float t,CCScene* scene);
void CCTransitionSlideInL::sceneOrder(this *CCTransitionSlideInL);
struct CCTransitionSlideInR{
};


void CCTransitionSlideInR::initScenes(this *CCTransitionSlideInR);
CCActionInterval* CCTransitionSlideInR::action(this *CCTransitionSlideInR);
CCTransitionSlideInR* CCTransitionSlideInR::create(float t,CCScene* scene);
void CCTransitionSlideInR::sceneOrder(this *CCTransitionSlideInR);
struct CCTransitionSlideInB{
};


void CCTransitionSlideInB::initScenes(this *CCTransitionSlideInB);
CCActionInterval* CCTransitionSlideInB::action(this *CCTransitionSlideInB);
CCTransitionSlideInB* CCTransitionSlideInB::create(float t,CCScene* scene);
void CCTransitionSlideInB::sceneOrder(this *CCTransitionSlideInB);
struct CCTransitionSlideInT{
};


void CCTransitionSlideInT::initScenes(this *CCTransitionSlideInT);
CCActionInterval* CCTransitionSlideInT::action(this *CCTransitionSlideInT);
CCTransitionSlideInT* CCTransitionSlideInT::create(float t,CCScene* scene);
void CCTransitionSlideInT::sceneOrder(this *CCTransitionSlideInT);
struct CCTransitionShrinkGrow{
};


void CCTransitionShrinkGrow::onEnter(this *CCTransitionShrinkGrow);
CCActionInterval* CCTransitionShrinkGrow::easeActionWithAction(this *CCTransitionShrinkGrow,CCActionInterval* action);
CCTransitionShrinkGrow* CCTransitionShrinkGrow::create(float t,CCScene* scene);
struct CCTransitionFlipX{
};


void CCTransitionFlipX::onEnter(this *CCTransitionFlipX);
CCTransitionFlipX* CCTransitionFlipX::create(float t,CCScene* s,tOrientation o);
CCTransitionFlipX* CCTransitionFlipX::create(float t,CCScene* s);
struct CCTransitionFlipY{
};


void CCTransitionFlipY::onEnter(this *CCTransitionFlipY);
CCTransitionFlipY* CCTransitionFlipY::create(float t,CCScene* s,tOrientation o);
CCTransitionFlipY* CCTransitionFlipY::create(float t,CCScene* s);
struct CCTransitionFlipAngular{
};


void CCTransitionFlipAngular::onEnter(this *CCTransitionFlipAngular);
CCTransitionFlipAngular* CCTransitionFlipAngular::create(float t,CCScene* s,tOrientation o);
CCTransitionFlipAngular* CCTransitionFlipAngular::create(float t,CCScene* s);
struct CCTransitionZoomFlipX{
};


void CCTransitionZoomFlipX::onEnter(this *CCTransitionZoomFlipX);
CCTransitionZoomFlipX* CCTransitionZoomFlipX::create(float t,CCScene* s,tOrientation o);
CCTransitionZoomFlipX* CCTransitionZoomFlipX::create(float t,CCScene* s);
struct CCTransitionZoomFlipY{
};


void CCTransitionZoomFlipY::onEnter(this *CCTransitionZoomFlipY);
CCTransitionZoomFlipY* CCTransitionZoomFlipY::create(float t,CCScene* s,tOrientation o);
CCTransitionZoomFlipY* CCTransitionZoomFlipY::create(float t,CCScene* s);
struct CCTransitionZoomFlipAngular{
};


void CCTransitionZoomFlipAngular::onEnter(this *CCTransitionZoomFlipAngular);
CCTransitionZoomFlipAngular* CCTransitionZoomFlipAngular::create(float t,CCScene* s,tOrientation o);
CCTransitionZoomFlipAngular* CCTransitionZoomFlipAngular::create(float t,CCScene* s);
struct CCTransitionFade{
	ccColor4B m_tColor;
};


CCTransitionFade* CCTransitionFade::create(float duration,CCScene* scene,const ccColor3B& color);
CCTransitionFade* CCTransitionFade::create(float duration,CCScene* scene);
bool CCTransitionFade::initWithDuration(this *CCTransitionFade,float t,CCScene* scene,const ccColor3B& color);
bool CCTransitionFade::initWithDuration(this *CCTransitionFade,float t,CCScene* scene);
void CCTransitionFade::onEnter(this *CCTransitionFade);
void CCTransitionFade::onExit(this *CCTransitionFade);
struct CCTransitionCrossFade{
};


void CCTransitionCrossFade::draw(this *CCTransitionCrossFade);
void CCTransitionCrossFade::onEnter(this *CCTransitionCrossFade);
void CCTransitionCrossFade::onExit(this *CCTransitionCrossFade);
CCTransitionCrossFade* CCTransitionCrossFade::create(float t,CCScene* scene);
struct CCTransitionTurnOffTiles{
};


void CCTransitionTurnOffTiles::onEnter(this *CCTransitionTurnOffTiles);
CCActionInterval* CCTransitionTurnOffTiles::easeActionWithAction(this *CCTransitionTurnOffTiles,CCActionInterval* action);
CCTransitionTurnOffTiles* CCTransitionTurnOffTiles::create(float t,CCScene* scene);
void CCTransitionTurnOffTiles::sceneOrder(this *CCTransitionTurnOffTiles);
struct CCTransitionSplitCols{
};


CCActionInterval* CCTransitionSplitCols::action(this *CCTransitionSplitCols);
void CCTransitionSplitCols::onEnter(this *CCTransitionSplitCols);
CCActionInterval* CCTransitionSplitCols::easeActionWithAction(this *CCTransitionSplitCols,CCActionInterval* action);
CCTransitionSplitCols* CCTransitionSplitCols::create(float t,CCScene* scene);
struct CCTransitionSplitRows{
};


CCActionInterval* CCTransitionSplitRows::action(this *CCTransitionSplitRows);
CCTransitionSplitRows* CCTransitionSplitRows::create(float t,CCScene* scene);
struct CCTransitionFadeTR{
};


CCActionInterval* CCTransitionFadeTR::actionWithSize(this *CCTransitionFadeTR,const CCSize& size);
void CCTransitionFadeTR::onEnter(this *CCTransitionFadeTR);
CCActionInterval* CCTransitionFadeTR::easeActionWithAction(this *CCTransitionFadeTR,CCActionInterval* action);
CCTransitionFadeTR* CCTransitionFadeTR::create(float t,CCScene* scene);
void CCTransitionFadeTR::sceneOrder(this *CCTransitionFadeTR);
struct CCTransitionFadeBL{
};


CCActionInterval* CCTransitionFadeBL::actionWithSize(this *CCTransitionFadeBL,const CCSize& size);
CCTransitionFadeBL* CCTransitionFadeBL::create(float t,CCScene* scene);
struct CCTransitionFadeUp{
};


CCActionInterval* CCTransitionFadeUp::actionWithSize(this *CCTransitionFadeUp,const CCSize& size);
CCTransitionFadeUp* CCTransitionFadeUp::create(float t,CCScene* scene);
struct CCTransitionFadeDown{
};


CCActionInterval* CCTransitionFadeDown::actionWithSize(this *CCTransitionFadeDown,const CCSize& size);
CCTransitionFadeDown* CCTransitionFadeDown::create(float t,CCScene* scene);
struct CCTransitionPageTurn{
	bool m_bBack;
};


CCTransitionPageTurn* CCTransitionPageTurn::create(float t,CCScene* scene,bool backwards);
bool CCTransitionPageTurn::initWithDuration(this *CCTransitionPageTurn,float t,CCScene* scene,bool backwards);
CCActionInterval* CCTransitionPageTurn::actionWithSize(this *CCTransitionPageTurn,const CCSize& vector);
void CCTransitionPageTurn::onEnter(this *CCTransitionPageTurn);
void CCTransitionPageTurn::sceneOrder(this *CCTransitionPageTurn);
struct CCTransitionProgress{
	float m_fTo;
	float m_fFrom;
	CCScene* m_pSceneToBeModified;
};
CCTransitionProgress* CCTransitionProgress::create(float t,CCScene* scene);

void CCTransitionProgress::onEnter(this *CCTransitionProgress);
void CCTransitionProgress::onExit(this *CCTransitionProgress);
CCProgressTimer* CCTransitionProgress::progressTimerNodeWithRenderTexture(this *CCTransitionProgress,CCRenderTexture* texture);
void CCTransitionProgress::setupTransition(this *CCTransitionProgress);
void CCTransitionProgress::sceneOrder(this *CCTransitionProgress);
struct CCTransitionProgressRadialCCW{
};
CCTransitionProgressRadialCCW* CCTransitionProgressRadialCCW::create(float t,CCScene* scene);
CCProgressTimer* CCTransitionProgressRadialCCW::progressTimerNodeWithRenderTexture(this *CCTransitionProgressRadialCCW,CCRenderTexture* texture);
struct CCTransitionProgressRadialCW{
};
CCTransitionProgressRadialCW* CCTransitionProgressRadialCW::create(float t,CCScene* scene);
CCProgressTimer* CCTransitionProgressRadialCW::progressTimerNodeWithRenderTexture(this *CCTransitionProgressRadialCW,CCRenderTexture* texture);
struct CCTransitionProgressHorizontal{
};
CCTransitionProgressHorizontal* CCTransitionProgressHorizontal::create(float t,CCScene* scene);
CCProgressTimer* CCTransitionProgressHorizontal::progressTimerNodeWithRenderTexture(this *CCTransitionProgressHorizontal,CCRenderTexture* texture);
struct CCTransitionProgressVertical{
};
CCTransitionProgressVertical* CCTransitionProgressVertical::create(float t,CCScene* scene);
CCProgressTimer* CCTransitionProgressVertical::progressTimerNodeWithRenderTexture(this *CCTransitionProgressVertical,CCRenderTexture* texture);
struct CCTransitionProgressInOut{
};
CCTransitionProgressInOut* CCTransitionProgressInOut::create(float t,CCScene* scene);
CCProgressTimer* CCTransitionProgressInOut::progressTimerNodeWithRenderTexture(this *CCTransitionProgressInOut,CCRenderTexture* texture);
void CCTransitionProgressInOut::sceneOrder(this *CCTransitionProgressInOut);
void CCTransitionProgressInOut::setupTransition(this *CCTransitionProgressInOut);
struct CCTransitionProgressOutIn{
};
CCTransitionProgressOutIn* CCTransitionProgressOutIn::create(float t,CCScene* scene);
CCProgressTimer* CCTransitionProgressOutIn::progressTimerNodeWithRenderTexture(this *CCTransitionProgressOutIn,CCRenderTexture* texture);
struct CCMenuItem{
	bool m_bSelected;
	bool m_bEnabled;
	CCObject* m_pListener;
	SEL_MenuHandler m_pfnSelector;
	int m_nScriptTapHandler;
};


CCMenuItem* CCMenuItem::create();
CCMenuItem* CCMenuItem::create(CCObject* rec,SEL_MenuHandler selector);
bool CCMenuItem::initWithTarget(this *CCMenuItem,CCObject* rec,SEL_MenuHandler selector);
CCRect CCMenuItem::rect(this *CCMenuItem);
void CCMenuItem::activate(this *CCMenuItem);
void CCMenuItem::selected(this *CCMenuItem);
void CCMenuItem::unselected(this *CCMenuItem);
void CCMenuItem::registerScriptTapHandler(this *CCMenuItem,int nHandler);
void CCMenuItem::unregisterScriptTapHandler(this *CCMenuItem);
int CCMenuItem::getScriptTapHandler(this *CCMenuItem);
bool CCMenuItem::isEnabled(this *CCMenuItem);
void CCMenuItem::setEnabled(this *CCMenuItem,bool value);
bool CCMenuItem::isSelected(this *CCMenuItem);
void CCMenuItem::setTarget(this *CCMenuItem,CCObject* rec,SEL_MenuHandler selector);
struct CCMenuItemLabel{
	ccColor3B m_tDisabledColor;
	CCNode* m_pLabel;
	ccColor3B m_tColorBackup;
	float m_fOriginalScale;
};
const ccColor3B& CCMenuItemLabel::getDisabledColor(this *CCMenuItemLabel);
void CCMenuItemLabel::setDisabledColor(this *CCMenuItemLabel,const ccColor3B& var);
CCNode* CCMenuItemLabel::getLabel(this *CCMenuItemLabel);
void CCMenuItemLabel::setLabel(this *CCMenuItemLabel,CCNode* var);


CCMenuItemLabel* CCMenuItemLabel::create(CCNode* label,CCObject* target,SEL_MenuHandler selector);
CCMenuItemLabel* CCMenuItemLabel::create(CCNode* label);
bool CCMenuItemLabel::initWithLabel(this *CCMenuItemLabel,CCNode* label,CCObject* target,SEL_MenuHandler selector);
void CCMenuItemLabel::setString(this *CCMenuItemLabel,const char* label);
void CCMenuItemLabel::activate(this *CCMenuItemLabel);
void CCMenuItemLabel::selected(this *CCMenuItemLabel);
void CCMenuItemLabel::unselected(this *CCMenuItemLabel);
void CCMenuItemLabel::setEnabled(this *CCMenuItemLabel,bool enabled);
struct CCMenuItemAtlasFont{
};


CCMenuItemAtlasFont* CCMenuItemAtlasFont::create(const char* value,const char* charMapFile,int itemWidth,int itemHeight,char startCharMap);
CCMenuItemAtlasFont* CCMenuItemAtlasFont::create(const char* value,const char* charMapFile,int itemWidth,int itemHeight,char startCharMap,CCObject* target,SEL_MenuHandler selector);
bool CCMenuItemAtlasFont::initWithString(this *CCMenuItemAtlasFont,const char* value,const char* charMapFile,int itemWidth,int itemHeight,char startCharMap,CCObject* target,SEL_MenuHandler selector);
struct CCMenuItemFont{
	unsigned int m_uFontSize;
	basic_string m_strFontName;
};


void CCMenuItemFont::setFontSize(unsigned int s);
unsigned int CCMenuItemFont::fontSize();
void CCMenuItemFont::setFontName(const char* name);
const char* CCMenuItemFont::fontName();
CCMenuItemFont* CCMenuItemFont::create(const char* value);
CCMenuItemFont* CCMenuItemFont::create(const char* value,CCObject* target,SEL_MenuHandler selector);
bool CCMenuItemFont::initWithString(this *CCMenuItemFont,const char* value,CCObject* target,SEL_MenuHandler selector);
void CCMenuItemFont::setFontSizeObj(this *CCMenuItemFont,unsigned int s);
unsigned int CCMenuItemFont::fontSizeObj(this *CCMenuItemFont);
void CCMenuItemFont::setFontNameObj(this *CCMenuItemFont,const char* name);
const char* CCMenuItemFont::fontNameObj(this *CCMenuItemFont);
void CCMenuItemFont::recreateLabel(this *CCMenuItemFont);
struct CCMenuItemSprite{
	CCNode* m_pNormalImage;
	CCNode* m_pSelectedImage;
	CCNode* m_pDisabledImage;
};
CCNode* CCMenuItemSprite::getNormalImage(this *CCMenuItemSprite);
void CCMenuItemSprite::setNormalImage(this *CCMenuItemSprite,CCNode* var);
CCNode* CCMenuItemSprite::getSelectedImage(this *CCMenuItemSprite);
void CCMenuItemSprite::setSelectedImage(this *CCMenuItemSprite,CCNode* var);
CCNode* CCMenuItemSprite::getDisabledImage(this *CCMenuItemSprite);
void CCMenuItemSprite::setDisabledImage(this *CCMenuItemSprite,CCNode* var);

CCMenuItemSprite* CCMenuItemSprite::create(CCNode* normalSprite,CCNode* selectedSprite,CCNode* disabledSprite);
CCMenuItemSprite* CCMenuItemSprite::create(CCNode* normalSprite,CCNode* selectedSprite,CCObject* target,SEL_MenuHandler selector);
CCMenuItemSprite* CCMenuItemSprite::create(CCNode* normalSprite,CCNode* selectedSprite,CCNode* disabledSprite,CCObject* target,SEL_MenuHandler selector);
bool CCMenuItemSprite::initWithNormalSprite(this *CCMenuItemSprite,CCNode* normalSprite,CCNode* selectedSprite,CCNode* disabledSprite,CCObject* target,SEL_MenuHandler selector);
void CCMenuItemSprite::selected(this *CCMenuItemSprite);
void CCMenuItemSprite::unselected(this *CCMenuItemSprite);
void CCMenuItemSprite::setEnabled(this *CCMenuItemSprite,bool bEnabled);
void CCMenuItemSprite::updateImagesVisibility(this *CCMenuItemSprite);
struct CCMenuItemImage{
};


CCMenuItemImage* CCMenuItemImage::create(const char* normalImage,const char* selectedImage);
CCMenuItemImage* CCMenuItemImage::create(const char* normalImage,const char* selectedImage,const char* disabledImage);
CCMenuItemImage* CCMenuItemImage::create(const char* normalImage,const char* selectedImage,CCObject* target,SEL_MenuHandler selector);
CCMenuItemImage* CCMenuItemImage::create(const char* normalImage,const char* selectedImage,const char* disabledImage,CCObject* target,SEL_MenuHandler selector);
bool CCMenuItemImage::init(this *CCMenuItemImage);
bool CCMenuItemImage::initWithNormalImage(this *CCMenuItemImage,const char* normalImage,const char* selectedImage,const char* disabledImage,CCObject* target,SEL_MenuHandler selector);
void CCMenuItemImage::setNormalSpriteFrame(this *CCMenuItemImage,CCSpriteFrame* frame);
void CCMenuItemImage::setSelectedSpriteFrame(this *CCMenuItemImage,CCSpriteFrame* frame);
void CCMenuItemImage::setDisabledSpriteFrame(this *CCMenuItemImage,CCSpriteFrame* frame);
CCMenuItemImage* CCMenuItemImage::create();
struct CCMenuItemToggle{
	unsigned int m_uSelectedIndex;
	CCArray* m_pSubItems;
};
unsigned int CCMenuItemToggle::getSelectedIndex(this *CCMenuItemToggle);
void CCMenuItemToggle::setSelectedIndex(this *CCMenuItemToggle,unsigned int var);
CCArray* CCMenuItemToggle::getSubItems(this *CCMenuItemToggle);
void CCMenuItemToggle::setSubItems(this *CCMenuItemToggle,CCArray* var);


CCMenuItemToggle* CCMenuItemToggle::createWithTarget(CCObject* target,SEL_MenuHandler selector,CCArray* menuItems);
CCMenuItemToggle* CCMenuItemToggle::createWithTarget(CCObject* target,SEL_MenuHandler selector,CCMenuItem* item);
CCMenuItemToggle* CCMenuItemToggle::create();
bool CCMenuItemToggle::initWithTarget(this *CCMenuItemToggle,CCObject* target,SEL_MenuHandler selector,CCMenuItem* item,va_list args);
CCMenuItemToggle* CCMenuItemToggle::create(CCMenuItem* item);
bool CCMenuItemToggle::initWithItem(this *CCMenuItemToggle,CCMenuItem* item);
void CCMenuItemToggle::addSubItem(this *CCMenuItemToggle,CCMenuItem* item);
CCMenuItem* CCMenuItemToggle::selectedItem(this *CCMenuItemToggle);
void CCMenuItemToggle::activate(this *CCMenuItemToggle);
void CCMenuItemToggle::selected(this *CCMenuItemToggle);
void CCMenuItemToggle::unselected(this *CCMenuItemToggle);
void CCMenuItemToggle::setEnabled(this *CCMenuItemToggle,bool var);
struct CCMenu{
	bool m_bEnabled;
	tCCMenuState m_eState;
	CCMenuItem* m_pSelectedItem;
};


CCMenu* CCMenu::create();
CCMenu* CCMenu::create(CCMenuItem* item);
CCMenu* CCMenu::createWithArray(CCArray* pArrayOfItems);
CCMenu* CCMenu::createWithItem(CCMenuItem* item);
CCMenu* CCMenu::createWithItems(CCMenuItem* firstItem,va_list args);
bool CCMenu::init(this *CCMenu);
bool CCMenu::initWithArray(this *CCMenu,CCArray* pArrayOfItems);
void CCMenu::alignItemsVertically(this *CCMenu);
void CCMenu::alignItemsVerticallyWithPadding(this *CCMenu,float padding);
void CCMenu::alignItemsHorizontally(this *CCMenu);
void CCMenu::alignItemsHorizontallyWithPadding(this *CCMenu,float padding);
void CCMenu::alignItemsInColumns(this *CCMenu,unsigned int columns);
void CCMenu::alignItemsInColumns(this *CCMenu,unsigned int columns,va_list args);
void CCMenu::alignItemsInColumnsWithArray(this *CCMenu,CCArray* rows);
void CCMenu::alignItemsInRows(this *CCMenu,unsigned int rows);
void CCMenu::alignItemsInRows(this *CCMenu,unsigned int rows,va_list args);
void CCMenu::alignItemsInRowsWithArray(this *CCMenu,CCArray* columns);
void CCMenu::setHandlerPriority(this *CCMenu,int newPriority);
void CCMenu::addChild(this *CCMenu,CCNode* child);
void CCMenu::addChild(this *CCMenu,CCNode* child,int zOrder);
void CCMenu::addChild(this *CCMenu,CCNode* child,int zOrder,int tag);
void CCMenu::registerWithTouchDispatcher(this *CCMenu);
void CCMenu::removeChild(this *CCMenu,CCNode* child,bool cleanup);
bool CCMenu::ccTouchBegan(this *CCMenu,CCTouch* touch,CCEvent* event);
void CCMenu::ccTouchEnded(this *CCMenu,CCTouch* touch,CCEvent* event);
void CCMenu::ccTouchCancelled(this *CCMenu,CCTouch* touch,CCEvent* event);
void CCMenu::ccTouchMoved(this *CCMenu,CCTouch* touch,CCEvent* event);
void CCMenu::onExit(this *CCMenu);
void CCMenu::setOpacityModifyRGB(this *CCMenu,bool bValue);
bool CCMenu::isOpacityModifyRGB(this *CCMenu);
bool CCMenu::isEnabled(this *CCMenu);
void CCMenu::setEnabled(this *CCMenu,bool value);
CCMenuItem* CCMenu::itemForTouch(this *CCMenu,CCTouch* touch);
struct CCClippingNode{
	CCNode* m_pStencil;
	GLfloat m_fAlphaThreshold;
	bool m_bInverted;
};
CCClippingNode* CCClippingNode::create();
CCClippingNode* CCClippingNode::create(CCNode* pStencil);

bool CCClippingNode::init(this *CCClippingNode);
bool CCClippingNode::init(this *CCClippingNode,CCNode* pStencil);
void CCClippingNode::onEnter(this *CCClippingNode);
void CCClippingNode::onEnterTransitionDidFinish(this *CCClippingNode);
void CCClippingNode::onExitTransitionDidStart(this *CCClippingNode);
void CCClippingNode::onExit(this *CCClippingNode);
void CCClippingNode::visit(this *CCClippingNode);
CCNode* CCClippingNode::getStencil(this *CCClippingNode);
void CCClippingNode::setStencil(this *CCClippingNode,CCNode* pStencil);
GLfloat CCClippingNode::getAlphaThreshold(this *CCClippingNode);
void CCClippingNode::setAlphaThreshold(this *CCClippingNode,GLfloat fAlphaThreshold);
bool CCClippingNode::isInverted(this *CCClippingNode);
void CCClippingNode::setInverted(this *CCClippingNode,bool bInverted);

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


CCMotionStreak* CCMotionStreak::create(float fade,float minSeg,float stroke,const ccColor3B& color,const char* path);
CCMotionStreak* CCMotionStreak::create(float fade,float minSeg,float stroke,const ccColor3B& color,CCTexture2D* texture);
bool CCMotionStreak::initWithFade(this *CCMotionStreak,float fade,float minSeg,float stroke,const ccColor3B& color,const char* path);
bool CCMotionStreak::initWithFade(this *CCMotionStreak,float fade,float minSeg,float stroke,const ccColor3B& color,CCTexture2D* texture);
void CCMotionStreak::tintWithColor(this *CCMotionStreak,ccColor3B colors);
void CCMotionStreak::reset(this *CCMotionStreak);
void CCMotionStreak::setPosition(this *CCMotionStreak,const CCPoint& position);
void CCMotionStreak::draw(this *CCMotionStreak);
void CCMotionStreak::update(this *CCMotionStreak,float delta);
CCTexture2D* CCMotionStreak::getTexture(this *CCMotionStreak);
void CCMotionStreak::setTexture(this *CCMotionStreak,CCTexture2D* texture);
void CCMotionStreak::setBlendFunc(this *CCMotionStreak,ccBlendFunc blendFunc);
ccBlendFunc CCMotionStreak::getBlendFunc(this *CCMotionStreak);
GLubyte CCMotionStreak::getOpacity(this *CCMotionStreak);
void CCMotionStreak::setOpacity(this *CCMotionStreak,GLubyte opacity);
void CCMotionStreak::setOpacityModifyRGB(this *CCMotionStreak,bool bValue);
bool CCMotionStreak::isOpacityModifyRGB(this *CCMotionStreak);
bool CCMotionStreak::isFastMode(this *CCMotionStreak);
void CCMotionStreak::setFastMode(this *CCMotionStreak,bool bFastMode);
bool CCMotionStreak::isStartingPositionInitialized(this *CCMotionStreak);
void CCMotionStreak::setStartingPositionInitialized(this *CCMotionStreak,bool bStartingPositionInitialized);
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


CCProgressTimerType CCProgressTimer::getType(this *CCProgressTimer);
float CCProgressTimer::getPercentage(this *CCProgressTimer);
CCSprite* CCProgressTimer::getSprite(this *CCProgressTimer);
bool CCProgressTimer::initWithSprite(this *CCProgressTimer,CCSprite* sp);
void CCProgressTimer::setPercentage(this *CCProgressTimer,float fPercentage);
void CCProgressTimer::setSprite(this *CCProgressTimer,CCSprite* pSprite);
void CCProgressTimer::setType(this *CCProgressTimer,CCProgressTimerType type);
void CCProgressTimer::setReverseProgress(this *CCProgressTimer,bool reverse);
void CCProgressTimer::draw(this *CCProgressTimer);
void CCProgressTimer::setAnchorPoint(this *CCProgressTimer,CCPoint anchorPoint);
void CCProgressTimer::setColor(this *CCProgressTimer,const ccColor3B& color);
const ccColor3B& CCProgressTimer::getColor(this *CCProgressTimer);
GLubyte CCProgressTimer::getOpacity(this *CCProgressTimer);
void CCProgressTimer::setOpacity(this *CCProgressTimer,GLubyte opacity);
bool CCProgressTimer::isReverseDirection(this *CCProgressTimer);
void CCProgressTimer::setReverseDirection(this *CCProgressTimer,bool value);
CCProgressTimer* CCProgressTimer::create(CCSprite* sp);
ccTex2F CCProgressTimer::textureCoordFromAlphaPoint(this *CCProgressTimer,CCPoint alpha);
ccVertex2F CCProgressTimer::vertexFromAlphaPoint(this *CCProgressTimer,CCPoint alpha);
void CCProgressTimer::updateProgress(this *CCProgressTimer);
void CCProgressTimer::updateBar(this *CCProgressTimer);
void CCProgressTimer::updateRadial(this *CCProgressTimer);
void CCProgressTimer::updateColor(this *CCProgressTimer);
CCPoint CCProgressTimer::boundaryTexCoord(this *CCProgressTimer,char index);
CCPoint CCProgressTimer::getMidpoint(this *CCProgressTimer);
void CCProgressTimer::setMidpoint(this *CCProgressTimer,CCPoint var);
CCPoint CCProgressTimer::getBarChangeRate(this *CCProgressTimer);
void CCProgressTimer::setBarChangeRate(this *CCProgressTimer,CCPoint var);
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
CCSprite* CCRenderTexture::getSprite(this *CCRenderTexture);
void CCRenderTexture::setSprite(this *CCRenderTexture,CCSprite* var);


void CCRenderTexture::visit(this *CCRenderTexture);
void CCRenderTexture::draw(this *CCRenderTexture);
CCRenderTexture* CCRenderTexture::create(int w,int h,CCTexture2DPixelFormat eFormat,GLuint uDepthStencilFormat);
CCRenderTexture* CCRenderTexture::create(int w,int h,CCTexture2DPixelFormat eFormat);
CCRenderTexture* CCRenderTexture::create(int w,int h);
bool CCRenderTexture::initWithWidthAndHeight(this *CCRenderTexture,int w,int h,CCTexture2DPixelFormat eFormat);
bool CCRenderTexture::initWithWidthAndHeight(this *CCRenderTexture,int w,int h,CCTexture2DPixelFormat eFormat,GLuint uDepthStencilFormat);
void CCRenderTexture::begin(this *CCRenderTexture);
void CCRenderTexture::beginWithClear(this *CCRenderTexture,float r,float g,float b,float a);
void CCRenderTexture::beginWithClear(this *CCRenderTexture,float r,float g,float b,float a,float depthValue);
void CCRenderTexture::beginWithClear(this *CCRenderTexture,float r,float g,float b,float a,float depthValue,int stencilValue);
void CCRenderTexture::endToLua(this *CCRenderTexture);
void CCRenderTexture::end(this *CCRenderTexture);
void CCRenderTexture::clear(this *CCRenderTexture,float r,float g,float b,float a);
void CCRenderTexture::clearDepth(this *CCRenderTexture,float depthValue);
void CCRenderTexture::clearStencil(this *CCRenderTexture,int stencilValue);
CCImage* CCRenderTexture::newCCImage(this *CCRenderTexture,bool flipImage);
bool CCRenderTexture::saveToFile(this *CCRenderTexture,const char* szFilePath);
bool CCRenderTexture::saveToFile(this *CCRenderTexture,const char* name,tCCImageFormat format);
void CCRenderTexture::listenToBackground(this *CCRenderTexture,CCObject* obj);
void CCRenderTexture::listenToForeground(this *CCRenderTexture,CCObject* obj);
unsigned int CCRenderTexture::getClearFlags(this *CCRenderTexture);
void CCRenderTexture::setClearFlags(this *CCRenderTexture,unsigned int uClearFlags);
const ccColor4F& CCRenderTexture::getClearColor(this *CCRenderTexture);
void CCRenderTexture::setClearColor(this *CCRenderTexture,const ccColor4F& clearColor);
float CCRenderTexture::getClearDepth(this *CCRenderTexture);
void CCRenderTexture::setClearDepth(this *CCRenderTexture,float fClearDepth);
int CCRenderTexture::getClearStencil(this *CCRenderTexture);
void CCRenderTexture::setClearStencil(this *CCRenderTexture,float fClearStencil);
bool CCRenderTexture::isAutoDraw(this *CCRenderTexture);
void CCRenderTexture::setAutoDraw(this *CCRenderTexture,bool bAutoDraw);
void CCRenderTexture::beginWithClear(this *CCRenderTexture,float r,float g,float b,float a,float depthValue,int stencilValue,GLbitfield flags);
struct CCDevice{
};

int CCDevice::getDPI();
struct CCFileUtils{
	CCDictionary* m_pFilenameLookupDict;
	std::vector<basic_string> m_searchResolutionsOrderArray;
	std::vector<basic_string> m_searchPathArray;
	basic_string m_strDefaultResRootPath;
	std::map<basic_string, basic_string> m_fullPathCache;
	CCFileUtils* s_sharedFileUtils;
};
long CCFileUtils::getClassTypeInfo(this *CCFileUtils);
CCFileUtils* CCFileUtils::sharedFileUtils();
void CCFileUtils::purgeFileUtils();

void CCFileUtils::purgeCachedEntries(this *CCFileUtils);
unsigned char* CCFileUtils::getFileData(this *CCFileUtils,const char* pszFileName,const char* pszMode,unsigned long* pSize);
unsigned char* CCFileUtils::getFileDataFromZip(this *CCFileUtils,const char* pszZipFilePath,const char* pszFileName,unsigned long* pSize);
basic_string CCFileUtils::fullPathForFilename(this *CCFileUtils,const char* pszFileName);
void CCFileUtils::removeFullPath(this *CCFileUtils,const char* path);
void CCFileUtils::loadFilenameLookupDictionaryFromFile(this *CCFileUtils,const char* filename);
void CCFileUtils::setFilenameLookupDictionary(this *CCFileUtils,CCDictionary* pFilenameLookupDict);
const char* CCFileUtils::fullPathFromRelativeFile(this *CCFileUtils,const char* pszFilename,const char* pszRelativeFile);
void CCFileUtils::setSearchResolutionsOrder(this *CCFileUtils,const std::vector<basic_string>& searchResolutionsOrder);
void CCFileUtils::addSearchResolutionsOrder(this *CCFileUtils,const char* order);
const std::vector<basic_string>& CCFileUtils::getSearchResolutionsOrder(this *CCFileUtils);
void CCFileUtils::setSearchPaths(this *CCFileUtils,const std::vector<basic_string>& searchPaths);
void CCFileUtils::addSearchPath(this *CCFileUtils,const char* path);
void CCFileUtils::removeSearchPath(this *CCFileUtils,const char* path);
void CCFileUtils::removeAllPaths(this *CCFileUtils);
const std::vector<basic_string>& CCFileUtils::getSearchPaths(this *CCFileUtils);
basic_string CCFileUtils::getWritablePath(this *CCFileUtils);
basic_string CCFileUtils::getWritablePath2(this *CCFileUtils);
bool CCFileUtils::isFileExist(this *CCFileUtils,const basic_string& strFilePath);
bool CCFileUtils::isAbsolutePath(this *CCFileUtils,const basic_string& strPath);
void CCFileUtils::setPopupNotify(this *CCFileUtils,bool bNotify);
bool CCFileUtils::isPopupNotify(this *CCFileUtils);

bool CCFileUtils::init(this *CCFileUtils);
basic_string CCFileUtils::getNewFilename(this *CCFileUtils,const char* pszFileName);
bool CCFileUtils::shouldUseHD(this *CCFileUtils);
basic_string CCFileUtils::addSuffix(this *CCFileUtils);
basic_string CCFileUtils::getPathForFilename(this *CCFileUtils,const basic_string& filename,const basic_string& resolutionDirectory,const basic_string& searchPath);
basic_string CCFileUtils::getFullPathForDirectoryAndFilename(this *CCFileUtils,const basic_string& strDirectory,const basic_string& strFilename);
CCDictionary* CCFileUtils::createCCDictionaryWithContentsOfFile(this *CCFileUtils,const basic_string& filename);
bool CCFileUtils::writeToFile(this *CCFileUtils,CCDictionary* dict,const basic_string& fullPath);
CCArray* CCFileUtils::createCCArrayWithContentsOfFile(this *CCFileUtils,const basic_string& filename);
struct CCImage{
	unsigned short m_nWidth;
	unsigned short m_nHeight;
	int m_nBitsPerComponent;
	unsigned char* m_pData;
	bool m_bHasAlpha;
	bool m_bPreMulti;
};


bool CCImage::initWithImageFile(this *CCImage,const char* strPath,EImageFormat imageType);
bool CCImage::initWithImageFileThreadSafe(this *CCImage,const char* fullpath,EImageFormat imageType);
bool CCImage::initWithImageData(this *CCImage,void* pData,int nDataLen,EImageFormat eFmt,int nWidth,int nHeight,int nBitsPerComponent);
bool CCImage::initWithString(this *CCImage,const char* pText,int nWidth,int nHeight,ETextAlign eAlignMask,const char* pFontName,int nSize);
unsigned char* CCImage::getData(this *CCImage);
int CCImage::getDataLen(this *CCImage);
bool CCImage::hasAlpha(this *CCImage);
bool CCImage::isPremultipliedAlpha(this *CCImage);
bool CCImage::saveToFile(this *CCImage,const char* pszFilePath,bool bIsToRGB);
unsigned short CCImage::getWidth(this *CCImage);
unsigned short CCImage::getHeight(this *CCImage);
int CCImage::getBitsPerComponent(this *CCImage);
bool CCImage::_initWithJpgData(this *CCImage,void* pData,int nDatalen);
bool CCImage::_initWithPngData(this *CCImage,void* pData,int nDatalen);
bool CCImage::_initWithTiffData(this *CCImage,void* pData,int nDataLen);
bool CCImage::_initWithWebpData(this *CCImage,void* pData,int nDataLen);
bool CCImage::_initWithRawData(this *CCImage,void* pData,int nDatalen,int nWidth,int nHeight,int nBitsPerComponent,bool bPreMulti);
bool CCImage::_saveImageToPNG(this *CCImage,const char* pszFilePath,bool bIsToRGB);
bool CCImage::_saveImageToJPG(this *CCImage,const char* pszFilePath);

CCImage& CCImage::operator=(this *CCImage);
struct CCThread{
	void* m_pAutoreasePool;
};


void CCThread::createAutoreleasePool(this *CCThread);
struct cc_timeval{
	long tv_sec;
	int tv_usec;
};
struct CCTime{
};
int CCTime::gettimeofdayCocos2d(struct cc_timeval* tp,void* tzp);
double CCTime::timersubCocos2d(struct cc_timeval* start,struct cc_timeval* end);
struct CCAccelerometer{
	CCAcceleration m_obAccelerationValue;
	CCAccelerometerDelegate* m_pAccelDelegate;
};


void CCAccelerometer::setDelegate(this *CCAccelerometer,CCAccelerometerDelegate* pDelegate);
void CCAccelerometer::setAccelerometerInterval(this *CCAccelerometer,float interval);
void CCAccelerometer::update(this *CCAccelerometer,double x,double y,double z,double timestamp);
struct timezone{
	int tz_minuteswest;
	int tz_dsttime;
};
struct CCApplicationProtocol{
};

bool CCApplicationProtocol::applicationDidFinishLaunching(this *CCApplicationProtocol);
void CCApplicationProtocol::applicationDidEnterBackground(this *CCApplicationProtocol);
void CCApplicationProtocol::applicationWillEnterForeground(this *CCApplicationProtocol);
void CCApplicationProtocol::applicationWillBecomeActive(this *CCApplicationProtocol);
void CCApplicationProtocol::applicationWillResignActive(this *CCApplicationProtocol);
void CCApplicationProtocol::trySaveGame(this *CCApplicationProtocol);
void CCApplicationProtocol::gameDidSave(this *CCApplicationProtocol);
void CCApplicationProtocol::setAnimationInterval(this *CCApplicationProtocol,double interval);
ccLanguageType CCApplicationProtocol::getCurrentLanguage(this *CCApplicationProtocol);
TargetPlatform CCApplicationProtocol::getTargetPlatform(this *CCApplicationProtocol);
void CCApplicationProtocol::openURL(this *CCApplicationProtocol,const char* url);
struct CCApplication{
	HINSTANCE m_hInstance;
	HACCEL m_hAccelTable;
	LARGE_INTEGER m_nAnimationInterval;
	basic_string m_resourceRootPath;
	basic_string m_startupScriptFilename;
	CCApplication* sm_pSharedApplication;
};


void CCApplication::gameDidSave(this *CCApplication);
CCApplication* CCApplication::sharedApplication();
void CCApplication::setAnimationInterval(this *CCApplication,double interval);
ccLanguageType CCApplication::getCurrentLanguage(this *CCApplication);
TargetPlatform CCApplication::getTargetPlatform(this *CCApplication);
void CCApplication::openURL(this *CCApplication,const char* url);
int CCApplication::run(this *CCApplication);
void CCApplication::setupGLView(this *CCApplication);
void CCApplication::platformShutdown(this *CCApplication);
void CCApplication::toggleVerticalSync(this *CCApplication);
bool CCApplication::getVerticalSyncEnabled(this *CCApplication);
void CCApplication::setResourceRootPath(this *CCApplication,const basic_string& rootResDir);
const basic_string& CCApplication::getResourceRootPath(this *CCApplication);
void CCApplication::setStartupScriptFilename(this *CCApplication,const basic_string& startupScriptFile);
bool CCApplication::getControllerConnected(this *CCApplication);
const basic_string& CCApplication::getStartupScriptFilename(this *CCApplication);
struct CCEGLViewProtocol{
	EGLTouchDelegate* m_pDelegate;
	CCSize m_obScreenSize;
	CCSize m_obDesignResolutionSize;
	CCRect m_obViewPortRect;
	char[50] m_szViewName;
	float m_fScaleX;
	float m_fScaleY;
	ResolutionPolicy m_eResolutionPolicy;
};


void CCEGLViewProtocol::end(this *CCEGLViewProtocol);
bool CCEGLViewProtocol::isOpenGLReady(this *CCEGLViewProtocol);
void CCEGLViewProtocol::swapBuffers(this *CCEGLViewProtocol);
void CCEGLViewProtocol::setIMEKeyboardState(this *CCEGLViewProtocol,bool bOpen);
const CCSize& CCEGLViewProtocol::getFrameSize(this *CCEGLViewProtocol);
void CCEGLViewProtocol::setFrameSize(this *CCEGLViewProtocol,float width,float height);
CCSize CCEGLViewProtocol::getVisibleSize(this *CCEGLViewProtocol);
CCPoint CCEGLViewProtocol::getVisibleOrigin(this *CCEGLViewProtocol);
void CCEGLViewProtocol::setDesignResolutionSize(this *CCEGLViewProtocol,float width,float height,ResolutionPolicy resolutionPolicy);
const CCSize& CCEGLViewProtocol::getDesignResolutionSize(this *CCEGLViewProtocol);
void CCEGLViewProtocol::setTouchDelegate(this *CCEGLViewProtocol,EGLTouchDelegate* pDelegate);
void CCEGLViewProtocol::setViewPortInPoints(this *CCEGLViewProtocol,float x,float y,float w,float h);
void CCEGLViewProtocol::setScissorInPoints(this *CCEGLViewProtocol,float x,float y,float w,float h);
bool CCEGLViewProtocol::isScissorEnabled(this *CCEGLViewProtocol);
CCRect CCEGLViewProtocol::getScissorRect(this *CCEGLViewProtocol);
void CCEGLViewProtocol::setViewName(this *CCEGLViewProtocol,const char* pszViewName);
const char* CCEGLViewProtocol::getViewName(this *CCEGLViewProtocol);
void CCEGLViewProtocol::handleTouchesBegin(this *CCEGLViewProtocol,int num,int[] ids,float[] xs,float[] ys);
void CCEGLViewProtocol::handleTouchesMove(this *CCEGLViewProtocol,int num,int[] ids,float[] xs,float[] ys);
void CCEGLViewProtocol::handleTouchesEnd(this *CCEGLViewProtocol,int num,int[] ids,float[] xs,float[] ys);
void CCEGLViewProtocol::handleTouchesCancel(this *CCEGLViewProtocol,int num,int[] ids,float[] xs,float[] ys);
const CCRect& CCEGLViewProtocol::getViewPortRect(this *CCEGLViewProtocol);
float CCEGLViewProtocol::getScaleX(this *CCEGLViewProtocol);
float CCEGLViewProtocol::getScaleY(this *CCEGLViewProtocol);
void CCEGLViewProtocol::getSetOfTouchesEndOrCancel(this *CCEGLViewProtocol,CCSet& set,int num,int[] ids,float[] xs,float[] ys);
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
	GLFWwindow* m_pMainWindow;
	GLFWmonitor* m_pPrimaryMonitor;
	CCSize m_obWindowedSize;
	float m_fMouseX;
	float m_fMouseY;
	bool m_bIsFullscreen;
	bool m_bShouldHideCursor;
	bool m_bShouldCallGLFinish;
};

bool CCEGLView::isOpenGLReady(this *CCEGLView);
void CCEGLView::end(this *CCEGLView);
void CCEGLView::swapBuffers(this *CCEGLView);
void CCEGLView::setFrameSize(this *CCEGLView,float width,float height);
void CCEGLView::setIMEKeyboardState(this *CCEGLView,bool bOpen);
void CCEGLView::setMenuResource(this *CCEGLView,LPCWSTR menu);
void CCEGLView::setWndProc(this *CCEGLView,CUSTOM_WND_PROC proc);
bool CCEGLView::initGL(this *CCEGLView);
void CCEGLView::destroyGL(this *CCEGLView);
void CCEGLView::setHWnd(this *CCEGLView,HWND hWnd);
void CCEGLView::resizeWindow(this *CCEGLView,int width,int height);
void CCEGLView::setFrameZoomFactor(this *CCEGLView,float fZoomFactor);
float CCEGLView::getFrameZoomFactor(this *CCEGLView);
void CCEGLView::centerWindow(this *CCEGLView);
void CCEGLView::showCursor(this *CCEGLView,bool state);
void CCEGLView::setAccelerometerKeyHook(this *CCEGLView,LPFN_ACCELEROMETER_KEYHOOK lpfnAccelerometerKeyHook);
void CCEGLView::setViewPortInPoints(this *CCEGLView,float x,float y,float w,float h);
void CCEGLView::setScissorInPoints(this *CCEGLView,float x,float y,float w,float h);
CCEGLView* CCEGLView::sharedOpenGLView();
CCEGLView* CCEGLView::create();
CCPoint CCEGLView::getMousePosition(this *CCEGLView);
void CCEGLView::toggleFullScreen(this *CCEGLView,bool fullscreen);
GLFWwindow* CCEGLView::getWindow(this *CCEGLView);
void CCEGLView::onGLFWCharCallback(this *CCEGLView,GLFWwindow* window,unsigned int entered);
void CCEGLView::onGLFWCursorEnterFunCallback(this *CCEGLView,GLFWwindow* window,int entered);
void CCEGLView::onGLFWDeviceChangeFunCallback(this *CCEGLView,GLFWwindow* window);
void CCEGLView::onGLFWError(this *CCEGLView,int code,const char* description);
void CCEGLView::onGLFWframebuffersize(this *CCEGLView,GLFWwindow* window,int width,int height);
void CCEGLView::onGLFWMouseMoveCallBack(this *CCEGLView,GLFWwindow* window,double x,double y);
void CCEGLView::onGLFWMouseCallBack(this *CCEGLView,GLFWwindow* window,int button,int action,int mods);
void CCEGLView::onGLFWKeyCallback(this *CCEGLView,GLFWwindow* window,int key,int scancode,int action,int mods);
void CCEGLView::onGLFWMouseScrollCallback(this *CCEGLView,GLFWwindow* window,double xoffset,double yoffset);
void CCEGLView::onGLFWWindowIconifyFunCallback(this *CCEGLView,GLFWwindow* window,int iconified);
void CCEGLView::onGLFWWindowPosCallback(this *CCEGLView,GLFWwindow* window,int x,int y);
void CCEGLView::onGLFWWindowSizeFunCallback(this *CCEGLView,GLFWwindow* window,int width,int height);
struct CCShaderCache{
	CCDictionary* m_pPrograms;
};


CCShaderCache* CCShaderCache::sharedShaderCache();
void CCShaderCache::purgeSharedShaderCache();
void CCShaderCache::loadDefaultShaders(this *CCShaderCache);
void CCShaderCache::reloadDefaultShaders(this *CCShaderCache);
CCGLProgram* CCShaderCache::programForKey(this *CCShaderCache,const char* key);
void CCShaderCache::addProgram(this *CCShaderCache,CCGLProgram* program,const char* key);
bool CCShaderCache::init(this *CCShaderCache);
void CCShaderCache::loadDefaultShader(this *CCShaderCache,CCGLProgram* program,int type);
struct CCAnimationCache{
	CCDictionary* m_pAnimations;
	CCAnimationCache* s_pSharedAnimationCache;
};


CCAnimationCache* CCAnimationCache::sharedAnimationCache();
void CCAnimationCache::purgeSharedAnimationCache();
void CCAnimationCache::addAnimation(this *CCAnimationCache,CCAnimation* animation,const char* name);
void CCAnimationCache::removeAnimationByName(this *CCAnimationCache,const char* name);
CCAnimation* CCAnimationCache::animationByName(this *CCAnimationCache,const char* name);
void CCAnimationCache::addAnimationsWithDictionary(this *CCAnimationCache,CCDictionary* dictionary,const char* plist);
void CCAnimationCache::addAnimationsWithFile(this *CCAnimationCache,const char* plist);
bool CCAnimationCache::init(this *CCAnimationCache);
void CCAnimationCache::parseVersion1(this *CCAnimationCache,CCDictionary* animations);
void CCAnimationCache::parseVersion2(this *CCAnimationCache,CCDictionary* animations);
struct CCSpriteFrameCache{
	CCDictionary* m_pSpriteFrames;
	CCDictionary* m_pSpriteFramesAliases;
	std::set<basic_string>* m_pLoadedFileNames;
};

bool CCSpriteFrameCache::init(this *CCSpriteFrameCache);

void CCSpriteFrameCache::addSpriteFramesWithDictionary(this *CCSpriteFrameCache,CCDictionary* pobDictionary,CCTexture2D* pobTexture);
void CCSpriteFrameCache::addSpriteFramesWithFile(this *CCSpriteFrameCache,const char* pszPlist);
void CCSpriteFrameCache::addSpriteFramesWithFile(this *CCSpriteFrameCache,const char* plist,const char* textureFileName);
void CCSpriteFrameCache::addSpriteFramesWithFile(this *CCSpriteFrameCache,const char* pszPlist,CCTexture2D* pobTexture);
void CCSpriteFrameCache::addSpriteFrame(this *CCSpriteFrameCache,CCSpriteFrame* pobFrame,const char* pszFrameName);
void CCSpriteFrameCache::removeSpriteFrames(this *CCSpriteFrameCache);
void CCSpriteFrameCache::removeUnusedSpriteFrames(this *CCSpriteFrameCache);
void CCSpriteFrameCache::removeSpriteFrameByName(this *CCSpriteFrameCache,const char* pszName);
void CCSpriteFrameCache::removeSpriteFramesFromFile(this *CCSpriteFrameCache,const char* plist);
void CCSpriteFrameCache::removeSpriteFramesFromDictionary(this *CCSpriteFrameCache,CCDictionary* dictionary);
void CCSpriteFrameCache::removeSpriteFramesFromTexture(this *CCSpriteFrameCache,CCTexture2D* texture);
CCSpriteFrame* CCSpriteFrameCache::spriteFrameByName(this *CCSpriteFrameCache,const char* pszName);
CCSpriteFrameCache* CCSpriteFrameCache::sharedSpriteFrameCache();
void CCSpriteFrameCache::purgeSharedSpriteFrameCache();
struct CCNotificationCenter{
	CCArray* m_observers;
	int m_scriptHandler;
};


CCNotificationCenter* CCNotificationCenter::sharedNotificationCenter();
void CCNotificationCenter::purgeNotificationCenter();
void CCNotificationCenter::addObserver(this *CCNotificationCenter,CCObject* target,SEL_CallFuncO selector,const char* name,CCObject* obj);
void CCNotificationCenter::removeObserver(this *CCNotificationCenter,CCObject* target,const char* name);
int CCNotificationCenter::removeAllObservers(this *CCNotificationCenter,CCObject* target);
void CCNotificationCenter::registerScriptObserver(this *CCNotificationCenter,CCObject* target,int handler,const char* name);
void CCNotificationCenter::unregisterScriptObserver(this *CCNotificationCenter,CCObject* target,const char* name);
void CCNotificationCenter::postNotification(this *CCNotificationCenter,const char* name);
void CCNotificationCenter::postNotification(this *CCNotificationCenter,const char* name,CCObject* object);
int CCNotificationCenter::getScriptHandler(this *CCNotificationCenter);
int CCNotificationCenter::getObserverHandlerByName(this *CCNotificationCenter,const char* name);
bool CCNotificationCenter::observerExisted(this *CCNotificationCenter,CCObject* target,const char* name);
struct CCNotificationObserver{
	CCObject* m_target;
	SEL_CallFuncO m_selector;
	char* m_name;
	CCObject* m_object;
	int m_nHandler;
};


void CCNotificationObserver::performSelector(this *CCNotificationObserver,CCObject* obj);
CCObject* CCNotificationObserver::getTarget(this *CCNotificationObserver);
SEL_CallFuncO CCNotificationObserver::getSelector(this *CCNotificationObserver);
char* CCNotificationObserver::getName(this *CCNotificationObserver);
CCObject* CCNotificationObserver::getObject(this *CCNotificationObserver);
int CCNotificationObserver::getHandler(this *CCNotificationObserver);
void CCNotificationObserver::setHandler(this *CCNotificationObserver,int var);
struct CCProfiler{
	CCDictionary* m_pActiveTimers;
};

void CCProfiler::displayTimers(this *CCProfiler);
bool CCProfiler::init(this *CCProfiler);
CCProfiler* CCProfiler::sharedProfiler();
CCProfilingTimer* CCProfiler::createAndAddTimerWithName(this *CCProfiler,const char* timerName);
void CCProfiler::releaseTimer(this *CCProfiler,const char* timerName);
void CCProfiler::releaseAllTimers(this *CCProfiler);
struct CCProfilingTimer{
	basic_string m_NameStr;
	int numberOfCalls;
	int m_dAverageTime1;
	int m_dAverageTime2;
	long long totalTime;
	int minTime;
	int maxTime;
	struct cc_timeval m_sStartTime;
};


bool CCProfilingTimer::initWithName(this *CCProfilingTimer,const char* timerName);
const char* CCProfilingTimer::description(this *CCProfilingTimer);
struct cc_timeval* CCProfilingTimer::getStartTime(this *CCProfilingTimer);
void CCProfilingTimer::reset(this *CCProfilingTimer);
struct CCUserDefault{
	CCUserDefault* m_spUserDefault;
	basic_string m_sFilePath;
	bool m_sbIsFilePathInitialized;
};

bool CCUserDefault::getBoolForKey(this *CCUserDefault,const char* pKey);
bool CCUserDefault::getBoolForKey(this *CCUserDefault,const char* pKey,bool defaultValue);
int CCUserDefault::getIntegerForKey(this *CCUserDefault,const char* pKey);
int CCUserDefault::getIntegerForKey(this *CCUserDefault,const char* pKey,int defaultValue);
float CCUserDefault::getFloatForKey(this *CCUserDefault,const char* pKey);
float CCUserDefault::getFloatForKey(this *CCUserDefault,const char* pKey,float defaultValue);
double CCUserDefault::getDoubleForKey(this *CCUserDefault,const char* pKey);
double CCUserDefault::getDoubleForKey(this *CCUserDefault,const char* pKey,double defaultValue);
basic_string CCUserDefault::getStringForKey(this *CCUserDefault,const char* pKey);
basic_string CCUserDefault::getStringForKey(this *CCUserDefault,const char* pKey,const basic_string& defaultValue);
void CCUserDefault::setBoolForKey(this *CCUserDefault,const char* pKey,bool value);
void CCUserDefault::setIntegerForKey(this *CCUserDefault,const char* pKey,int value);
void CCUserDefault::setFloatForKey(this *CCUserDefault,const char* pKey,float value);
void CCUserDefault::setDoubleForKey(this *CCUserDefault,const char* pKey,double value);
void CCUserDefault::setStringForKey(this *CCUserDefault,const char* pKey,const basic_string& value);
void CCUserDefault::flush(this *CCUserDefault);
CCUserDefault* CCUserDefault::sharedUserDefault();
void CCUserDefault::purgeSharedUserDefault();
const basic_string& CCUserDefault::getXMLFilePath();
bool CCUserDefault::isXMLFileExist();

bool CCUserDefault::createXMLFile();
void CCUserDefault::initXMLFilePath();

struct CCIMEDelegate{
};

bool CCIMEDelegate::attachWithIME(this *CCIMEDelegate);
bool CCIMEDelegate::detachWithIME(this *CCIMEDelegate);
bool CCIMEDelegate::canAttachWithIME(this *CCIMEDelegate);
void CCIMEDelegate::didAttachWithIME(this *CCIMEDelegate);
bool CCIMEDelegate::canDetachWithIME(this *CCIMEDelegate);
void CCIMEDelegate::didDetachWithIME(this *CCIMEDelegate);
void CCIMEDelegate::insertText(this *CCIMEDelegate,const char* text,int len);
void CCIMEDelegate::deleteBackward(this *CCIMEDelegate);
const char* CCIMEDelegate::getContentText(this *CCIMEDelegate);
void CCIMEDelegate::keyboardWillShow(this *CCIMEDelegate,CCIMEKeyboardNotificationInfo& info);
void CCIMEDelegate::keyboardDidShow(this *CCIMEDelegate,CCIMEKeyboardNotificationInfo& info);
void CCIMEDelegate::keyboardWillHide(this *CCIMEDelegate,CCIMEKeyboardNotificationInfo& info);
void CCIMEDelegate::keyboardDidHide(this *CCIMEDelegate,CCIMEKeyboardNotificationInfo& info);

struct CCIMEDispatcher{
	Impl* m_pImpl;
};

CCIMEDispatcher* CCIMEDispatcher::sharedDispatcher();
void CCIMEDispatcher::dispatchInsertText(this *CCIMEDispatcher,const char* pText,int nLen);
void CCIMEDispatcher::dispatchDeleteBackward(this *CCIMEDispatcher);
const char* CCIMEDispatcher::getContentText(this *CCIMEDispatcher);
void CCIMEDispatcher::dispatchKeyboardWillShow(this *CCIMEDispatcher,CCIMEKeyboardNotificationInfo& info);
void CCIMEDispatcher::dispatchKeyboardDidShow(this *CCIMEDispatcher,CCIMEKeyboardNotificationInfo& info);
void CCIMEDispatcher::dispatchKeyboardWillHide(this *CCIMEDispatcher,CCIMEKeyboardNotificationInfo& info);
void CCIMEDispatcher::dispatchKeyboardDidHide(this *CCIMEDispatcher,CCIMEKeyboardNotificationInfo& info);
void CCIMEDispatcher::addDelegate(this *CCIMEDispatcher,CCIMEDelegate* pDelegate);
bool CCIMEDispatcher::attachDelegateWithIME(this *CCIMEDispatcher,CCIMEDelegate* pDelegate);
bool CCIMEDispatcher::detachDelegateWithIME(this *CCIMEDispatcher,CCIMEDelegate* pDelegate);
void CCIMEDispatcher::removeDelegate(this *CCIMEDispatcher,CCIMEDelegate* pDelegate);

struct CCTextFieldDelegate{
};
bool CCTextFieldDelegate::onTextFieldAttachWithIME(this *CCTextFieldDelegate,CCTextFieldTTF* sender);
bool CCTextFieldDelegate::onTextFieldDetachWithIME(this *CCTextFieldDelegate,CCTextFieldTTF* sender);
bool CCTextFieldDelegate::onTextFieldInsertText(this *CCTextFieldDelegate,CCTextFieldTTF* sender,const char* text,int nLen);
bool CCTextFieldDelegate::onTextFieldDeleteBackward(this *CCTextFieldDelegate,CCTextFieldTTF* sender,const char* delText,int nLen);
bool CCTextFieldDelegate::onDraw(this *CCTextFieldDelegate,CCTextFieldTTF* sender);
struct CCTextFieldTTF{
	CCTextFieldDelegate* m_pDelegate;
	int m_nCharCount;
	basic_string* m_pInputText;
	basic_string* m_pPlaceHolder;
	ccColor3B m_ColorSpaceHolder;
	bool m_bSecureTextEntry;
	LengthStack* m_pLens;
};


CCTextFieldTTF* CCTextFieldTTF::textFieldWithPlaceHolder(const char* placeholder,const CCSize& dimensions,CCTextAlignment alignment,const char* fontName,float fontSize);
CCTextFieldTTF* CCTextFieldTTF::textFieldWithPlaceHolder(const char* placeholder,const char* fontName,float fontSize);
bool CCTextFieldTTF::initWithPlaceHolder(this *CCTextFieldTTF,const char* placeholder,const CCSize& dimensions,CCTextAlignment alignment,const char* fontName,float fontSize);
bool CCTextFieldTTF::initWithPlaceHolder(this *CCTextFieldTTF,const char* placeholder,const char* fontName,float fontSize);
bool CCTextFieldTTF::attachWithIME(this *CCTextFieldTTF);
bool CCTextFieldTTF::detachWithIME(this *CCTextFieldTTF);
CCTextFieldDelegate* CCTextFieldTTF::getDelegate(this *CCTextFieldTTF);
void CCTextFieldTTF::setDelegate(this *CCTextFieldTTF,CCTextFieldDelegate* var);
int CCTextFieldTTF::getCharCount(this *CCTextFieldTTF);
const ccColor3B& CCTextFieldTTF::getColorSpaceHolder(this *CCTextFieldTTF);
void CCTextFieldTTF::setColorSpaceHolder(this *CCTextFieldTTF,const ccColor3B& color);
void CCTextFieldTTF::setString(this *CCTextFieldTTF,const char* text);
const char* CCTextFieldTTF::getString(this *CCTextFieldTTF);
void CCTextFieldTTF::setPlaceHolder(this *CCTextFieldTTF,const char* text);
const char* CCTextFieldTTF::getPlaceHolder(this *CCTextFieldTTF);
void CCTextFieldTTF::setSecureTextEntry(this *CCTextFieldTTF,bool value);
bool CCTextFieldTTF::isSecureTextEntry(this *CCTextFieldTTF);
void CCTextFieldTTF::draw(this *CCTextFieldTTF);
bool CCTextFieldTTF::canAttachWithIME(this *CCTextFieldTTF);
bool CCTextFieldTTF::canDetachWithIME(this *CCTextFieldTTF);
void CCTextFieldTTF::insertText(this *CCTextFieldTTF,const char* text,int len);
void CCTextFieldTTF::deleteBackward(this *CCTextFieldTTF);
const char* CCTextFieldTTF::getContentText(this *CCTextFieldTTF);
struct CCTextureCache{
	CCDictionary* m_pTextures;
};
void CCTextureCache::addImageAsyncCallBack(this *CCTextureCache,float dt);


const char* CCTextureCache::description(this *CCTextureCache);
CCDictionary* CCTextureCache::snapshotTextures(this *CCTextureCache);
CCTextureCache* CCTextureCache::sharedTextureCache();
void CCTextureCache::purgeSharedTextureCache();
CCTexture2D* CCTextureCache::addImage(this *CCTextureCache,const char* fileimage);
void CCTextureCache::addImageAsync(this *CCTextureCache,const char* path,CCObject* target,SEL_CallFuncO selector);
CCTexture2D* CCTextureCache::addUIImage(this *CCTextureCache,CCImage* image,const char* key);
CCTexture2D* CCTextureCache::textureForKey(this *CCTextureCache,const char* key);
bool CCTextureCache::reloadTexture(this *CCTextureCache,const char* fileName);
void CCTextureCache::removeAllTextures(this *CCTextureCache);
void CCTextureCache::removeUnusedTextures(this *CCTextureCache);
void CCTextureCache::removeTexture(this *CCTextureCache,CCTexture2D* texture);
void CCTextureCache::removeTextureForKey(this *CCTextureCache,const char* textureKeyName);
void CCTextureCache::dumpCachedTextureInfo(this *CCTextureCache);
CCTexture2D* CCTextureCache::addPVRImage(this *CCTextureCache,const char* filename);
CCTexture2D* CCTextureCache::addETCImage(this *CCTextureCache,const char* filename);
void CCTextureCache::reloadAllTextures();
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
	struct CCPVRMipmap[CC_PVRMIPMAP_MAX] m_asMipmaps;
	unsigned int m_uNumberOfMipmaps;
	unsigned int m_uWidth;
	unsigned int m_uHeight;
	GLuint m_uName;
	bool m_bHasAlpha;
	bool m_bHasPremultipliedAlpha;
	bool m_bForcePremultipliedAlpha;
	bool m_bRetainName;
	CCTexture2DPixelFormat m_eFormat;
	const ccPVRTexturePixelFormatInfo* m_pPixelFormatInfo;
};


bool CCTexturePVR::initWithContentsOfFile(this *CCTexturePVR,const char* path);
CCTexturePVR* CCTexturePVR::create(const char* path);
unsigned int CCTexturePVR::getName(this *CCTexturePVR);
unsigned int CCTexturePVR::getWidth(this *CCTexturePVR);
unsigned int CCTexturePVR::getHeight(this *CCTexturePVR);
bool CCTexturePVR::hasAlpha(this *CCTexturePVR);
bool CCTexturePVR::hasPremultipliedAlpha(this *CCTexturePVR);
bool CCTexturePVR::isForcePremultipliedAlpha(this *CCTexturePVR);
unsigned int CCTexturePVR::getNumberOfMipmaps(this *CCTexturePVR);
CCTexture2DPixelFormat CCTexturePVR::getFormat(this *CCTexturePVR);
bool CCTexturePVR::isRetainName(this *CCTexturePVR);
void CCTexturePVR::setRetainName(this *CCTexturePVR,bool retainName);
bool CCTexturePVR::unpackPVRv2Data(this *CCTexturePVR,unsigned char* data,unsigned int len);
bool CCTexturePVR::unpackPVRv3Data(this *CCTexturePVR,unsigned char* dataPointer,unsigned int dataLength);
bool CCTexturePVR::createGLTexture(this *CCTexturePVR);
struct CCParallaxNode{
	struct _ccArray* m_pParallaxArray;
	CCPoint m_tLastPosition;
};
struct _ccArray* CCParallaxNode::getParallaxArray(this *CCParallaxNode);
void CCParallaxNode::setParallaxArray(this *CCParallaxNode,struct _ccArray* var);


CCParallaxNode* CCParallaxNode::create();
void CCParallaxNode::addChild(this *CCParallaxNode,CCNode* child,unsigned int z,const CCPoint& parallaxRatio,const CCPoint& positionOffset);
void CCParallaxNode::addChild(this *CCParallaxNode,CCNode* child,unsigned int zOrder,int tag);
void CCParallaxNode::removeChild(this *CCParallaxNode,CCNode* child,bool cleanup);
void CCParallaxNode::removeAllChildrenWithCleanup(this *CCParallaxNode,bool cleanup);
void CCParallaxNode::visit(this *CCParallaxNode);
CCPoint CCParallaxNode::absolutePosition(this *CCParallaxNode);
struct CCTMXObjectGroup{
	CCPoint m_tPositionOffset;
	CCDictionary* m_pProperties;
	CCArray* m_pObjects;
	basic_string m_sGroupName;
};
const CCPoint& CCTMXObjectGroup::getPositionOffset(this *CCTMXObjectGroup);
void CCTMXObjectGroup::setPositionOffset(this *CCTMXObjectGroup,const CCPoint& var);
CCDictionary* CCTMXObjectGroup::getProperties(this *CCTMXObjectGroup);
void CCTMXObjectGroup::setProperties(this *CCTMXObjectGroup,CCDictionary* var);
CCArray* CCTMXObjectGroup::getObjects(this *CCTMXObjectGroup);
void CCTMXObjectGroup::setObjects(this *CCTMXObjectGroup,CCArray* var);


const char* CCTMXObjectGroup::getGroupName(this *CCTMXObjectGroup);
void CCTMXObjectGroup::setGroupName(this *CCTMXObjectGroup,const char* groupName);
CCString* CCTMXObjectGroup::propertyNamed(this *CCTMXObjectGroup,const char* propertyName);
CCDictionary* CCTMXObjectGroup::objectNamed(this *CCTMXObjectGroup,const char* objectName);
struct CCTMXLayerInfo{
	CCDictionary* m_pProperties;
	basic_string m_sName;
	CCSize m_tLayerSize;
	unsigned int* m_pTiles;
	bool m_bVisible;
	unsigned char m_cOpacity;
	bool m_bOwnTiles;
	unsigned int m_uMinGID;
	unsigned int m_uMaxGID;
	CCPoint m_tOffset;
};
CCDictionary* CCTMXLayerInfo::getProperties(this *CCTMXLayerInfo);
void CCTMXLayerInfo::setProperties(this *CCTMXLayerInfo,CCDictionary* var);


struct CCTMXTilesetInfo{
	basic_string m_sName;
	unsigned int m_uFirstGid;
	CCSize m_tTileSize;
	unsigned int m_uSpacing;
	unsigned int m_uMargin;
	basic_string m_sSourceImage;
	CCSize m_tImageSize;
};


CCRect CCTMXTilesetInfo::rectForGID(this *CCTMXTilesetInfo,unsigned int gid);
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
	basic_string m_sTMXFileName;
	basic_string m_sResources;
	basic_string m_sCurrentString;
	CCDictionary* m_pTileProperties;
	unsigned int m_uCurrentFirstGID;
};
int CCTMXMapInfo::getOrientation(this *CCTMXMapInfo);
void CCTMXMapInfo::setOrientation(this *CCTMXMapInfo,int var);
const CCSize& CCTMXMapInfo::getMapSize(this *CCTMXMapInfo);
void CCTMXMapInfo::setMapSize(this *CCTMXMapInfo,const CCSize& var);
const CCSize& CCTMXMapInfo::getTileSize(this *CCTMXMapInfo);
void CCTMXMapInfo::setTileSize(this *CCTMXMapInfo,const CCSize& var);
CCArray* CCTMXMapInfo::getLayers(this *CCTMXMapInfo);
void CCTMXMapInfo::setLayers(this *CCTMXMapInfo,CCArray* var);
CCArray* CCTMXMapInfo::getTilesets(this *CCTMXMapInfo);
void CCTMXMapInfo::setTilesets(this *CCTMXMapInfo,CCArray* var);
CCArray* CCTMXMapInfo::getObjectGroups(this *CCTMXMapInfo);
void CCTMXMapInfo::setObjectGroups(this *CCTMXMapInfo,CCArray* var);
int CCTMXMapInfo::getParentElement(this *CCTMXMapInfo);
void CCTMXMapInfo::setParentElement(this *CCTMXMapInfo,int var);
unsigned int CCTMXMapInfo::getParentGID(this *CCTMXMapInfo);
void CCTMXMapInfo::setParentGID(this *CCTMXMapInfo,unsigned int var);
int CCTMXMapInfo::getLayerAttribs(this *CCTMXMapInfo);
void CCTMXMapInfo::setLayerAttribs(this *CCTMXMapInfo,int var);
bool CCTMXMapInfo::getStoringCharacters(this *CCTMXMapInfo);
void CCTMXMapInfo::setStoringCharacters(this *CCTMXMapInfo,bool var);
CCDictionary* CCTMXMapInfo::getProperties(this *CCTMXMapInfo);
void CCTMXMapInfo::setProperties(this *CCTMXMapInfo,CCDictionary* var);


CCTMXMapInfo* CCTMXMapInfo::formatWithTMXFile(const char* tmxFile);
CCTMXMapInfo* CCTMXMapInfo::formatWithXML(const char* tmxString,const char* resourcePath);
bool CCTMXMapInfo::initWithTMXFile(this *CCTMXMapInfo,const char* tmxFile);
bool CCTMXMapInfo::initWithXML(this *CCTMXMapInfo,const char* tmxString,const char* resourcePath);
bool CCTMXMapInfo::parseXMLFile(this *CCTMXMapInfo,const char* xmlFilename);
bool CCTMXMapInfo::parseXMLString(this *CCTMXMapInfo,const char* xmlString);
CCDictionary* CCTMXMapInfo::getTileProperties(this *CCTMXMapInfo);
void CCTMXMapInfo::setTileProperties(this *CCTMXMapInfo,CCDictionary* tileProperties);
void CCTMXMapInfo::startElement(this *CCTMXMapInfo,void* ctx,const char* name,const char** atts);
void CCTMXMapInfo::endElement(this *CCTMXMapInfo,void* ctx,const char* name);
void CCTMXMapInfo::textHandler(this *CCTMXMapInfo,void* ctx,const char* ch,int len);
const char* CCTMXMapInfo::getCurrentString(this *CCTMXMapInfo);
void CCTMXMapInfo::setCurrentString(this *CCTMXMapInfo,const char* currentString);
const char* CCTMXMapInfo::getTMXFileName(this *CCTMXMapInfo);
void CCTMXMapInfo::setTMXFileName(this *CCTMXMapInfo,const char* fileName);
void CCTMXMapInfo::internalInit(this *CCTMXMapInfo,const char* tmxFileName,const char* resourcePath);
struct CCTMXLayer{
	CCSize m_tLayerSize;
	CCSize m_tMapTileSize;
	unsigned int* m_pTiles;
	CCTMXTilesetInfo* m_pTileSet;
	unsigned int m_uLayerOrientation;
	CCDictionary* m_pProperties;
	basic_string m_sLayerName;
	unsigned char m_cOpacity;
	unsigned int m_uMinGID;
	unsigned int m_uMaxGID;
	int m_nVertexZvalue;
	bool m_bUseAutomaticVertexZ;
	CCSprite* m_pReusedTile;
	ccCArray* m_pAtlasIndexArray;
	float m_fContentScaleFactor;
};
const CCSize& CCTMXLayer::getLayerSize(this *CCTMXLayer);
void CCTMXLayer::setLayerSize(this *CCTMXLayer,const CCSize& var);
const CCSize& CCTMXLayer::getMapTileSize(this *CCTMXLayer);
void CCTMXLayer::setMapTileSize(this *CCTMXLayer,const CCSize& var);
unsigned int* CCTMXLayer::getTiles(this *CCTMXLayer);
void CCTMXLayer::setTiles(this *CCTMXLayer,unsigned int* var);
CCTMXTilesetInfo* CCTMXLayer::getTileSet(this *CCTMXLayer);
void CCTMXLayer::setTileSet(this *CCTMXLayer,CCTMXTilesetInfo* var);
unsigned int CCTMXLayer::getLayerOrientation(this *CCTMXLayer);
void CCTMXLayer::setLayerOrientation(this *CCTMXLayer,unsigned int var);
CCDictionary* CCTMXLayer::getProperties(this *CCTMXLayer);
void CCTMXLayer::setProperties(this *CCTMXLayer,CCDictionary* var);


CCTMXLayer* CCTMXLayer::create(CCTMXTilesetInfo* tilesetInfo,CCTMXLayerInfo* layerInfo,CCTMXMapInfo* mapInfo);
bool CCTMXLayer::initWithTilesetInfo(this *CCTMXLayer,CCTMXTilesetInfo* tilesetInfo,CCTMXLayerInfo* layerInfo,CCTMXMapInfo* mapInfo);
void CCTMXLayer::releaseMap(this *CCTMXLayer);
CCSprite* CCTMXLayer::tileAt(this *CCTMXLayer,const CCPoint& tileCoordinate);
unsigned int CCTMXLayer::tileGIDAt(this *CCTMXLayer,const CCPoint& tileCoordinate);
unsigned int CCTMXLayer::tileGIDAt(this *CCTMXLayer,const CCPoint& tileCoordinate,ccTMXTileFlags* flags);
void CCTMXLayer::setTileGID(this *CCTMXLayer,unsigned int gid,const CCPoint& tileCoordinate);
void CCTMXLayer::setTileGID(this *CCTMXLayer,unsigned int gid,const CCPoint& tileCoordinate,ccTMXTileFlags flags);
void CCTMXLayer::removeTileAt(this *CCTMXLayer,const CCPoint& tileCoordinate);
CCPoint CCTMXLayer::positionAt(this *CCTMXLayer,const CCPoint& tileCoordinate);
CCString* CCTMXLayer::propertyNamed(this *CCTMXLayer,const char* propertyName);
void CCTMXLayer::setupTiles(this *CCTMXLayer);
void CCTMXLayer::addChild(this *CCTMXLayer,CCNode* child,int zOrder,int tag);
void CCTMXLayer::removeChild(this *CCTMXLayer,CCNode* child,bool cleanup);
const char* CCTMXLayer::getLayerName(this *CCTMXLayer);
void CCTMXLayer::setLayerName(this *CCTMXLayer,const char* layerName);
CCPoint CCTMXLayer::positionForIsoAt(this *CCTMXLayer,const CCPoint& pos);
CCPoint CCTMXLayer::positionForOrthoAt(this *CCTMXLayer,const CCPoint& pos);
CCPoint CCTMXLayer::positionForHexAt(this *CCTMXLayer,const CCPoint& pos);
CCPoint CCTMXLayer::calculateLayerOffset(this *CCTMXLayer,const CCPoint& offset);
CCSprite* CCTMXLayer::appendTileForGID(this *CCTMXLayer,unsigned int gid,const CCPoint& pos);
CCSprite* CCTMXLayer::insertTileForGID(this *CCTMXLayer,unsigned int gid,const CCPoint& pos);
CCSprite* CCTMXLayer::updateTileForGID(this *CCTMXLayer,unsigned int gid,const CCPoint& pos);
void CCTMXLayer::parseInternalProperties(this *CCTMXLayer);
void CCTMXLayer::setupTileSprite(this *CCTMXLayer,CCSprite* sprite,CCPoint pos,unsigned int gid);
CCSprite* CCTMXLayer::reusedTileWithRect(this *CCTMXLayer,CCRect rect);
int CCTMXLayer::vertexZForPos(this *CCTMXLayer,const CCPoint& pos);
unsigned int CCTMXLayer::atlasIndexForExistantZ(this *CCTMXLayer,unsigned int z);
unsigned int CCTMXLayer::atlasIndexForNewZ(this *CCTMXLayer,int z);
struct CCTMXTiledMap{
	CCSize m_tMapSize;
	CCSize m_tTileSize;
	int m_nMapOrientation;
	CCArray* m_pObjectGroups;
	CCDictionary* m_pProperties;
	CCDictionary* m_pTileProperties;
};
const CCSize& CCTMXTiledMap::getMapSize(this *CCTMXTiledMap);
void CCTMXTiledMap::setMapSize(this *CCTMXTiledMap,const CCSize& var);
const CCSize& CCTMXTiledMap::getTileSize(this *CCTMXTiledMap);
void CCTMXTiledMap::setTileSize(this *CCTMXTiledMap,const CCSize& var);
int CCTMXTiledMap::getMapOrientation(this *CCTMXTiledMap);
void CCTMXTiledMap::setMapOrientation(this *CCTMXTiledMap,int var);
CCArray* CCTMXTiledMap::getObjectGroups(this *CCTMXTiledMap);
void CCTMXTiledMap::setObjectGroups(this *CCTMXTiledMap,CCArray* var);
CCDictionary* CCTMXTiledMap::getProperties(this *CCTMXTiledMap);
void CCTMXTiledMap::setProperties(this *CCTMXTiledMap,CCDictionary* var);


CCTMXTiledMap* CCTMXTiledMap::create(const char* tmxFile);
CCTMXTiledMap* CCTMXTiledMap::createWithXML(const char* tmxString,const char* resourcePath);
bool CCTMXTiledMap::initWithTMXFile(this *CCTMXTiledMap,const char* tmxFile);
bool CCTMXTiledMap::initWithXML(this *CCTMXTiledMap,const char* tmxString,const char* resourcePath);
CCTMXLayer* CCTMXTiledMap::layerNamed(this *CCTMXTiledMap,const char* layerName);
CCTMXObjectGroup* CCTMXTiledMap::objectGroupNamed(this *CCTMXTiledMap,const char* groupName);
CCString* CCTMXTiledMap::propertyNamed(this *CCTMXTiledMap,const char* propertyName);
CCDictionary* CCTMXTiledMap::propertiesForGID(this *CCTMXTiledMap,int GID);
CCTMXLayer* CCTMXTiledMap::parseLayer(this *CCTMXTiledMap,CCTMXLayerInfo* layerInfo,CCTMXMapInfo* mapInfo);
CCTMXTilesetInfo* CCTMXTiledMap::tilesetForLayer(this *CCTMXTiledMap,CCTMXLayerInfo* layerInfo,CCTMXMapInfo* mapInfo);
void CCTMXTiledMap::buildWithMapInfo(this *CCTMXTiledMap,CCTMXMapInfo* mapInfo);
struct CCTileMapAtlas{
	struct sImageTGA* m_pTGAInfo;
	CCDictionary* m_pPosToAtlasIndex;
	int m_nItemsToRender;
};
struct sImageTGA* CCTileMapAtlas::getTGAInfo(this *CCTileMapAtlas);
void CCTileMapAtlas::setTGAInfo(this *CCTileMapAtlas,struct sImageTGA* var);


CCTileMapAtlas* CCTileMapAtlas::create(const char* tile,const char* mapFile,int tileWidth,int tileHeight);
bool CCTileMapAtlas::initWithTileFile(this *CCTileMapAtlas,const char* tile,const char* mapFile,int tileWidth,int tileHeight);
ccColor3B CCTileMapAtlas::tileAt(this *CCTileMapAtlas,const CCPoint& position);
void CCTileMapAtlas::setTile(this *CCTileMapAtlas,const ccColor3B& tile,const CCPoint& position);
void CCTileMapAtlas::releaseMap(this *CCTileMapAtlas);
void CCTileMapAtlas::loadTGAfile(this *CCTileMapAtlas,const char* file);
void CCTileMapAtlas::calculateItemsToRender(this *CCTileMapAtlas);
void CCTileMapAtlas::updateAtlasValueAt(this *CCTileMapAtlas,const CCPoint& pos,const ccColor3B& value,unsigned int index);
void CCTileMapAtlas::updateAtlasValues(this *CCTileMapAtlas);
struct ccTouchHandlerHelperData{
	int m_type;
};
struct EGLTouchDelegate{
};
void EGLTouchDelegate::touchesBegan(this *EGLTouchDelegate,CCSet* touches,CCEvent* pEvent);
void EGLTouchDelegate::touchesMoved(this *EGLTouchDelegate,CCSet* touches,CCEvent* pEvent);
void EGLTouchDelegate::touchesEnded(this *EGLTouchDelegate,CCSet* touches,CCEvent* pEvent);
void EGLTouchDelegate::touchesCancelled(this *EGLTouchDelegate,CCSet* touches,CCEvent* pEvent);

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
	struct ccTouchHandlerHelperData[ccTouchMax] m_sHandlerHelperData;
	bool m_bForcePrio;
	int m_nTargetPrio;
};

bool CCTouchDispatcher::init(this *CCTouchDispatcher);

bool CCTouchDispatcher::isDispatchEvents(this *CCTouchDispatcher);
void CCTouchDispatcher::setDispatchEvents(this *CCTouchDispatcher,bool bDispatchEvents);
void CCTouchDispatcher::addStandardDelegate(this *CCTouchDispatcher,CCTouchDelegate* pDelegate,int nPriority);
void CCTouchDispatcher::addTargetedDelegate(this *CCTouchDispatcher,CCTouchDelegate* pDelegate,int nPriority,bool bSwallowsTouches);
void CCTouchDispatcher::removeDelegate(this *CCTouchDispatcher,CCTouchDelegate* pDelegate);
void CCTouchDispatcher::removeAllDelegates(this *CCTouchDispatcher);
void CCTouchDispatcher::setPriority(this *CCTouchDispatcher,int nPriority,CCTouchDelegate* pDelegate);
void CCTouchDispatcher::touches(this *CCTouchDispatcher,CCSet* pTouches,CCEvent* pEvent,unsigned int uIndex);
void CCTouchDispatcher::touchesBegan(this *CCTouchDispatcher,CCSet* touches,CCEvent* pEvent);
void CCTouchDispatcher::touchesMoved(this *CCTouchDispatcher,CCSet* touches,CCEvent* pEvent);
void CCTouchDispatcher::touchesEnded(this *CCTouchDispatcher,CCSet* touches,CCEvent* pEvent);
void CCTouchDispatcher::touchesCancelled(this *CCTouchDispatcher,CCSet* touches,CCEvent* pEvent);
CCTouchHandler* CCTouchDispatcher::findHandler(this *CCTouchDispatcher,CCTouchDelegate* pDelegate);
void CCTouchDispatcher::incrementForcePrio(this *CCTouchDispatcher,int priority);
void CCTouchDispatcher::decrementForcePrio(this *CCTouchDispatcher,int priority);
void CCTouchDispatcher::forceRemoveDelegate(this *CCTouchDispatcher,CCTouchDelegate* pDelegate);
void CCTouchDispatcher::forceAddHandler(this *CCTouchDispatcher,CCTouchHandler* pHandler,CCArray* pArray);
void CCTouchDispatcher::forceRemoveAllDelegates(this *CCTouchDispatcher);
void CCTouchDispatcher::rearrangeHandlers(this *CCTouchDispatcher,CCArray* pArray);
CCTouchHandler* CCTouchDispatcher::findHandler(this *CCTouchDispatcher,CCArray* pArray,CCTouchDelegate* pDelegate);
bool CCTouchDispatcher::getForcePrio(this *CCTouchDispatcher);
void CCTouchDispatcher::setForcePrio(this *CCTouchDispatcher,bool var);
int CCTouchDispatcher::getTargetPrio(this *CCTouchDispatcher);
void CCTouchDispatcher::setTargetPrio(this *CCTouchDispatcher,int var);
struct CCTouchHandler{
	CCTouchDelegate* m_pDelegate;
	int m_nPriority;
	int m_nEnabledSelectors;
};

CCTouchDelegate* CCTouchHandler::getDelegate(this *CCTouchHandler);
void CCTouchHandler::setDelegate(this *CCTouchHandler,CCTouchDelegate* pDelegate);
int CCTouchHandler::getPriority(this *CCTouchHandler);
void CCTouchHandler::setPriority(this *CCTouchHandler,int nPriority);
int CCTouchHandler::getEnabledSelectors(this *CCTouchHandler);
void CCTouchHandler::setEnalbedSelectors(this *CCTouchHandler,int nValue);
bool CCTouchHandler::initWithDelegate(this *CCTouchHandler,CCTouchDelegate* pDelegate,int nPriority);
CCTouchHandler* CCTouchHandler::handlerWithDelegate(CCTouchDelegate* pDelegate,int nPriority);
struct CCStandardTouchHandler{
};
bool CCStandardTouchHandler::initWithDelegate(this *CCStandardTouchHandler,CCTouchDelegate* pDelegate,int nPriority);
CCStandardTouchHandler* CCStandardTouchHandler::handlerWithDelegate(CCTouchDelegate* pDelegate,int nPriority);
struct CCTargetedTouchHandler{
	bool m_bSwallowsTouches;
	CCSet* m_pClaimedTouches;
};

bool CCTargetedTouchHandler::isSwallowsTouches(this *CCTargetedTouchHandler);
void CCTargetedTouchHandler::setSwallowsTouches(this *CCTargetedTouchHandler,bool bSwallowsTouches);
CCSet* CCTargetedTouchHandler::getClaimedTouches(this *CCTargetedTouchHandler);
bool CCTargetedTouchHandler::initWithDelegate(this *CCTargetedTouchHandler,CCTouchDelegate* pDelegate,int nPriority,bool bSwallow);
CCTargetedTouchHandler* CCTargetedTouchHandler::handlerWithDelegate(CCTouchDelegate* pDelegate,int nPriority,bool bSwallow);
struct CCTimer{
	CCObject* m_pTarget;
	float m_fElapsed;
	bool m_bRunForever;
	bool m_bUseDelay;
	unsigned int m_uTimesExecuted;
	unsigned int m_uRepeat;
	float m_fDelay;
	float m_fInterval;
	SEL_SCHEDULE m_pfnSelector;
	int m_nScriptHandler;
};

float CCTimer::getInterval(this *CCTimer);
void CCTimer::setInterval(this *CCTimer,float fInterval);
SEL_SCHEDULE CCTimer::getSelector(this *CCTimer);
bool CCTimer::initWithTarget(this *CCTimer,CCObject* pTarget,SEL_SCHEDULE pfnSelector);
bool CCTimer::initWithTarget(this *CCTimer,CCObject* pTarget,SEL_SCHEDULE pfnSelector,float fSeconds,unsigned int nRepeat,float fDelay);
bool CCTimer::initWithScriptHandler(this *CCTimer,int nHandler,float fSeconds);
void CCTimer::update(this *CCTimer,float dt);
CCTimer* CCTimer::timerWithTarget(CCObject* pTarget,SEL_SCHEDULE pfnSelector);
CCTimer* CCTimer::timerWithTarget(CCObject* pTarget,SEL_SCHEDULE pfnSelector,float fSeconds);
CCTimer* CCTimer::timerWithScriptHandler(int nHandler,float fSeconds);
int CCTimer::getScriptHandler(this *CCTimer);
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


float CCScheduler::getTimeScale(this *CCScheduler);
void CCScheduler::setTimeScale(this *CCScheduler,float fTimeScale);
void CCScheduler::update(this *CCScheduler,float dt);
void CCScheduler::scheduleSelector(this *CCScheduler,SEL_SCHEDULE pfnSelector,CCObject* pTarget,float fInterval,unsigned int repeat,float delay,bool bPaused);
void CCScheduler::scheduleSelector(this *CCScheduler,SEL_SCHEDULE pfnSelector,CCObject* pTarget,float fInterval,bool bPaused);
void CCScheduler::scheduleUpdateForTarget(this *CCScheduler,CCObject* pTarget,int nPriority,bool bPaused);
void CCScheduler::unscheduleSelector(this *CCScheduler,SEL_SCHEDULE pfnSelector,CCObject* pTarget);
void CCScheduler::unscheduleUpdateForTarget(this *CCScheduler,const CCObject* pTarget);
void CCScheduler::unscheduleAllForTarget(this *CCScheduler,CCObject* pTarget);
void CCScheduler::unscheduleAll(this *CCScheduler);
void CCScheduler::unscheduleAllWithMinPriority(this *CCScheduler,int nMinPriority);
unsigned int CCScheduler::scheduleScriptFunc(this *CCScheduler,unsigned int nHandler,float fInterval,bool bPaused);
void CCScheduler::unscheduleScriptEntry(this *CCScheduler,unsigned int uScheduleScriptEntryID);
void CCScheduler::pauseTarget(this *CCScheduler,CCObject* pTarget);
void CCScheduler::resumeTarget(this *CCScheduler,CCObject* pTarget);
bool CCScheduler::isTargetPaused(this *CCScheduler,CCObject* pTarget);
CCSet* CCScheduler::pauseAllTargets(this *CCScheduler);
CCSet* CCScheduler::pauseAllTargetsWithMinPriority(this *CCScheduler,int nMinPriority);
void CCScheduler::resumeTargets(this *CCScheduler,CCSet* targetsToResume);
void CCScheduler::removeHashElement(this *CCScheduler,struct _hashSelectorEntry* pElement);
void CCScheduler::removeUpdateFromHash(this *CCScheduler,struct _listEntry* entry);
void CCScheduler::priorityIn(this *CCScheduler,struct _listEntry** ppList,CCObject* pTarget,int nPriority,bool bPaused);
void CCScheduler::appendIn(this *CCScheduler,struct _listEntry** ppList,CCObject* pTarget,bool bPaused);
struct CCComponent{
	CCNode* m_pOwner;
	basic_string m_strName;
	bool m_bEnabled;
};


bool CCComponent::init(this *CCComponent);
void CCComponent::onEnter(this *CCComponent);
void CCComponent::onExit(this *CCComponent);
void CCComponent::update(this *CCComponent,float delta);
bool CCComponent::serialize(this *CCComponent,void* r);
bool CCComponent::isEnabled(this *CCComponent);
void CCComponent::setEnabled(this *CCComponent,bool b);
CCComponent* CCComponent::create();
const char* CCComponent::getName(this *CCComponent);
void CCComponent::setName(this *CCComponent,const char* pName);
void CCComponent::setOwner(this *CCComponent,CCNode* pOwner);
CCNode* CCComponent::getOwner(this *CCComponent);
struct CCComponentContainer{
	CCDictionary* m_pComponents;
	CCNode* m_pOwner;
};


CCComponent* CCComponentContainer::get(this *CCComponentContainer,const char* pName);
bool CCComponentContainer::add(this *CCComponentContainer,CCComponent* pCom);
bool CCComponentContainer::remove(this *CCComponentContainer,const char* pName);
bool CCComponentContainer::remove(this *CCComponentContainer,CCComponent* pCom);
void CCComponentContainer::removeAll(this *CCComponentContainer);
void CCComponentContainer::visit(this *CCComponentContainer,float fDelta);
bool CCComponentContainer::isEmpty(this *CCComponentContainer);
void CCComponentContainer::alloc(this *CCComponentContainer);
struct CCKeyboardDispatcher{
	CCArray* m_pDelegates;
	bool m_bUnknown24;
	bool m_bUnknown25;
	char[2] pad7;
	ccCArray* m_pUnknown28;
	ccCArray* m_pUnknown2c;
	bool m_bShiftPressed;
	bool m_bControlPressed;
	bool m_bAltPressed;
	bool m_bCommandPressed;
};



CCKeyboardDispatcher& CCKeyboardDispatcher::operator=(this *CCKeyboardDispatcher);
void CCKeyboardDispatcher::addDelegate(this *CCKeyboardDispatcher,CCKeyboardDelegate* pDelegate);
void CCKeyboardDispatcher::removeDelegate(this *CCKeyboardDispatcher,CCKeyboardDelegate* pDelegate);
void CCKeyboardDispatcher::forceAddDelegate(this *CCKeyboardDispatcher,CCKeyboardDelegate* pDelegate);
void CCKeyboardDispatcher::forceRemoveDelegate(this *CCKeyboardDispatcher,CCKeyboardDelegate* pDelegate);
enumKeyCodes CCKeyboardDispatcher::convertKeyCode(this *CCKeyboardDispatcher,enumKeyCodes key);
bool CCKeyboardDispatcher::dispatchKeyboardMSG(this *CCKeyboardDispatcher,enumKeyCodes key);
bool CCKeyboardDispatcher::getAltKeyPressed(this *CCKeyboardDispatcher);
bool CCKeyboardDispatcher::getCommandKeyPressed(this *CCKeyboardDispatcher);
bool CCKeyboardDispatcher::getControlKeyPressed(this *CCKeyboardDispatcher);
bool CCKeyboardDispatcher::getShiftKeyPressed(this *CCKeyboardDispatcher);
const char* CCKeyboardDispatcher::keyToString(this *CCKeyboardDispatcher,enumKeyCodes key);
void CCKeyboardDispatcher::updateModifierKeys(this *CCKeyboardDispatcher,bool shft,bool ctrl,bool alt,bool cmd);
struct CCMouseDispatcher{
	CCArray* m_pDelegates;
};



CCMouseDispatcher& CCMouseDispatcher::operator=(this *CCMouseDispatcher);
void CCMouseDispatcher::addDelegate(this *CCMouseDispatcher,CCMouseDelegate* pDelegate);
void CCMouseDispatcher::removeDelegate(this *CCMouseDispatcher,CCMouseDelegate* pDelegate);
void CCMouseDispatcher::forceAddDelegate(this *CCMouseDispatcher,CCMouseDelegate* pDelegate);
void CCMouseDispatcher::forceRemoveDelegate(this *CCMouseDispatcher,CCMouseDelegate* pDelegate);
bool CCMouseDispatcher::dispatchScrollMSG(this *CCMouseDispatcher,float x,float y);
struct CCSceneTransitionDelegate{
};


CCSceneTransitionDelegate& CCSceneTransitionDelegate::operator=(this *CCSceneTransitionDelegate);
void CCSceneTransitionDelegate::sceneWillResume(this *CCSceneTransitionDelegate);
struct DS_Dictionary{
	pugi::xml_document doc;
	std::vector<pugi::xml_node> dictTree;
	bool compatible;
};
basic_string DS_Dictionary::cleanStringWhiteSpace(this *DS_Dictionary);
void DS_Dictionary::split(this *DS_Dictionary);
bool DS_Dictionary::splitWithForm(this *DS_Dictionary);
bool DS_Dictionary::rectFromString(this *DS_Dictionary);
bool DS_Dictionary::vec2FromString(this *DS_Dictionary);


void DS_Dictionary::copyFile();
CCObject* DS_Dictionary::decodeObjectForKey(this *DS_Dictionary);
bool DS_Dictionary::loadRootSubDictFromFile(this *DS_Dictionary);
bool DS_Dictionary::loadRootSubDictFromCompressedFile(this *DS_Dictionary);
bool DS_Dictionary::loadRootSubDictFromString(this *DS_Dictionary);
bool DS_Dictionary::saveRootSubDictToFile(this *DS_Dictionary);
bool DS_Dictionary::saveRootSubDictToCompressedFile(this *DS_Dictionary);
basic_string DS_Dictionary::saveRootSubDictToString(this *DS_Dictionary);
bool DS_Dictionary::stepIntoSubDictWithKey(this *DS_Dictionary);
void DS_Dictionary::stepOutOfSubDict(this *DS_Dictionary);
void DS_Dictionary::stepBackToRootSubDict(this *DS_Dictionary);
unsigned int DS_Dictionary::getNumKeys(this *DS_Dictionary);
basic_string DS_Dictionary::getKey(this *DS_Dictionary);
std::vector<basic_string> DS_Dictionary::getAllKeys(this *DS_Dictionary);
unsigned int DS_Dictionary::getIndexOfKey(this *DS_Dictionary);
unsigned int DS_Dictionary::getIndexOfKeyWithClosestAlphaNumericalMatch(this *DS_Dictionary);
void DS_Dictionary::removeKey(this *DS_Dictionary);
void DS_Dictionary::removeKey(this *DS_Dictionary);
void DS_Dictionary::removeAllKeys(this *DS_Dictionary);
int DS_Dictionary::getIntegerForKey(this *DS_Dictionary);
bool DS_Dictionary::getBoolForKey(this *DS_Dictionary);
float DS_Dictionary::getFloatForKey(this *DS_Dictionary);
basic_string DS_Dictionary::getStringForKey(this *DS_Dictionary);
CCPoint DS_Dictionary::getVec2ForKey(this *DS_Dictionary);
CCRect DS_Dictionary::getRectForKey(this *DS_Dictionary);
std::vector<basic_string> DS_Dictionary::getStringArrayForKey(this *DS_Dictionary);
std::vector<CCPoint> DS_Dictionary::getVec2ArrayForKey(this *DS_Dictionary);
std::vector<CCRect> DS_Dictionary::getRectArrayForKey(this *DS_Dictionary);
CCArray* DS_Dictionary::getArrayForKey(this *DS_Dictionary);
CCDictionary* DS_Dictionary::getDictForKey(this *DS_Dictionary);
CCObject* DS_Dictionary::getObjectForKey(this *DS_Dictionary);
void DS_Dictionary::setIntegerForKey(this *DS_Dictionary);
void DS_Dictionary::setIntegerForKey(this *DS_Dictionary);
void DS_Dictionary::setBoolForKey(this *DS_Dictionary);
void DS_Dictionary::setBoolForKey(this *DS_Dictionary);
void DS_Dictionary::setFloatForKey(this *DS_Dictionary);
void DS_Dictionary::setFloatForKey(this *DS_Dictionary);
void DS_Dictionary::setStringForKey(this *DS_Dictionary);
void DS_Dictionary::setStringForKey(this *DS_Dictionary);
void DS_Dictionary::setVec2ForKey(this *DS_Dictionary);
void DS_Dictionary::setVec2ForKey(this *DS_Dictionary);
void DS_Dictionary::setRectForKey(this *DS_Dictionary);
void DS_Dictionary::setRectForKey(this *DS_Dictionary);
void DS_Dictionary::setStringArrayForKey(this *DS_Dictionary);
void DS_Dictionary::setStringArrayForKey(this *DS_Dictionary);
void DS_Dictionary::setVec2ArrayForKey(this *DS_Dictionary);
void DS_Dictionary::setVec2ArrayForKey(this *DS_Dictionary);
void DS_Dictionary::setRectArrayForKey(this *DS_Dictionary);
void DS_Dictionary::setRectArrayForKey(this *DS_Dictionary);
void DS_Dictionary::setArrayForKey(this *DS_Dictionary);
void DS_Dictionary::setBoolMapForKey(this *DS_Dictionary);
void DS_Dictionary::setSubDictForKey(this *DS_Dictionary);
void DS_Dictionary::setSubDictForKey(this *DS_Dictionary);
void DS_Dictionary::setDictForKey(this *DS_Dictionary);
void DS_Dictionary::setObjectForKey(this *DS_Dictionary);
void DS_Dictionary::addBoolValuesToMapForKey(this *DS_Dictionary);
void DS_Dictionary::addBoolValuesToMapForKeySpecial(this *DS_Dictionary);
void DS_Dictionary::checkCompatibility(this *DS_Dictionary);
