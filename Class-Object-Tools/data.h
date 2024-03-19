#include <string>
#include <gl/GL.h>

class CCObject;
class CCBool;
class CCInteger;
class CCFloat;
class CCDouble;
class CCString;
class CCArray;
class CCDictionary;
class CCSet;
class CCDataVisitor
{
public:
    virtual ~CCDataVisitor() {}

    virtual void visitObject(const CCObject *p) = 0;

    virtual void visit(const CCBool *p);
    virtual void visit(const CCInteger *p);
    virtual void visit(const CCFloat *p);
    virtual void visit(const CCDouble *p);
    virtual void visit(const CCString *p);
    virtual void visit(const CCArray *p);
    virtual void visit(const CCDictionary *p);
    virtual void visit(const CCSet *p);
};

class CCPrettyPrinter : public CCDataVisitor
{
public:
    CCPrettyPrinter(int indentLevel = 0);

    virtual void clear();
    virtual std::string getResult();

    virtual void visitObject(const CCObject *p);
    virtual void visit(const CCBool *p);
    virtual void visit(const CCInteger *p);
    virtual void visit(const CCFloat *p);
    virtual void visit(const CCDouble *p);
    virtual void visit(const CCString *p);
    virtual void visit(const CCArray *p);
    virtual void visit(const CCDictionary *p);
    virtual void visit(const CCSet *p);

private:
    void setIndentLevel(int indentLevel);
    int _indentLevel;
    std::string _indentStr;
    std::string _result;
};
static const int kMaxLogLen = 16 * 1024;

void CCLog(const char *pszFormat, ...);

void CCLuaLog(const char *pszFormat);

void CCMessageBox(const char *pszMsg, const char *pszTitle);

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

typedef enum
{
    kHttpGet,
    kHttpPost,
    kHttpPut,
    kHttpDelete,
    kHttpUnkown,
} HttpRequestType;

extern unsigned int g_uNumberOfDraws;
class DS_Dictionary;
typedef enum
{
    kCCObjectTypePlayLayer = 5,
    kCCObjectTypeLevelEditorLayer = 6,
    kCCObjectTypeMenuLayer = 15,
} CCObjectType;
class CCZone;
class CCObject;
class CCNode;
class CCEvent;

class CCCopying
{
public:
    virtual CCObject *copyWithZone(CCZone *pZone);
};

class CCObject : public CCCopying
{
public:
    unsigned int m_uID;

    int m_nLuaID;

protected:
    int m_nTag;

    unsigned int m_uReference;

    unsigned int m_uAutoReleaseCount;

    int m_eObjType;
    unsigned int m_uObjectIdxInArray;

public:
    CCObject(void);
    CCObject(const CCObject &);

    virtual ~CCObject(void);

    CCObject &operator=(const CCObject &);

    void release(void);
    void retain(void);
    CCObject *autorelease(void);
    CCObject *copy(void);
    bool isSingleReference(void) const;
    unsigned int retainCount(void) const;
    virtual bool isEqual(const CCObject *pObject);

    virtual void acceptVisitor(CCDataVisitor &visitor);

    virtual void update(float dt);

    virtual void encodeWithCoder(DS_Dictionary *);
    static CCObject *createWithCoder(DS_Dictionary *);
    virtual bool canEncode();
    CCObjectType getObjType() const;
    virtual int getTag() const;
    virtual void setTag(int nTag);
    void setObjType(CCObjectType);
    // #line 131 "cocos2d/cocos-headers/cocos2dx/cocoa/CCObject.h"
    friend class CCAutoreleasePool;
};

// typedef void (CCObject::*SEL_SCHEDULE)(float);
// typedef void (CCObject::*SEL_CallFunc)();
// typedef void (CCObject::*SEL_CallFuncN)(CCNode*);
// typedef void (CCObject::*SEL_CallFuncND)(CCNode*, void*);
// typedef void (CCObject::*SEL_CallFuncO)(CCObject*);
// typedef void (CCObject::*SEL_MenuHandler)(CCObject*);
// typedef void (CCObject::*SEL_EventHandler)(CCEvent*);
// typedef int (CCObject::*SEL_Compare)(CCObject*);

class CCSize;

class CCPoint
{
public:
    float x;
    float y;

public:
    CCPoint();
    CCPoint(float x, float y);

    CCPoint(const CCPoint &other);

    CCPoint(const CCSize &size);

    CCPoint &operator=(const CCPoint &other);

    CCPoint &operator=(const CCSize &size);

    CCPoint operator+(const CCPoint &right) const;

    CCPoint operator-(const CCPoint &right) const;

    CCPoint operator-() const;

    CCPoint operator*(float a) const;

    CCPoint operator/(float a) const;

    inline CCPoint operator*(const CCPoint &right) const { return CCPoint(x * right.x, y * right.y); }
    inline CCPoint operator/(const CCPoint &right) const { return CCPoint(x / right.x, y / right.y); }

    void setPoint(float x, float y);
    bool equals(const CCPoint &target) const;

    bool fuzzyEquals(const CCPoint &target, float variance) const;

    inline float getLength() const
    {
        return sqrtf(x * x + y * y);
    };

    inline float getLengthSq() const
    {
        return dot(*this);
    };

    inline float getDistanceSq(const CCPoint &other) const
    {
        return (*this - other).getLengthSq();
    };

    inline float getDistance(const CCPoint &other) const
    {
        return (*this - other).getLength();
    };

    inline float getAngle() const
    {
        return atan2f(y, x);
    };

    float getAngle(const CCPoint &other) const;

    inline float dot(const CCPoint &other) const
    {
        return x * other.x + y * other.y;
    };

    inline float cross(const CCPoint &other) const
    {
        return x * other.y - y * other.x;
    };

    inline CCPoint getPerp() const
    {
        return CCPoint(-y, x);
    };

    inline CCPoint getRPerp() const
    {
        return CCPoint(y, -x);
    };

    inline CCPoint project(const CCPoint &other) const
    {
        return other * (dot(other) / other.dot(other));
    };

    inline CCPoint rotate(const CCPoint &other) const
    {
        return CCPoint(x * other.x - y * other.y, x * other.y + y * other.x);
    };

    inline CCPoint unrotate(const CCPoint &other) const
    {
        return CCPoint(x * other.x + y * other.y, y * other.x - x * other.y);
    };

    inline CCPoint normalize() const
    {
        float length = getLength();
        if (length == 0.)
            return CCPoint(1.f, 0);
        return *this / getLength();
    };
    // #line 229 "cocos2d/cocos-headers/cocos2dx/cocoa/CCGeometry.h"
    inline CCPoint lerp(const CCPoint &other, float alpha) const
    {
        return *this * (1.f - alpha) + other * alpha;
    };
    // #line 239 "cocos2d/cocos-headers/cocos2dx/cocoa/CCGeometry.h"
    CCPoint rotateByAngle(const CCPoint &pivot, float angle) const;

    static inline CCPoint forAngle(const float a)
    {
        return CCPoint(cosf(a), sinf(a));
    }
};

class CCSize
{
public:
    float width;
    float height;

public:
    CCSize();
    CCSize(float width, float height);

    CCSize(const CCSize &other);

    CCSize(const CCPoint &point);

    CCSize &operator=(const CCSize &other);

    CCSize &operator=(const CCPoint &point);

    CCSize operator+(const CCSize &right) const;

    CCSize operator-(const CCSize &right) const;

    CCSize operator*(float a) const;

    CCSize operator/(float a) const;

    void setSize(float width, float height);

    bool equals(const CCSize &target) const;
};

class CCRect
{
public:
    CCPoint origin;
    CCSize size;

public:
    CCRect();
    CCRect(float x, float y, float width, float height);

    CCRect(const CCRect &other);

    CCRect &operator=(const CCRect &other);
    void setRect(float x, float y, float width, float height);
    float getMinX() const;
    float getMidX() const;
    float getMaxX() const;
    float getMinY() const;
    float getMidY() const;
    float getMaxY() const;
    bool equals(const CCRect &rect) const;
    bool containsPoint(const CCPoint &point) const;
    bool intersectsRect(const CCRect &rect) const;
};
// #line 339 "cocos2d/cocos-headers/cocos2dx/cocoa/CCGeometry.h"
const CCPoint CCPointZero = CCPoint((float)(0), (float)(0));

const CCSize CCSizeZero = CCSize((float)(0), (float)(0));

const CCRect CCRectZero = CCRect((float)(0), (float)(0), (float)(0), (float)(0));
// #line 36 "cocos2d/cocos-headers/cocos2dx/actions/CCAction.h"
enum
{

    kCCActionTagInvalid = -1,
};
// #line 49 "cocos2d/cocos-headers/cocos2dx/actions/CCAction.h"
class CCAction : public CCObject
{
public:
    CCAction(void);

    virtual ~CCAction(void);

    const char *description();

    virtual CCObject *copyWithZone(CCZone *pZone);

    virtual bool isDone(void);

    virtual void startWithTarget(CCNode *pTarget);

    virtual void stop(void);

    virtual void step(float dt);
    // #line 95 "cocos2d/cocos-headers/cocos2dx/actions/CCAction.h"
    virtual void update(float time);

    inline CCNode *getTarget(void) { return m_pTarget; }

    inline void setTarget(CCNode *pTarget) { m_pTarget = pTarget; }

    inline CCNode *getOriginalTarget(void) { return m_pOriginalTarget; }

    inline void setOriginalTarget(CCNode *pOriginalTarget) { m_pOriginalTarget = pOriginalTarget; }

    inline int getTag(void) { return m_nTag; }
    inline void setTag(int nTag) { m_nTag = nTag; }

    void setSpeedMod(float mod);

public:
    static CCAction *create();

protected:
    CCNode *m_pOriginalTarget;

    CCNode *m_pTarget;

    int m_nTag;
    float m_fSpeedMod;
};
// #line 139 "cocos2d/cocos-headers/cocos2dx/actions/CCAction.h"
class CCFiniteTimeAction : public CCAction
{
public:
    CCFiniteTimeAction()
        : m_fDuration(0)
    {
    }

    virtual ~CCFiniteTimeAction() {}

    inline float getDuration(void) { return m_fDuration; }

    inline void setDuration(float duration) { m_fDuration = duration; }

    virtual CCFiniteTimeAction *reverse(void);

protected:
    float m_fDuration;
};

class CCActionInterval;
class CCRepeatForever;
// #line 174 "cocos2d/cocos-headers/cocos2dx/actions/CCAction.h"
class CCSpeed : public CCAction
{
public:
    CCSpeed()
        : m_fSpeed(0.0), m_pInnerAction(NULL)
    {
    }

    virtual ~CCSpeed(void);

    inline float getSpeed(void) { return m_fSpeed; }

    inline void setSpeed(float fSpeed) { m_fSpeed = fSpeed; }

    bool initWithAction(CCActionInterval *pAction, float fSpeed);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void startWithTarget(CCNode *pTarget);
    virtual void stop();
    virtual void step(float dt);
    virtual bool isDone(void);
    virtual CCActionInterval *reverse(void);

    void setInnerAction(CCActionInterval *pAction);

    inline CCActionInterval *getInnerAction()
    {
        return m_pInnerAction;
    }

public:
    static CCSpeed *create(CCActionInterval *pAction, float fSpeed);

protected:
    float m_fSpeed;
    CCActionInterval *m_pInnerAction;
};
// #line 231 "cocos2d/cocos-headers/cocos2dx/actions/CCAction.h"
class CCFollow : public CCAction
{
public:
    CCFollow()
        : m_pobFollowedNode(NULL), m_bBoundarySet(false), m_bBoundaryFullyCovered(false), m_fLeftBoundary(0.0), m_fRightBoundary(0.0), m_fTopBoundary(0.0), m_fBottomBoundary(0.0)
    {
    }

    virtual ~CCFollow(void);

    inline bool isBoundarySet(void) { return m_bBoundarySet; }

    inline void setBoudarySet(bool bValue) { m_bBoundarySet = bValue; }

    bool initWithTarget(CCNode *pFollowedNode, const CCRect &rect = CCRectZero);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void step(float dt);
    virtual bool isDone(void);
    virtual void stop(void);

public:
    static CCFollow *create(CCNode *pFollowedNode, const CCRect &rect = CCRectZero);

protected:
    CCNode *m_pobFollowedNode;

    bool m_bBoundarySet;

    bool m_bBoundaryFullyCovered;

    CCPoint m_obHalfScreenSize;
    CCPoint m_obFullScreenSize;

    float m_fLeftBoundary;
    float m_fRightBoundary;
    float m_fTopBoundary;
    float m_fBottomBoundary;
};
// #line 33 "cocos2d/cocos-headers/cocos2dx/cocoa/CCAffineTransform.h"
struct CCAffineTransform
{
    float a, b, c, d;
    float tx, ty;
};

CCAffineTransform __CCAffineTransformMake(float a, float b, float c, float d, float tx, float ty);

CCPoint __CCPointApplyAffineTransform(const CCPoint &point, const CCAffineTransform &t);

CCSize __CCSizeApplyAffineTransform(const CCSize &size, const CCAffineTransform &t);

CCAffineTransform CCAffineTransformMakeIdentity();
CCRect CCRectApplyAffineTransform(const CCRect &rect, const CCAffineTransform &anAffineTransform);

CCAffineTransform CCAffineTransformTranslate(const CCAffineTransform &t, float tx, float ty);
CCAffineTransform CCAffineTransformRotate(const CCAffineTransform &aTransform, float anAngle);
CCAffineTransform CCAffineTransformScale(const CCAffineTransform &t, float sx, float sy);
CCAffineTransform CCAffineTransformConcat(const CCAffineTransform &t1, const CCAffineTransform &t2);
bool CCAffineTransformEqualToTransform(const CCAffineTransform &t1, const CCAffineTransform &t2);
CCAffineTransform CCAffineTransformInvert(const CCAffineTransform &t);

extern const CCAffineTransform CCAffineTransformIdentity;
// #line 48 "cocos2d/cocos-headers/cocos2dx/support/data_support/ccCArray.h"
#include <stdlib.h>
#include <string.h>
#include <limits.h>
// #line 61 "cocos2d/cocos-headers/cocos2dx/support/data_support/ccCArray.h"
typedef struct _ccArray
{
    unsigned int num, max;
    CCObject **arr;
} ccArray;

ccArray *ccArrayNew(unsigned int capacity);

void ccArrayFree(ccArray *&arr);

void ccArrayDoubleCapacity(ccArray *arr);

void ccArrayEnsureExtraCapacity(ccArray *arr, unsigned int extra);

void ccArrayShrink(ccArray *arr);

unsigned int ccArrayGetIndexOfObject(ccArray *arr, CCObject *object);

bool ccArrayContainsObject(ccArray *arr, CCObject *object);

void ccArrayAppendObject(ccArray *arr, CCObject *object);

void ccArrayAppendObjectWithResize(ccArray *arr, CCObject *object);

void ccArrayAppendArray(ccArray *arr, ccArray *plusArr);

void ccArrayAppendArrayWithResize(ccArray *arr, ccArray *plusArr);

void ccArrayInsertObjectAtIndex(ccArray *arr, CCObject *object, unsigned int index);

void ccArraySwapObjectsAtIndexes(ccArray *arr, unsigned int index1, unsigned int index2);

void ccArrayRemoveAllObjects(ccArray *arr);

void ccArrayRemoveObjectAtIndex(ccArray *arr, unsigned int index, bool bReleaseObj = true);

void ccArrayFastRemoveObjectAtIndex(ccArray *arr, unsigned int index);

void ccArrayFastRemoveObject(ccArray *arr, CCObject *object);

void ccArrayRemoveObject(ccArray *arr, CCObject *object, bool bReleaseObj = true);

void ccArrayRemoveArray(ccArray *arr, ccArray *minusArr);

void ccArrayFullRemoveArray(ccArray *arr, ccArray *minusArr);

typedef struct _ccCArray
{
    unsigned int num, max;
    void **arr;
} ccCArray;

ccCArray *ccCArrayNew(unsigned int capacity);

void ccCArrayFree(ccCArray *arr);

void ccCArrayDoubleCapacity(ccCArray *arr);

void ccCArrayEnsureExtraCapacity(ccCArray *arr, unsigned int extra);

unsigned int ccCArrayGetIndexOfValue(ccCArray *arr, void *value);

bool ccCArrayContainsValue(ccCArray *arr, void *value);

void ccCArrayInsertValueAtIndex(ccCArray *arr, void *value, unsigned int index);

void ccCArrayAppendValue(ccCArray *arr, void *value);

void ccCArrayAppendValueWithResize(ccCArray *arr, void *value);

void ccCArrayAppendArray(ccCArray *arr, ccCArray *plusArr);

void ccCArrayAppendArrayWithResize(ccCArray *arr, ccCArray *plusArr);

void ccCArrayRemoveAllValues(ccCArray *arr);

void ccCArrayRemoveValueAtIndex(ccCArray *arr, unsigned int index);

void ccCArrayFastRemoveValueAtIndex(ccCArray *arr, unsigned int index);

void ccCArrayRemoveValue(ccCArray *arr, void *value);

void ccCArrayRemoveArray(ccCArray *arr, ccCArray *minusArr);

void ccCArrayFullRemoveArray(ccCArray *arr, ccCArray *minusArr);
// #line 114 "cocos2d/cocos-headers/cocos2dx/cocoa/CCArray.h"
class CCArray : public CCObject
{
public:
    ~CCArray();

    static CCArray *create();

    static CCArray *create(CCObject *pObject, ...);

    static CCArray *createWithObject(CCObject *pObject);

    static CCArray *createWithCapacity(unsigned int capacity);

    static CCArray *createWithArray(CCArray *otherArray);

    static CCArray *createWithContentsOfFile(const char *pFileName);

    static CCArray *createWithContentsOfFileThreadSafe(const char *pFileName);

    bool init();

    bool initWithObject(CCObject *pObject);

    bool initWithObjects(CCObject *pObject, ...);

    bool initWithCapacity(unsigned int capacity);

    bool initWithArray(CCArray *otherArray);

    unsigned int count() const;

    unsigned int capacity() const;

    unsigned int indexOfObject(CCObject *object) const;

    CCObject *objectAtIndex(unsigned int index);

    CCObject *lastObject();

    CCObject *randomObject();

    bool containsObject(CCObject *object) const;

    bool isEqualToArray(CCArray *pOtherArray);

    void addObject(CCObject *object);

    void addObjectsFromArray(CCArray *otherArray);

    void insertObject(CCObject *object, unsigned int index);

    void removeLastObject(bool bReleaseObj = true);

    void removeObject(CCObject *object, bool bReleaseObj = true);

    void removeObjectAtIndex(unsigned int index, bool bReleaseObj = true);

    void removeObjectsInArray(CCArray *otherArray);

    void removeAllObjects();

    void fastRemoveObject(CCObject *object);

    void fastRemoveObjectAtIndex(unsigned int index);

    void exchangeObject(CCObject *object1, CCObject *object2);

    void exchangeObjectAtIndex(unsigned int index1, unsigned int index2);

    void replaceObjectAtIndex(unsigned int uIndex, CCObject *pObject, bool bReleaseObject = true);

    void reverseObjects();

    void reduceMemoryFootprint();

    virtual CCObject *copyWithZone(CCZone *pZone);

    virtual void acceptVisitor(CCDataVisitor &visitor);

public:
    ccArray *data;

    CCArray();

    CCArray(unsigned int capacity);
};

class CCGLProgram;

enum
{
    kCCVertexAttribFlag_None = 0,

    kCCVertexAttribFlag_Position = 1 << 0,
    kCCVertexAttribFlag_Color = 1 << 1,
    kCCVertexAttribFlag_TexCoords = 1 << 2,

    kCCVertexAttribFlag_PosColorTex = (kCCVertexAttribFlag_Position | kCCVertexAttribFlag_Color | kCCVertexAttribFlag_TexCoords),
};

typedef enum
{
    // #line 63 "cocos2d/cocos-headers/cocos2dx/shaders/ccGLStateCache.h"
    CC_GL_ALL = 0,

} ccGLServerState;
// #line 74 "cocos2d/cocos-headers/cocos2dx/shaders/ccGLStateCache.h"
void ccGLInvalidateStateCache(void);

// void ccGLUseProgram(GLuint program);

// void ccGLDeleteProgram(GLuint program);

// void ccGLBlendFunc(GLenum sfactor, GLenum dfactor);

// void ccGLBlendResetToCache(void);

// void ccSetProjectionMatrixDirty(void);
// // #line 116 "cocos2d/cocos-headers/cocos2dx/shaders/ccGLStateCache.h"
// void ccGLEnableVertexAttribs(unsigned int flags);

// void ccGLBindTexture2D(GLuint textureId);

// void ccGLBindTexture2DN(GLuint textureUnit, GLuint textureId);

// void ccGLDeleteTexture(GLuint textureId);

// void ccGLDeleteTextureN(GLuint textureUnit, GLuint textureId);

// void ccGLBindVAO(GLuint vaoId);

void ccGLEnable(ccGLServerState flags);

enum
{
    kCCVertexAttrib_Position,
    kCCVertexAttrib_Color,
    kCCVertexAttrib_TexCoords,

    kCCVertexAttrib_MAX,
};

enum
{
    kCCUniformPMatrix,
    kCCUniformMVMatrix,
    kCCUniformMVPMatrix,
    kCCUniformTime,
    kCCUniformSinTime,
    kCCUniformCosTime,
    kCCUniformRandom01,
    kCCUniformSampler,

    kCCUniform_MAX,
};
// #line 90 "cocos2d/cocos-headers/cocos2dx/shaders/CCGLProgram.h"
struct _hashUniformEntry;

typedef char GLchar;
typedef void (*GLInfoFunction)(GLuint program, GLenum pname, GLint *params);
typedef void (*GLLogFunction)(GLuint program, GLsizei bufsize, GLsizei *length, GLchar *infolog);

// #line 101 "cocos2d/cocos-headers/cocos2dx/shaders/CCGLProgram.h"
class CCGLProgram : public CCObject
{
public:
    CCGLProgram();

    virtual ~CCGLProgram();

    bool initWithVertexShaderByteArray(const GLchar *vShaderByteArray, const GLchar *fShaderByteArray);
    // #line 128 "cocos2d/cocos-headers/cocos2dx/shaders/CCGLProgram.h"
    bool initWithVertexShaderFilename(const char *vShaderFilename, const char *fShaderFilename);

    void addAttribute(const char *attributeName, GLuint index);

    bool link();

    void use();
    // #line 150 "cocos2d/cocos-headers/cocos2dx/shaders/CCGLProgram.h"
    void updateUniforms();

    GLint getUniformLocationForName(const char *name);

    void setUniformLocationWith1i(GLint location, GLint i1);

    void setUniformLocationWith2i(GLint location, GLint i1, GLint i2);

    void setUniformLocationWith3i(GLint location, GLint i1, GLint i2, GLint i3);

    void setUniformLocationWith4i(GLint location, GLint i1, GLint i2, GLint i3, GLint i4);

    void setUniformLocationWith2iv(GLint location, GLint *ints, unsigned int numberOfArrays);

    void setUniformLocationWith3iv(GLint location, GLint *ints, unsigned int numberOfArrays);

    void setUniformLocationWith4iv(GLint location, GLint *ints, unsigned int numberOfArrays);

    void setUniformLocationWith1f(GLint location, GLfloat f1);

    void setUniformLocationWith2f(GLint location, GLfloat f1, GLfloat f2);

    void setUniformLocationWith3f(GLint location, GLfloat f1, GLfloat f2, GLfloat f3);

    void setUniformLocationWith4f(GLint location, GLfloat f1, GLfloat f2, GLfloat f3, GLfloat f4);

    void setUniformLocationWith2fv(GLint location, GLfloat *floats, unsigned int numberOfArrays);

    void setUniformLocationWith3fv(GLint location, GLfloat *floats, unsigned int numberOfArrays);

    void setUniformLocationWith4fv(GLint location, GLfloat *floats, unsigned int numberOfArrays);

    void setUniformLocationWithMatrix4fv(GLint location, GLfloat *matrixArray, unsigned int numberOfMatrices);

    void setUniformsForBuiltins();

    const char *vertexShaderLog();

    const char *fragmentShaderLog();

    const char *programLog();

    void reset();

    inline const GLuint getProgram() { return m_uProgram; }

protected:
    bool updateUniformLocation(GLint location, GLvoid *data, unsigned int bytes);
    const char *description();
    bool compileShader(GLuint *shader, GLenum type, const GLchar *source);
    const char *logForOpenGLObject(GLuint object, GLInfoFunction infoFunc, GLLogFunction logFunc);

protected:
    GLuint m_uProgram;
    GLuint m_uVertShader;
    GLuint m_uFragShader;
    GLint m_uUniforms[kCCUniform_MAX];
    struct _hashUniformEntry *m_pHashForUniforms;
    bool m_bUsesTime;
    bool m_hasShaderCompiler;
};

class CCTouch : public CCObject
{
public:
    CCTouch()
        : m_nId(0),
          m_startPointCaptured(false)
    {
    }

    CCPoint getLocation() const;

    CCPoint getPreviousLocation() const;

    CCPoint getStartLocation() const;

    CCPoint getDelta() const;

    CCPoint getLocationInView() const;

    CCPoint getPreviousLocationInView() const;

    CCPoint getStartLocationInView() const;

    void setTouchInfo(int id, float x, float y)
    {
        m_nId = id;
        m_prevPoint = m_point;
        m_point.x = x;
        m_point.y = y;
        if (!m_startPointCaptured)
        {
            m_startPoint = m_point;
            m_startPointCaptured = true;
        }
    }

    int getID() const
    {
        return m_nId;
    }

private:
    int m_nId;
    bool m_startPointCaptured;
    CCPoint m_startPoint;
    CCPoint m_point;
    CCPoint m_prevPoint;
};

class CCEvent : public CCObject
{
};
// #line 28 "cocos2d/cocos-headers/cocos2dx/cocoa/CCSet.h"
#include <set>
// #line 38 "cocos2d/cocos-headers/cocos2dx/cocoa/CCSet.h"
typedef std::set<CCObject *>::iterator CCSetIterator;

class CCSet : public CCObject
{
public:
    CCSet(void);

    CCSet(const CCSet &rSetObject);

    virtual ~CCSet(void);

    static CCSet *create();

    CCSet *copy();

    CCSet *mutableCopy();

    int count();

    void addObject(CCObject *pObject);

    void removeObject(CCObject *pObject);

    void removeAllObjects();

    bool containsObject(CCObject *pObject);

    CCSetIterator begin();

    CCSetIterator end();

    CCObject *anyObject();

    virtual void acceptVisitor(CCDataVisitor &visitor);

private:
    std::set<CCObject *> *m_pSet;
};
#include <map>
#include <string>
#include <list>

typedef struct lua_State lua_State;

class CCTimer;
class CCLayer;
class CCMenuItem;
class CCNotificationCenter;
class CCCallFunc;
class CCAcceleration;

enum ccScriptType
{
    kScriptTypeNone = 0,
    kScriptTypeLua,
    kScriptTypeJavascript
};

class CCScriptHandlerEntry : public CCObject
{
public:
    static CCScriptHandlerEntry *create(int nHandler);
    ~CCScriptHandlerEntry(void);

    int getHandler(void)
    {
        return m_nHandler;
    }

    int getEntryId(void)
    {
        return m_nEntryId;
    }

protected:
    CCScriptHandlerEntry(int nHandler)
        : m_nHandler(nHandler)
    {
        static int newEntryId = 0;
        newEntryId++;
        m_nEntryId = newEntryId;
    }

    int m_nHandler;
    int m_nEntryId;
};
// #line 91 "cocos2d/cocos-headers/cocos2dx/script_support/CCScriptSupport.h"
class CCSchedulerScriptHandlerEntry : public CCScriptHandlerEntry
{
public:
    static CCSchedulerScriptHandlerEntry *create(int nHandler, float fInterval, bool bPaused);
    ~CCSchedulerScriptHandlerEntry(void);

    CCTimer *getTimer(void)
    {
        return m_pTimer;
    }

    bool isPaused(void)
    {
        return m_bPaused;
    }

    void markedForDeletion(void)
    {
        m_bMarkedForDeletion = true;
    }

    bool isMarkedForDeletion(void)
    {
        return m_bMarkedForDeletion;
    }

private:
    CCSchedulerScriptHandlerEntry(int nHandler)
        : CCScriptHandlerEntry(nHandler), m_pTimer(NULL), m_bPaused(false), m_bMarkedForDeletion(false)
    {
    }
    bool init(float fInterval, bool bPaused);

    CCTimer *m_pTimer;
    bool m_bPaused;
    bool m_bMarkedForDeletion;
};

class CCTouchScriptHandlerEntry : public CCScriptHandlerEntry
{
public:
    static CCTouchScriptHandlerEntry *create(int nHandler, bool bIsMultiTouches, int nPriority, bool bSwallowsTouches);
    ~CCTouchScriptHandlerEntry(void);

    bool isMultiTouches(void)
    {
        return m_bIsMultiTouches;
    }

    int getPriority(void)
    {
        return m_nPriority;
    }

    bool getSwallowsTouches(void)
    {
        return m_bSwallowsTouches;
    }

private:
    CCTouchScriptHandlerEntry(int nHandler)
        : CCScriptHandlerEntry(nHandler), m_bIsMultiTouches(false), m_nPriority(0), m_bSwallowsTouches(false)
    {
    }
    bool init(bool bIsMultiTouches, int nPriority, bool bSwallowsTouches);

    bool m_bIsMultiTouches;
    int m_nPriority;
    bool m_bSwallowsTouches;
};
// #line 175 "cocos2d/cocos-headers/cocos2dx/script_support/CCScriptSupport.h"
class CCScriptEngineProtocol
{
public:
    virtual ~CCScriptEngineProtocol(){};

    virtual ccScriptType getScriptType() { return kScriptTypeNone; };

    virtual void removeScriptObjectByCCObject(CCObject *pObj) = 0;

    virtual void removeScriptHandler(int nHandler){};

    virtual int reallocateScriptHandler(int nHandler) { return -1; }
    // #line 198 "cocos2d/cocos-headers/cocos2dx/script_support/CCScriptSupport.h"
    virtual int executeString(const char *codes) = 0;

    virtual int executeScriptFile(const char *filename) = 0;
    // #line 212 "cocos2d/cocos-headers/cocos2dx/script_support/CCScriptSupport.h"
    virtual int executeGlobalFunction(const char *functionName) = 0;
    // #line 220 "cocos2d/cocos-headers/cocos2dx/script_support/CCScriptSupport.h"
    virtual int executeNodeEvent(CCNode *pNode, int nAction) = 0;

    virtual int executeMenuItemEvent(CCMenuItem *pMenuItem) = 0;

    virtual int executeNotificationEvent(CCNotificationCenter *pNotificationCenter, const char *pszName) = 0;

    virtual int executeCallFuncActionEvent(CCCallFunc *pAction, CCObject *pTarget = NULL) = 0;

    virtual int executeSchedule(int nHandler, float dt, CCNode *pNode = NULL) = 0;

    virtual int executeLayerTouchesEvent(CCLayer *pLayer, int eventType, CCSet *pTouches) = 0;
    virtual int executeLayerTouchEvent(CCLayer *pLayer, int eventType, CCTouch *pTouch) = 0;

    virtual int executeLayerKeypadEvent(CCLayer *pLayer, int eventType) = 0;

    virtual int executeAccelerometerEvent(CCLayer *pLayer, CCAcceleration *pAccelerationValue) = 0;

    virtual int executeEvent(int nHandler, const char *pEventName, CCObject *pEventSource = NULL, const char *pEventSourceClassName = NULL) = 0;

    virtual int executeEventWithArgs(int nHandler, CCArray *pArgs) { return 0; }

    virtual bool handleAssert(const char *msg) = 0;

    enum ConfigType
    {
        NONE,
        COCOSTUDIO,
    };
    virtual bool parseConfig(ConfigType type, const std::string &str) = 0;
};
// #line 270 "cocos2d/cocos-headers/cocos2dx/script_support/CCScriptSupport.h"
class CCScriptEngineManager
{
public:
    ~CCScriptEngineManager(void);

    CCScriptEngineProtocol *getScriptEngine(void)
    {
        return m_pScriptEngine;
    }
    void setScriptEngine(CCScriptEngineProtocol *pScriptEngine);
    void removeScriptEngine(void);

    static CCScriptEngineManager *sharedManager(void);
    static void purgeSharedManager(void);

private:
    CCScriptEngineManager(void)
        : m_pScriptEngine(NULL)
    {
    }

    CCScriptEngineProtocol *m_pScriptEngine;
};
// #line 30 "cocos2d/cocos-headers/cocos2dx/include/ccTypes.h"
#include <string>
// #line 40 "cocos2d/cocos-headers/cocos2dx/include/ccTypes.h"
typedef struct _ccColor3B
{
    GLubyte r;
    GLubyte g;
    GLubyte b;
} ccColor3B;

typedef struct _ccHSVValue
{
    float h, s, v;
    GLubyte absoluteSaturation;
    GLubyte absoluteBrightness;

private:
    unsigned char __pad[2];
} ccHSVValue;

static inline ccHSVValue
cchsv(const float vh, const float vs, const float vv, const bool as, const bool ab)
{
    ccHSVValue hsv;
    hsv.h = vh;
    hsv.s = vs;
    hsv.v = vv;
    hsv.absoluteSaturation = as;
    hsv.absoluteBrightness = ab;
    return hsv;
}

static inline bool hsv_geta(ccHSVValue hsv, bool brightOrSaturation)
{
    if (brightOrSaturation)
        return static_cast<bool>(hsv.absoluteSaturation);
    return static_cast<bool>(hsv.absoluteBrightness);
}

static inline ccColor3B
ccc3(const GLubyte r, const GLubyte g, const GLubyte b)
{
    ccColor3B c = {r, g, b};
    return c;
}

static inline bool ccc3BEqual(const ccColor3B &col1, const ccColor3B &col2)
{
    return col1.r == col2.r && col1.g == col2.g && col1.b == col2.b;
}

static const ccColor3B ccWHITE = {255, 255, 255};

static const ccColor3B ccYELLOW = {255, 255, 0};

static const ccColor3B ccBLUE = {0, 0, 255};

static const ccColor3B ccGREEN = {0, 255, 0};

static const ccColor3B ccRED = {255, 0, 0};

static const ccColor3B ccMAGENTA = {255, 0, 255};

static const ccColor3B ccBLACK = {0, 0, 0};

static const ccColor3B ccORANGE = {255, 127, 0};

static const ccColor3B ccGRAY = {166, 166, 166};

typedef struct _ccColor4B
{
    GLubyte r;
    GLubyte g;
    GLubyte b;
    GLubyte a;
} ccColor4B;

static inline ccColor4B
ccc4(const GLubyte r, const GLubyte g, const GLubyte b, const GLubyte o)
{
    ccColor4B c = {r, g, b, o};
    return c;
}

typedef struct _ccColor4F
{
    GLfloat r;
    GLfloat g;
    GLfloat b;
    GLfloat a;
} ccColor4F;

static inline ccColor4F ccc4FFromccc3B(ccColor3B c)
{
    ccColor4F c4 = {c.r / 255.f, c.g / 255.f, c.b / 255.f, 1.f};
    return c4;
}

static inline ccColor4F
ccc4f(const GLfloat r, const GLfloat g, const GLfloat b, const GLfloat a)
{
    ccColor4F c4 = {r, g, b, a};
    return c4;
}

static inline ccColor4F ccc4FFromccc4B(ccColor4B c)
{
    ccColor4F c4 = {c.r / 255.f, c.g / 255.f, c.b / 255.f, c.a / 255.f};
    return c4;
}

static inline ccColor4B ccc4BFromccc4F(ccColor4F c)
{
    ccColor4B ret = {(GLubyte)(c.r * 255), (GLubyte)(c.g * 255), (GLubyte)(c.b * 255), (GLubyte)(c.a * 255)};
    return ret;
}

static inline bool ccc4FEqual(ccColor4F a, ccColor4F b)
{
    return a.r == b.r && a.g == b.g && a.b == b.b && a.a == b.a;
}

typedef struct _ccVertex2F
{
    GLfloat x;
    GLfloat y;
} ccVertex2F;

static inline ccVertex2F vertex2(const float x, const float y)
{
    ccVertex2F c = {x, y};
    return c;
}

typedef struct _ccVertex3F
{
    GLfloat x;
    GLfloat y;
    GLfloat z;
} ccVertex3F;

static inline ccVertex3F vertex3(const float x, const float y, const float z)
{
    ccVertex3F c = {x, y, z};
    return c;
}

typedef struct _ccTex2F
{
    GLfloat u;
    GLfloat v;
} ccTex2F;

static inline ccTex2F tex2(const float u, const float v)
{
    ccTex2F t = {u, v};
    return t;
}

typedef struct _ccPointSprite
{
    ccVertex2F pos;
    ccColor4B color;
    GLfloat size;
} ccPointSprite;

typedef struct _ccQuad2
{
    ccVertex2F tl;
    ccVertex2F tr;
    ccVertex2F bl;
    ccVertex2F br;
} ccQuad2;

typedef struct _ccQuad3
{
    ccVertex3F bl;
    ccVertex3F br;
    ccVertex3F tl;
    ccVertex3F tr;
} ccQuad3;

typedef struct _ccV2F_C4B_T2F
{

    ccVertex2F vertices;

    ccColor4B colors;

    ccTex2F texCoords;
} ccV2F_C4B_T2F;

typedef struct _ccV2F_C4F_T2F
{

    ccVertex2F vertices;

    ccColor4F colors;

    ccTex2F texCoords;
} ccV2F_C4F_T2F;

typedef struct _ccV3F_C4B_T2F
{

    ccVertex3F vertices;

    ccColor4B colors;

    ccTex2F texCoords;
} ccV3F_C4B_T2F;

typedef struct _ccV2F_C4B_T2F_Triangle
{

    ccV2F_C4B_T2F a;

    ccV2F_C4B_T2F b;

    ccV2F_C4B_T2F c;
} ccV2F_C4B_T2F_Triangle;

typedef struct _ccV2F_C4B_T2F_Quad
{

    ccV2F_C4B_T2F bl;

    ccV2F_C4B_T2F br;

    ccV2F_C4B_T2F tl;

    ccV2F_C4B_T2F tr;
} ccV2F_C4B_T2F_Quad;

typedef struct _ccV3F_C4B_T2F_Quad
{

    ccV3F_C4B_T2F tl;

    ccV3F_C4B_T2F bl;

    ccV3F_C4B_T2F tr;

    ccV3F_C4B_T2F br;
} ccV3F_C4B_T2F_Quad;

typedef struct _ccV2F_C4F_T2F_Quad
{

    ccV2F_C4F_T2F bl;

    ccV2F_C4F_T2F br;

    ccV2F_C4F_T2F tl;

    ccV2F_C4F_T2F tr;
} ccV2F_C4F_T2F_Quad;

typedef struct _ccBlendFunc
{

    GLenum src;

    GLenum dst;
} ccBlendFunc;

static const ccBlendFunc kCCBlendFuncDisable;

typedef enum
{
    kCCVerticalTextAlignmentTop,
    kCCVerticalTextAlignmentCenter,
    kCCVerticalTextAlignmentBottom,
} CCVerticalTextAlignment;

typedef enum
{
    kCCTextAlignmentLeft,
    kCCTextAlignmentCenter,
    kCCTextAlignmentRight,
} CCTextAlignment;

typedef struct _ccT2F_Quad
{

    ccTex2F bl;

    ccTex2F br;

    ccTex2F tl;

    ccTex2F tr;
} ccT2F_Quad;

typedef struct
{
    ccT2F_Quad texCoords;
    float delay;
    CCSize size;
} ccAnimationFrameData;
// #line 398 "cocos2d/cocos-headers/cocos2dx/include/ccTypes.h"
typedef struct _ccFontShadow
{
public:
    _ccFontShadow() : m_shadowEnabled(false) {}

    bool m_shadowEnabled;

    CCSize m_shadowOffset;

    float m_shadowBlur;

    float m_shadowOpacity;

} ccFontShadow;

typedef struct _ccFontStroke
{
public:
    _ccFontStroke() : m_strokeEnabled(false) {}

    bool m_strokeEnabled;

    ccColor3B m_strokeColor;

    float m_strokeSize;

} ccFontStroke;

typedef struct _ccFontDefinition
{
public:
    _ccFontDefinition() : m_alignment(kCCTextAlignmentCenter),
                          m_vertAlignment(kCCVerticalTextAlignmentTop),
                          m_fontFillColor(ccWHITE)
    {
        m_dimensions = CCSize((float)(0), (float)(0));
    }

    std::string m_fontName;

    int m_fontSize;

    CCTextAlignment m_alignment;

    CCVerticalTextAlignment m_vertAlignment;

    CCSize m_dimensions;

    ccColor3B m_fontFillColor;

    ccFontShadow m_shadow;

    ccFontStroke m_stroke;

} ccFontDefinition;
// #line 29 "cocos2d/cocos-headers/cocos2dx/textures/CCTexture2D.h"
#include <string>
// #line 39 "cocos2d/cocos-headers/cocos2dx/textures/CCTexture2D.h"
class CCImage;
// #line 51 "cocos2d/cocos-headers/cocos2dx/textures/CCTexture2D.h"
typedef enum
{

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

class CCGLProgram;

typedef struct _ccTexParams
{
    GLuint minFilter;
    GLuint magFilter;
    GLuint wrapS;
    GLuint wrapT;
} ccTexParams;
// #line 109 "cocos2d/cocos-headers/cocos2dx/textures/CCTexture2D.h"
class CCTexture2D : public CCObject

{
public:
    CCTexture2D();

    virtual ~CCTexture2D();

    const char *description(void);

    void releaseData(void *data);

    void *keepData(void *data, unsigned int length);

    bool initWithData(const void *data, CCTexture2DPixelFormat pixelFormat, unsigned int pixelsWide, unsigned int pixelsHigh, const CCSize &contentSize);

    void drawAtPoint(const CCPoint &point);

    void drawInRect(const CCRect &rect);
    // #line 160 "cocos2d/cocos-headers/cocos2dx/textures/CCTexture2D.h"
    bool initWithImage(CCImage *uiImage);

    bool initWithString(const char *text, const char *fontName, float fontSize, const CCSize &dimensions, CCTextAlignment hAlignment, CCVerticalTextAlignment vAlignment);

    bool initWithString(const char *text, const char *fontName, float fontSize);

    bool initWithString(const char *text, ccFontDefinition *textDefinition);

    bool initWithPVRFile(const char *file);

    bool initWithETCFile(const char *file);
    // #line 186 "cocos2d/cocos-headers/cocos2dx/textures/CCTexture2D.h"
    void setTexParameters(ccTexParams *texParams);
    // #line 196 "cocos2d/cocos-headers/cocos2dx/textures/CCTexture2D.h"
    void setAntiAliasTexParameters();
    // #line 206 "cocos2d/cocos-headers/cocos2dx/textures/CCTexture2D.h"
    void setAliasTexParameters();

    void generateMipmap();

    const char *stringForFormat();

    unsigned int bitsPerPixelForFormat();

    unsigned int bitsPerPixelForFormat(CCTexture2DPixelFormat format);
    // #line 247 "cocos2d/cocos-headers/cocos2dx/textures/CCTexture2D.h"
    static void setDefaultAlphaPixelFormat(CCTexture2DPixelFormat format);

    static CCTexture2DPixelFormat defaultAlphaPixelFormat();
    // #line 263 "cocos2d/cocos-headers/cocos2dx/textures/CCTexture2D.h"
    static void PVRImagesHavePremultipliedAlpha(bool haveAlphaPremultiplied);

    const CCSize &getContentSizeInPixels();

    bool hasPremultipliedAlpha();
    bool hasMipmaps();

private:
    bool initPremultipliedATextureWithImage(CCImage *image, unsigned int pixelsWide, unsigned int pixelsHigh);

    bool m_bPVRHaveAlphaPremultiplied;

protected:
    CCTexture2DPixelFormat m_ePixelFormat;

public:
    virtual CCTexture2DPixelFormat getPixelFormat(void);

protected:
    unsigned int m_uPixelsWide;

public:
    virtual unsigned int getPixelsWide(void);

protected:
    unsigned int m_uPixelsHigh;

public:
    virtual unsigned int getPixelsHigh(void);

protected:
    GLuint m_uName;

public:
    virtual GLuint getName(void);

protected:
    GLfloat m_fMaxS;

public:
    virtual GLfloat getMaxS(void);

public:
    virtual void setMaxS(GLfloat var);

protected:
    GLfloat m_fMaxT;

public:
    virtual GLfloat getMaxT(void);

public:
    virtual void setMaxT(GLfloat var);

protected:
    CCSize m_tContentSize;

public:
    virtual CCSize getContentSize(void);

    bool m_bHasPremultipliedAlpha;

    bool m_bHasMipmaps;

protected:
    CCGLProgram *m_pShaderProgram;

public:
    virtual CCGLProgram *getShaderProgram(void);

public:
    virtual void setShaderProgram(CCGLProgram *var);
    ;
};
// #line 31 "cocos2d/cocos-headers/cocos2dx/include/CCProtocols.h"
#include <string>
// #line 39 "cocos2d/cocos-headers/cocos2dx/include/CCProtocols.h"
class CCRGBAProtocol
{
public:
    virtual void setColor(const ccColor3B &color) = 0;

    virtual const ccColor3B &getColor(void) = 0;

    virtual const ccColor3B &getDisplayedColor(void) = 0;

    virtual GLubyte getDisplayedOpacity(void) = 0;
    // #line 77 "cocos2d/cocos-headers/cocos2dx/include/CCProtocols.h"
    virtual GLubyte getOpacity(void) = 0;

    virtual void setOpacity(GLubyte opacity) = 0;
    // #line 96 "cocos2d/cocos-headers/cocos2dx/include/CCProtocols.h"
    virtual void setOpacityModifyRGB(bool bValue) = 0;
    // #line 104 "cocos2d/cocos-headers/cocos2dx/include/CCProtocols.h"
    virtual bool isOpacityModifyRGB(void) = 0;

    virtual bool isCascadeColorEnabled(void) = 0;
    virtual void setCascadeColorEnabled(bool cascadeColorEnabled) = 0;

    virtual void updateDisplayedColor(const ccColor3B &color) = 0;

    virtual bool isCascadeOpacityEnabled(void) = 0;
    virtual void setCascadeOpacityEnabled(bool cascadeOpacityEnabled) = 0;

    virtual void updateDisplayedOpacity(GLubyte opacity) = 0;
};
// #line 136 "cocos2d/cocos-headers/cocos2dx/include/CCProtocols.h"
class CCBlendProtocol
{
public:
    // #line 146 "cocos2d/cocos-headers/cocos2dx/include/CCProtocols.h"
    virtual void setBlendFunc(ccBlendFunc blendFunc) = 0;

    virtual ccBlendFunc getBlendFunc(void) = 0;
};
// #line 166 "cocos2d/cocos-headers/cocos2dx/include/CCProtocols.h"
class CCTextureProtocol : public CCBlendProtocol
{
public:
    virtual CCTexture2D *getTexture(void) = 0;
    // #line 183 "cocos2d/cocos-headers/cocos2dx/include/CCProtocols.h"
    virtual void setTexture(CCTexture2D *texture) = 0;
};

class CCLabelProtocol
{
public:
    virtual void setString(const char *label) = 0;

    virtual const char *getString(void) = 0;
};

class CCDirectorDelegate
{
public:
    virtual void updateProjection(void) = 0;
};
// #line 43 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
class CCCamera;
class CCGridBase;
class CCPoint;
class CCTouch;
class CCAction;
class CCRGBAProtocol;
class CCLabelProtocol;
class CCScheduler;
class CCActionManager;
class CCComponent;
class CCDictionary;
class CCComponentContainer;

enum
{
    kCCNodeTagInvalid = -1,
};

enum
{
    kCCNodeOnEnter,
    kCCNodeOnExit,
    kCCNodeOnEnterTransitionDidFinish,
    kCCNodeOnExitTransitionDidStart,
    kCCNodeOnCleanup
};
// #line 128 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
class CCNode : public CCObject
{
public:
    // #line 138 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    CCNode(void);

    CCNode(const CCNode &);
    // #line 149 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual ~CCNode(void);

    virtual bool init();

    static CCNode *create(void);

    const char *description(void);
    // #line 186 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void setZOrder(int zOrder);
    // #line 195 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void _setZOrder(int z);
    // #line 203 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual int getZOrder();
    // #line 218 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void setVertexZ(float vertexZ);
    // #line 226 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual float getVertexZ();
    // #line 236 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void setScaleX(float fScaleX);
    // #line 244 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual float getScaleX();
    // #line 254 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void setScaleY(float fScaleY);
    // #line 262 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual float getScaleY();
    // #line 272 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void setScale(float scale);
    // #line 281 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual float getScale();
    // #line 292 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void setScale(float fScaleX, float fScaleY);
    // #line 309 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void setPosition(const CCPoint &position);
    // #line 317 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual const CCPoint &getPosition();
    // #line 335 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void setPosition(float x, float y);

    virtual void getPosition(float *x, float *y);

    virtual void setPositionX(float x);
    virtual float getPositionX(void);
    virtual void setPositionY(float y);
    virtual float getPositionY(void);
    // #line 361 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void setSkewX(float fSkewX);
    // #line 369 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual float getSkewX();
    // #line 381 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void setSkewY(float fSkewY);
    // #line 389 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual float getSkewY();
    // #line 403 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void setAnchorPoint(const CCPoint &anchorPoint);
    // #line 411 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual const CCPoint &getAnchorPoint();
    // #line 420 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual const CCPoint &getAnchorPointInPoints();
    // #line 430 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void setContentSize(const CCSize &contentSize);
    // #line 438 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual const CCSize &getContentSize() const;

    virtual CCSize getScaledContentSize(void);
    // #line 449 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void setVisible(bool visible);
    // #line 457 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual bool isVisible();
    // #line 468 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void setRotation(float fRotation);
    // #line 476 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual float getRotation();
    // #line 487 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void setRotationX(float fRotaionX);
    // #line 495 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual float getRotationX();
    // #line 506 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void setRotationY(float fRotationY);
    // #line 514 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual float getRotationY();
    // #line 527 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void setOrderOfArrival(unsigned int uOrderOfArrival);
    // #line 535 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual unsigned int getOrderOfArrival();
    // #line 544 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void setGLServerState(ccGLServerState glServerState);

    virtual ccGLServerState getGLServerState();
    // #line 563 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void ignoreAnchorPointForPosition(bool ignore);
    // #line 571 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual bool isIgnoreAnchorPointForPosition();
    // #line 586 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void addChild(CCNode *child);
    // #line 595 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void addChild(CCNode *child, int zOrder);
    // #line 605 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void addChild(CCNode *child, int zOrder, int tag);
    // #line 613 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual CCNode *getChildByTag(int tag);
    // #line 630 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual CCArray *getChildren();

    virtual unsigned int getChildrenCount(void) const;

    virtual void setParent(CCNode *parent);
    // #line 652 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual CCNode *getParent();
    // #line 662 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void removeFromParent();

    virtual void removeFromParentAndCleanup(bool cleanup);

    virtual void removeMeAndCleanup(void);
    // #line 680 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void removeChild(CCNode *child);

    virtual void removeChild(CCNode *child, bool cleanup);
    // #line 695 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void removeChildByTag(int tag);

    virtual void removeChildByTag(int tag, bool cleanup);

    virtual void removeAllChildren();

    virtual void removeAllChildrenWithCleanup(bool cleanup);
    // #line 723 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void reorderChild(CCNode *child, int zOrder);

    virtual void sortAllChildren();
    // #line 745 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual CCGridBase *getGrid();

    virtual void setGrid(CCGridBase *pGrid);
    // #line 810 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void *getUserData();
    // #line 821 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void setUserData(void *pUserData);
    // #line 831 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual CCObject *getUserObject();
    // #line 842 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void setUserObject(CCObject *pUserObject);
    // #line 854 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual CCGLProgram *getShaderProgram();
    // #line 866 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void setShaderProgram(CCGLProgram *pShaderProgram);
    // #line 881 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual CCCamera *getCamera();
    // #line 890 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual bool isRunning();
    // #line 917 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void registerScriptHandler(int handler);

    virtual void unregisterScriptHandler(void);
    // #line 931 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    inline int getScriptHandler() { return m_nScriptHandler; };

    void scheduleUpdateWithPriorityLua(int nHandler, int priority);
    // #line 953 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void onEnter();
    // #line 961 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void onEnterTransitionDidFinish();
    // #line 971 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void onExit();
    // #line 979 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void onExitTransitionDidStart();
    // #line 987 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void cleanup(void);
    // #line 999 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void draw(void);

    virtual void visit(void);
    // #line 1017 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    CCRect boundingBox(void);
    // #line 1029 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void setActionManager(CCActionManager *actionManager);

    virtual CCActionManager *getActionManager();
    // #line 1045 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    CCAction *runAction(CCAction *action);

    void stopAllActions(void);

    void stopAction(CCAction *action);

    void stopActionByTag(int tag);
    // #line 1073 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    CCAction *getActionByTag(int tag);
    // #line 1085 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    unsigned int numberOfRunningActions(void);
    // #line 1100 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void setScheduler(CCScheduler *scheduler);
    // #line 1108 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual CCScheduler *getScheduler();
    // #line 1118 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    bool isScheduled(SEL_SCHEDULE selector);
    // #line 1128 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    void scheduleUpdate(void);
    // #line 1138 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    void scheduleUpdateWithPriority(int priority);

    void unscheduleUpdate(void);
    // #line 1162 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    void schedule(SEL_SCHEDULE selector, float interval, unsigned int repeat, float delay);
    // #line 1172 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    void schedule(SEL_SCHEDULE selector, float interval);
    // #line 1182 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    void scheduleOnce(SEL_SCHEDULE selector, float delay);
    // #line 1191 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    void schedule(SEL_SCHEDULE selector);
    // #line 1200 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    void unschedule(SEL_SCHEDULE selector);

    void unscheduleAllSelectors(void);
    // #line 1214 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    void resumeSchedulerAndActions(void);

    void pauseSchedulerAndActions(void);

    virtual void update(float delta);
    // #line 1236 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    void transform(void);

    void transformAncestors(void);
    // #line 1250 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    virtual void updateTransform(void);

    virtual const CCAffineTransform nodeToParentTransform(void);

    virtual const CCAffineTransform parentToNodeTransform(void);

    virtual CCAffineTransform nodeToWorldTransform(void);

    virtual CCAffineTransform worldToNodeTransform(void);
    // #line 1285 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    CCPoint convertToNodeSpace(const CCPoint &worldPoint);

    CCPoint convertToWorldSpace(const CCPoint &nodePoint);

    CCPoint convertToNodeSpaceAR(const CCPoint &worldPoint);

    CCPoint convertToWorldSpaceAR(const CCPoint &nodePoint);

    CCPoint convertTouchToNodeSpace(CCTouch *touch);

    CCPoint convertTouchToNodeSpaceAR(CCTouch *touch);
    // #line 1362 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    void setAdditionalTransform(const CCAffineTransform &additionalTransform);
    // #line 1371 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
    CCComponent *getComponent(const char *pName) const;

    virtual bool addComponent(CCComponent *pComponent);

    virtual bool removeComponent(const char *pName);

    virtual bool removeComponent(CCComponent *pComponent);

    virtual void removeAllComponents();

    virtual void updateTweenAction(float, const char *);
    CCNode &operator=(const CCNode &);

private:
    void childrenAlloc(void);

    void insertChild(CCNode *child, int z);

    void detachChild(CCNode *child, bool doCleanup);

    CCPoint convertToWindowSpace(const CCPoint &nodePoint);

protected:
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

    CCCamera *m_pCamera;

    CCGridBase *m_pGrid;

    int m_nZOrder;

    CCArray *m_pChildren;
    CCNode *m_pParent;

    void *m_pUserData;
    CCObject *m_pUserObject;

    CCGLProgram *m_pShaderProgram;

    ccGLServerState m_eGLServerState;

    unsigned int m_uOrderOfArrival;

    CCScheduler *m_pScheduler;

    CCActionManager *m_pActionManager;

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

    CCComponentContainer *m_pComponentContainer;
};
// #line 1497 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCNode.h"
class CCNodeRGBA : public CCNode, public CCRGBAProtocol
{
public:
    CCNodeRGBA();

    virtual ~CCNodeRGBA();

    virtual bool init();

    static CCNodeRGBA *create(void);

    virtual GLubyte getOpacity();
    virtual GLubyte getDisplayedOpacity();
    virtual void setOpacity(GLubyte opacity);
    virtual void updateDisplayedOpacity(GLubyte parentOpacity);
    virtual bool isCascadeOpacityEnabled();
    virtual void setCascadeOpacityEnabled(bool cascadeOpacityEnabled);

    virtual const ccColor3B &getColor(void);
    virtual const ccColor3B &getDisplayedColor();
    virtual void setColor(const ccColor3B &color);
    virtual void updateDisplayedColor(const ccColor3B &parentColor);
    virtual bool isCascadeColorEnabled();
    virtual void setCascadeColorEnabled(bool cascadeColorEnabled);
    virtual void setOpacityModifyRGB(bool bValue);
    virtual bool isOpacityModifyRGB();

protected:
    GLubyte _displayedOpacity;
    GLubyte _realOpacity;
    ccColor3B _displayedColor;
    ccColor3B _realColor;
    bool _cascadeColorEnabled;
    bool _cascadeOpacityEnabled;
};
// #line 37 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSpriteFrame.h"
class CCTexture2D;
class CCZone;
// #line 55 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSpriteFrame.h"
class CCSpriteFrame : public CCObject
{
public:
    inline const CCRect &getRectInPixels(void) { return m_obRectInPixels; }
    void setRectInPixels(const CCRect &rectInPixels);

    inline bool isRotated(void) { return m_bRotated; }
    inline void setRotated(bool bRotated) { m_bRotated = bRotated; }

    inline const CCRect &getRect(void) { return m_obRect; }
    void setRect(const CCRect &rect);

    const CCPoint &getOffsetInPixels(void);

    void setOffsetInPixels(const CCPoint &offsetInPixels);

    inline const CCSize &getOriginalSizeInPixels(void) { return m_obOriginalSizeInPixels; }

    inline void setOriginalSizeInPixels(const CCSize &sizeInPixels) { m_obOriginalSizeInPixels = sizeInPixels; }

    inline const CCSize &getOriginalSize(void) { return m_obOriginalSize; }

    inline void setOriginalSize(const CCSize &sizeInPixels) { m_obOriginalSize = sizeInPixels; }

    CCTexture2D *getTexture(void);

    void setTexture(CCTexture2D *pobTexture);

    const CCPoint &getOffset(void);
    void setOffset(const CCPoint &offsets);

public:
    ~CCSpriteFrame(void);

    virtual CCObject *copyWithZone(CCZone *pZone);

    static CCSpriteFrame *create(const char *filename, const CCRect &rect);

    static CCSpriteFrame *create(const char *filename, const CCRect &rect, bool rotated, const CCPoint &offset, const CCSize &originalSize);

    static CCSpriteFrame *createWithTexture(CCTexture2D *pobTexture, const CCRect &rect);

    static CCSpriteFrame *createWithTexture(CCTexture2D *pobTexture, const CCRect &rect, bool rotated, const CCPoint &offset, const CCSize &originalSize);

public:
    bool initWithTexture(CCTexture2D *pobTexture, const CCRect &rect);

    bool initWithTextureFilename(const char *filename, const CCRect &rect);

    bool initWithTexture(CCTexture2D *pobTexture, const CCRect &rect, bool rotated, const CCPoint &offset, const CCSize &originalSize);

    bool initWithTextureFilename(const char *filename, const CCRect &rect, bool rotated, const CCPoint &offset, const CCSize &originalSize);

protected:
    CCPoint m_obOffset;
    CCSize m_obOriginalSize;
    CCRect m_obRectInPixels;
    bool m_bRotated;
    CCRect m_obRect;
    CCPoint m_obOffsetInPixels;
    CCSize m_obOriginalSizeInPixels;
    CCTexture2D *m_pobTexture;
    std::string m_strTextureFilename;
};
// #line 27 "cocos2d/cocos-headers/cocos2dx/support/data_support/uthash.h"
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
// #line 64 "cocos2d/cocos-headers/cocos2dx/support/data_support/uthash.h"
#include <inttypes.h>
// #line 872 "cocos2d/cocos-headers/cocos2dx/support/data_support/uthash.h"
typedef struct UT_hash_bucket
{
    struct UT_hash_handle *hh_head;
    unsigned count;
    // #line 888 "cocos2d/cocos-headers/cocos2dx/support/data_support/uthash.h"
    unsigned expand_mult;

} UT_hash_bucket;

typedef struct UT_hash_table
{
    UT_hash_bucket *buckets;
    unsigned num_buckets, log2_num_buckets;
    unsigned num_items;
    struct UT_hash_handle *tail;
    ptrdiff_t hho;

    unsigned ideal_chain_maxlen;

    unsigned nonideal_items;
    // #line 918 "cocos2d/cocos-headers/cocos2dx/support/data_support/uthash.h"
    unsigned ineff_expands, noexpand;

    uint32_t signature;

} UT_hash_table;

typedef struct UT_hash_handle
{
    struct UT_hash_table *tbl;
    void *prev;
    void *next;
    struct UT_hash_handle *hh_prev;
    struct UT_hash_handle *hh_next;
    void *key;
    unsigned keylen;
    unsigned hashv;
} UT_hash_handle;
// #line 31 "cocos2d/cocos-headers/cocos2dx/cocoa/CCString.h"
#include <stdarg.h>
#include <string>
#include <functional>
// #line 44 "cocos2d/cocos-headers/cocos2dx/cocoa/CCString.h"
class CCString : public CCObject
{
public:
    CCString();

    CCString(const char *str);

    CCString(const std::string &str);

    CCString(const CCString &str);

    virtual ~CCString();

    CCString &operator=(const CCString &other);

    bool initWithFormat(const char *format, ...);

    int intValue() const;

    unsigned int uintValue() const;

    float floatValue() const;

    double doubleValue() const;

    bool boolValue() const;

    const char *getCString() const;

    unsigned int length() const;

    int compare(const char *) const;

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual bool isEqual(const CCObject *pObject);

    static CCString *create(const std::string &str);
    // #line 121 "cocos2d/cocos-headers/cocos2dx/cocoa/CCString.h"
    static CCString *createWithFormat(const char *format, ...);

    static CCString *createWithData(const unsigned char *pData, unsigned long nLen);

    static CCString *createWithContentsOfFile(const char *pszFileName);

    virtual void acceptVisitor(CCDataVisitor &visitor);

private:
    bool initWithFormatAndValist(const char *format, va_list ap);

public:
    std::string m_sString;
};
// #line 35 "cocos2d/cocos-headers/cocos2dx/cocoa/CCDictionary.h"
class CCDictionary;
// #line 63 "cocos2d/cocos-headers/cocos2dx/cocoa/CCDictionary.h"
class CCDictElement
{
private:
    CCDictElement(const char *pszKey, CCObject *pObject);
    // #line 80 "cocos2d/cocos-headers/cocos2dx/cocoa/CCDictionary.h"
    CCDictElement(intptr_t iKey, CCObject *pObject);

public:
    ~CCDictElement();
    // #line 97 "cocos2d/cocos-headers/cocos2dx/cocoa/CCDictionary.h"
    inline const char *getStrKey() const
    {
        ((void)(m_szKey[0] != '\0'));
        return m_szKey;
    }
    // #line 110 "cocos2d/cocos-headers/cocos2dx/cocoa/CCDictionary.h"
    inline intptr_t getIntKey() const
    {
        ((void)(m_szKey[0] == '\0'));
        return m_iKey;
    }

    inline CCObject *getObject() const { return m_pObject; }

private:
    char m_szKey[256];
    intptr_t m_iKey;
    CCObject *m_pObject;

public:
    UT_hash_handle hh;
    friend class CCDictionary;
};
// #line 174 "cocos2d/cocos-headers/cocos2dx/cocoa/CCDictionary.h"
class CCDictionary : public CCObject
{
public:
    CCDictionary();

    ~CCDictionary();

    unsigned int count();

    CCArray *allKeys();

    CCArray *allKeysForObject(CCObject *object);
    // #line 228 "cocos2d/cocos-headers/cocos2dx/cocoa/CCDictionary.h"
    CCObject *objectForKey(const std::string &key);
    // #line 238 "cocos2d/cocos-headers/cocos2dx/cocoa/CCDictionary.h"
    CCObject *objectForKey(intptr_t key);
    // #line 248 "cocos2d/cocos-headers/cocos2dx/cocoa/CCDictionary.h"
    const CCString *valueForKey(const std::string &key);
    // #line 258 "cocos2d/cocos-headers/cocos2dx/cocoa/CCDictionary.h"
    const CCString *valueForKey(intptr_t key);
    // #line 271 "cocos2d/cocos-headers/cocos2dx/cocoa/CCDictionary.h"
    void setObject(CCObject *pObject, const std::string &key);
    // #line 283 "cocos2d/cocos-headers/cocos2dx/cocoa/CCDictionary.h"
    void setObject(CCObject *pObject, intptr_t key);
    // #line 292 "cocos2d/cocos-headers/cocos2dx/cocoa/CCDictionary.h"
    void removeObjectForKey(const std::string &key);
    // #line 301 "cocos2d/cocos-headers/cocos2dx/cocoa/CCDictionary.h"
    void removeObjectForKey(intptr_t key);
    // #line 310 "cocos2d/cocos-headers/cocos2dx/cocoa/CCDictionary.h"
    void removeObjectsForKeys(CCArray *pKeyArray);
    // #line 320 "cocos2d/cocos-headers/cocos2dx/cocoa/CCDictionary.h"
    void removeObjectForElememt(CCDictElement *pElement);
    // #line 328 "cocos2d/cocos-headers/cocos2dx/cocoa/CCDictionary.h"
    void removeAllObjects();
    // #line 338 "cocos2d/cocos-headers/cocos2dx/cocoa/CCDictionary.h"
    virtual CCObject *copyWithZone(CCZone *pZone);
    // #line 348 "cocos2d/cocos-headers/cocos2dx/cocoa/CCDictionary.h"
    CCObject *randomObject();

    static CCDictionary *create();
    // #line 364 "cocos2d/cocos-headers/cocos2dx/cocoa/CCDictionary.h"
    static CCDictionary *createWithDictionary(CCDictionary *srcDict);
    // #line 372 "cocos2d/cocos-headers/cocos2dx/cocoa/CCDictionary.h"
    static CCDictionary *createWithContentsOfFile(const char *pFileName);
    // #line 380 "cocos2d/cocos-headers/cocos2dx/cocoa/CCDictionary.h"
    bool writeToFile(const char *fullPath);
    // #line 394 "cocos2d/cocos-headers/cocos2dx/cocoa/CCDictionary.h"
    static CCDictionary *createWithContentsOfFileThreadSafe(const char *pFileName);

    virtual void acceptVisitor(CCDataVisitor &visitor);

private:
    void setObjectUnSafe(CCObject *pObject, const std::string &key);
    void setObjectUnSafe(CCObject *pObject, const intptr_t key);

public:
    CCDictElement *m_pElements;

private:
    enum CCDictType
    {
        kCCDictUnknown = 0,
        kCCDictStr,
        kCCDictInt
    };

    CCDictType m_eDictType;
};
// #line 35 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCAnimation.h"
#include <string>

class CCTexture2D;
class CCSpriteFrame;
// #line 55 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCAnimation.h"
class CCAnimationFrame : public CCObject
{
public:
    CCAnimationFrame();

    virtual ~CCAnimationFrame();

    virtual CCObject *copyWithZone(CCZone *pZone);

    bool initWithSpriteFrame(CCSpriteFrame *spriteFrame, float delayUnits, CCDictionary *userInfo);

private:
    CCSpriteFrame *m_pSpriteFrame;

public:
    virtual CCSpriteFrame *getSpriteFrame(void) const { return m_pSpriteFrame; }

public:
    virtual void setSpriteFrame(CCSpriteFrame *var)
    {
        if (m_pSpriteFrame != var)
        {
            do
            {
                if (var)
                {
                    (var)->retain();
                }
            } while (0);
            do
            {
                if (m_pSpriteFrame)
                {
                    (m_pSpriteFrame)->release();
                }
            } while (0);
            m_pSpriteFrame = var;
        }
    }

protected:
    float m_fDelayUnits;

public:
    virtual float getDelayUnits(void) const { return m_fDelayUnits; }

public:
    virtual void setDelayUnits(float var) { m_fDelayUnits = var; }

private:
    CCDictionary *m_pUserInfo;

public:
    virtual CCDictionary *getUserInfo(void) const { return m_pUserInfo; }

public:
    virtual void setUserInfo(CCDictionary *var)
    {
        if (m_pUserInfo != var)
        {
            do
            {
                if (var)
                {
                    (var)->retain();
                }
            } while (0);
            do
            {
                if (m_pUserInfo)
                {
                    (m_pUserInfo)->release();
                }
            } while (0);
            m_pUserInfo = var;
        }
    }
};
// #line 96 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCAnimation.h"
class CCAnimation : public CCObject
{
public:
    CCAnimation();

    ~CCAnimation(void);

public:
    static CCAnimation *create(void);

    static CCAnimation *createWithSpriteFrames(CCArray *arrayOfSpriteFrameNames, float delay = 0.0f);

    static CCAnimation *create(CCArray *arrayOfAnimationFrameNames, float delayPerUnit, unsigned int loops);
    static CCAnimation *create(CCArray *arrayOfAnimationFrameNames, float delayPerUnit)
    {
        return CCAnimation::create(arrayOfAnimationFrameNames, delayPerUnit, 1);
    }

    void addSpriteFrame(CCSpriteFrame *pFrame);

    void addSpriteFrameWithFileName(const char *pszFileName);

    void addSpriteFrameWithTexture(CCTexture2D *pobTexture, const CCRect &rect);

    bool init();

    bool initWithSpriteFrames(CCArray *pFrames, float delay = 0.0f);

    bool initWithAnimationFrames(CCArray *arrayOfAnimationFrames, float delayPerUnit, unsigned int loops);

    virtual CCObject *copyWithZone(CCZone *pZone);

protected:
    float m_fTotalDelayUnits;

public:
    virtual float getTotalDelayUnits(void) const { return m_fTotalDelayUnits; }

protected:
    float m_fDelayPerUnit;

public:
    virtual float getDelayPerUnit(void) const { return m_fDelayPerUnit; }

public:
    virtual void setDelayPerUnit(float var) { m_fDelayPerUnit = var; }

protected:
    float m_fDuration;

public:
    virtual float getDuration(void);

private:
    CCArray *m_pFrames;

public:
    virtual CCArray *getFrames(void) const { return m_pFrames; }

public:
    virtual void setFrames(CCArray *var)
    {
        if (m_pFrames != var)
        {
            do
            {
                if (var)
                {
                    (var)->retain();
                }
            } while (0);
            do
            {
                if (m_pFrames)
                {
                    (m_pFrames)->release();
                }
            } while (0);
            m_pFrames = var;
        }
    }

protected:
    bool m_bRestoreOriginalFrame;

public:
    virtual bool getRestoreOriginalFrame(void) const { return m_bRestoreOriginalFrame; }

public:
    virtual void setRestoreOriginalFrame(bool var) { m_bRestoreOriginalFrame = var; }

protected:
    unsigned int m_uLoops;

public:
    virtual unsigned int getLoops(void) const { return m_uLoops; }

public:
    virtual void setLoops(unsigned int var) { m_uLoops = var; }
};
// #line 35 "cocos2d/cocos-headers/cocos2dx/actions/CCActionInterval.h"
#include <vector>
// #line 61 "cocos2d/cocos-headers/cocos2dx/actions/CCActionInterval.h"
class CCActionInterval : public CCFiniteTimeAction
{
public:
    inline float getElapsed(void) { return m_elapsed; }

    bool initWithDuration(float d);

    virtual bool isDone(void);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void step(float dt);
    virtual void startWithTarget(CCNode *pTarget);

    virtual CCActionInterval *reverse(void);

public:
    static CCActionInterval *create(float d);

public:
    void setAmplitudeRate(float amp);
    float getAmplitudeRate(void);

protected:
    float m_elapsed;
    bool m_bFirstTick;
};

class CCSequence : public CCActionInterval
{
public:
    ~CCSequence(void);

    bool initWithTwoActions(CCFiniteTimeAction *pActionOne, CCFiniteTimeAction *pActionTwo);

    virtual CCObject *copyWithZone(CCZone *pZone);

    virtual void startWithTarget(CCNode *pTarget);

    virtual void stop(void);

    virtual void update(float t);
    virtual CCActionInterval *reverse(void);

public:
    static CCSequence *create(CCFiniteTimeAction *pAction1, ...);

    static CCSequence *create(CCArray *arrayOfActions);

    static CCSequence *createWithVariableList(CCFiniteTimeAction *pAction1, va_list args);

    static CCSequence *createWithTwoActions(CCFiniteTimeAction *pActionOne, CCFiniteTimeAction *pActionTwo);

protected:
    CCFiniteTimeAction *m_pActions[2];
    float m_split;
    int m_last;
};

class CCRepeat : public CCActionInterval
{
public:
    ~CCRepeat(void);

    bool initWithAction(CCFiniteTimeAction *pAction, unsigned int times);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void startWithTarget(CCNode *pTarget);
    virtual void stop(void);
    virtual void update(float dt);
    virtual bool isDone(void);
    virtual CCActionInterval *reverse(void);

    inline void setInnerAction(CCFiniteTimeAction *pAction)
    {
        if (m_pInnerAction != pAction)
        {
            do
            {
                if (pAction)
                {
                    (pAction)->retain();
                }
            } while (0);
            do
            {
                if (m_pInnerAction)
                {
                    (m_pInnerAction)->release();
                }
            } while (0);
            m_pInnerAction = pAction;
        }
    }

    inline CCFiniteTimeAction *getInnerAction()
    {
        return m_pInnerAction;
    }

public:
    static CCRepeat *create(CCFiniteTimeAction *pAction, unsigned int times);

protected:
    unsigned int m_uTimes;
    unsigned int m_uTotal;
    float m_fNextDt;
    bool m_bActionInstant;

    CCFiniteTimeAction *m_pInnerAction;
};

class CCRepeatForever : public CCActionInterval
{
public:
    CCRepeatForever()
        : m_pInnerAction(NULL)
    {
    }

    virtual ~CCRepeatForever();

    bool initWithAction(CCActionInterval *pAction);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void startWithTarget(CCNode *pTarget);
    virtual void step(float dt);
    virtual bool isDone(void);
    virtual CCActionInterval *reverse(void);

    inline void setInnerAction(CCActionInterval *pAction)
    {
        if (m_pInnerAction != pAction)
        {
            do
            {
                if (m_pInnerAction)
                {
                    (m_pInnerAction)->release();
                }
            } while (0);
            m_pInnerAction = pAction;
            do
            {
                if (m_pInnerAction)
                {
                    (m_pInnerAction)->retain();
                }
            } while (0);
        }
    }

    inline CCActionInterval *getInnerAction()
    {
        return m_pInnerAction;
    }

public:
    static CCRepeatForever *create(CCActionInterval *pAction);

protected:
    CCActionInterval *m_pInnerAction;
};

class CCSpawn : public CCActionInterval
{
public:
    ~CCSpawn(void);

    bool initWithTwoActions(CCFiniteTimeAction *pAction1, CCFiniteTimeAction *pAction2);

    virtual CCObject *copyWithZone(CCZone *pZone);

    virtual void startWithTarget(CCNode *pTarget);

    virtual void stop(void);

    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

public:
    static CCSpawn *create(CCFiniteTimeAction *pAction1, ...);

    static CCSpawn *createWithVariableList(CCFiniteTimeAction *pAction1, va_list args);

    static CCSpawn *create(CCArray *arrayOfActions);

    static CCSpawn *createWithTwoActions(CCFiniteTimeAction *pAction1, CCFiniteTimeAction *pAction2);

protected:
    CCFiniteTimeAction *m_pOne;
    CCFiniteTimeAction *m_pTwo;
};

class CCRotateTo : public CCActionInterval
{
public:
    static CCRotateTo *create(float fDuration, float fDeltaAngle);

    bool initWithDuration(float fDuration, float fDeltaAngle);

    static CCRotateTo *create(float fDuration, float fDeltaAngleX, float fDeltaAngleY);
    virtual bool initWithDuration(float fDuration, float fDeltaAngleX, float fDeltaAngleY);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void startWithTarget(CCNode *pTarget);
    virtual void update(float time);

protected:
    float m_fDstAngleX;
    float m_fStartAngleX;
    float m_fDiffAngleX;

    float m_fDstAngleY;
    float m_fStartAngleY;
    float m_fDiffAngleY;
};

class CCRotateBy : public CCActionInterval
{
public:
    static CCRotateBy *create(float fDuration, float fDeltaAngle);

    bool initWithDuration(float fDuration, float fDeltaAngle);

    static CCRotateBy *create(float fDuration, float fDeltaAngleX, float fDeltaAngleY);
    bool initWithDuration(float fDuration, float fDeltaAngleX, float fDeltaAngleY);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void startWithTarget(CCNode *pTarget);
    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

protected:
    float m_fAngleX;
    float m_fStartAngleX;
    float m_fAngleY;
    float m_fStartAngleY;
};
// #line 394 "cocos2d/cocos-headers/cocos2dx/actions/CCActionInterval.h"
class CCMoveBy : public CCActionInterval
{
public:
    bool initWithDuration(float duration, const CCPoint &deltaPosition);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void startWithTarget(CCNode *pTarget);
    virtual CCActionInterval *reverse(void);
    virtual void update(float time);

public:
    static CCMoveBy *create(float duration, const CCPoint &deltaPosition);

protected:
    CCPoint m_positionDelta;
    CCPoint m_startPosition;
    CCPoint m_previousPosition;
};

class CCMoveTo : public CCMoveBy
{
public:
    bool initWithDuration(float duration, const CCPoint &position);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void startWithTarget(CCNode *pTarget);

public:
    static CCMoveTo *create(float duration, const CCPoint &position);

protected:
    CCPoint m_endPosition;
};

class CCSkewTo : public CCActionInterval
{
public:
    CCSkewTo();
    virtual bool initWithDuration(float t, float sx, float sy);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void startWithTarget(CCNode *pTarget);
    virtual void update(float time);

public:
    static CCSkewTo *create(float t, float sx, float sy);

protected:
    float m_fSkewX;
    float m_fSkewY;
    float m_fStartSkewX;
    float m_fStartSkewY;
    float m_fEndSkewX;
    float m_fEndSkewY;
    float m_fDeltaX;
    float m_fDeltaY;
};

class CCSkewBy : public CCSkewTo
{
public:
    virtual bool initWithDuration(float t, float sx, float sy);
    virtual void startWithTarget(CCNode *pTarget);
    virtual CCActionInterval *reverse(void);

public:
    static CCSkewBy *create(float t, float deltaSkewX, float deltaSkewY);
};

class CCJumpBy : public CCActionInterval
{
public:
    bool initWithDuration(float duration, const CCPoint &position, float height, unsigned int jumps);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void startWithTarget(CCNode *pTarget);
    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

public:
    static CCJumpBy *create(float duration, const CCPoint &position, float height, unsigned int jumps);

protected:
    CCPoint m_startPosition;
    CCPoint m_delta;
    float m_height;
    unsigned int m_nJumps;
    CCPoint m_previousPos;
};

class CCJumpTo : public CCJumpBy
{
public:
    virtual void startWithTarget(CCNode *pTarget);

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCJumpTo *create(float duration, const CCPoint &position, float height, int jumps);
};

typedef struct _ccBezierConfig
{

    CCPoint endPosition;

    CCPoint controlPoint_1;

    CCPoint controlPoint_2;
} ccBezierConfig;

class CCBezierBy : public CCActionInterval
{
public:
    bool initWithDuration(float t, const ccBezierConfig &c);

    virtual CCObject *copyWithZone(CCZone *pZone);

    virtual void startWithTarget(CCNode *pTarget);

    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

public:
    static CCBezierBy *create(float t, const ccBezierConfig &c);

protected:
    ccBezierConfig m_sConfig;
    CCPoint m_startPosition;
    CCPoint m_previousPosition;
};

class CCBezierTo : public CCBezierBy
{
public:
    virtual void startWithTarget(CCNode *pTarget);

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    // #line 608 "cocos2d/cocos-headers/cocos2dx/actions/CCActionInterval.h"
    static CCBezierTo *create(float t, const ccBezierConfig &c);

    bool initWithDuration(float t, const ccBezierConfig &c);

protected:
    ccBezierConfig m_sToConfig;
};

class CCScaleTo : public CCActionInterval
{
public:
    bool initWithDuration(float duration, float s);

    bool initWithDuration(float duration, float sx, float sy);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void startWithTarget(CCNode *pTarget);
    virtual void update(float time);

public:
    static CCScaleTo *create(float duration, float s);

    static CCScaleTo *create(float duration, float sx, float sy);

protected:
    float m_fScaleX;
    float m_fScaleY;
    float m_fStartScaleX;
    float m_fStartScaleY;
    float m_fEndScaleX;
    float m_fEndScaleY;
    float m_fDeltaX;
    float m_fDeltaY;
};

class CCScaleBy : public CCScaleTo
{
public:
    virtual void startWithTarget(CCNode *pTarget);
    virtual CCActionInterval *reverse(void);

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCScaleBy *create(float duration, float s);

    static CCScaleBy *create(float duration, float sx, float sy);
};

class CCBlink : public CCActionInterval
{
public:
    bool initWithDuration(float duration, unsigned int uBlinks);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

public:
    static CCBlink *create(float duration, unsigned int uBlinks);

    virtual void startWithTarget(CCNode *pTarget);
    virtual void stop();

protected:
    unsigned int m_nTimes;
    bool m_bOriginalState;
};

class CCFadeIn : public CCActionInterval
{
public:
    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCFadeIn *create(float d);
};

class CCFadeOut : public CCActionInterval
{
public:
    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCFadeOut *create(float d);
};

class CCFadeTo : public CCActionInterval
{
public:
    bool initWithDuration(float duration, GLubyte opacity);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void startWithTarget(CCNode *pTarget);
    virtual void update(float time);

public:
    static CCFadeTo *create(float duration, GLubyte opacity);

protected:
    GLubyte m_toOpacity;
    GLubyte m_fromOpacity;
};

class CCTintTo : public CCActionInterval
{
public:
    bool initWithDuration(float duration, GLubyte red, GLubyte green, GLubyte blue);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void startWithTarget(CCNode *pTarget);
    virtual void update(float time);

public:
    static CCTintTo *create(float duration, GLubyte red, GLubyte green, GLubyte blue);

protected:
    ccColor3B m_to;
    ccColor3B m_from;
};

class CCTintBy : public CCActionInterval
{
public:
    bool initWithDuration(float duration, GLshort deltaRed, GLshort deltaGreen, GLshort deltaBlue);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void startWithTarget(CCNode *pTarget);
    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

public:
    static CCTintBy *create(float duration, GLshort deltaRed, GLshort deltaGreen, GLshort deltaBlue);

protected:
    GLshort m_deltaR;
    GLshort m_deltaG;
    GLshort m_deltaB;

    GLshort m_fromR;
    GLshort m_fromG;
    GLshort m_fromB;
};

class CCDelayTime : public CCActionInterval
{
public:
    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCDelayTime *create(float d);
};
// #line 849 "cocos2d/cocos-headers/cocos2dx/actions/CCActionInterval.h"
class CCReverseTime : public CCActionInterval
{
public:
    ~CCReverseTime(void);

    CCReverseTime();

    bool initWithAction(CCFiniteTimeAction *pAction);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void startWithTarget(CCNode *pTarget);
    virtual void stop(void);
    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

public:
    static CCReverseTime *create(CCFiniteTimeAction *pAction);

protected:
    CCFiniteTimeAction *m_pOther;
};

class CCTexture2D;

class CCAnimate : public CCActionInterval
{
public:
    CCAnimate();

    ~CCAnimate();

    bool initWithAnimation(CCAnimation *pAnimation);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void startWithTarget(CCNode *pTarget);
    virtual void stop(void);
    virtual void update(float t);
    virtual CCActionInterval *reverse(void);

public:
    static CCAnimate *create(CCAnimation *pAnimation);

private:
    CCAnimation *m_pAnimation;

public:
    virtual CCAnimation *getAnimation(void) const { return m_pAnimation; }

public:
    virtual void setAnimation(CCAnimation *var)
    {
        if (m_pAnimation != var)
        {
            do
            {
                if (var)
                {
                    (var)->retain();
                }
            } while (0);
            do
            {
                if (m_pAnimation)
                {
                    (m_pAnimation)->release();
                }
            } while (0);
            m_pAnimation = var;
        }
    }

protected:
    std::vector<float> *m_pSplitTimes;
    int m_nNextFrame;
    CCSpriteFrame *m_pOrigFrame;
    unsigned int m_uExecutedLoops;
};

class CCTargetedAction : public CCActionInterval
{
public:
    CCTargetedAction();

    virtual ~CCTargetedAction();

    static CCTargetedAction *create(CCNode *pTarget, CCFiniteTimeAction *pAction);

    bool initWithTarget(CCNode *pTarget, CCFiniteTimeAction *pAction);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void startWithTarget(CCNode *pTarget);
    virtual void stop(void);
    virtual void update(float time);

private:
    CCNode *m_pForcedTarget;

public:
    virtual CCNode *getForcedTarget(void) const { return m_pForcedTarget; }

public:
    virtual void setForcedTarget(CCNode *var)
    {
        if (m_pForcedTarget != var)
        {
            do
            {
                if (var)
                {
                    (var)->retain();
                }
            } while (0);
            do
            {
                if (m_pForcedTarget)
                {
                    (m_pForcedTarget)->release();
                }
            } while (0);
            m_pForcedTarget = var;
        }
    };

private:
    CCFiniteTimeAction *m_pAction;
};
// #line 33 "cocos2d/cocos-headers/cocos2dx/actions/CCActionCamera.h"
class CCCamera;
// #line 44 "cocos2d/cocos-headers/cocos2dx/actions/CCActionCamera.h"
class CCActionCamera : public CCActionInterval
{
public:
    CCActionCamera()
        : m_fCenterXOrig(0), m_fCenterYOrig(0), m_fCenterZOrig(0), m_fEyeXOrig(0), m_fEyeYOrig(0), m_fEyeZOrig(0), m_fUpXOrig(0), m_fUpYOrig(0), m_fUpZOrig(0)
    {
    }

    virtual ~CCActionCamera() {}

    virtual void startWithTarget(CCNode *pTarget);
    virtual CCActionInterval *reverse();

protected:
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

class CCOrbitCamera : public CCActionCamera
{
public:
    CCOrbitCamera()
        : m_fRadius(0.0), m_fDeltaRadius(0.0), m_fAngleZ(0.0), m_fDeltaAngleZ(0.0), m_fAngleX(0.0), m_fDeltaAngleX(0.0), m_fRadZ(0.0), m_fRadDeltaZ(0.0), m_fRadX(0.0), m_fRadDeltaX(0.0)
    {
    }

    ~CCOrbitCamera() {}

    static CCOrbitCamera *create(float t, float radius, float deltaRadius, float angleZ, float deltaAngleZ, float angleX, float deltaAngleX);

    bool initWithDuration(float t, float radius, float deltaRadius, float angleZ, float deltaAngleZ, float angleX, float deltaAngleX);

    void sphericalRadius(float *r, float *zenith, float *azimuth);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void startWithTarget(CCNode *pTarget);
    virtual void update(float time);

protected:
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
// #line 37 "cocos2d/cocos-headers/cocos2dx/actions/CCActionManager.h"
class CCSet;

struct _hashElement;
// #line 57 "cocos2d/cocos-headers/cocos2dx/actions/CCActionManager.h"
class CCActionManager : public CCObject
{
public:
    CCActionManager(void);

    ~CCActionManager(void);
    // #line 77 "cocos2d/cocos-headers/cocos2dx/actions/CCActionManager.h"
    void addAction(CCAction *pAction, CCNode *pTarget, bool paused);

    void removeAllActions(void);

    void removeAllActionsFromTarget(CCObject *pTarget);

    void removeAction(CCAction *pAction);

    void removeActionByTag(unsigned int tag, CCObject *pTarget);

    CCAction *getActionByTag(unsigned int tag, CCObject *pTarget);

    unsigned int numberOfRunningActionsInTarget(CCObject *pTarget);

    void pauseTarget(CCObject *pTarget);

    void resumeTarget(CCObject *pTarget);

    CCSet *pauseAllRunningActions();

    void resumeTargets(CCSet *targetsToResume);

protected:
    void removeActionAtIndex(unsigned int uIndex, struct _hashElement *pElement);
    void deleteHashElement(struct _hashElement *pElement);
    void actionAllocWithHashElement(struct _hashElement *pElement);
    void update(float dt);

protected:
    struct _hashElement *m_pTargets;
    struct _hashElement *m_pCurrentTarget;
    bool m_bCurrentTargetSalvaged;
};
// #line 33 "cocos2d/cocos-headers/cocos2dx/actions/CCActionEase.h"
class CCObject;
class CCZone;
// #line 45 "cocos2d/cocos-headers/cocos2dx/actions/CCActionEase.h"
class CCActionEase : public CCActionInterval
{
public:
    virtual ~CCActionEase(void);

    bool initWithAction(CCActionInterval *pAction);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void startWithTarget(CCNode *pTarget);
    virtual void stop(void);
    virtual void update(float time);
    virtual CCActionInterval *reverse(void);
    virtual CCActionInterval *getInnerAction();

public:
    static CCActionEase *create(CCActionInterval *pAction);

protected:
    CCActionInterval *m_pInner;
};

class CCEaseRateAction : public CCActionEase
{
public:
    virtual ~CCEaseRateAction(void);

    inline void setRate(float rate) { m_fRate = rate; }

    inline float getRate(void) { return m_fRate; }

    bool initWithAction(CCActionInterval *pAction, float fRate);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual CCActionInterval *reverse(void);

public:
    static CCEaseRateAction *create(CCActionInterval *pAction, float fRate);

protected:
    float m_fRate;
};

class CCEaseIn : public CCEaseRateAction
{
public:
    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCEaseIn *create(CCActionInterval *pAction, float fRate);
};

class CCEaseOut : public CCEaseRateAction
{
public:
    virtual void update(float time);
    virtual CCActionInterval *reverse();

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCEaseOut *create(CCActionInterval *pAction, float fRate);
};

class CCEaseInOut : public CCEaseRateAction
{
public:
    virtual void update(float time);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual CCActionInterval *reverse(void);

public:
    static CCEaseInOut *create(CCActionInterval *pAction, float fRate);
};

class CCEaseExponentialIn : public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCEaseExponentialIn *create(CCActionInterval *pAction);
};

class CCEaseExponentialOut : public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCEaseExponentialOut *create(CCActionInterval *pAction);
};

class CCEaseExponentialInOut : public CCActionEase
{
public:
    virtual void update(float time);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual CCActionInterval *reverse();

public:
    static CCEaseExponentialInOut *create(CCActionInterval *pAction);
};

class CCEaseSineIn : public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCEaseSineIn *create(CCActionInterval *pAction);
};

class CCEaseSineOut : public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCEaseSineOut *create(CCActionInterval *pAction);
};

class CCEaseSineInOut : public CCActionEase
{
public:
    virtual void update(float time);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual CCActionInterval *reverse();

public:
    static CCEaseSineInOut *create(CCActionInterval *pAction);
};

class CCEaseElastic : public CCActionEase
{
public:
    inline float getPeriod(void) { return m_fPeriod; }

    inline void setPeriod(float fPeriod) { m_fPeriod = fPeriod; }

    bool initWithAction(CCActionInterval *pAction, float fPeriod = 0.3f);

    virtual CCActionInterval *reverse(void);

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCEaseElastic *create(CCActionInterval *pAction, float fPeriod);
    static CCEaseElastic *create(CCActionInterval *pAction);

protected:
    float m_fPeriod;
};
// #line 336 "cocos2d/cocos-headers/cocos2dx/actions/CCActionEase.h"
class CCEaseElasticIn : public CCEaseElastic
{
public:
    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCEaseElasticIn *create(CCActionInterval *pAction, float fPeriod);
    static CCEaseElasticIn *create(CCActionInterval *pAction);
};
// #line 360 "cocos2d/cocos-headers/cocos2dx/actions/CCActionEase.h"
class CCEaseElasticOut : public CCEaseElastic
{
public:
    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCEaseElasticOut *create(CCActionInterval *pAction, float fPeriod);
    static CCEaseElasticOut *create(CCActionInterval *pAction);
};
// #line 384 "cocos2d/cocos-headers/cocos2dx/actions/CCActionEase.h"
class CCEaseElasticInOut : public CCEaseElastic
{
public:
    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCEaseElasticInOut *create(CCActionInterval *pAction, float fPeriod);
    static CCEaseElasticInOut *create(CCActionInterval *pAction);
};

class CCEaseBounce : public CCActionEase
{
public:
    float bounceTime(float time);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual CCActionInterval *reverse();

public:
    static CCEaseBounce *create(CCActionInterval *pAction);
};
// #line 430 "cocos2d/cocos-headers/cocos2dx/actions/CCActionEase.h"
class CCEaseBounceIn : public CCEaseBounce
{
public:
    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCEaseBounceIn *create(CCActionInterval *pAction);
};
// #line 453 "cocos2d/cocos-headers/cocos2dx/actions/CCActionEase.h"
class CCEaseBounceOut : public CCEaseBounce
{
public:
    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCEaseBounceOut *create(CCActionInterval *pAction);
};
// #line 476 "cocos2d/cocos-headers/cocos2dx/actions/CCActionEase.h"
class CCEaseBounceInOut : public CCEaseBounce
{
public:
    virtual void update(float time);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual CCActionInterval *reverse();

public:
    static CCEaseBounceInOut *create(CCActionInterval *pAction);
};
// #line 499 "cocos2d/cocos-headers/cocos2dx/actions/CCActionEase.h"
class CCEaseBackIn : public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCEaseBackIn *create(CCActionInterval *pAction);
};
// #line 522 "cocos2d/cocos-headers/cocos2dx/actions/CCActionEase.h"
class CCEaseBackOut : public CCActionEase
{
public:
    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCEaseBackOut *create(CCActionInterval *pAction);
};
// #line 545 "cocos2d/cocos-headers/cocos2dx/actions/CCActionEase.h"
class CCEaseBackInOut : public CCActionEase
{
public:
    virtual void update(float time);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual CCActionInterval *reverse();

public:
    static CCEaseBackInOut *create(CCActionInterval *pAction);
};
// #line 30 "cocos2d/cocos-headers/cocos2dx/actions/CCActionInstant.h"
#include <string>
// #line 30 "cocos2d/cocos-headers/cocos2dx/include/ccTypeInfo.h"
#include <typeinfo>
#include <ctype.h>
#include <string.h>

class TypeInfo
{
public:
    virtual long getClassTypeInfo() = 0;
};

static inline unsigned int getHashCodeByString(const char *key)
{
    unsigned int len = strlen(key);
    const char *end = key + len;
    unsigned int hash;

    for (hash = 0; key < end; key++)
    {
        hash *= 16777619;
        hash ^= (unsigned int)(unsigned char)toupper(*key);
    }
    return (hash);
}
// #line 45 "cocos2d/cocos-headers/cocos2dx/actions/CCActionInstant.h"
class CCActionInstant : public CCFiniteTimeAction
{
public:
    CCActionInstant();

    virtual ~CCActionInstant() {}

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual bool isDone(void);
    virtual void step(float dt);
    virtual void update(float time);

    virtual CCFiniteTimeAction *reverse(void);
};

class CCShow : public CCActionInstant
{
public:
    CCShow() {}

    virtual ~CCShow() {}

    virtual void update(float time);
    virtual CCFiniteTimeAction *reverse(void);

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCShow *create();
};

class CCHide : public CCActionInstant
{
public:
    CCHide() {}

    virtual ~CCHide() {}

    virtual void update(float time);
    virtual CCFiniteTimeAction *reverse(void);

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCHide *create();
};

class CCToggleVisibility : public CCActionInstant
{
public:
    CCToggleVisibility() {}

    virtual ~CCToggleVisibility() {}

    virtual void update(float time);

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCToggleVisibility *create();
};

class CCRemoveSelf : public CCActionInstant
{
public:
    CCRemoveSelf() {}
    virtual ~CCRemoveSelf() {}

    virtual void update(float time);
    virtual CCFiniteTimeAction *reverse(void);
    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCRemoveSelf *create(bool isNeedCleanUp = true);

    bool init(bool isNeedCleanUp);

protected:
    bool m_bIsNeedCleanUp;
};

class CCFlipX : public CCActionInstant
{
public:
    CCFlipX()
        : m_bFlipX(false)
    {
    }

    virtual ~CCFlipX() {}

    static CCFlipX *create(bool x);

    bool initWithFlipX(bool x);

    virtual void update(float time);
    virtual CCFiniteTimeAction *reverse(void);

    virtual CCObject *copyWithZone(CCZone *pZone);

protected:
    bool m_bFlipX;
};

class CCFlipY : public CCActionInstant
{
public:
    CCFlipY()
        : m_bFlipY(false)
    {
    }

    virtual ~CCFlipY() {}

    static CCFlipY *create(bool y);

    bool initWithFlipY(bool y);

    virtual void update(float time);
    virtual CCFiniteTimeAction *reverse(void);

    virtual CCObject *copyWithZone(CCZone *pZone);

protected:
    bool m_bFlipY;
};

class CCPlace : public CCActionInstant
{
public:
    CCPlace() {}

    virtual ~CCPlace() {}

    static CCPlace *create(const CCPoint &pos);

    bool initWithPosition(const CCPoint &pos);

    virtual void update(float time);

    virtual CCObject *copyWithZone(CCZone *pZone);

protected:
    CCPoint m_tPosition;
};

class CCCallFunc : public CCActionInstant
{
public:
    CCCallFunc()
        : m_pSelectorTarget(NULL), m_nScriptHandler(0), m_pCallFunc(NULL)
    {
    }

    virtual ~CCCallFunc();

    static CCCallFunc *create(CCObject *pSelectorTarget, SEL_CallFunc selector);

    static CCCallFunc *create(int nHandler);

    virtual bool initWithTarget(CCObject *pSelectorTarget);

    virtual void execute();

    virtual void update(float time);

    CCObject *copyWithZone(CCZone *pZone);

    inline CCObject *getTargetCallback()
    {
        return m_pSelectorTarget;
    }

    inline void setTargetCallback(CCObject *pSel)
    {
        if (pSel != m_pSelectorTarget)
        {
            do
            {
                if (pSel)
                {
                    (pSel)->retain();
                }
            } while (0);
            do
            {
                if (m_pSelectorTarget)
                {
                    (m_pSelectorTarget)->release();
                }
            } while (0);
            m_pSelectorTarget = pSel;
        }
    }

    inline int getScriptHandler() { return m_nScriptHandler; };

protected:
    CCObject *m_pSelectorTarget;

    int m_nScriptHandler;

    union
    {
        SEL_CallFunc m_pCallFunc;
        SEL_CallFuncN m_pCallFuncN;
        SEL_CallFuncND m_pCallFuncND;
        SEL_CallFuncO m_pCallFuncO;
    };
};

class CCCallFuncN : public CCCallFunc, public TypeInfo
{
public:
    CCCallFuncN() {}

    virtual ~CCCallFuncN() {}

    virtual long getClassTypeInfo()
    {
        static const long id = getHashCodeByString(typeid(CCCallFunc).name());
        return id;
    }

    static CCCallFuncN *create(CCObject *pSelectorTarget, SEL_CallFuncN selector);

    static CCCallFuncN *create(int nHandler);

    virtual bool initWithTarget(CCObject *pSelectorTarget, SEL_CallFuncN selector);

    virtual CCObject *copyWithZone(CCZone *pZone);

    virtual void execute();
};
// #line 437 "cocos2d/cocos-headers/cocos2dx/actions/CCActionInstant.h"
class CCCallFuncND : public CCCallFuncN
{
public:
    virtual long getClassTypeInfo()
    {
        static const long id = getHashCodeByString(typeid(CCCallFunc).name());
        return id;
    }

    static CCCallFuncND *create(CCObject *pSelectorTarget, SEL_CallFuncND selector, void *d);

    virtual bool initWithTarget(CCObject *pSelectorTarget, SEL_CallFuncND selector, void *d);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void execute();

protected:
    void *m_pData;
};
// #line 471 "cocos2d/cocos-headers/cocos2dx/actions/CCActionInstant.h"
class CCCallFuncO : public CCCallFunc, public TypeInfo
{
public:
    CCCallFuncO();
    virtual ~CCCallFuncO();

    virtual long getClassTypeInfo()
    {
        static const long id = getHashCodeByString(typeid(CCCallFunc).name());
        return id;
    }

    static CCCallFuncO *create(CCObject *pSelectorTarget, SEL_CallFuncO selector, CCObject *pObject);

    virtual bool initWithTarget(CCObject *pSelectorTarget, SEL_CallFuncO selector, CCObject *pObject);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void execute();

    inline CCObject *getObject()
    {
        return m_pObject;
    }

    inline void setObject(CCObject *pObj)
    {
        if (pObj != m_pObject)
        {
            do
            {
                if (m_pObject)
                {
                    (m_pObject)->release();
                }
            } while (0);
            m_pObject = pObj;
            do
            {
                if (m_pObject)
                {
                    (m_pObject)->retain();
                }
            } while (0);
        }
    }

protected:
    CCObject *m_pObject;
};
// #line 33 "cocos2d/cocos-headers/cocos2dx/actions/CCActionGrid.h"
class CCGridBase;
// #line 41 "cocos2d/cocos-headers/cocos2dx/actions/CCActionGrid.h"
class CCGridAction : public CCActionInterval
{
public:
    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void startWithTarget(CCNode *pTarget);
    virtual CCActionInterval *reverse(void);

    virtual bool initWithDuration(float duration, const CCSize &gridSize);

    virtual CCGridBase *getGrid(void);

public:
    // #line 65 "cocos2d/cocos-headers/cocos2dx/actions/CCActionGrid.h"
    static CCGridAction *create(float duration, const CCSize &gridSize);

protected:
    CCSize m_sGridSize;
};

class CCGrid3DAction : public CCGridAction
{
public:
    virtual CCGridBase *getGrid(void);

    ccVertex3F vertex(const CCPoint &position);

    ccVertex3F originalVertex(const CCPoint &position);

    void setVertex(const CCPoint &position, const ccVertex3F &vertex);

public:
    static CCGrid3DAction *create(float duration, const CCSize &gridSize);
};

class CCTiledGrid3DAction : public CCGridAction
{
public:
    ccQuad3 tile(const CCPoint &position);

    ccQuad3 originalTile(const CCPoint &position);

    void setTile(const CCPoint &position, const ccQuad3 &coords);

    virtual CCGridBase *getGrid(void);

public:
    static CCTiledGrid3DAction *create(float duration, const CCSize &gridSize);
};

class CCAccelDeccelAmplitude : public CCActionInterval
{
public:
    virtual ~CCAccelDeccelAmplitude(void);

    bool initWithAction(CCAction *pAction, float duration);

    virtual void startWithTarget(CCNode *pTarget);
    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

    inline float getRate(void) { return m_fRate; }

    inline void setRate(float fRate) { m_fRate = fRate; }

public:
    static CCAccelDeccelAmplitude *create(CCAction *pAction, float duration);

protected:
    float m_fRate;
    CCActionInterval *m_pOther;
};

class CCAccelAmplitude : public CCActionInterval
{
public:
    ~CCAccelAmplitude(void);

    bool initWithAction(CCAction *pAction, float duration);

    inline float getRate(void) { return m_fRate; }

    inline void setRate(float fRate) { m_fRate = fRate; }

    virtual void startWithTarget(CCNode *pTarget);
    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

public:
    static CCAccelAmplitude *create(CCAction *pAction, float duration);

protected:
    float m_fRate;
    CCActionInterval *m_pOther;
};

class CCDeccelAmplitude : public CCActionInterval
{
public:
    ~CCDeccelAmplitude(void);

    bool initWithAction(CCAction *pAction, float duration);

    inline float getRate(void) { return m_fRate; }

    inline void setRate(float fRate) { m_fRate = fRate; }

    virtual void startWithTarget(CCNode *pTarget);
    virtual void update(float time);
    virtual CCActionInterval *reverse(void);

public:
    static CCDeccelAmplitude *create(CCAction *pAction, float duration);

protected:
    float m_fRate;
    CCActionInterval *m_pOther;
};

class CCStopGrid : public CCActionInstant
{
public:
    virtual void startWithTarget(CCNode *pTarget);

public:
    static CCStopGrid *create(void);
};

class CCReuseGrid : public CCActionInstant
{
public:
    bool initWithTimes(int times);

    virtual void startWithTarget(CCNode *pTarget);

public:
    static CCReuseGrid *create(int times);

protected:
    int m_nTimes;
};
// #line 40 "cocos2d/cocos-headers/cocos2dx/actions/CCActionGrid3D.h"
class CCWaves3D : public CCGrid3DAction
{
public:
    inline float getAmplitude(void) { return m_fAmplitude; }
    inline void setAmplitude(float fAmplitude) { m_fAmplitude = fAmplitude; }

    inline float getAmplitudeRate(void) { return m_fAmplitudeRate; }
    inline void setAmplitudeRate(float fAmplitudeRate) { m_fAmplitudeRate = fAmplitudeRate; }

    bool initWithDuration(float duration, const CCSize &gridSize, unsigned int waves, float amplitude);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void update(float time);

public:
    static CCWaves3D *create(float duration, const CCSize &gridSize, unsigned int waves, float amplitude);

protected:
    unsigned int m_nWaves;
    float m_fAmplitude;
    float m_fAmplitudeRate;
};

class CCFlipX3D : public CCGrid3DAction
{
public:
    virtual bool initWithDuration(float duration);
    virtual bool initWithSize(const CCSize &gridSize, float duration);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void update(float time);

public:
    static CCFlipX3D *create(float duration);
};

class CCFlipY3D : public CCFlipX3D
{
public:
    virtual void update(float time);

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCFlipY3D *create(float duration);
};

class CCLens3D : public CCGrid3DAction
{
public:
    inline float getLensEffect(void) { return m_fLensEffect; }

    inline void setLensEffect(float fLensEffect) { m_fLensEffect = fLensEffect; }

    inline void setConcave(bool bConcave) { m_bConcave = bConcave; }

    inline const CCPoint &getPosition(void) { return m_position; }
    void setPosition(const CCPoint &position);

    bool initWithDuration(float duration, const CCSize &gridSize, const CCPoint &position, float radius);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void update(float time);

public:
    static CCLens3D *create(float duration, const CCSize &gridSize, const CCPoint &position, float radius);

protected:
    CCPoint m_position;
    float m_fRadius;

    float m_fLensEffect;

    bool m_bConcave;

    bool m_bDirty;
};

class CCRipple3D : public CCGrid3DAction
{
public:
    inline const CCPoint &getPosition(void) { return m_position; }

    void setPosition(const CCPoint &position);

    inline float getAmplitude(void) { return m_fAmplitude; }
    inline void setAmplitude(float fAmplitude) { m_fAmplitude = fAmplitude; }

    inline float getAmplitudeRate(void) { return m_fAmplitudeRate; }
    inline void setAmplitudeRate(float fAmplitudeRate) { m_fAmplitudeRate = fAmplitudeRate; }

    bool initWithDuration(float duration, const CCSize &gridSize, const CCPoint &position, float radius, unsigned int waves, float amplitude);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void update(float time);

public:
    static CCRipple3D *create(float duration, const CCSize &gridSize, const CCPoint &position, float radius, unsigned int waves, float amplitude);

protected:
    CCPoint m_position;
    float m_fRadius;
    unsigned int m_nWaves;
    float m_fAmplitude;
    float m_fAmplitudeRate;
};

class CCShaky3D : public CCGrid3DAction
{
public:
    bool initWithDuration(float duration, const CCSize &gridSize, int range, bool shakeZ);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void update(float time);

public:
    static CCShaky3D *create(float duration, const CCSize &gridSize, int range, bool shakeZ);

protected:
    int m_nRandrange;
    bool m_bShakeZ;
};

class CCLiquid : public CCGrid3DAction
{
public:
    inline float getAmplitude(void) { return m_fAmplitude; }
    inline void setAmplitude(float fAmplitude) { m_fAmplitude = fAmplitude; }

    inline float getAmplitudeRate(void) { return m_fAmplitudeRate; }
    inline void setAmplitudeRate(float fAmplitudeRate) { m_fAmplitudeRate = fAmplitudeRate; }

    bool initWithDuration(float duration, const CCSize &gridSize, unsigned int waves, float amplitude);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void update(float time);

public:
    static CCLiquid *create(float duration, const CCSize &gridSize, unsigned int waves, float amplitude);

protected:
    unsigned int m_nWaves;
    float m_fAmplitude;
    float m_fAmplitudeRate;
};

class CCWaves : public CCGrid3DAction
{
public:
    inline float getAmplitude(void) { return m_fAmplitude; }
    inline void setAmplitude(float fAmplitude) { m_fAmplitude = fAmplitude; }

    inline float getAmplitudeRate(void) { return m_fAmplitudeRate; }
    inline void setAmplitudeRate(float fAmplitudeRate) { m_fAmplitudeRate = fAmplitudeRate; }

    bool initWithDuration(float duration, const CCSize &gridSize, unsigned int waves, float amplitude, bool horizontal, bool vertical);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void update(float time);

public:
    static CCWaves *create(float duration, const CCSize &gridSize, unsigned int waves, float amplitude, bool horizontal, bool vertical);

protected:
    unsigned int m_nWaves;
    float m_fAmplitude;
    float m_fAmplitudeRate;
    bool m_bVertical;
    bool m_bHorizontal;
};

class CCTwirl : public CCGrid3DAction
{
public:
    inline const CCPoint &getPosition(void) { return m_position; }

    void setPosition(const CCPoint &position);

    inline float getAmplitude(void) { return m_fAmplitude; }
    inline void setAmplitude(float fAmplitude) { m_fAmplitude = fAmplitude; }

    inline float getAmplitudeRate(void) { return m_fAmplitudeRate; }
    inline void setAmplitudeRate(float fAmplitudeRate) { m_fAmplitudeRate = fAmplitudeRate; }

    bool initWithDuration(float duration, const CCSize &gridSize, CCPoint position, unsigned int twirls, float amplitude);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void update(float time);

public:
    static CCTwirl *create(float duration, const CCSize &gridSize, CCPoint position, unsigned int twirls, float amplitude);

protected:
    CCPoint m_position;
    unsigned int m_nTwirls;
    float m_fAmplitude;
    float m_fAmplitudeRate;
};
// #line 46 "cocos2d/cocos-headers/cocos2dx/actions/CCActionPageTurn3D.h"
class CCPageTurn3D : public CCGrid3DAction
{
public:
    virtual void update(float time);

public:
    static CCPageTurn3D *create(float duration, const CCSize &gridSize);
};
// #line 41 "cocos2d/cocos-headers/cocos2dx/actions/CCActionProgressTimer.h"
class CCProgressTo : public CCActionInterval
{
public:
    bool initWithDuration(float duration, float fPercent);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void startWithTarget(CCNode *pTarget);
    virtual void update(float time);

public:
    static CCProgressTo *create(float duration, float fPercent);

protected:
    float m_fTo;
    float m_fFrom;
};

class CCProgressFromTo : public CCActionInterval
{
public:
    bool initWithDuration(float duration, float fFromPercentage, float fToPercentage);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual CCActionInterval *reverse(void);
    virtual void startWithTarget(CCNode *pTarget);
    virtual void update(float time);

public:
    static CCProgressFromTo *create(float duration, float fFromPercentage, float fToPercentage);

protected:
    float m_fTo;
    float m_fFrom;
};
// #line 38 "cocos2d/cocos-headers/cocos2dx/actions/CCActionTiledGrid.h"
class CCShakyTiles3D : public CCTiledGrid3DAction
{
public:
    virtual bool initWithDuration(float duration, const CCSize &gridSize, int nRange, bool bShakeZ);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void update(float time);

public:
    static CCShakyTiles3D *create(float duration, const CCSize &gridSize, int nRange, bool bShakeZ);

protected:
    int m_nRandrange;
    bool m_bShakeZ;
};

class CCShatteredTiles3D : public CCTiledGrid3DAction
{
public:
    virtual bool initWithDuration(float duration, const CCSize &gridSize, int nRange, bool bShatterZ);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void update(float time);

public:
    static CCShatteredTiles3D *create(float duration, const CCSize &gridSize, int nRange, bool bShatterZ);

protected:
    int m_nRandrange;
    bool m_bOnce;
    bool m_bShatterZ;
};

struct Tile;

class CCShuffleTiles : public CCTiledGrid3DAction
{
public:
    ~CCShuffleTiles(void);

    virtual bool initWithDuration(float duration, const CCSize &gridSize, unsigned int seed);
    void shuffle(unsigned int *pArray, unsigned int nLen);
    CCSize getDelta(const CCSize &pos);
    void placeTile(const CCPoint &pos, Tile *t);

    virtual void startWithTarget(CCNode *pTarget);
    virtual void update(float time);

    virtual CCObject *copyWithZone(CCZone *pZone);

public:
    static CCShuffleTiles *create(float duration, const CCSize &gridSize, unsigned int seed);

protected:
    unsigned int m_nSeed;
    unsigned int m_nTilesCount;
    unsigned int *m_pTilesOrder;
    Tile *m_pTiles;
};

class CCFadeOutTRTiles : public CCTiledGrid3DAction
{
public:
    virtual float testFunc(const CCSize &pos, float time);
    void turnOnTile(const CCPoint &pos);
    void turnOffTile(const CCPoint &pos);
    virtual void transformTile(const CCPoint &pos, float distance);
    virtual void update(float time);

public:
    static CCFadeOutTRTiles *create(float duration, const CCSize &gridSize);
};

class CCFadeOutBLTiles : public CCFadeOutTRTiles
{
public:
    virtual float testFunc(const CCSize &pos, float time);

public:
    static CCFadeOutBLTiles *create(float duration, const CCSize &gridSize);
};

class CCFadeOutUpTiles : public CCFadeOutTRTiles
{
public:
    virtual float testFunc(const CCSize &pos, float time);
    virtual void transformTile(const CCPoint &pos, float distance);

public:
    static CCFadeOutUpTiles *create(float duration, const CCSize &gridSize);
};

class CCFadeOutDownTiles : public CCFadeOutUpTiles
{
public:
    virtual float testFunc(const CCSize &pos, float time);

public:
    static CCFadeOutDownTiles *create(float duration, const CCSize &gridSize);
};

class CCTurnOffTiles : public CCTiledGrid3DAction
{
public:
    ~CCTurnOffTiles(void);

    virtual bool initWithDuration(float duration, const CCSize &gridSize, unsigned int seed);
    void shuffle(unsigned int *pArray, unsigned int nLen);
    void turnOnTile(const CCPoint &pos);
    void turnOffTile(const CCPoint &pos);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void startWithTarget(CCNode *pTarget);
    virtual void update(float time);

public:
    static CCTurnOffTiles *create(float duration, const CCSize &gridSize);

    static CCTurnOffTiles *create(float duration, const CCSize &gridSize, unsigned int seed);

protected:
    unsigned int m_nSeed;
    unsigned int m_nTilesCount;
    unsigned int *m_pTilesOrder;
};

class CCWavesTiles3D : public CCTiledGrid3DAction
{
public:
    inline float getAmplitude(void) { return m_fAmplitude; }
    inline void setAmplitude(float fAmplitude) { m_fAmplitude = fAmplitude; }

    inline float getAmplitudeRate(void) { return m_fAmplitudeRate; }
    inline void setAmplitudeRate(float fAmplitudeRate) { m_fAmplitudeRate = fAmplitudeRate; }

    virtual bool initWithDuration(float duration, const CCSize &gridSize, unsigned int waves, float amplitude);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void update(float time);

public:
    static CCWavesTiles3D *create(float duration, const CCSize &gridSize, unsigned int waves, float amplitude);

protected:
    unsigned int m_nWaves;
    float m_fAmplitude;
    float m_fAmplitudeRate;
};

class CCJumpTiles3D : public CCTiledGrid3DAction
{
public:
    inline float getAmplitude(void) { return m_fAmplitude; }
    inline void setAmplitude(float fAmplitude) { m_fAmplitude = fAmplitude; }

    inline float getAmplitudeRate(void) { return m_fAmplitudeRate; }
    inline void setAmplitudeRate(float fAmplitudeRate) { m_fAmplitudeRate = fAmplitudeRate; }

    bool initWithDuration(float duration, const CCSize &gridSize, unsigned int numberOfJumps, float amplitude);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void update(float time);

public:
    static CCJumpTiles3D *create(float duration, const CCSize &gridSize, unsigned int numberOfJumps, float amplitude);

protected:
    unsigned int m_nJumps;
    float m_fAmplitude;
    float m_fAmplitudeRate;
};

class CCSplitRows : public CCTiledGrid3DAction
{
public:
    virtual bool initWithDuration(float duration, unsigned int nRows);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void update(float time);
    virtual void startWithTarget(CCNode *pTarget);

public:
    static CCSplitRows *create(float duration, unsigned int nRows);

protected:
    unsigned int m_nRows;
    CCSize m_winSize;
};

class CCSplitCols : public CCTiledGrid3DAction
{
public:
    virtual bool initWithDuration(float duration, unsigned int nCols);

    virtual CCObject *copyWithZone(CCZone *pZone);
    virtual void update(float time);
    virtual void startWithTarget(CCNode *pTarget);

public:
    static CCSplitCols *create(float duration, unsigned int nCols);

protected:
    unsigned int m_nCols;
    CCSize m_winSize;
};
// #line 37 "cocos2d/cocos-headers/cocos2dx/actions/CCActionTween.h"
class CCActionTweenDelegate
{
public:
    virtual ~CCActionTweenDelegate() {}
    virtual void updateTweenAction(float value, const char *key) = 0;
};
// #line 66 "cocos2d/cocos-headers/cocos2dx/actions/CCActionTween.h"
class CCActionTween : public CCActionInterval
{
public:
    static CCActionTween *create(float aDuration, const char *key, float from, float to);

    bool initWithDuration(float aDuration, const char *key, float from, float to);

    void startWithTarget(CCNode *pTarget);
    void update(float dt);
    CCActionInterval *reverse();

    std::string m_strKey;
    float m_fFrom, m_fTo;
    float m_fDelta;
};
// #line 40 "cocos2d/cocos-headers/cocos2dx/actions/CCActionCatmullRom.h"
#include <vector>

;
// #line 58 "cocos2d/cocos-headers/cocos2dx/actions/CCActionCatmullRom.h"
class CCPointArray : public CCObject
{
public:
    static CCPointArray *create(unsigned int capacity);

    virtual ~CCPointArray();

    CCPointArray();

    bool initWithCapacity(unsigned int capacity);

    void addControlPoint(CCPoint controlPoint);

    void insertControlPoint(CCPoint &controlPoint, unsigned int index);

    void replaceControlPoint(CCPoint &controlPoint, unsigned int index);

    CCPoint getControlPointAtIndex(unsigned int index);

    void removeControlPointAtIndex(unsigned int index);

    unsigned int count();

    CCPointArray *reverse();

    void reverseInline();

    virtual CCObject *copyWithZone(CCZone *zone);

    const std::vector<CCPoint *> *getControlPoints();

    void setControlPoints(std::vector<CCPoint *> *controlPoints);

private:
    std::vector<CCPoint *> *m_pControlPoints;
};

class CCCardinalSplineTo : public CCActionInterval
{
public:
    // #line 129 "cocos2d/cocos-headers/cocos2dx/actions/CCActionCatmullRom.h"
    static CCCardinalSplineTo *create(float duration, CCPointArray *points, float tension);

    virtual ~CCCardinalSplineTo();

    CCCardinalSplineTo();

    bool initWithDuration(float duration, CCPointArray *points, float tension);

    virtual CCCardinalSplineTo *copyWithZone(CCZone *pZone);

    virtual void startWithTarget(CCNode *pTarget);

    virtual void update(float time);
    virtual CCActionInterval *reverse();

    virtual void updatePosition(CCPoint &newPos);

    inline CCPointArray *getPoints() { return m_pPoints; }

    inline void setPoints(CCPointArray *points)
    {
        do
        {
            if (points)
            {
                (points)->retain();
            }
        } while (0);
        do
        {
            if (m_pPoints)
            {
                (m_pPoints)->release();
            }
        } while (0);
        m_pPoints = points;
    }

protected:
    CCPointArray *m_pPoints;
    float m_fDeltaT;
    float m_fTension;
    CCPoint m_previousPosition;
    CCPoint m_accumulatedDiff;
};

class CCCardinalSplineBy : public CCCardinalSplineTo
{
public:
    // #line 200 "cocos2d/cocos-headers/cocos2dx/actions/CCActionCatmullRom.h"
    static CCCardinalSplineBy *create(float duration, CCPointArray *points, float tension);

    CCCardinalSplineBy();

    virtual void startWithTarget(CCNode *pTarget);
    virtual CCActionInterval *reverse();

    virtual void updatePosition(CCPoint &newPos);

protected:
    CCPoint m_startPosition;
};

class CCCatmullRomTo : public CCCardinalSplineTo
{
public:
    // #line 234 "cocos2d/cocos-headers/cocos2dx/actions/CCActionCatmullRom.h"
    static CCCatmullRomTo *create(float dt, CCPointArray *points);

    bool initWithDuration(float dt, CCPointArray *points);
};

class CCCatmullRomBy : public CCCardinalSplineBy
{
public:
    // #line 258 "cocos2d/cocos-headers/cocos2dx/actions/CCActionCatmullRom.h"
    static CCCatmullRomBy *create(float dt, CCPointArray *points);

    bool initWithDuration(float dt, CCPointArray *points);
};

extern CCPoint ccCardinalSplineAt(CCPoint &p0, CCPoint &p1, CCPoint &p2, CCPoint &p3, float tension, float t);

;
// #line 41 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCAtlasNode.h"
class CCTextureAtlas;
// #line 51 "cocos2d/cocos-headers/cocos2dx/base_nodes/CCAtlasNode.h"
class CCAtlasNode : public CCNodeRGBA, public CCTextureProtocol
{
protected:
    unsigned int m_uItemsPerRow;

    unsigned int m_uItemsPerColumn;

    unsigned int m_uItemWidth;

    unsigned int m_uItemHeight;

    ccColor3B m_tColorUnmodified;

protected:
    CCTextureAtlas *m_pTextureAtlas;

public:
    virtual CCTextureAtlas *getTextureAtlas(void);

public:
    virtual void setTextureAtlas(CCTextureAtlas *var);
    ;

    bool m_bIsOpacityModifyRGB;

protected:
    ccBlendFunc m_tBlendFunc;

public:
    virtual ccBlendFunc getBlendFunc(void);

public:
    virtual void setBlendFunc(ccBlendFunc var);
    ;

protected:
    unsigned int m_uQuadsToDraw;

public:
    virtual unsigned int getQuadsToDraw(void);

public:
    virtual void setQuadsToDraw(unsigned int var);
    ;

    GLint m_nUniformColor;

    bool m_bIgnoreContentScaleFactor;

public:
    CCAtlasNode();

    virtual ~CCAtlasNode();

    static CCAtlasNode *create(const char *tile, unsigned int tileWidth, unsigned int tileHeight,
                               unsigned int itemsToRender);

    bool initWithTileFile(const char *tile, unsigned int tileWidth, unsigned int tileHeight, unsigned int itemsToRender);

    bool initWithTexture(CCTexture2D *texture, unsigned int tileWidth, unsigned int tileHeight, unsigned int itemsToRender);

    virtual void updateAtlasValues();

    virtual void draw(void);

    virtual CCTexture2D *getTexture(void);

    virtual void setTexture(CCTexture2D *texture);

    virtual bool isOpacityModifyRGB();
    virtual void setOpacityModifyRGB(bool isOpacityModifyRGB);
    virtual const ccColor3B &getColor(void);
    virtual void setColor(const ccColor3B &color);
    virtual void setOpacity(GLubyte opacity);

private:
    void calculateMaxItems();
    void updateBlendFunc();
    void updateOpacityModifyRGB();

    friend class CCDirector;
    void setIgnoreContentScaleFactor(bool bIgnoreContentScaleFactor);
};
// #line 39 "cocos2d/cocos-headers/cocos2dx/cocoa/CCAutoreleasePool.h"
class CCAutoreleasePool : public CCObject
{
    CCArray *m_pManagedObjectArray;

public:
    CCAutoreleasePool(void);
    ~CCAutoreleasePool(void);

    void addObject(CCObject *pObject);
    void removeObject(CCObject *pObject);

    void clear();
};

class CCPoolManager
{
    CCArray *m_pReleasePoolStack;
    CCAutoreleasePool *m_pCurReleasePool;

    CCAutoreleasePool *getCurReleasePool();

public:
    CCPoolManager();
    ~CCPoolManager();
    void finalize();
    void push();
    void pop();

    void removeObject(CCObject *pObject);
    void addObject(CCObject *pObject);

    static CCPoolManager *sharedPoolManager();
    static void purgePoolManager();

    friend class CCAutoreleasePool;
};
// #line 14 "cocos2d/cocos-headers/cocos2dx/cocoa/CCInteger.h"
class CCInteger : public CCObject
{
public:
    CCInteger(int v)
        : m_nValue(v) {}
    int getValue() const { return m_nValue; }

    static CCInteger *create(int v)
    {
        CCInteger *pRet = new CCInteger(v);
        pRet->autorelease();
        return pRet;
    }

    virtual void acceptVisitor(CCDataVisitor &visitor) { visitor.visit(this); }

private:
    int m_nValue;
};
// #line 39 "cocos2d/cocos-headers/cocos2dx/cocoa/CCFloat.h"
class CCFloat : public CCObject
{
public:
    CCFloat(float v)
        : m_fValue(v) {}
    float getValue() const { return m_fValue; }

    static CCFloat *create(float v)
    {
        CCFloat *pRet = new CCFloat(v);
        if (pRet)
        {
            pRet->autorelease();
        }
        return pRet;
    }

    virtual void acceptVisitor(CCDataVisitor &visitor) { visitor.visit(this); }

private:
    float m_fValue;
};
// #line 39 "cocos2d/cocos-headers/cocos2dx/cocoa/CCDouble.h"
class CCDouble : public CCObject
{
public:
    CCDouble(double v)
        : m_dValue(v) {}
    double getValue() const { return m_dValue; }

    static CCDouble *create(double v)
    {
        CCDouble *pRet = new CCDouble(v);
        if (pRet)
        {
            pRet->autorelease();
        }
        return pRet;
    }

    virtual void acceptVisitor(CCDataVisitor &visitor) { visitor.visit(this); }

private:
    double m_dValue;
};
// #line 39 "cocos2d/cocos-headers/cocos2dx/cocoa/CCBool.h"
class CCBool : public CCObject
{
public:
    CCBool(bool v)
        : m_bValue(v) {}
    bool getValue() const { return m_bValue; }

    static CCBool *create(bool v)
    {
        CCBool *pRet = new CCBool(v);
        if (pRet)
        {
            pRet->autorelease();
        }
        return pRet;
    }

    virtual void acceptVisitor(CCDataVisitor &visitor) { visitor.visit(this); }

private:
    bool m_bValue;
};
// #line 47 "cocos2d/cocos-headers/cocos2dx/cocoa/CCNS.h"
CCRect CCRectFromString(const char *pszContent);
// #line 59 "cocos2d/cocos-headers/cocos2dx/cocoa/CCNS.h"
CCPoint CCPointFromString(const char *pszContent);
// #line 71 "cocos2d/cocos-headers/cocos2dx/cocoa/CCNS.h"
CCSize CCSizeFromString(const char *pszContent);
// #line 29 "cocos2d/cocos-headers/cocos2dx/cocoa/CCZone.h"
#include <stdio.h>
// #line 38 "cocos2d/cocos-headers/cocos2dx/cocoa/CCZone.h"
class CCObject;

class CCZone
{
public:
    CCZone(CCObject *pObject = NULL);

public:
    CCObject *m_pCopyObject;
};
// #line 76 "cocos2d/cocos-headers/cocos2dx/draw_nodes/CCDrawingPrimitives.h"
class CCPointArray;

void ccDrawInit();

void ccDrawFree();

void ccDrawPoint(const CCPoint &point);

void ccDrawPoints(const CCPoint *points, unsigned int numberOfPoints);

void ccDrawLine(const CCPoint &origin, const CCPoint &destination);

void ccDrawRect(CCPoint origin, CCPoint destination);

void ccDrawSolidRect(CCPoint origin, CCPoint destination, ccColor4F color);

void ccDrawPoly(const CCPoint *vertices, unsigned int numOfVertices, bool closePolygon);

void ccDrawSolidPoly(const CCPoint *poli, unsigned int numberOfPoints, ccColor4F color);

void ccDrawCircle(const CCPoint &center, float radius, float angle, unsigned int segments, bool drawLineToCenter, float scaleX, float scaleY);
void ccDrawCircle(const CCPoint &center, float radius, float angle, unsigned int segments, bool drawLineToCenter);

void ccDrawQuadBezier(const CCPoint &origin, const CCPoint &control, const CCPoint &destination, unsigned int segments);

void ccDrawCubicBezier(const CCPoint &origin, const CCPoint &control1, const CCPoint &control2, const CCPoint &destination, unsigned int segments);

void ccDrawCatmullRom(CCPointArray *arrayOfControlPoints, unsigned int segments);

void ccDrawCardinalSpline(CCPointArray *config, float tension, unsigned int segments);

void ccDrawColor4B(GLubyte r, GLubyte g, GLubyte b, GLubyte a);

void ccDrawColor4F(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

void ccPointSize(GLfloat pointSize);
// #line 45 "cocos2d/cocos-headers/cocos2dx/draw_nodes/CCDrawNode.h"
class CCDrawNode : public CCNode
{
protected:
    GLuint m_uVao;
    GLuint m_uVbo;

    unsigned int m_uBufferCapacity;
    GLsizei m_nBufferCount;
    ccV2F_C4B_T2F *m_pBuffer;

    ccBlendFunc m_sBlendFunc;

    bool m_bDirty;

public:
    static CCDrawNode *create();
    virtual ~CCDrawNode();

    virtual bool init();
    virtual void draw();

    void drawDot(const CCPoint &pos, float radius, const ccColor4F &color);

    void drawSegment(const CCPoint &from, const CCPoint &to, float radius, const ccColor4F &color);
    // #line 78 "cocos2d/cocos-headers/cocos2dx/draw_nodes/CCDrawNode.h"
    void drawPolygon(CCPoint *verts, unsigned int count, const ccColor4F &fillColor, float borderWidth, const ccColor4F &borderColor);

    void clear();

    ccBlendFunc getBlendFunc() const;

    void setBlendFunc(const ccBlendFunc &blendFunc);

    CCDrawNode();

    void listenBackToForeground(CCObject *obj);

private:
    void ensureCapacity(unsigned int count);
    void render();
};

typedef enum _ccConfigurationType
{
    ConfigurationError,
    ConfigurationString,
    ConfigurationInt,
    ConfigurationDouble,
    ConfigurationBoolean
} ccConfigurationType;

class CCConfiguration : public CCObject
{
public:
    static CCConfiguration *sharedConfiguration(void);

    static void purgeConfiguration(void);

public:
    virtual ~CCConfiguration(void);

    int getMaxTextureSize(void) const;

    int getMaxModelviewStackDepth(void) const;

    int getMaxTextureUnits(void) const;

    bool supportsNPOT(void) const;

    bool supportsPVRTC(void) const;

    bool supportsBGRA8888(void) const;

    bool supportsDiscardFramebuffer(void) const;

    bool supportsShareableVAO(void) const;

    bool checkForGLExtension(const std::string &searchName) const;

    bool init(void);

    const char *getCString(const char *key, const char *default_value = NULL) const;

    bool getBool(const char *key, bool default_value = false) const;

    double getNumber(const char *key, double default_value = 0.0) const;

    CCObject *getObject(const char *key) const;

    void setObject(const char *key, CCObject *value);

    void dumpInfo(void) const;

    void gatherGPUInfo(void);

    void loadConfigFile(const char *filename);

private:
    CCConfiguration(void);
    static CCConfiguration *s_gSharedConfiguration;
    static std::string s_sConfigfile;

protected:
    GLint m_nMaxTextureSize;
    GLint m_nMaxModelviewStackDepth;
    bool m_bSupportsPVRTC;
    bool m_bSupportsNPOT;
    bool m_bSupportsBGRA8888;
    bool m_bSupportsDiscardFramebuffer;
    bool m_bSupportsShareableVAO;
    GLint m_nMaxSamplesAllowed;
    GLint m_nMaxTextureUnits;
    char *m_pGlExtensions;

    CCDictionary *m_pValueDict;
};

class CCTexture2D;
class CCGrabber : public CCObject
{
public:
    CCGrabber(void);
    ~CCGrabber(void);

    void grab(CCTexture2D *pTexture);
    void beforeRender(CCTexture2D *pTexture);
    void afterRender(CCTexture2D *pTexture);

protected:
    GLuint m_FBO;
    GLint m_oldFBO;
    GLfloat m_oldClearColor[4];
};

class CCCamera : public CCObject
{
protected:
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

public:
    CCCamera(void);

    ~CCCamera(void);

    void init(void);

    const char *description(void);

    inline void setDirty(bool bValue) { m_bDirty = bValue; }

    inline bool isDirty(void) { return m_bDirty; }

    void restore(void);

    void locate(void);

    void setEyeXYZ(float fEyeX, float fEyeY, float fEyeZ);

    void setCenterXYZ(float fCenterX, float fCenterY, float fCenterZ);

    void setUpXYZ(float fUpX, float fUpY, float fUpZ);

    void getEyeXYZ(float *pEyeX, float *pEyeY, float *pEyeZ);

    void getCenterXYZ(float *pCenterX, float *pCenterY, float *pCenterZ);

    void getUpXYZ(float *pUpX, float *pUpY, float *pUpZ);

public:
    static float getZEye();

private:
    CCCamera(const CCCamera &);
    void operator=(const CCCamera &);
};

class CCLabelAtlas : public CCAtlasNode, public CCLabelProtocol
{
public:
    CCLabelAtlas()
        : m_sString("")
    {
    }

    virtual ~CCLabelAtlas()
    {
        m_sString.clear();
    }

    static CCLabelAtlas *create(const char *string, const char *charMapFile, unsigned int itemWidth, unsigned int itemHeight, unsigned int startCharMap);

    static CCLabelAtlas *create(const char *string, const char *fntFile);

    bool initWithString(const char *string, const char *charMapFile, unsigned int itemWidth, unsigned int itemHeight, unsigned int startCharMap);

    bool initWithString(const char *string, const char *fntFile);

    bool initWithString(const char *string, CCTexture2D *texture, unsigned int itemWidth, unsigned int itemHeight, unsigned int startCharMap);

    virtual void updateAtlasValues();
    virtual void setString(const char *label);
    virtual const char *getString(void);

protected:
    std::string m_sString;

    unsigned int m_uMapStartChar;
};
// #line 51 "cocos2d/cocos-headers/cocos2dx/CCDirector.h"
typedef enum
{

    kCCDirectorProjection2D,

    kCCDirectorProjection3D,

    kCCDirectorProjectionCustom,

    kCCDirectorProjectionDefault = kCCDirectorProjection3D,
} ccDirectorProjection;

typedef enum
{
    kTextureQualityLow = 1,
    kTextureQualityMedium,
    kTextureQualityHigh
} TextureQuality;
typedef enum
{
    kPopTransitionFade,
    kPopTransitionMoveInT
} PopTransition;
// #line 80 "cocos2d/cocos-headers/cocos2dx/CCDirector.h"
class CCLabelAtlas;
class CCScene;
class CCEGLView;
class CCDirectorDelegate;
class CCNode;
class CCScheduler;
class CCActionManager;
class CCTouchDispatcher;
class CCKeypadDispatcher;
class CCAccelerometer;
class CCKeyboardDispatcher;
class CCMouseDispatcher;
class CCSceneDelegate;
// #line 116 "cocos2d/cocos-headers/cocos2dx/CCDirector.h"
class CCDirector : public CCObject, public TypeInfo
{
public:
    CCDirector(void);

    virtual ~CCDirector(void);
    virtual bool init(void);

    virtual long getClassTypeInfo()
    {
        static const long id = getHashCodeByString(typeid(CCDirector).name());
        return id;
    }

    inline CCScene *getRunningScene(void) { return m_pRunningScene; }

    inline double getAnimationInterval(void) { return m_dAnimationInterval; }

    virtual void setAnimationInterval(double dValue) = 0;

    inline bool isDisplayStats(void) { return m_bDisplayStats; }

    inline void setDisplayStats(bool bDisplayStats) { m_bDisplayStats = bDisplayStats; }

    inline float getSecondsPerFrame() { return m_fSecondsPerFrame; }

    inline CCEGLView *getOpenGLView(void) { return m_pobOpenGLView; }
    void setOpenGLView(CCEGLView *pobOpenGLView);

    inline bool isNextDeltaTimeZero(void) { return m_bNextDeltaTimeZero; }
    void setNextDeltaTimeZero(bool bNextDeltaTimeZero);

    inline bool isPaused(void) { return m_bPaused; }

    inline unsigned int getTotalFrames(void) { return m_uTotalFrames; }

    inline ccDirectorProjection getProjection(void) { return m_eProjection; }
    void setProjection(ccDirectorProjection kProjection);

    void reshapeProjection(const CCSize &newWindowSize);

    void setViewport();
    // #line 191 "cocos2d/cocos-headers/cocos2dx/CCDirector.h"
    inline bool isSendCleanupToScene(void) { return m_bSendCleanupToScene; }

    CCNode *getNotificationNode();
    void setNotificationNode(CCNode *node);

    CCDirectorDelegate *getDelegate() const;
    void setDelegate(CCDirectorDelegate *pDelegate);

    CCSize getWinSize(void);

    CCSize getWinSizeInPixels(void);

    CCSize getVisibleSize();

    CCPoint getVisibleOrigin();

    CCPoint convertToGL(const CCPoint &obPoint);

    CCPoint convertToUI(const CCPoint &obPoint);

    float getZEye(void);
    // #line 248 "cocos2d/cocos-headers/cocos2dx/CCDirector.h"
    void runWithScene(CCScene *pScene);
    // #line 256 "cocos2d/cocos-headers/cocos2dx/CCDirector.h"
    bool pushScene(CCScene *pScene);

    void popScene(void);

    void popToRootScene(void);

    void popToSceneStackLevel(int level);

    bool replaceScene(CCScene *pScene);

    void end(void);

    void pause(void);

    void resume(void);

    virtual void stopAnimation(void) = 0;

    virtual void startAnimation(void) = 0;

    void drawScene(void);
    // #line 323 "cocos2d/cocos-headers/cocos2dx/CCDirector.h"
    void purgeCachedData(void);

    void setDefaultValues(void);

    void setGLDefaultValues(void);

    void setAlphaBlending(bool bOn);

    void setDepthTest(bool bOn);

    virtual void mainLoop(void) = 0;

    void setContentScaleFactor(float scaleFactor);
    float getContentScaleFactor(void);

public:
    CCDirector(const CCDirector &);
    CCDirector &operator=(const CCDirector &);
    void checkSceneReference(void);
    CCScene *getNextScene(void);
    int levelForSceneInStack(CCScene *);
    bool popSceneWithTransition(float, PopTransition);
    void popToSceneInStack(CCScene *);
    int sceneCount(void);
    void willSwitchToScene(CCScene *);
    void removeStatsLabel(void);
    void resetSmoothFixCounter(void);
    void setDeltaTime(float);
    void setupScreenScale(CCSize, CCSize, TextureQuality);
    void updateContentScale(TextureQuality);
    void updateScreenScale(CCSize);
    TextureQuality getLoadedTextureQuality(void) const;

protected:
protected:
    float m_fScreenScaleFactor;

public:
    float getScreenScaleFactor(void) const { return m_fScreenScaleFactor; };

protected:
    float m_fScreenScaleFactorMax;

public:
    float getScreenScaleFactorMax(void) const { return m_fScreenScaleFactorMax; };

protected:
    float m_fScreenScaleFactorW;

public:
    float getScreenScaleFactorW(void) const { return m_fScreenScaleFactorW; };

protected:
    float m_fScreenScaleFactorH;

public:
    float getScreenScaleFactorH(void) const { return m_fScreenScaleFactorH; };

protected:
    float m_fScreenTop;

public:
    float getScreenTop(void) const { return m_fScreenTop; };

protected:
    float m_fScreenBottom;

public:
    float getScreenBottom(void) const { return m_fScreenBottom; };

protected:
    float m_fScreenLeft;

public:
    float getScreenLeft(void) const { return m_fScreenLeft; };

protected:
    float m_fScreenRight;

public:
    float getScreenRight(void) const { return m_fScreenRight; };

protected:
    CCScene *m_pSceneReference;

public:
    CCScene *getSceneReference(void) const { return m_pSceneReference; }

public:
    void setSceneReference(CCScene *var) { m_pSceneReference = var; };
    // #line 386 "cocos2d/cocos-headers/cocos2dx/CCDirector.h"
public:
protected:
    CCScheduler *m_pScheduler;

public:
    virtual CCScheduler *getScheduler(void);

public:
    virtual void setScheduler(CCScheduler *var);
    ;

protected:
    CCActionManager *m_pActionManager;

public:
    virtual CCActionManager *getActionManager(void);

public:
    virtual void setActionManager(CCActionManager *var);
    ;

protected:
    CCTouchDispatcher *m_pTouchDispatcher;

public:
    virtual CCTouchDispatcher *getTouchDispatcher(void);

public:
    virtual void setTouchDispatcher(CCTouchDispatcher *var);
    ;

protected:
    CCKeypadDispatcher *m_pKeypadDispatcher;

public:
    virtual CCKeypadDispatcher *getKeypadDispatcher(void);

public:
    virtual void setKeypadDispatcher(CCKeypadDispatcher *var);
    ;

protected:
    CCKeyboardDispatcher *m_pKeyboardDispatcher;

public:
    virtual CCKeyboardDispatcher *getKeyboardDispatcher(void);

public:
    virtual void setKeyboardDispatcher(CCKeyboardDispatcher *var);
    ;

protected:
    CCMouseDispatcher *m_pMouseDispatcher;

public:
    virtual CCMouseDispatcher *getMouseDispatcher(void);

public:
    virtual void setMouseDispatcher(CCMouseDispatcher *var);
    ;
    // #line 418 "cocos2d/cocos-headers/cocos2dx/CCDirector.h"
protected:
    CCAccelerometer *m_pAccelerometer;

public:
    virtual CCAccelerometer *getAccelerometer(void);

public:
    virtual void setAccelerometer(CCAccelerometer *var);
    ;

protected:
    float m_fDeltaTime;

public:
    virtual float getDeltaTime(void);
    ;

protected:
    float m_fActualDeltaTime;

public:
    float getActualDeltaTime(void) const { return m_fActualDeltaTime; }

public:
    void setActualDeltaTime(float var) { m_fActualDeltaTime = var; };

public:
    static CCDirector *sharedDirector(void);

protected:
    void purgeDirector();

protected:
    bool m_bIsTransitioning;

public:
    bool getIsTransitioning(void) const { return m_bIsTransitioning; };

protected:
    bool m_bSmoothFix;

public:
    bool getSmoothFix(void) const { return m_bSmoothFix; }

public:
    void setSmoothFix(bool var) { m_bSmoothFix = var; };

protected:
    bool m_bSmoothFixCheck;

public:
    bool getSmoothFixCheck(void) const { return m_bSmoothFixCheck; }

public:
    void setSmoothFixCheck(bool var) { m_bSmoothFixCheck = var; };

protected:
    bool m_bForceSmoothFix;

public:
    bool getForceSmoothFix(void) const { return m_bForceSmoothFix; }

public:
    void setForceSmoothFix(bool var) { m_bForceSmoothFix = var; };

protected:
    int m_nSmoothFixCounter;

public:
    int getSmoothFixCounter(void) const { return m_nSmoothFixCounter; };
    // #line 447 "cocos2d/cocos-headers/cocos2dx/CCDirector.h"
protected:
    bool m_bPurgeDirecotorInNextLoop;

    void setNextScene(void);

    void showStats();
    void createStatsLabel();
    void calculateMPF();
    void getFPSImageData(unsigned char **datapointer, unsigned int *length);

    void calculateDeltaTime();

protected:
    CCEGLView *m_pobOpenGLView;

    char pad463[0x4] = {};
    ;

    double m_dAnimationInterval;
    double m_dOldAnimationInterval;

    bool m_bLandscape;

    bool m_bDisplayStats;
    float m_fAccumDt;
    float m_fFrameRate;

    CCLabelAtlas *m_pFPSLabel;
    CCLabelAtlas *m_pSPFLabel;
    CCLabelAtlas *m_pDrawsLabel;

    bool m_bPaused;

    unsigned int m_uTotalFrames;
    unsigned int m_uFrames;
    float m_fSecondsPerFrame;

    CCScene *m_pRunningScene;

    CCScene *m_pNextScene;

    bool m_bSendCleanupToScene;

    CCArray *m_pobScenesStack;

    struct cc_timeval *m_pLastUpdate;

    bool m_bNextDeltaTimeZero;

    ccDirectorProjection m_eProjection;

    CCSize m_obWinSizeInPoints;

    float m_fContentScaleFactor;

    char *m_pszFPS;

    CCNode *m_pNotificationNode;

    CCDirectorDelegate *m_pProjectionDelegate;

protected:
    CCSceneDelegate *m_pAppDelegate;

public:
    virtual CCSceneDelegate *getSceneDelegate(void);

public:
    virtual void setSceneDelegate(CCSceneDelegate *var);
    ;
    CCSize m_obScaleFactor;
    CCSize m_obResolutionInPixels;
    TextureQuality m_eTextureQuality;

protected:
    bool m_bDontCallWillSwitch;

public:
    bool getDontCallWillSwitch(void) const { return m_bDontCallWillSwitch; }

public:
    void setDontCallWillSwitch(bool var) { m_bDontCallWillSwitch = var; };
    // #line 536 "cocos2d/cocos-headers/cocos2dx/CCDirector.h"
    friend class CCEGLViewProtocol;
};
// #line 550 "cocos2d/cocos-headers/cocos2dx/CCDirector.h"
class CCDisplayLinkDirector : public CCDirector
{
public:
    CCDisplayLinkDirector(void)
        : m_bInvalid(false)
    {
    }

    virtual void mainLoop(void);
    virtual void setAnimationInterval(double dValue);
    virtual void startAnimation(void);
    virtual void stopAnimation();

protected:
    bool m_bInvalid;
};
// #line 34 "cocos2d/cocos-headers/cocos2dx/effects/CCGrid.h"

class CCTexture2D;
class CCGrabber;
class CCGLProgram;
// #line 52 "cocos2d/cocos-headers/cocos2dx/effects/CCGrid.h"
class CCGridBase : public CCObject
{
public:
    virtual ~CCGridBase(void);

    inline bool isActive(void) { return m_bActive; }

    void setActive(bool bActive);

    inline int getReuseGrid(void) { return m_nReuseGrid; }

    inline void setReuseGrid(int nReuseGrid) { m_nReuseGrid = nReuseGrid; }

    inline const CCSize &getGridSize(void) { return m_sGridSize; }

    inline void setGridSize(const CCSize &gridSize) { m_sGridSize = gridSize; }

    inline const CCPoint &getStep(void) { return m_obStep; }

    inline void setStep(const CCPoint &step) { m_obStep = step; }

    inline bool isTextureFlipped(void) { return m_bIsTextureFlipped; }

    void setTextureFlipped(bool bFlipped);

    bool initWithSize(const CCSize &gridSize, CCTexture2D *pTexture, bool bFlipped);

    bool initWithSize(const CCSize &gridSize);

    void beforeDraw(void);

    void afterDraw(CCNode *pTarget);

    virtual void blit(void);

    virtual void reuse(void);

    virtual void calculateVertexPoints(void);

public:
    static CCGridBase *create(const CCSize &gridSize, CCTexture2D *texture, bool flipped);

    static CCGridBase *create(const CCSize &gridSize);

    void set2DProjection(void);

protected:
    bool m_bActive;
    int m_nReuseGrid;
    CCSize m_sGridSize;
    CCTexture2D *m_pTexture;
    CCPoint m_obStep;
    CCGrabber *m_pGrabber;
    bool m_bIsTextureFlipped;
    CCGLProgram *m_pShaderProgram;
    ccDirectorProjection m_directorProjection;
};

class CCGrid3D : public CCGridBase

{
public:
    CCGrid3D();
    ~CCGrid3D(void);

    ccVertex3F vertex(const CCPoint &pos);

    ccVertex3F originalVertex(const CCPoint &pos);

    void setVertex(const CCPoint &pos, const ccVertex3F &vertex);

    virtual void blit(void);
    virtual void reuse(void);
    virtual void calculateVertexPoints(void);

public:
    static CCGrid3D *create(const CCSize &gridSize, CCTexture2D *pTexture, bool bFlipped);

    static CCGrid3D *create(const CCSize &gridSize);

protected:
    GLvoid *m_pTexCoordinates;
    GLvoid *m_pVertices;
    GLvoid *m_pOriginalVertices;
    GLushort *m_pIndices;
};
// #line 205 "cocos2d/cocos-headers/cocos2dx/effects/CCGrid.h"
class CCTiledGrid3D : public CCGridBase

{
public:
    CCTiledGrid3D();
    ~CCTiledGrid3D(void);

    ccQuad3 tile(const CCPoint &pos);

    ccQuad3 originalTile(const CCPoint &pos);

    void setTile(const CCPoint &pos, const ccQuad3 &coords);

    virtual void blit(void);
    virtual void reuse(void);
    virtual void calculateVertexPoints(void);

public:
    static CCTiledGrid3D *create(const CCSize &gridSize, CCTexture2D *pTexture, bool bFlipped);

    static CCTiledGrid3D *create(const CCSize &gridSize);

protected:
    GLvoid *m_pTexCoordinates;
    GLvoid *m_pVertices;
    GLvoid *m_pOriginalVertices;
    GLushort *m_pIndices;
};
// #line 31 "cocos2d/cocos-headers/cocos2dx/kazmath/include/kazmath/vec2.h"
struct kmMat3;

#pragma pack(push)
#pragma pack(1)
typedef struct kmVec2
{
    float x;
    float y;
} kmVec2;

#pragma pack(pop)

kmVec2 *kmVec2Fill(kmVec2 *pOut, float x, float y);
float kmVec2Length(const kmVec2 *pIn);
float kmVec2LengthSq(const kmVec2 *pIn);
kmVec2 *kmVec2Normalize(kmVec2 *pOut, const kmVec2 *pIn);
kmVec2 *kmVec2Add(kmVec2 *pOut, const kmVec2 *pV1, const kmVec2 *pV2);
float kmVec2Dot(const kmVec2 *pV1, const kmVec2 *pV2);
kmVec2 *kmVec2Subtract(kmVec2 *pOut, const kmVec2 *pV1, const kmVec2 *pV2);
kmVec2 *kmVec2Transform(kmVec2 *pOut, const kmVec2 *pV1, const struct kmMat3 *pM);
kmVec2 *kmVec2TransformCoord(kmVec2 *pOut, const kmVec2 *pV, const struct kmMat3 *pM);
kmVec2 *kmVec2Scale(kmVec2 *pOut, const kmVec2 *pIn, const float s);
int kmVec2AreEqual(const kmVec2 *p1, const kmVec2 *p2);
// #line 30 "cocos2d/cocos-headers/cocos2dx/kazmath/include/kazmath/vec3.h"
#include <assert.h>

struct kmMat4;

typedef struct kmVec3
{
    float x;
    float y;
    float z;
} kmVec3;

kmVec3 *kmVec3Fill(kmVec3 *pOut, float x, float y, float z);
float kmVec3Length(const kmVec3 *pIn);
float kmVec3LengthSq(const kmVec3 *pIn);
kmVec3 *kmVec3Normalize(kmVec3 *pOut, const kmVec3 *pIn);
kmVec3 *kmVec3Cross(kmVec3 *pOut, const kmVec3 *pV1, const kmVec3 *pV2);
float kmVec3Dot(const kmVec3 *pV1, const kmVec3 *pV2);
kmVec3 *kmVec3Add(kmVec3 *pOut, const kmVec3 *pV1, const kmVec3 *pV2);
kmVec3 *kmVec3Subtract(kmVec3 *pOut, const kmVec3 *pV1, const kmVec3 *pV2);
kmVec3 *kmVec3Transform(kmVec3 *pOut, const kmVec3 *pV1, const struct kmMat4 *pM);
kmVec3 *kmVec3TransformNormal(kmVec3 *pOut, const kmVec3 *pV, const struct kmMat4 *pM);
kmVec3 *kmVec3TransformCoord(kmVec3 *pOut, const kmVec3 *pV, const struct kmMat4 *pM);
kmVec3 *kmVec3Scale(kmVec3 *pOut, const kmVec3 *pIn, const float s);
int kmVec3AreEqual(const kmVec3 *p1, const kmVec3 *p2);
kmVec3 *kmVec3InverseTransform(kmVec3 *pOut, const kmVec3 *pV, const struct kmMat4 *pM);
kmVec3 *kmVec3InverseTransformNormal(kmVec3 *pOut, const kmVec3 *pVect, const struct kmMat4 *pM);
kmVec3 *kmVec3Assign(kmVec3 *pOut, const kmVec3 *pIn);
kmVec3 *kmVec3Zero(kmVec3 *pOut);
// #line 30 "cocos2d/cocos-headers/cocos2dx/kazmath/include/kazmath/utility.h"
#include <math.h>
// #line 63 "cocos2d/cocos-headers/cocos2dx/kazmath/include/kazmath/utility.h"
float kmSQR(float s);
float kmDegreesToRadians(float degrees);
float kmRadiansToDegrees(float radians);

float kmMin(float lhs, float rhs);
float kmMax(float lhs, float rhs);
unsigned char kmAlmostEqual(float lhs, float rhs);
// #line 33 "cocos2d/cocos-headers/cocos2dx/kazmath/include/kazmath/mat3.h"
struct kmVec3;
struct kmQuaternion;

typedef struct kmMat3
{
    float mat[9];
} kmMat3;

kmMat3 *const kmMat3Fill(kmMat3 *pOut, const float *pMat);
kmMat3 *const kmMat3Adjugate(kmMat3 *pOut, const kmMat3 *pIn);
kmMat3 *const kmMat3Identity(kmMat3 *pOut);
kmMat3 *const kmMat3Inverse(kmMat3 *pOut, const float pDeterminate, const kmMat3 *pM);
const int kmMat3IsIdentity(const kmMat3 *pIn);
kmMat3 *const kmMat3Transpose(kmMat3 *pOut, const kmMat3 *pIn);
const float kmMat3Determinant(const kmMat3 *pIn);
kmMat3 *const kmMat3Multiply(kmMat3 *pOut, const kmMat3 *pM1, const kmMat3 *pM2);
kmMat3 *const kmMat3ScalarMultiply(kmMat3 *pOut, const kmMat3 *pM, const float pFactor);

kmMat3 *const kmMat3RotationAxisAngle(kmMat3 *pOut, const struct kmVec3 *axis, float radians);
struct kmVec3 *const kmMat3RotationToAxisAngle(struct kmVec3 *pAxis, float *radians, const kmMat3 *pIn);

kmMat3 *const kmMat3Assign(kmMat3 *pOut, const kmMat3 *pIn);
const int kmMat3AreEqual(const kmMat3 *pM1, const kmMat3 *pM2);

kmMat3 *const kmMat3RotationX(kmMat3 *pOut, const float radians);
kmMat3 *const kmMat3RotationY(kmMat3 *pOut, const float radians);
kmMat3 *const kmMat3RotationZ(kmMat3 *pOut, const float radians);

kmMat3 *const kmMat3Rotation(kmMat3 *pOut, const float radians);
kmMat3 *const kmMat3Scaling(kmMat3 *pOut, const float x, const float y);
kmMat3 *const kmMat3Translation(kmMat3 *pOut, const float x, const float y);

kmMat3 *const kmMat3RotationQuaternion(kmMat3 *pOut, const struct kmQuaternion *pIn);
kmMat3 *const kmMat3RotationAxisAngle(kmMat3 *pOut, const struct kmVec3 *axis, float radians);
struct kmVec3 *const kmMat3RotationToAxisAngle(struct kmVec3 *pAxis, float *radians, const kmMat3 *pIn);
// #line 32 "cocos2d/cocos-headers/cocos2dx/kazmath/include/kazmath/mat4.h"
struct kmVec3;
struct kmMat3;
struct kmQuaternion;
struct kmPlane;
// #line 50 "cocos2d/cocos-headers/cocos2dx/kazmath/include/kazmath/mat4.h"
typedef struct kmMat4
{
    float mat[16];
} kmMat4;

kmMat4 *const kmMat4Fill(kmMat4 *pOut, const float *pMat);

kmMat4 *const kmMat4Identity(kmMat4 *pOut);

kmMat4 *const kmMat4Inverse(kmMat4 *pOut, const kmMat4 *pM);

const int kmMat4IsIdentity(const kmMat4 *pIn);

kmMat4 *const kmMat4Transpose(kmMat4 *pOut, const kmMat4 *pIn);
kmMat4 *const kmMat4Multiply(kmMat4 *pOut, const kmMat4 *pM1, const kmMat4 *pM2);

kmMat4 *const kmMat4Assign(kmMat4 *pOut, const kmMat4 *pIn);
const int kmMat4AreEqual(const kmMat4 *pM1, const kmMat4 *pM2);

kmMat4 *const kmMat4RotationX(kmMat4 *pOut, const float radians);
kmMat4 *const kmMat4RotationY(kmMat4 *pOut, const float radians);
kmMat4 *const kmMat4RotationZ(kmMat4 *pOut, const float radians);
kmMat4 *const kmMat4RotationPitchYawRoll(kmMat4 *pOut, const float pitch, const float yaw, const float roll);
kmMat4 *const kmMat4RotationQuaternion(kmMat4 *pOut, const struct kmQuaternion *pQ);
kmMat4 *const kmMat4RotationTranslation(kmMat4 *pOut, const struct kmMat3 *rotation, const struct kmVec3 *translation);
kmMat4 *const kmMat4Scaling(kmMat4 *pOut, const float x, const float y, const float z);
kmMat4 *const kmMat4Translation(kmMat4 *pOut, const float x, const float y, const float z);

struct kmVec3 *const kmMat4GetUpVec3(struct kmVec3 *pOut, const kmMat4 *pIn);
struct kmVec3 *const kmMat4GetRightVec3(struct kmVec3 *pOut, const kmMat4 *pIn);
struct kmVec3 *const kmMat4GetForwardVec3(struct kmVec3 *pOut, const kmMat4 *pIn);

kmMat4 *const kmMat4PerspectiveProjection(kmMat4 *pOut, float fovY, float aspect, float zNear, float zFar);
kmMat4 *const kmMat4OrthographicProjection(kmMat4 *pOut, float left, float right, float bottom, float top, float nearVal, float farVal);
kmMat4 *const kmMat4LookAt(kmMat4 *pOut, const struct kmVec3 *pEye, const struct kmVec3 *pCenter, const struct kmVec3 *pUp);

kmMat4 *const kmMat4RotationAxisAngle(kmMat4 *pOut, const struct kmVec3 *axis, float radians);
struct kmMat3 *const kmMat4ExtractRotation(struct kmMat3 *pOut, const kmMat4 *pIn);
struct kmPlane *const kmMat4ExtractPlane(struct kmPlane *pOut, const kmMat4 *pIn, const unsigned int plane);
struct kmVec3 *const kmMat4RotationToAxisAngle(struct kmVec3 *pAxis, float *radians, const kmMat4 *pIn);
// #line 36 "cocos2d/cocos-headers/cocos2dx/kazmath/include/kazmath/quaternion.h"
struct kmMat4;
struct kmMat3;
struct kmVec3;

typedef struct kmQuaternion
{
    float x;
    float y;
    float z;
    float w;
} kmQuaternion;

kmQuaternion *const kmQuaternionConjugate(kmQuaternion *pOut, const kmQuaternion *pIn);

const float kmQuaternionDot(const kmQuaternion *q1, const kmQuaternion *q2);

kmQuaternion *kmQuaternionExp(kmQuaternion *pOut, const kmQuaternion *pIn);

kmQuaternion *kmQuaternionIdentity(kmQuaternion *pOut);

kmQuaternion *kmQuaternionInverse(kmQuaternion *pOut,
                                  const kmQuaternion *pIn);

int kmQuaternionIsIdentity(const kmQuaternion *pIn);

float kmQuaternionLength(const kmQuaternion *pIn);

float kmQuaternionLengthSq(const kmQuaternion *pIn);

kmQuaternion *kmQuaternionLn(kmQuaternion *pOut, const kmQuaternion *pIn);

kmQuaternion *kmQuaternionMultiply(kmQuaternion *pOut, const kmQuaternion *q1, const kmQuaternion *q2);

kmQuaternion *kmQuaternionNormalize(kmQuaternion *pOut, const kmQuaternion *pIn);

kmQuaternion *kmQuaternionRotationAxis(kmQuaternion *pOut, const struct kmVec3 *pV, float angle);

kmQuaternion *kmQuaternionRotationMatrix(kmQuaternion *pOut, const struct kmMat3 *pIn);

kmQuaternion *kmQuaternionRotationYawPitchRoll(kmQuaternion *pOut, float yaw, float pitch, float roll);

kmQuaternion *kmQuaternionSlerp(kmQuaternion *pOut, const kmQuaternion *q1, const kmQuaternion *q2, float t);

void kmQuaternionToAxisAngle(const kmQuaternion *pIn, struct kmVec3 *pVector, float *pAngle);

kmQuaternion *kmQuaternionScale(kmQuaternion *pOut, const kmQuaternion *pIn, float s);
kmQuaternion *kmQuaternionAssign(kmQuaternion *pOut, const kmQuaternion *pIn);
kmQuaternion *kmQuaternionAdd(kmQuaternion *pOut, const kmQuaternion *pQ1, const kmQuaternion *pQ2);
kmQuaternion *kmQuaternionRotationBetweenVec3(kmQuaternion *pOut, const struct kmVec3 *vec1, const struct kmVec3 *vec2, const struct kmVec3 *fallback);
struct kmVec3 *kmQuaternionMultiplyVec3(struct kmVec3 *pOut, const kmQuaternion *q, const struct kmVec3 *v);
// #line 39 "cocos2d/cocos-headers/cocos2dx/kazmath/include/kazmath/plane.h"
struct kmVec3;
struct kmVec4;
struct kmMat4;

typedef struct kmPlane
{
    float a, b, c, d;
} kmPlane;

typedef enum POINT_CLASSIFICATION
{
    POINT_INFRONT_OF_PLANE = 0,
    POINT_BEHIND_PLANE,
    POINT_ON_PLANE,
} POINT_CLASSIFICATION;

const float kmPlaneDot(const kmPlane *pP, const struct kmVec4 *pV);
const float kmPlaneDotCoord(const kmPlane *pP, const struct kmVec3 *pV);
const float kmPlaneDotNormal(const kmPlane *pP, const struct kmVec3 *pV);
kmPlane *const kmPlaneFromPointNormal(kmPlane *pOut, const struct kmVec3 *pPoint, const struct kmVec3 *pNormal);
kmPlane *const kmPlaneFromPoints(kmPlane *pOut, const struct kmVec3 *p1, const struct kmVec3 *p2, const struct kmVec3 *p3);
kmVec3 *const kmPlaneIntersectLine(struct kmVec3 *pOut, const kmPlane *pP, const struct kmVec3 *pV1, const struct kmVec3 *pV2);
kmPlane *const kmPlaneNormalize(kmPlane *pOut, const kmPlane *pP);
kmPlane *const kmPlaneScale(kmPlane *pOut, const kmPlane *pP, float s);
const POINT_CLASSIFICATION kmPlaneClassifyPoint(const kmPlane *pIn, const kmVec3 *pP);
// #line 41 "cocos2d/cocos-headers/cocos2dx/kazmath/include/kazmath/aabb.h"
typedef struct kmAABB
{
    kmVec3 min;
    kmVec3 max;
} kmAABB;

const int kmAABBContainsPoint(const kmVec3 *pPoint, const kmAABB *pBox);
kmAABB *const kmAABBAssign(kmAABB *pOut, const kmAABB *pIn);
kmAABB *const kmAABBScale(kmAABB *pOut, const kmAABB *pIn, float s);
// #line 37 "cocos2d/cocos-headers/cocos2dx/kazmath/include/kazmath/ray2.h"
typedef struct kmRay2
{
    kmVec2 start;
    kmVec2 dir;
} kmRay2;

void kmRay2Fill(kmRay2 *ray, float px, float py, float vx, float vy);
unsigned char kmRay2IntersectLineSegment(const kmRay2 *ray, const kmVec2 *p1, const kmVec2 *p2, kmVec2 *intersection);
unsigned char kmRay2IntersectTriangle(const kmRay2 *ray, const kmVec2 *p1, const kmVec2 *p2, const kmVec2 *p3, kmVec2 *intersection, kmVec2 *normal_out);
unsigned char kmRay2IntersectCircle(const kmRay2 *ray, const kmVec2 centre, const float radius, kmVec2 *intersection);
// #line 35 "cocos2d/cocos-headers/cocos2dx/kazmath/include/kazmath/GL/matrix.h"
typedef unsigned int kmGLEnum;
// #line 44 "cocos2d/cocos-headers/cocos2dx/kazmath/include/kazmath/GL/matrix.h"
void kmGLFreeAll(void);
void kmGLPushMatrix(void);
void kmGLPopMatrix(void);
void kmGLMatrixMode(kmGLEnum mode);
void kmGLLoadIdentity(void);
void kmGLLoadMatrix(const kmMat4 *pIn);
void kmGLMultMatrix(const kmMat4 *pIn);
void kmGLTranslatef(float x, float y, float z);
void kmGLRotatef(float angle, float x, float y, float z);
void kmGLScalef(float x, float y, float z);
void kmGLGetMatrix(kmGLEnum mode, kmMat4 *pOut);
// #line 40 "cocos2d/cocos-headers/cocos2dx/keypad_dispatcher/CCKeypadDelegate.h"
class CCKeypadDelegate
{
public:
    virtual void keyBackClicked() {}

    virtual void keyMenuClicked(){};
};
// #line 57 "cocos2d/cocos-headers/cocos2dx/keypad_dispatcher/CCKeypadDelegate.h"
class CCKeypadHandler : public CCObject
{
public:
    virtual ~CCKeypadHandler(void);

    CCKeypadDelegate *getDelegate();
    void setDelegate(CCKeypadDelegate *pDelegate);

    virtual bool initWithDelegate(CCKeypadDelegate *pDelegate);

public:
    static CCKeypadHandler *handlerWithDelegate(CCKeypadDelegate *pDelegate);

protected:
    CCKeypadDelegate *m_pDelegate;
};
// #line 38 "cocos2d/cocos-headers/cocos2dx/keypad_dispatcher/CCKeypadDispatcher.h"
typedef enum
{

    kTypeBackClicked = 1,
    kTypeMenuClicked,
} ccKeypadMSGType;

struct _ccCArray;

class CCKeypadDispatcher : public CCObject
{
public:
    CCKeypadDispatcher();
    ~CCKeypadDispatcher();

    void addDelegate(CCKeypadDelegate *pDelegate);

    void removeDelegate(CCKeypadDelegate *pDelegate);

    void forceAddDelegate(CCKeypadDelegate *pDelegate);

    void forceRemoveDelegate(CCKeypadDelegate *pDelegate);

    bool dispatchKeypadMSG(ccKeypadMSGType nMsgType);

protected:
    CCArray *m_pDelegates;
    bool m_bLocked;
    bool m_bToAdd;
    bool m_bToRemove;

    struct _ccCArray *m_pHandlersToAdd;
    struct _ccCArray *m_pHandlersToRemove;
};
// #line 33 "cocos2d/cocos-headers/cocos2dx/textures/CCTextureAtlas.h"
#include <string>

class CCTexture2D;
// #line 56 "cocos2d/cocos-headers/cocos2dx/textures/CCTextureAtlas.h"
class CCTextureAtlas : public CCObject
{
protected:
    GLushort *m_pIndices;

    GLuint m_pBuffersVBO[2];
    bool m_bDirty;

protected:
    unsigned int m_uTotalQuads;

public:
    virtual unsigned int getTotalQuads(void);

protected:
    unsigned int m_uCapacity;

public:
    virtual unsigned int getCapacity(void);

protected:
    CCTexture2D *m_pTexture;

public:
    virtual CCTexture2D *getTexture(void);

public:
    virtual void setTexture(CCTexture2D *var);

protected:
    ccV3F_C4B_T2F_Quad *m_pQuads;

public:
    virtual ccV3F_C4B_T2F_Quad *getQuads(void);

public:
    virtual void setQuads(ccV3F_C4B_T2F_Quad *var);

public:
    CCTextureAtlas();

    virtual ~CCTextureAtlas();

    const char *description();

    static CCTextureAtlas *create(const char *file, unsigned int capacity);

    bool initWithFile(const char *file, unsigned int capacity);

    static CCTextureAtlas *createWithTexture(CCTexture2D *texture, unsigned int capacity);
    // #line 117 "cocos2d/cocos-headers/cocos2dx/textures/CCTextureAtlas.h"
    bool initWithTexture(CCTexture2D *texture, unsigned int capacity);

    void updateQuad(ccV3F_C4B_T2F_Quad *quad, unsigned int index);

    void insertQuad(ccV3F_C4B_T2F_Quad *quad, unsigned int index);

    void insertQuads(ccV3F_C4B_T2F_Quad *quads, unsigned int index, unsigned int amount);

    void insertQuadFromIndex(unsigned int fromIndex, unsigned int newIndex);

    void removeQuadAtIndex(unsigned int index);

    void removeQuadsAtIndex(unsigned int index, unsigned int amount);

    void removeAllQuads();
    // #line 167 "cocos2d/cocos-headers/cocos2dx/textures/CCTextureAtlas.h"
    bool resizeCapacity(unsigned int n);

    void increaseTotalQuadsWith(unsigned int amount);

    void moveQuadsFromIndex(unsigned int oldIndex, unsigned int amount, unsigned int newIndex);
    // #line 187 "cocos2d/cocos-headers/cocos2dx/textures/CCTextureAtlas.h"
    void moveQuadsFromIndex(unsigned int index, unsigned int newIndex);

    void fillWithEmptyQuadsFromIndex(unsigned int index, unsigned int amount);

    void drawNumberOfQuads(unsigned int n);

    void drawNumberOfQuads(unsigned int n, unsigned int start);

    void drawQuads();

    void listenBackToForeground(CCObject *obj);

    inline bool isDirty(void) { return m_bDirty; }

    inline void setDirty(bool bDirty) { m_bDirty = bDirty; }

private:
    void setupIndices();
    void mapBuffers();

    void setupVBO();
};
// #line 35 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
#include <string>

class CCSpriteBatchNode;
class CCSpriteFrame;
class CCAnimation;
class CCRect;
class CCPoint;
class CCSize;
class CCTexture2D;
struct transformValues_;
// #line 82 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
class CCSprite : public CCNodeRGBA, public CCTextureProtocol

{
public:
    // #line 96 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    static CCSprite *create();
    // #line 107 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    static CCSprite *create(const char *pszFileName);
    // #line 116 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    static CCSprite *create(const char *pszFileName, const CCRect &rect);
    // #line 125 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    static CCSprite *createWithTexture(CCTexture2D *pTexture);
    // #line 137 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    static CCSprite *createWithTexture(CCTexture2D *pTexture, const CCRect &rect);
    // #line 145 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    static CCSprite *createWithSpriteFrame(CCSpriteFrame *pSpriteFrame);
    // #line 156 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    static CCSprite *createWithSpriteFrameName(const char *pszSpriteFrameName);
    // #line 169 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    CCSprite(void);

    virtual ~CCSprite(void);

    virtual bool init(void);
    // #line 192 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    virtual bool initWithTexture(CCTexture2D *pTexture);
    // #line 204 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    virtual bool initWithTexture(CCTexture2D *pTexture, const CCRect &rect);
    // #line 217 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    virtual bool initWithTexture(CCTexture2D *pTexture, const CCRect &rect, bool rotated);
    // #line 225 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    virtual bool initWithSpriteFrame(CCSpriteFrame *pSpriteFrame);
    // #line 236 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    virtual bool initWithSpriteFrameName(const char *pszSpriteFrameName);
    // #line 249 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    virtual bool initWithFile(const char *pszFilename);
    // #line 263 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    virtual bool initWithFile(const char *pszFilename, const CCRect &rect);

    virtual void setChildColor(const ccColor3B &);
    virtual void setChildOpacity(GLubyte);

    virtual void setTexture(CCTexture2D *texture);
    virtual CCTexture2D *getTexture(void);
    inline void setBlendFunc(ccBlendFunc blendFunc) { m_sBlendFunc = blendFunc; }

    inline ccBlendFunc getBlendFunc(void) { return m_sBlendFunc; }
    // #line 285 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    virtual void setScaleX(float fScaleX);
    virtual void setScaleY(float fScaleY);

    virtual void setPosition(const CCPoint &pos);
    virtual void setRotation(float fRotation);
    virtual void setRotationX(float fRotationX);
    virtual void setRotationY(float fRotationY);
    virtual void setSkewX(float sx);
    virtual void setSkewY(float sy);
    virtual void removeChild(CCNode *pChild, bool bCleanup);
    virtual void removeAllChildrenWithCleanup(bool bCleanup);
    virtual void reorderChild(CCNode *pChild, int zOrder);
    virtual void addChild(CCNode *pChild);
    virtual void addChild(CCNode *pChild, int zOrder);
    virtual void addChild(CCNode *pChild, int zOrder, int tag);
    virtual void sortAllChildren();
    virtual void setScale(float fScale);
    virtual void setVertexZ(float fVertexZ);
    virtual void setAnchorPoint(const CCPoint &anchor);
    virtual void ignoreAnchorPointForPosition(bool value);
    virtual void setVisible(bool bVisible);
    virtual void draw(void);
    // #line 313 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    virtual void setColor(const ccColor3B &color3);
    virtual void updateDisplayedColor(const ccColor3B &parentColor);
    virtual void setOpacity(GLubyte opacity);
    virtual void setOpacityModifyRGB(bool modify);
    virtual bool isOpacityModifyRGB(void);
    virtual void updateDisplayedOpacity(GLubyte parentOpacity);
    // #line 328 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    virtual void updateTransform(void);
    // #line 336 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    virtual CCSpriteBatchNode *getBatchNode(void);
    // #line 347 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    virtual void setBatchNode(CCSpriteBatchNode *pobSpriteBatchNode);

    virtual void refreshTextureRect(void);
    // #line 362 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    virtual void setTextureRect(const CCRect &rect);

    virtual void setTextureRect(const CCRect &rect, bool rotated, const CCSize &untrimmedSize);
    // #line 376 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    virtual void setVertexRect(const CCRect &rect);
    // #line 388 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    virtual void setDisplayFrame(CCSpriteFrame *pNewFrame);

    virtual bool isFrameDisplayed(CCSpriteFrame *pFrame);

    virtual CCSpriteFrame *displayFrame(void);
    // #line 410 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    virtual void setDisplayFrameWithAnimationName(const char *animationName, int frameIndex);
    // #line 422 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    inline virtual bool isDirty(void) { return m_bDirty; }

    inline virtual void setDirty(bool bDirty) { m_bDirty = bDirty; }

    inline ccV3F_C4B_T2F_Quad getQuad(void) { return m_sQuad; }

    inline bool isTextureRectRotated(void) { return m_bRectRotated; }

    inline unsigned int getAtlasIndex(void) { return m_uAtlasIndex; }

    inline void setAtlasIndex(unsigned int uAtlasIndex) { m_uAtlasIndex = uAtlasIndex; }

    inline const CCRect &getTextureRect(void) { return m_obRect; }

    inline CCTextureAtlas *getTextureAtlas(void) { return m_pobTextureAtlas; }

    inline void setTextureAtlas(CCTextureAtlas *pobTextureAtlas) { m_pobTextureAtlas = pobTextureAtlas; }

    inline const CCPoint &getOffsetPosition(void) { return m_obOffsetPosition; }
    // #line 483 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    bool isFlipX(void);

    void setFlipX(bool bFlipX);
    // #line 502 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    bool isFlipY(void);

    void setFlipY(bool bFlipY);

protected:
    void updateColor(void);

    virtual void setTextureCoords(const CCRect &rect);
    virtual void updateBlendFunc(void);
    virtual void setReorderChildDirtyRecursively(void);
    virtual void setDirtyRecursively(bool bValue);
    // #line 523 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    CCTextureAtlas *m_pobTextureAtlas;
    unsigned int m_uAtlasIndex;
    CCSpriteBatchNode *m_pobBatchNode;

    bool m_bDirty;
    bool m_bRecursiveDirty;
    bool m_bHasChildren;
    bool m_bShouldBeHidden;
    CCAffineTransform m_transformToBatch;
    // #line 536 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    ccBlendFunc m_sBlendFunc;
    CCTexture2D *m_pobTexture;
    // #line 544 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
    CCRect m_obRect;
    bool m_bRectRotated;

    CCPoint m_obOffsetPosition;
    CCPoint m_obUnflippedOffsetPositionFromCenter;

    ccV3F_C4B_T2F_Quad m_sQuad;

    bool m_bOpacityModifyRGB;

    bool m_bFlipX;
    bool m_bFlipY;

protected:
    bool m_bDontDraw;

public:
    bool getDontDraw(void) const { return m_bDontDraw; }

public:
    void setDontDraw(bool var) { m_bDontDraw = var; };

protected:
    float m_fTlVertexMod;

public:
    float getTlVertexMod(void) const { return m_fTlVertexMod; }

public:
    void setTlVertexMod(float var) { m_fTlVertexMod = var; };

protected:
    float m_fTrVertexMod;

public:
    float getTrVertexMod(void) const { return m_fTrVertexMod; }

public:
    void setTrVertexMod(float var) { m_fTrVertexMod = var; };

protected:
    float m_fBlVertexMod;

public:
    float getBlVertexMod(void) const { return m_fBlVertexMod; }

public:
    void setBlVertexMod(float var) { m_fBlVertexMod = var; };

protected:
    float m_fBrVertexMod;

public:
    float getBrVertexMod(void) const { return m_fBrVertexMod; }

public:
    void setBrVertexMod(float var) { m_fBrVertexMod = var; };
    char pad561[16] = {};
    ;
    bool m_bUnknown;
    int m_nUnknown;
    // #line 571 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSprite.h"
};
// #line 57 "cocos2d/cocos-headers/cocos2dx/label_nodes/CCLabelTTF.h"
class CCLabelTTF : public CCSprite, public CCLabelProtocol
{
public:
    CCLabelTTF();

    virtual ~CCLabelTTF();

    const char *description();

    static CCLabelTTF *create(const char *string, const char *fontName, float fontSize);

    static CCLabelTTF *create(const char *string, const char *fontName, float fontSize,
                              const CCSize &dimensions, CCTextAlignment hAlignment);

    static CCLabelTTF *create(const char *string, const char *fontName, float fontSize,
                              const CCSize &dimensions, CCTextAlignment hAlignment,
                              CCVerticalTextAlignment vAlignment);

    static CCLabelTTF *createWithFontDefinition(const char *string, ccFontDefinition &textDefinition);

    bool initWithString(const char *string, const char *fontName, float fontSize);

    bool initWithString(const char *string, const char *fontName, float fontSize,
                        const CCSize &dimensions, CCTextAlignment hAlignment);

    bool initWithString(const char *string, const char *fontName, float fontSize,
                        const CCSize &dimensions, CCTextAlignment hAlignment,
                        CCVerticalTextAlignment vAlignment);

    bool initWithStringAndTextDefinition(const char *string, ccFontDefinition &textDefinition);

    void setTextDefinition(ccFontDefinition *theDefinition);

    ccFontDefinition *getTextDefinition();

    void enableShadow(const CCSize &shadowOffset, float shadowOpacity, float shadowBlur, bool mustUpdateTexture = true);

    void disableShadow(bool mustUpdateTexture = true);

    void enableStroke(const ccColor3B &strokeColor, float strokeSize, bool mustUpdateTexture = true);

    void disableStroke(bool mustUpdateTexture = true);

    void setFontFillColor(const ccColor3B &tintColor, bool mustUpdateTexture = true);

    bool init();

    static CCLabelTTF *create();

    virtual void setString(const char *label);
    virtual const char *getString(void);

    CCTextAlignment getHorizontalAlignment();
    void setHorizontalAlignment(CCTextAlignment alignment);

    CCVerticalTextAlignment getVerticalAlignment();
    void setVerticalAlignment(CCVerticalTextAlignment verticalAlignment);

    CCSize getDimensions();
    void setDimensions(const CCSize &dim);

    float getFontSize();
    void setFontSize(float fontSize);

    const char *getFontName();
    void setFontName(const char *fontName);

private:
    bool updateTexture();

protected:
    void _updateWithTextDefinition(ccFontDefinition &textDefinition, bool mustUpdateTexture = true);
    ccFontDefinition _prepareTextDefinition(bool adjustForResolution = false);

    CCSize m_tDimensions;

    CCTextAlignment m_hAlignment;

    CCVerticalTextAlignment m_vAlignment;

    std::string *m_pFontName;

    float m_fFontSize;

    std::string m_string;

    bool m_shadowEnabled;
    CCSize m_shadowOffset;
    float m_shadowOpacity;
    float m_shadowBlur;

    bool m_strokeEnabled;
    ccColor3B m_strokeColor;
    float m_strokeSize;

    ccColor3B m_textFillColor;
};
// #line 46 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSpriteBatchNode.h"
class CCSprite;
// #line 63 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSpriteBatchNode.h"
class CCSpriteBatchNode : public CCNode, public CCTextureProtocol
{
public:
    CCSpriteBatchNode();

    ~CCSpriteBatchNode();

    inline CCTextureAtlas *getTextureAtlas(void) { return m_pobTextureAtlas; }
    inline void setTextureAtlas(CCTextureAtlas *textureAtlas)
    {
        if (textureAtlas != m_pobTextureAtlas)
        {
            do
            {
                if (textureAtlas)
                {
                    (textureAtlas)->retain();
                }
            } while (0);
            do
            {
                if (m_pobTextureAtlas)
                {
                    (m_pobTextureAtlas)->release();
                }
            } while (0);
            m_pobTextureAtlas = textureAtlas;
        }
    }

    inline CCArray *getDescendants(void) { return m_pobDescendants; }

    static CCSpriteBatchNode *createWithTexture(CCTexture2D *tex, unsigned int capacity);
    static CCSpriteBatchNode *createWithTexture(CCTexture2D *tex)
    {
        return CCSpriteBatchNode::createWithTexture(tex, 29);
    }

    static CCSpriteBatchNode *create(const char *fileImage, unsigned int capacity);
    static CCSpriteBatchNode *create(const char *fileImage)
    {
        return CCSpriteBatchNode::create(fileImage, 29);
    }

    bool initWithTexture(CCTexture2D *tex, unsigned int capacity);

    bool initWithFile(const char *fileImage, unsigned int capacity);
    bool init();

    void increaseAtlasCapacity();

    void removeChildAtIndex(unsigned int index, bool doCleanup);

    void insertChild(CCSprite *child, unsigned int index);
    void appendChild(CCSprite *sprite);
    void removeSpriteFromAtlas(CCSprite *sprite);

    unsigned int rebuildIndexInOrder(CCSprite *parent, unsigned int index);
    unsigned int highestAtlasIndexInChild(CCSprite *sprite);
    unsigned int lowestAtlasIndexInChild(CCSprite *sprite);
    unsigned int atlasIndexForChild(CCSprite *sprite, int z);

    void reorderBatch(bool reorder);

    virtual CCTexture2D *getTexture(void);
    virtual void setTexture(CCTexture2D *texture);
    virtual void setBlendFunc(ccBlendFunc blendFunc);

    virtual ccBlendFunc getBlendFunc(void);

    virtual void visit(void);
    virtual void addChild(CCNode *child);
    virtual void addChild(CCNode *child, int zOrder);
    virtual void addChild(CCNode *child, int zOrder, int tag);
    virtual void reorderChild(CCNode *child, int zOrder);

    virtual void removeChild(CCNode *child, bool cleanup);
    virtual void removeAllChildrenWithCleanup(bool cleanup);
    virtual void sortAllChildren();
    virtual void draw(void);

protected:
    void insertQuadFromSprite(CCSprite *sprite, unsigned int index);

    void updateQuadFromSprite(CCSprite *sprite, unsigned int index);

    CCSpriteBatchNode *addSpriteWithoutQuad(CCSprite *child, unsigned int z, int aTag);

private:
    void updateAtlasIndex(CCSprite *sprite, int *curIndex);
    void swap(int oldIndex, int newIndex);
    void updateBlendFunc();

protected:
    CCTextureAtlas *m_pobTextureAtlas;
    ccBlendFunc m_blendFunc;

    CCArray *m_pobDescendants;

    bool m_bManualSortChildren;
    bool m_bManualSortAllChildrenDirty;
};
// #line 38 "cocos2d/cocos-headers/cocos2dx/label_nodes/CCLabelBMFont.h"
#include <map>
#include <sstream>
#include <iostream>
#include <vector>
// #line 52 "cocos2d/cocos-headers/cocos2dx/label_nodes/CCLabelBMFont.h"
enum
{
    kCCLabelAutomaticWidth = -1,
};

struct _FontDefHashElement;

typedef struct _BMFontDef
{

    unsigned int charID;

    CCRect rect;

    short xOffset;

    short yOffset;

    short xAdvance;
} ccBMFontDef;

typedef struct _BMFontPadding
{

    int left;

    int top;

    int right;

    int bottom;
} ccBMFontPadding;

typedef struct _FontDefHashElement
{
    unsigned int key;
    ccBMFontDef fontDef;
    UT_hash_handle hh;
} tCCFontDefHashElement;

typedef struct _KerningHashElement
{
    int key;
    int amount;
    UT_hash_handle hh;
} tCCKerningHashElement;

class CCBMFontConfiguration : public CCObject
{

public:
    tCCFontDefHashElement *m_pFontDefDictionary;

    int m_nCommonHeight;

    ccBMFontPadding m_tPadding;

    std::string m_sAtlasName;

    tCCKerningHashElement *m_pKerningDictionary;

    std::set<unsigned int> *m_pCharacterSet;

public:
    CCBMFontConfiguration();

    virtual ~CCBMFontConfiguration();

    const char *description();

    static CCBMFontConfiguration *create(const char *FNTfile);

    bool initWithFNTfile(const char *FNTfile);

    inline const char *getAtlasName() { return m_sAtlasName.c_str(); }
    inline void setAtlasName(const char *atlasName) { m_sAtlasName = atlasName; }

    std::set<unsigned int> *getCharacterSet() const;

private:
    std::set<unsigned int> *parseConfigFile(const char *controlFile);
    void parseCharacterDefinition(std::string line, ccBMFontDef *characterDefinition);
    void parseInfoArguments(std::string line);
    void parseCommonArguments(std::string line);
    void parseImageFileName(std::string line, const char *fntFile);
    void parseKerningEntry(std::string line);
    void purgeKerningDictionary();
    void purgeFontDefDictionary();
};
// #line 192 "cocos2d/cocos-headers/cocos2dx/label_nodes/CCLabelBMFont.h"
class CCLabelBMFont : public CCSpriteBatchNode, public CCLabelProtocol, public CCRGBAProtocol
{
public:
    CCLabelBMFont();

    virtual ~CCLabelBMFont();

    static void purgeCachedData();

    static CCLabelBMFont *create(const char *str, const char *fntFile, float width, CCTextAlignment alignment, CCPoint imageOffset);

    static CCLabelBMFont *create(const char *str, const char *fntFile, float width, CCTextAlignment alignment);

    static CCLabelBMFont *create(const char *str, const char *fntFile, float width);

    static CCLabelBMFont *create(const char *str, const char *fntFile);

    static CCLabelBMFont *create();

    bool init();

    bool initWithString(const char *str, const char *fntFile, float width = kCCLabelAutomaticWidth, CCTextAlignment alignment = kCCTextAlignmentLeft, CCPoint imageOffset = CCPointZero);

    void createFontChars();

    virtual void setString(const char *newString);
    virtual void setString(const char *newString, bool needUpdateLabel);

    virtual const char *getString(void);
    virtual void setCString(const char *label);
    virtual void setAnchorPoint(const CCPoint &var);
    virtual void updateLabel();
    virtual void setAlignment(CCTextAlignment alignment);
    virtual void setWidth(float width);
    virtual void setLineBreakWithoutSpace(bool breakWithoutSpace);
    virtual void setScale(float scale);
    virtual void setScaleX(float scaleX);
    virtual void setScaleY(float scaleY);

    virtual bool isOpacityModifyRGB();
    virtual void setOpacityModifyRGB(bool isOpacityModifyRGB);
    virtual GLubyte getOpacity();
    virtual GLubyte getDisplayedOpacity();
    virtual void setOpacity(GLubyte opacity);
    virtual void updateDisplayedOpacity(GLubyte parentOpacity);
    virtual bool isCascadeOpacityEnabled();
    virtual void setCascadeOpacityEnabled(bool cascadeOpacityEnabled);
    virtual const ccColor3B &getColor(void);
    virtual const ccColor3B &getDisplayedColor();
    virtual void setColor(const ccColor3B &color);
    virtual void updateDisplayedColor(const ccColor3B &parentColor);
    virtual bool isCascadeColorEnabled();
    virtual void setCascadeColorEnabled(bool cascadeColorEnabled);

    void setFntFile(const char *fntFile);
    const char *getFntFile();
    CCBMFontConfiguration *getConfiguration() const;

    static CCLabelBMFont *createBatched(const char *str, const char *fntFile, CCArray *);
    void limitLabelWidth(float width, float defaultScale, float minScale);

private:
    char *atlasNameFromFntFile(const char *fntFile);
    int kerningAmountForFirst(unsigned short first, unsigned short second);
    float getLetterPosXLeft(CCSprite *characterSprite);
    float getLetterPosXRight(CCSprite *characterSprite);

protected:
    virtual void setString(unsigned short *newString, bool needUpdateLabel);

    unsigned short *m_sString;

    std::string m_sFntFile;

    unsigned short *m_sInitialString;
    std::string m_sInitialStringUTF8;

    CCTextAlignment m_pAlignment;

    float m_fWidth;

    CCBMFontConfiguration *m_pConfiguration;

    bool m_bLineBreakWithoutSpaces;

    CCPoint m_tImageOffset;

    CCSprite *m_pReusedChar;

    GLubyte m_cDisplayedOpacity;
    GLubyte m_cRealOpacity;
    ccColor3B m_tDisplayedColor;
    ccColor3B m_tRealColor;
    bool m_bCascadeColorEnabled;
    bool m_bCascadeOpacityEnabled;

    bool m_bIsOpacityModifyRGB;

    bool m_bIsBatched;
    CCArray *m_pTargetArray;
    CCTexture2D *m_pSomeTexture;
};

CCBMFontConfiguration *FNTConfigLoadFile(const char *file);

void FNTConfigRemoveCache(void);
// #line 34 "cocos2d/cocos-headers/cocos2dx/touch_dispatcher/CCTouchDelegateProtocol.h"
class CCTouch;
class CCEvent;
class CCSet;
class CCTouchDispatcher;
// #line 46 "cocos2d/cocos-headers/cocos2dx/touch_dispatcher/CCTouchDelegateProtocol.h"
class CCTouchDelegate
{
public:
    CCTouchDelegate() {}

    virtual ~CCTouchDelegate()
    {
    }

    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);

    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent);
};
// #line 86 "cocos2d/cocos-headers/cocos2dx/touch_dispatcher/CCTouchDelegateProtocol.h"
class CCTargetedTouchDelegate : public CCTouchDelegate
{
public:
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
};
// #line 106 "cocos2d/cocos-headers/cocos2dx/touch_dispatcher/CCTouchDelegateProtocol.h"
class CCStandardTouchDelegate : public CCTouchDelegate
{
public:
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent);
};
// #line 34 "cocos2d/cocos-headers/cocos2dx/platform/CCAccelerometerDelegate.h"
class CCAcceleration
{
public:
    double x;
    double y;
    double z;

    double timestamp;
};
// #line 51 "cocos2d/cocos-headers/cocos2dx/platform/CCAccelerometerDelegate.h"
class CCAccelerometerDelegate
{
public:
    virtual void didAccelerate(CCAcceleration *pAccelerationValue);
};
// #line 7 "cocos2d/cocos-headers/cocos2dx/robtop/keyboard_dispatcher/CCKeyboardDelegate.h"
typedef enum
{
    KEY_None = 0x00,
    KEY_Backspace = 0x08,
    KEY_Tab = 0x09,
    KEY_Clear = 0x0C,
    KEY_Enter = 0x0D,
    KEY_Shift = 0x10,
    KEY_Control = 0x11,
    KEY_Alt = 0x12,
    KEY_Pause = 0x13,
    KEY_CapsLock = 0x14,
    KEY_Escape = 0x1B,
    KEY_Space = 0x20,
    KEY_PageUp = 0x21,
    KEY_PageDown = 0x22,
    KEY_End = 0x23,
    KEY_Home = 0x24,
    KEY_Left = 0x25,
    KEY_Up = 0x26,
    KEY_Right = 0x27,
    KEY_Down = 0x28,
    KEY_Select = 0x29,
    KEY_Print = 0x2A,
    KEY_Execute = 0x2B,
    KEY_PrintScreen = 0x2C,
    KEY_Insert = 0x2D,
    KEY_Delete = 0x2E,
    KEY_Help = 0x2F,
    KEY_Zero = 0x30,
    KEY_One = 0x31,
    KEY_Two = 0x32,
    KEY_Three = 0x33,
    KEY_Four = 0x34,
    KEY_Five = 0x35,
    KEY_Six = 0x36,
    KEY_Seven = 0x37,
    KEY_Eight = 0x38,
    KEY_Nine = 0x39,
    KEY_A = 0x41,
    KEY_B = 0x42,
    KEY_C = 0x43,
    KEY_D = 0x44,
    KEY_E = 0x45,
    KEY_F = 0x46,
    KEY_G = 0x47,
    KEY_H = 0x48,
    KEY_I = 0x49,
    KEY_J = 0x4A,
    KEY_K = 0x4B,
    KEY_L = 0x4C,
    KEY_M = 0x4D,
    KEY_N = 0x4E,
    KEY_O = 0x4F,
    KEY_P = 0x50,
    KEY_Q = 0x51,
    KEY_R = 0x52,
    KEY_S = 0x53,
    KEY_T = 0x54,
    KEY_U = 0x55,
    KEY_V = 0x56,
    KEY_W = 0x57,
    KEY_X = 0x58,
    KEY_Y = 0x59,
    KEY_Z = 0x5A,
    KEY_LeftWindowsKey = 0x5B,
    KEY_RightWindowsKey = 0x5C,
    KEY_ApplicationsKey = 0x5D,
    KEY_Sleep = 0x5F,
    KEY_NumPad0 = 0x60,
    KEY_NumPad1 = 0x61,
    KEY_NumPad2 = 0x62,
    KEY_NumPad3 = 0x63,
    KEY_NumPad4 = 0x64,
    KEY_NumPad5 = 0x65,
    KEY_NumPad6 = 0x66,
    KEY_NumPad7 = 0x67,
    KEY_NumPad8 = 0x68,
    KEY_NumPad9 = 0x69,
    KEY_Multiply = 0x6A,
    KEY_Add = 0x6B,
    KEY_Seperator = 0x6C,
    KEY_Subtract = 0x6D,
    KEY_Decimal = 0x6E,
    KEY_Divide = 0x6F,
    KEY_F1 = 0x70,
    KEY_F2 = 0x71,
    KEY_F3 = 0x72,
    KEY_F4 = 0x73,
    KEY_F5 = 0x74,
    KEY_F6 = 0x75,
    KEY_F7 = 0x76,
    KEY_F8 = 0x77,
    KEY_F9 = 0x78,
    KEY_F10 = 0x79,
    KEY_F11 = 0x7A,
    KEY_F12 = 0x7B,
    KEY_F13 = 0x7C,
    KEY_F14 = 0x7D,
    KEY_F15 = 0x7E,
    KEY_F16 = 0x7F,
    KEY_F17 = 0x80,
    KEY_F18 = 0x81,
    KEY_F19 = 0x82,
    KEY_F20 = 0x83,
    KEY_F21 = 0x84,
    KEY_F22 = 0x85,
    KEY_F23 = 0x86,
    KEY_F24 = 0x87,
    KEY_Numlock = 0x90,
    KEY_ScrollLock = 0x91,
    KEY_LeftShift = 0xA0,
    KEY_RightShift = 0xA1,
    KEY_LeftControl = 0xA2,
    KEY_RightContol = 0xA3,
    KEY_LeftMenu = 0xA4,
    KEY_RightMenu = 0xA5,
    KEY_BrowserBack = 0xA6,
    KEY_BrowserForward = 0xA7,
    KEY_BrowserRefresh = 0xA8,
    KEY_BrowserStop = 0xA9,
    KEY_BrowserSearch = 0xAA,
    KEY_BrowserFavorites = 0xAB,
    KEY_BrowserHome = 0xAC,
    KEY_VolumeMute = 0xAD,
    KEY_VolumeDown = 0xAE,
    KEY_VolumeUp = 0xAF,
    KEY_NextTrack = 0xB0,
    KEY_PreviousTrack = 0xB1,
    KEY_StopMedia = 0xB2,
    KEY_PlayPause = 0xB3,
    KEY_LaunchMail = 0xB4,
    KEY_SelectMedia = 0xB5,
    KEY_LaunchApp1 = 0xB6,
    KEY_LaunchApp2 = 0xB7,
    KEY_OEM1 = 0xBA,
    KEY_OEMPlus = 0xB8,
    KEY_OEMComma = 0xBC,
    KEY_OEMMinus = 0xBD,
    KEY_OEMPeriod = 0xBE,
    KEY_OEM2 = 0xBF,
    KEY_OEM3 = 0xC0,
    KEY_OEM4 = 0xDB,
    KEY_OEM5 = 0xDC,
    KEY_OEM6 = 0xDD,
    KEY_OEM7 = 0xDE,
    KEY_OEM8 = 0xDF,
    KEY_OEM102 = 0xE2,
    KEY_Process = 0xE5,
    KEY_Packet = 0xE7,
    KEY_Attn = 0xF6,
    KEY_CrSel = 0xF7,
    KEY_ExSel = 0xF8,
    KEY_EraseEOF = 0xF9,
    KEY_Play = 0xFA,
    KEY_Zoom = 0xFB,
    KEY_PA1 = 0xFD,
    KEY_OEMClear = 0xFE,
    KEY_ArrowUp = 0x11B,
    KEY_ArrowDown = 0x11C,
    KEY_ArrowLeft = 0x11D,
    KEY_ArrowRight = 0x11E,
    CONTROLLER_A = 0x3E9,
    CONTROLLER_B = 0x3EA,
    CONTROLLER_Y = 0x3EB,
    CONTROLLER_X = 0x3EC,
    CONTROLLER_Start = 0x3ED,
    CONTROLLER_Back = 0x3EE,
    CONTROLLER_RB = 0x3EF,
    CONTROLLER_LB = 0x3F0,
    CONTROLLER_RT = 0x3F1,
    CONTROLLER_LT = 0x3F2,
    CONTROLLER_Up = 0x3F3,
    CONTROLLER_Down = 0x3F4,
    CONTROLLER_Left = 0x3F5,
    CONTROLLER_Right = 0x3F6
} enumKeyCodes;
class CCKeyboardDelegate
{
public:
    CCKeyboardDelegate(const CCKeyboardDelegate &);
    CCKeyboardDelegate();
    CCKeyboardDelegate &operator=(const CCKeyboardDelegate &);
    virtual void keyDown(enumKeyCodes key);
    virtual void keyUp(enumKeyCodes key);
};
class CCKeyboardHandler : public CCObject
{
public:
    CCKeyboardHandler(const CCKeyboardHandler &);
    CCKeyboardHandler();
    virtual ~CCKeyboardHandler();
    CCKeyboardHandler &operator=(const CCKeyboardHandler &);
    CCKeyboardDelegate *getDelegate();
    static CCKeyboardHandler *handlerWithDelegate(CCKeyboardDelegate *pDelegate);
    virtual bool initWithDelegate(CCKeyboardDelegate *pDelegate);
    void setDelegate(CCKeyboardDelegate *pDelegate);

protected:
    CCKeyboardDelegate *m_pDelegate;
};
// #line 7 "cocos2d/cocos-headers/cocos2dx/robtop/mouse_dispatcher/CCMouseDelegate.h"
class CCMouseDelegate
{
public:
    CCMouseDelegate(const CCMouseDelegate &);
    CCMouseDelegate();
    CCMouseDelegate &operator=(const CCMouseDelegate &);
    virtual void rightKeyDown();
    virtual void rightKeyUp();
    virtual void scrollWheel(float x, float y);
};
class CCMouseHandler : public CCObject
{
public:
    CCMouseHandler(const CCMouseHandler &);
    CCMouseHandler();
    virtual ~CCMouseHandler();
    CCMouseHandler &operator=(const CCMouseHandler &);
    CCMouseDelegate *getDelegate();
    static CCMouseHandler *handlerWithDelegate(CCMouseDelegate *pDelegate);
    virtual bool initWithDelegate(CCMouseDelegate *pDelegate);
    void setDelegate(CCMouseDelegate *pDelegate);

protected:
    CCMouseDelegate *m_pDelegate;
};
// #line 48 "cocos2d/cocos-headers/cocos2dx/layers_scenes_transitions_nodes/CCLayer.h"
typedef enum
{
    kCCTouchesAllAtOnce,
    kCCTouchesOneByOne,
} ccTouchesMode;

class CCTouchScriptHandlerEntry;
// #line 69 "cocos2d/cocos-headers/cocos2dx/layers_scenes_transitions_nodes/CCLayer.h"
class CCLayer : public CCNode, public CCTouchDelegate, public CCAccelerometerDelegate, public CCKeypadDelegate, public CCKeyboardDelegate, public CCMouseDelegate
{
public:
    CCLayer();

    virtual ~CCLayer();
    virtual bool init();

    static CCLayer *create(void);

    virtual void onEnter();

    virtual void onExit();

    virtual void onEnterTransitionDidFinish();

    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);

    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent);

    virtual void didAccelerate(CCAcceleration *pAccelerationValue);
    void registerScriptAccelerateHandler(int nHandler);
    void unregisterScriptAccelerateHandler(void);
    // #line 131 "cocos2d/cocos-headers/cocos2dx/layers_scenes_transitions_nodes/CCLayer.h"
    virtual void registerWithTouchDispatcher(void);

    virtual void registerScriptTouchHandler(int nHandler, bool bIsMultiTouches = false, int nPriority = INT_MIN, bool bSwallowsTouches = false);

    virtual void unregisterScriptTouchHandler(void);

    virtual bool isTouchEnabled();
    virtual void setTouchEnabled(bool value);

    virtual void setTouchMode(ccTouchesMode mode);
    virtual int getTouchMode();

    virtual void setTouchPriority(int priority);
    virtual int getTouchPriority();

    virtual bool isAccelerometerEnabled();
    virtual void setAccelerometerEnabled(bool value);
    virtual void setAccelerometerInterval(double interval);

    virtual bool isKeypadEnabled();
    virtual void setKeypadEnabled(bool value);

    virtual bool isKeyboardEnabled();
    virtual void setKeyboardEnabled(bool value);
    virtual bool isMouseEnabled();
    virtual void setMouseEnabled(bool value);
    // #line 177 "cocos2d/cocos-headers/cocos2dx/layers_scenes_transitions_nodes/CCLayer.h"
    void registerScriptKeypadHandler(int nHandler);

    void unregisterScriptKeypadHandler(void);

    virtual void keyBackClicked(void);
    virtual void keyMenuClicked(void);

    void keyDown(enumKeyCodes);

    inline CCTouchScriptHandlerEntry *getScriptTouchHandlerEntry() { return m_pScriptTouchHandlerEntry; };
    inline CCScriptHandlerEntry *getScriptKeypadHandlerEntry() { return m_pScriptKeypadHandlerEntry; };
    inline CCScriptHandlerEntry *getScriptAccelerateHandlerEntry() { return m_pScriptAccelerateHandlerEntry; };

protected:
    bool m_bTouchEnabled;
    bool m_bAccelerometerEnabled;
    bool m_bKeypadEnabled;
    bool m_bKeyboardEnabled;
    bool m_bMouseEnabled;

private:
    CCTouchScriptHandlerEntry *m_pScriptTouchHandlerEntry;
    CCScriptHandlerEntry *m_pScriptKeypadHandlerEntry;
    CCScriptHandlerEntry *m_pScriptAccelerateHandlerEntry;

    int m_nTouchPriority;
    ccTouchesMode m_eTouchMode;

    int excuteScriptTouchHandler(int nEventType, CCTouch *pTouch);
    int excuteScriptTouchHandler(int nEventType, CCSet *pTouches);
};
// #line 225 "cocos2d/cocos-headers/cocos2dx/layers_scenes_transitions_nodes/CCLayer.h"
class CCLayerRGBA : public CCLayer, public CCRGBAProtocol
{
public:
    static CCLayerRGBA *create()
    {
        CCLayerRGBA *pRet = new CCLayerRGBA();
        if (pRet && pRet->init())
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    };

    CCLayerRGBA();

    virtual ~CCLayerRGBA();

    virtual bool init();

    virtual GLubyte getOpacity();
    virtual GLubyte getDisplayedOpacity();
    virtual void setOpacity(GLubyte opacity);
    virtual void updateDisplayedOpacity(GLubyte parentOpacity);
    virtual bool isCascadeOpacityEnabled();
    virtual void setCascadeOpacityEnabled(bool cascadeOpacityEnabled);

    virtual const ccColor3B &getColor();
    virtual const ccColor3B &getDisplayedColor();
    virtual void setColor(const ccColor3B &color);
    virtual void updateDisplayedColor(const ccColor3B &parentColor);
    virtual bool isCascadeColorEnabled();
    virtual void setCascadeColorEnabled(bool cascadeColorEnabled);

    virtual void setOpacityModifyRGB(bool bValue);
    virtual bool isOpacityModifyRGB() { return false; }

protected:
    GLubyte _displayedOpacity, _realOpacity;
    ccColor3B _displayedColor, _realColor;
    bool _cascadeOpacityEnabled, _cascadeColorEnabled;
};
// #line 272 "cocos2d/cocos-headers/cocos2dx/layers_scenes_transitions_nodes/CCLayer.h"
class CCLayerColor : public CCLayerRGBA, public CCBlendProtocol

{
protected:
    ccVertex2F m_pSquareVertices[4];
    ccColor4F m_pSquareColors[4];

public:
    CCLayerColor();

    virtual ~CCLayerColor();

    virtual void draw();
    virtual void setContentSize(const CCSize &var);

    static CCLayerColor *create();

    static CCLayerColor *create(const ccColor4B &color, GLfloat width, GLfloat height);

    static CCLayerColor *create(const ccColor4B &color);

    virtual bool init();

    virtual bool initWithColor(const ccColor4B &color, GLfloat width, GLfloat height);

    virtual bool initWithColor(const ccColor4B &color);

    void changeWidth(GLfloat w);

    void changeHeight(GLfloat h);

    void changeWidthAndHeight(GLfloat w, GLfloat h);

protected:
    ccBlendFunc m_tBlendFunc;

public:
    virtual ccBlendFunc getBlendFunc(void);

public:
    virtual void setBlendFunc(ccBlendFunc var);

    virtual void setColor(const ccColor3B &color);
    virtual void setOpacity(GLubyte opacity);

protected:
    virtual void updateColor();
};
// #line 349 "cocos2d/cocos-headers/cocos2dx/layers_scenes_transitions_nodes/CCLayer.h"
class CCLayerGradient : public CCLayerColor
{
public:
    static CCLayerGradient *create(const ccColor4B &start, const ccColor4B &end);

    static CCLayerGradient *create(const ccColor4B &start, const ccColor4B &end, const CCPoint &v);

    virtual bool init();

    virtual bool initWithColor(const ccColor4B &start, const ccColor4B &end);

    virtual bool initWithColor(const ccColor4B &start, const ccColor4B &end, const CCPoint &v);

protected:
    ccColor3B m_startColor;

public:
    virtual const ccColor3B &getStartColor(void);

public:
    virtual void setStartColor(const ccColor3B &var);

protected:
    ccColor3B m_endColor;

public:
    virtual const ccColor3B &getEndColor(void);

public:
    virtual void setEndColor(const ccColor3B &var);

protected:
    GLubyte m_cStartOpacity;

public:
    virtual GLubyte getStartOpacity(void);

public:
    virtual void setStartOpacity(GLubyte var);

protected:
    GLubyte m_cEndOpacity;

public:
    virtual GLubyte getEndOpacity(void);

public:
    virtual void setEndOpacity(GLubyte var);

protected:
    CCPoint m_AlongVector;

public:
    virtual const CCPoint &getVector(void);

public:
    virtual void setVector(const CCPoint &var);

protected:
    bool m_bCompressedInterpolation;

public:
    virtual void setCompressedInterpolation(bool bCompressedInterpolation);
    virtual bool isCompressedInterpolation();

    static CCLayerGradient *create();

protected:
    virtual void updateColor();
};
// #line 397 "cocos2d/cocos-headers/cocos2dx/layers_scenes_transitions_nodes/CCLayer.h"
class CCLayerMultiplex : public CCLayer
{
protected:
    unsigned int m_nEnabledLayer;
    CCArray *m_pLayers;

public:
    CCLayerMultiplex();

    virtual ~CCLayerMultiplex();

    static CCLayerMultiplex *create();

    static CCLayerMultiplex *createWithArray(CCArray *arrayOfLayers);

    static CCLayerMultiplex *create(CCLayer *layer, ...);

    static CCLayerMultiplex *createWithLayer(CCLayer *layer);

    void addLayer(CCLayer *layer);

    bool initWithLayers(CCLayer *layer, va_list params);
    // #line 450 "cocos2d/cocos-headers/cocos2dx/layers_scenes_transitions_nodes/CCLayer.h"
    bool initWithArray(CCArray *arrayOfLayers);

    void switchTo(unsigned int n);

    void switchToAndReleaseMe(unsigned int n);
};
// #line 49 "cocos2d/cocos-headers/cocos2dx/layers_scenes_transitions_nodes/CCScene.h"
class CCScene : public CCNode
{
public:
    CCScene();

    virtual ~CCScene();
    bool init();

    static CCScene *create(void);

    CCScene(const CCScene &);
    CCScene &operator=(const CCScene &);
    int getHighestChildZ(void);

protected:
    void *m_pIDK;
    // #line 75 "cocos2d/cocos-headers/cocos2dx/layers_scenes_transitions_nodes/CCScene.h"
};
// #line 44 "cocos2d/cocos-headers/cocos2dx/layers_scenes_transitions_nodes/CCTransition.h"
class CCActionInterval;
class CCNode;

class CCTransitionEaseScene
{
public:
    virtual CCActionInterval *easeActionWithAction(CCActionInterval *action) = 0;
};

typedef enum
{

    kCCTransitionOrientationLeftOver = 0,

    kCCTransitionOrientationRightOver = 1,

    kCCTransitionOrientationUpOver = 0,

    kCCTransitionOrientationDownOver = 1,
    // #line 76 "cocos2d/cocos-headers/cocos2dx/layers_scenes_transitions_nodes/CCTransition.h"
} tOrientation;

class CCTransitionScene : public CCScene
{

protected:
    CCScene *m_pInScene;
    CCScene *m_pOutScene;
    float m_fDuration;
    bool m_bIsInSceneOnTop;
    bool m_bIsSendCleanupToScene;

public:
    CCTransitionScene();

    virtual ~CCTransitionScene();
    virtual void draw();

    virtual void onEnter();

    virtual void onExit();
    virtual void cleanup();

    static CCTransitionScene *create(float t, CCScene *scene);

    virtual bool initWithDuration(float t, CCScene *scene);

    void finish(void);

    void hideOutShowIn(void);

protected:
    virtual void sceneOrder();

private:
    void setNewScene(float dt);
};

class CCTransitionSceneOriented : public CCTransitionScene
{
protected:
    tOrientation m_eOrientation;

public:
    CCTransitionSceneOriented();

    virtual ~CCTransitionSceneOriented();

    static CCTransitionSceneOriented *create(float t, CCScene *scene, tOrientation orientation);

    virtual bool initWithDuration(float t, CCScene *scene, tOrientation orientation);
};

class CCTransitionRotoZoom : public CCTransitionScene
{
public:
    CCTransitionRotoZoom();

    virtual ~CCTransitionRotoZoom();

    virtual void onEnter();

    static CCTransitionRotoZoom *create(float t, CCScene *scene);
};

class CCTransitionJumpZoom : public CCTransitionScene
{
public:
    CCTransitionJumpZoom();

    virtual ~CCTransitionJumpZoom();

    virtual void onEnter();

    static CCTransitionJumpZoom *create(float t, CCScene *scene);
};

class CCTransitionMoveInL : public CCTransitionScene, public CCTransitionEaseScene
{
public:
    CCTransitionMoveInL();

    virtual ~CCTransitionMoveInL();

    virtual void initScenes(void);

    virtual CCActionInterval *action(void);

    virtual CCActionInterval *easeActionWithAction(CCActionInterval *action);

    virtual void onEnter();

    static CCTransitionMoveInL *create(float t, CCScene *scene);
};

class CCTransitionMoveInR : public CCTransitionMoveInL
{
public:
    CCTransitionMoveInR();

    virtual ~CCTransitionMoveInR();
    virtual void initScenes();

    static CCTransitionMoveInR *create(float t, CCScene *scene);
};

class CCTransitionMoveInT : public CCTransitionMoveInL
{
public:
    CCTransitionMoveInT();

    virtual ~CCTransitionMoveInT();
    virtual void initScenes();

    static CCTransitionMoveInT *create(float t, CCScene *scene);
};

class CCTransitionMoveInB : public CCTransitionMoveInL
{
public:
    CCTransitionMoveInB();

    virtual ~CCTransitionMoveInB();
    virtual void initScenes();

    static CCTransitionMoveInB *create(float t, CCScene *scene);
};

class CCTransitionSlideInL : public CCTransitionScene, public CCTransitionEaseScene
{
public:
    CCTransitionSlideInL();

    virtual ~CCTransitionSlideInL();

    virtual void initScenes(void);

    virtual CCActionInterval *action(void);

    virtual void onEnter();

    virtual CCActionInterval *easeActionWithAction(CCActionInterval *action);

    static CCTransitionSlideInL *create(float t, CCScene *scene);

protected:
    virtual void sceneOrder();
};

class CCTransitionSlideInR : public CCTransitionSlideInL
{
public:
    CCTransitionSlideInR();

    virtual ~CCTransitionSlideInR();

    virtual void initScenes(void);

    virtual CCActionInterval *action(void);

    static CCTransitionSlideInR *create(float t, CCScene *scene);

protected:
    virtual void sceneOrder();
};

class CCTransitionSlideInB : public CCTransitionSlideInL
{
public:
    CCTransitionSlideInB();

    virtual ~CCTransitionSlideInB();

    virtual void initScenes(void);

    virtual CCActionInterval *action(void);

    static CCTransitionSlideInB *create(float t, CCScene *scene);

protected:
    virtual void sceneOrder();
};

class CCTransitionSlideInT : public CCTransitionSlideInL
{
public:
    CCTransitionSlideInT();

    virtual ~CCTransitionSlideInT();

    virtual void initScenes(void);

    virtual CCActionInterval *action(void);

    static CCTransitionSlideInT *create(float t, CCScene *scene);

protected:
    virtual void sceneOrder();
};

class CCTransitionShrinkGrow : public CCTransitionScene, public CCTransitionEaseScene
{
public:
    CCTransitionShrinkGrow();

    virtual ~CCTransitionShrinkGrow();

    virtual void onEnter();
    virtual CCActionInterval *easeActionWithAction(CCActionInterval *action);

    static CCTransitionShrinkGrow *create(float t, CCScene *scene);
};

class CCTransitionFlipX : public CCTransitionSceneOriented
{
public:
    CCTransitionFlipX();

    virtual ~CCTransitionFlipX();

    virtual void onEnter();

    static CCTransitionFlipX *create(float t, CCScene *s, tOrientation o);
    static CCTransitionFlipX *create(float t, CCScene *s);
};

class CCTransitionFlipY : public CCTransitionSceneOriented
{
public:
    CCTransitionFlipY();

    virtual ~CCTransitionFlipY();

    virtual void onEnter();

    static CCTransitionFlipY *create(float t, CCScene *s, tOrientation o);
    static CCTransitionFlipY *create(float t, CCScene *s);
};

class CCTransitionFlipAngular : public CCTransitionSceneOriented
{
public:
    CCTransitionFlipAngular();

    virtual ~CCTransitionFlipAngular();

    virtual void onEnter();

    static CCTransitionFlipAngular *create(float t, CCScene *s, tOrientation o);
    static CCTransitionFlipAngular *create(float t, CCScene *s);
};

class CCTransitionZoomFlipX : public CCTransitionSceneOriented
{
public:
    CCTransitionZoomFlipX();

    virtual ~CCTransitionZoomFlipX();

    virtual void onEnter();

    static CCTransitionZoomFlipX *create(float t, CCScene *s, tOrientation o);
    static CCTransitionZoomFlipX *create(float t, CCScene *s);
};

class CCTransitionZoomFlipY : public CCTransitionSceneOriented
{
public:
    CCTransitionZoomFlipY();

    virtual ~CCTransitionZoomFlipY();

    virtual void onEnter();

    static CCTransitionZoomFlipY *create(float t, CCScene *s, tOrientation o);
    static CCTransitionZoomFlipY *create(float t, CCScene *s);
};

class CCTransitionZoomFlipAngular : public CCTransitionSceneOriented
{
public:
    CCTransitionZoomFlipAngular();

    virtual ~CCTransitionZoomFlipAngular();

    virtual void onEnter();

    static CCTransitionZoomFlipAngular *create(float t, CCScene *s, tOrientation o);
    static CCTransitionZoomFlipAngular *create(float t, CCScene *s);
};

class CCTransitionFade : public CCTransitionScene
{
protected:
    ccColor4B m_tColor;

public:
    CCTransitionFade();

    virtual ~CCTransitionFade();

    static CCTransitionFade *create(float duration, CCScene *scene, const ccColor3B &color);
    static CCTransitionFade *create(float duration, CCScene *scene);

    virtual bool initWithDuration(float t, CCScene *scene, const ccColor3B &color);

    virtual bool initWithDuration(float t, CCScene *scene);

    virtual void onEnter();

    virtual void onExit();
};

class CCRenderTexture;

class CCTransitionCrossFade : public CCTransitionScene
{
public:
    CCTransitionCrossFade();

    virtual ~CCTransitionCrossFade();

    virtual void draw();

    virtual void onEnter();

    virtual void onExit();

public:
    static CCTransitionCrossFade *create(float t, CCScene *scene);
};

class CCTransitionTurnOffTiles : public CCTransitionScene, public CCTransitionEaseScene
{
public:
    CCTransitionTurnOffTiles();

    virtual ~CCTransitionTurnOffTiles();

    virtual void onEnter();
    virtual CCActionInterval *easeActionWithAction(CCActionInterval *action);

public:
    static CCTransitionTurnOffTiles *create(float t, CCScene *scene);

protected:
    virtual void sceneOrder();
};

class CCTransitionSplitCols : public CCTransitionScene, public CCTransitionEaseScene
{
public:
    CCTransitionSplitCols();

    virtual ~CCTransitionSplitCols();

    virtual CCActionInterval *action(void);

    virtual void onEnter();
    virtual CCActionInterval *easeActionWithAction(CCActionInterval *action);

public:
    static CCTransitionSplitCols *create(float t, CCScene *scene);
};

class CCTransitionSplitRows : public CCTransitionSplitCols
{
public:
    CCTransitionSplitRows();

    virtual ~CCTransitionSplitRows();

    virtual CCActionInterval *action(void);

public:
    static CCTransitionSplitRows *create(float t, CCScene *scene);
};

class CCTransitionFadeTR : public CCTransitionScene, public CCTransitionEaseScene
{
public:
    CCTransitionFadeTR();

    virtual ~CCTransitionFadeTR();
    virtual CCActionInterval *actionWithSize(const CCSize &size);

    virtual void onEnter();
    virtual CCActionInterval *easeActionWithAction(CCActionInterval *action);

public:
    static CCTransitionFadeTR *create(float t, CCScene *scene);

protected:
    virtual void sceneOrder();
};

class CCTransitionFadeBL : public CCTransitionFadeTR
{
public:
    CCTransitionFadeBL();

    virtual ~CCTransitionFadeBL();
    virtual CCActionInterval *actionWithSize(const CCSize &size);

public:
    static CCTransitionFadeBL *create(float t, CCScene *scene);
};

class CCTransitionFadeUp : public CCTransitionFadeTR
{
public:
    CCTransitionFadeUp();

    virtual ~CCTransitionFadeUp();
    virtual CCActionInterval *actionWithSize(const CCSize &size);

public:
    static CCTransitionFadeUp *create(float t, CCScene *scene);
};

class CCTransitionFadeDown : public CCTransitionFadeTR
{
public:
    CCTransitionFadeDown();

    virtual ~CCTransitionFadeDown();
    virtual CCActionInterval *actionWithSize(const CCSize &size);

public:
    static CCTransitionFadeDown *create(float t, CCScene *scene);
};
// #line 49 "cocos2d/cocos-headers/cocos2dx/layers_scenes_transitions_nodes/CCTransitionPageTurn.h"
class CCTransitionPageTurn : public CCTransitionScene
{
protected:
    bool m_bBack;

public:
    CCTransitionPageTurn();

    virtual ~CCTransitionPageTurn();

    static CCTransitionPageTurn *create(float t, CCScene *scene, bool backwards);

    virtual bool initWithDuration(float t, CCScene *scene, bool backwards);

    CCActionInterval *actionWithSize(const CCSize &vector);

    virtual void onEnter();

protected:
    virtual void sceneOrder();
};
// #line 34 "cocos2d/cocos-headers/cocos2dx/layers_scenes_transitions_nodes/CCTransitionProgress.h"
class CCProgressTimer;
class CCRenderTexture;

class CCTransitionProgress : public CCTransitionScene
{
public:
    static CCTransitionProgress *create(float t, CCScene *scene);

    CCTransitionProgress();

    virtual void onEnter();

    virtual void onExit();

protected:
    virtual CCProgressTimer *progressTimerNodeWithRenderTexture(CCRenderTexture *texture);
    virtual void setupTransition();
    virtual void sceneOrder();
    float m_fTo;
    float m_fFrom;
    CCScene *m_pSceneToBeModified;
};

class CCTransitionProgressRadialCCW : public CCTransitionProgress
{
public:
    static CCTransitionProgressRadialCCW *create(float t, CCScene *scene);

protected:
    virtual CCProgressTimer *progressTimerNodeWithRenderTexture(CCRenderTexture *texture);
};

class CCTransitionProgressRadialCW : public CCTransitionProgress
{
public:
    static CCTransitionProgressRadialCW *create(float t, CCScene *scene);

protected:
    virtual CCProgressTimer *progressTimerNodeWithRenderTexture(CCRenderTexture *texture);
};

class CCTransitionProgressHorizontal : public CCTransitionProgress
{
public:
    static CCTransitionProgressHorizontal *create(float t, CCScene *scene);

protected:
    virtual CCProgressTimer *progressTimerNodeWithRenderTexture(CCRenderTexture *texture);
};

class CCTransitionProgressVertical : public CCTransitionProgress
{
public:
    static CCTransitionProgressVertical *create(float t, CCScene *scene);

protected:
    virtual CCProgressTimer *progressTimerNodeWithRenderTexture(CCRenderTexture *texture);
};

class CCTransitionProgressInOut : public CCTransitionProgress
{
public:
    static CCTransitionProgressInOut *create(float t, CCScene *scene);

protected:
    virtual CCProgressTimer *progressTimerNodeWithRenderTexture(CCRenderTexture *texture);
    virtual void sceneOrder();
    virtual void setupTransition();
};

class CCTransitionProgressOutIn : public CCTransitionProgress
{
public:
    static CCTransitionProgressOutIn *create(float t, CCScene *scene);

protected:
    virtual CCProgressTimer *progressTimerNodeWithRenderTexture(CCRenderTexture *texture);
};
// #line 36 "cocos2d/cocos-headers/cocos2dx/menu_nodes/CCMenuItem.h"
class CCLabelTTF;
class CCLabelAtlas;
class CCSprite;
class CCSpriteFrame;
// #line 53 "cocos2d/cocos-headers/cocos2dx/menu_nodes/CCMenuItem.h"
class CCMenuItem : public CCNodeRGBA
{
protected:
    bool m_bSelected;
    bool m_bEnabled;

public:
    CCMenuItem()
        : m_bSelected(false), m_bEnabled(false), m_pListener(NULL), m_pfnSelector(NULL), m_nScriptTapHandler(0)
    {
    }

    virtual ~CCMenuItem();

    static CCMenuItem *create();

    static CCMenuItem *create(CCObject *rec, SEL_MenuHandler selector);

    bool initWithTarget(CCObject *rec, SEL_MenuHandler selector);

    CCRect rect();

    virtual void activate();

    virtual void selected();

    virtual void unselected();

    virtual void registerScriptTapHandler(int nHandler);
    virtual void unregisterScriptTapHandler(void);
    int getScriptTapHandler() { return m_nScriptTapHandler; };

    virtual bool isEnabled();

    virtual void setEnabled(bool value);
    virtual bool isSelected();

    void setTarget(CCObject *rec, SEL_MenuHandler selector);

protected:
    CCObject *m_pListener;
    SEL_MenuHandler m_pfnSelector;
    int m_nScriptTapHandler;
};
// #line 125 "cocos2d/cocos-headers/cocos2dx/menu_nodes/CCMenuItem.h"
class CCMenuItemLabel : public CCMenuItem
{

protected:
    ccColor3B m_tDisabledColor;

public:
    virtual const ccColor3B &getDisabledColor(void);

public:
    virtual void setDisabledColor(const ccColor3B &var);
    ;

protected:
    CCNode *m_pLabel;

public:
    virtual CCNode *getLabel(void);

public:
    virtual void setLabel(CCNode *var);
    ;

public:
    CCMenuItemLabel()
        : m_pLabel(NULL), m_fOriginalScale(0.0)
    {
    }

    virtual ~CCMenuItemLabel();

    static CCMenuItemLabel *create(CCNode *label, CCObject *target, SEL_MenuHandler selector);

    static CCMenuItemLabel *create(CCNode *label);

    bool initWithLabel(CCNode *label, CCObject *target, SEL_MenuHandler selector);

    void setString(const char *label);

    virtual void activate();
    virtual void selected();
    virtual void unselected();

    virtual void setEnabled(bool enabled);

protected:
    ccColor3B m_tColorBackup;
    float m_fOriginalScale;
};

class CCMenuItemAtlasFont : public CCMenuItemLabel
{
public:
    CCMenuItemAtlasFont() {}

    virtual ~CCMenuItemAtlasFont() {}

    static CCMenuItemAtlasFont *create(const char *value, const char *charMapFile, int itemWidth, int itemHeight, char startCharMap);

    static CCMenuItemAtlasFont *create(const char *value, const char *charMapFile, int itemWidth, int itemHeight, char startCharMap, CCObject *target, SEL_MenuHandler selector);

    bool initWithString(const char *value, const char *charMapFile, int itemWidth, int itemHeight, char startCharMap, CCObject *target, SEL_MenuHandler selector);
};

class CCMenuItemFont : public CCMenuItemLabel
{
public:
    CCMenuItemFont() : m_uFontSize(0), m_strFontName("") {}

    virtual ~CCMenuItemFont() {}

    static void setFontSize(unsigned int s);

    static unsigned int fontSize();

    static void setFontName(const char *name);

    static const char *fontName();

    static CCMenuItemFont *create(const char *value);

    static CCMenuItemFont *create(const char *value, CCObject *target, SEL_MenuHandler selector);

    bool initWithString(const char *value, CCObject *target, SEL_MenuHandler selector);

    void setFontSizeObj(unsigned int s);

    unsigned int fontSizeObj();

    void setFontNameObj(const char *name);

    const char *fontNameObj();

protected:
    void recreateLabel();

    unsigned int m_uFontSize;
    std::string m_strFontName;
};
// #line 271 "cocos2d/cocos-headers/cocos2dx/menu_nodes/CCMenuItem.h"
class CCMenuItemSprite : public CCMenuItem
{

protected:
    CCNode *m_pNormalImage;

public:
    virtual CCNode *getNormalImage(void);

public:
    virtual void setNormalImage(CCNode *var);
    ;

protected:
    CCNode *m_pSelectedImage;

public:
    virtual CCNode *getSelectedImage(void);

public:
    virtual void setSelectedImage(CCNode *var);
    ;

protected:
    CCNode *m_pDisabledImage;

public:
    virtual CCNode *getDisabledImage(void);

public:
    virtual void setDisabledImage(CCNode *var);
    ;

public:
    CCMenuItemSprite()
        : m_pNormalImage(NULL), m_pSelectedImage(NULL), m_pDisabledImage(NULL)
    {
    }

    static CCMenuItemSprite *create(CCNode *normalSprite, CCNode *selectedSprite, CCNode *disabledSprite = NULL);

    static CCMenuItemSprite *create(CCNode *normalSprite, CCNode *selectedSprite, CCObject *target, SEL_MenuHandler selector);

    static CCMenuItemSprite *create(CCNode *normalSprite, CCNode *selectedSprite, CCNode *disabledSprite, CCObject *target, SEL_MenuHandler selector);

    bool initWithNormalSprite(CCNode *normalSprite, CCNode *selectedSprite, CCNode *disabledSprite, CCObject *target, SEL_MenuHandler selector);

    virtual void selected();
    virtual void unselected();
    virtual void setEnabled(bool bEnabled);

protected:
    virtual void updateImagesVisibility();
};
// #line 323 "cocos2d/cocos-headers/cocos2dx/menu_nodes/CCMenuItem.h"
class CCMenuItemImage : public CCMenuItemSprite
{
public:
    CCMenuItemImage() {}

    virtual ~CCMenuItemImage() {}

    static CCMenuItemImage *create(const char *normalImage, const char *selectedImage);

    static CCMenuItemImage *create(const char *normalImage, const char *selectedImage, const char *disabledImage);

    static CCMenuItemImage *create(const char *normalImage, const char *selectedImage, CCObject *target, SEL_MenuHandler selector);

    static CCMenuItemImage *create(const char *normalImage, const char *selectedImage, const char *disabledImage, CCObject *target, SEL_MenuHandler selector);

    bool init();

    bool initWithNormalImage(const char *normalImage, const char *selectedImage, const char *disabledImage, CCObject *target, SEL_MenuHandler selector);

    void setNormalSpriteFrame(CCSpriteFrame *frame);

    void setSelectedSpriteFrame(CCSpriteFrame *frame);

    void setDisabledSpriteFrame(CCSpriteFrame *frame);

    static CCMenuItemImage *create();
};

class CCMenuItemToggle : public CCMenuItem
{

protected:
    unsigned int m_uSelectedIndex;

public:
    virtual unsigned int getSelectedIndex(void);

public:
    virtual void setSelectedIndex(unsigned int var);
    ;

protected:
    CCArray *m_pSubItems;

public:
    virtual CCArray *getSubItems(void);

public:
    virtual void setSubItems(CCArray *var);
    ;

public:
    CCMenuItemToggle()
        : m_uSelectedIndex(0), m_pSubItems(NULL)
    {
    }

    virtual ~CCMenuItemToggle();

    static CCMenuItemToggle *createWithTarget(CCObject *target, SEL_MenuHandler selector, CCArray *menuItems);

    static CCMenuItemToggle *createWithTarget(CCObject *target, SEL_MenuHandler selector, CCMenuItem *item, ...);

    static CCMenuItemToggle *create();

    bool initWithTarget(CCObject *target, SEL_MenuHandler selector, CCMenuItem *item, va_list args);

    static CCMenuItemToggle *create(CCMenuItem *item);

    bool initWithItem(CCMenuItem *item);

    void addSubItem(CCMenuItem *item);

    CCMenuItem *selectedItem();

    virtual void activate();
    virtual void selected();
    virtual void unselected();
    virtual void setEnabled(bool var);
};
// #line 39 "cocos2d/cocos-headers/cocos2dx/menu_nodes/CCMenu.h"
typedef enum
{
    kCCMenuStateWaiting,
    kCCMenuStateTrackingTouch
} tCCMenuState;

enum
{

    kCCMenuHandlerPriority = -128,
};
// #line 56 "cocos2d/cocos-headers/cocos2dx/menu_nodes/CCMenu.h"
class CCMenu : public CCLayerRGBA
{

    bool m_bEnabled;

public:
    CCMenu() : m_pSelectedItem(NULL) {}

    virtual ~CCMenu() {}

    static CCMenu *create();

    static CCMenu *create(CCMenuItem *item, ...);

    static CCMenu *createWithArray(CCArray *pArrayOfItems);

    static CCMenu *createWithItem(CCMenuItem *item);

    static CCMenu *createWithItems(CCMenuItem *firstItem, va_list args);

    bool init();

    bool initWithArray(CCArray *pArrayOfItems);

    void alignItemsVertically();

    void alignItemsVerticallyWithPadding(float padding);

    void alignItemsHorizontally();

    void alignItemsHorizontallyWithPadding(float padding);
    // #line 127 "cocos2d/cocos-headers/cocos2dx/menu_nodes/CCMenu.h"
    void alignItemsInColumns(unsigned int columns, ...);

    void alignItemsInColumns(unsigned int columns, va_list args);

    void alignItemsInColumnsWithArray(CCArray *rows);
    // #line 145 "cocos2d/cocos-headers/cocos2dx/menu_nodes/CCMenu.h"
    void alignItemsInRows(unsigned int rows, ...);

    void alignItemsInRows(unsigned int rows, va_list args);

    void alignItemsInRowsWithArray(CCArray *columns);

    void setHandlerPriority(int newPriority);

    virtual void addChild(CCNode *child);
    virtual void addChild(CCNode *child, int zOrder);
    virtual void addChild(CCNode *child, int zOrder, int tag);
    virtual void registerWithTouchDispatcher();
    virtual void removeChild(CCNode *child, bool cleanup);

    virtual bool ccTouchBegan(CCTouch *touch, CCEvent *event);
    virtual void ccTouchEnded(CCTouch *touch, CCEvent *event);
    virtual void ccTouchCancelled(CCTouch *touch, CCEvent *event);
    virtual void ccTouchMoved(CCTouch *touch, CCEvent *event);
    // #line 180 "cocos2d/cocos-headers/cocos2dx/menu_nodes/CCMenu.h"
    virtual void onExit();

    virtual void setOpacityModifyRGB(bool bValue);
    virtual bool isOpacityModifyRGB(void);

    virtual bool isEnabled() { return m_bEnabled; }
    virtual void setEnabled(bool value) { m_bEnabled = value; };

protected:
    CCMenuItem *itemForTouch(CCTouch *touch);
    tCCMenuState m_eState;
    CCMenuItem *m_pSelectedItem;
};
// #line 32 "cocos2d/cocos-headers/cocos2dx/misc_nodes/CCClippingNode.h"
// #line 41 "cocos2d/cocos-headers/cocos2dx/misc_nodes/CCClippingNode.h"
class CCClippingNode : public CCNode
{
protected:
    CCNode *m_pStencil;
    GLfloat m_fAlphaThreshold;
    bool m_bInverted;

public:
    static CCClippingNode *create();

    static CCClippingNode *create(CCNode *pStencil);

    virtual ~CCClippingNode();

    virtual bool init();

    virtual bool init(CCNode *pStencil);

    virtual void onEnter();

    virtual void onEnterTransitionDidFinish();

    virtual void onExitTransitionDidStart();

    virtual void onExit();
    virtual void visit();

    CCNode *getStencil() const;
    void setStencil(CCNode *pStencil);

    GLfloat getAlphaThreshold() const;
    void setAlphaThreshold(GLfloat fAlphaThreshold);

    bool isInverted() const;
    void setInverted(bool bInverted);

protected:
    CCClippingNode();
};
// #line 46 "cocos2d/cocos-headers/cocos2dx/misc_nodes/CCMotionStreak.h"
class CCMotionStreak : public CCNodeRGBA, public CCTextureProtocol

{
public:
    CCMotionStreak();

    virtual ~CCMotionStreak();

    static CCMotionStreak *create(float fade, float minSeg, float stroke, const ccColor3B &color, const char *path);

    static CCMotionStreak *create(float fade, float minSeg, float stroke, const ccColor3B &color, CCTexture2D *texture);

    bool initWithFade(float fade, float minSeg, float stroke, const ccColor3B &color, const char *path);

    bool initWithFade(float fade, float minSeg, float stroke, const ccColor3B &color, CCTexture2D *texture);

    void tintWithColor(ccColor3B colors);

    void reset();

    virtual void setPosition(const CCPoint &position);
    virtual void draw();
    virtual void update(float delta);

    virtual CCTexture2D *getTexture(void);
    virtual void setTexture(CCTexture2D *texture);

    virtual void setBlendFunc(ccBlendFunc blendFunc);

    virtual ccBlendFunc getBlendFunc(void);
    virtual GLubyte getOpacity(void);
    virtual void setOpacity(GLubyte opacity);
    virtual void setOpacityModifyRGB(bool bValue);
    virtual bool isOpacityModifyRGB(void);

    inline bool isFastMode() { return m_bFastMode; }
    inline void setFastMode(bool bFastMode) { m_bFastMode = bFastMode; }

    inline bool isStartingPositionInitialized() { return m_bStartingPositionInitialized; }
    inline void setStartingPositionInitialized(bool bStartingPositionInitialized)
    {
        m_bStartingPositionInitialized = bStartingPositionInitialized;
    }

protected:
    bool m_bFastMode;
    bool m_bStartingPositionInitialized;

private:
    CCTexture2D *m_pTexture;
    ccBlendFunc m_tBlendFunc;
    CCPoint m_tPositionR;

    float m_fStroke;
    float m_fFadeDelta;
    float m_fMinSeg;

    unsigned int m_uMaxPoints;
    unsigned int m_uNuPoints;
    unsigned int m_uPreviousNuPoints;

    CCPoint *m_pPointVertexes;
    float *m_pPointState;

    ccVertex2F *m_pVertices;
    GLubyte *m_pColorPointer;
    ccTex2F *m_pTexCoords;
};
// #line 43 "cocos2d/cocos-headers/cocos2dx/misc_nodes/CCProgressTimer.h"
typedef enum
{

    kCCProgressTimerTypeRadial,

    kCCProgressTimerTypeBar,
} CCProgressTimerType;
// #line 56 "cocos2d/cocos-headers/cocos2dx/misc_nodes/CCProgressTimer.h"
class CCProgressTimer : public CCNodeRGBA

{
public:
    CCProgressTimer();

    ~CCProgressTimer(void);

    inline CCProgressTimerType getType(void) { return m_eType; }

    inline float getPercentage(void) { return m_fPercentage; }

    inline CCSprite *getSprite(void) { return m_pSprite; }

    bool initWithSprite(CCSprite *sp);

    void setPercentage(float fPercentage);
    void setSprite(CCSprite *pSprite);
    void setType(CCProgressTimerType type);

    void setReverseProgress(bool reverse);

    virtual void draw(void);
    void setAnchorPoint(CCPoint anchorPoint);

    virtual void setColor(const ccColor3B &color);
    virtual const ccColor3B &getColor() const;
    virtual GLubyte getOpacity() const;
    virtual void setOpacity(GLubyte opacity);

    inline bool isReverseDirection() { return m_bReverseDirection; };
    inline void setReverseDirection(bool value) { m_bReverseDirection = value; };

public:
    static CCProgressTimer *create(CCSprite *sp);

protected:
    ccTex2F textureCoordFromAlphaPoint(CCPoint alpha);
    ccVertex2F vertexFromAlphaPoint(CCPoint alpha);
    void updateProgress(void);
    void updateBar(void);
    void updateRadial(void);
    void updateColor(void);
    CCPoint boundaryTexCoord(char index);

protected:
    CCProgressTimerType m_eType;
    float m_fPercentage;
    CCSprite *m_pSprite;
    int m_nVertexDataCount;
    ccV2F_C4B_T2F *m_pVertexData;
    // #line 132 "cocos2d/cocos-headers/cocos2dx/misc_nodes/CCProgressTimer.h"
protected:
    CCPoint m_tMidpoint;

public:
    virtual CCPoint getMidpoint(void);

public:
    virtual void setMidpoint(CCPoint var);
    ;
    // #line 140 "cocos2d/cocos-headers/cocos2dx/misc_nodes/CCProgressTimer.h"
protected:
    CCPoint m_tBarChangeRate;

public:
    virtual CCPoint getBarChangeRate(void) const { return m_tBarChangeRate; }

public:
    virtual void setBarChangeRate(CCPoint var) { m_tBarChangeRate = var; };

    bool m_bReverseDirection;
};
// #line 30 "cocos2d/cocos-headers/cocos2dx/misc_nodes/CCRenderTexture.h"
// #line 39 "cocos2d/cocos-headers/cocos2dx/misc_nodes/CCRenderTexture.h"
typedef enum eImageFormat
{
    kCCImageFormatJPEG = 0,
    kCCImageFormatPNG = 1,
} tCCImageFormat;
// #line 54 "cocos2d/cocos-headers/cocos2dx/misc_nodes/CCRenderTexture.h"
class CCRenderTexture : public CCNode
{

protected:
    CCSprite *m_pSprite;

public:
    virtual CCSprite *getSprite(void);

public:
    virtual void setSprite(CCSprite *var);

public:
    CCRenderTexture();

    virtual ~CCRenderTexture();

    virtual void visit();
    virtual void draw();

    static CCRenderTexture *create(int w, int h, CCTexture2DPixelFormat eFormat, GLuint uDepthStencilFormat);

    static CCRenderTexture *create(int w, int h, CCTexture2DPixelFormat eFormat);

    static CCRenderTexture *create(int w, int h);

    bool initWithWidthAndHeight(int w, int h, CCTexture2DPixelFormat eFormat);

    bool initWithWidthAndHeight(int w, int h, CCTexture2DPixelFormat eFormat, GLuint uDepthStencilFormat);

    void begin();

    void beginWithClear(float r, float g, float b, float a);

    void beginWithClear(float r, float g, float b, float a, float depthValue);

    void beginWithClear(float r, float g, float b, float a, float depthValue, int stencilValue);

    inline void endToLua() { end(); };

    void end();

    void clear(float r, float g, float b, float a);

    void clearDepth(float depthValue);

    void clearStencil(int stencilValue);

    CCImage *newCCImage(bool flipImage = true);

    bool saveToFile(const char *szFilePath);

    bool saveToFile(const char *name, tCCImageFormat format);

    void listenToBackground(CCObject *obj);

    void listenToForeground(CCObject *obj);

    unsigned int getClearFlags() const;
    void setClearFlags(unsigned int uClearFlags);

    const ccColor4F &getClearColor() const;
    void setClearColor(const ccColor4F &clearColor);

    float getClearDepth() const;
    void setClearDepth(float fClearDepth);

    int getClearStencil() const;
    void setClearStencil(float fClearStencil);

    bool isAutoDraw() const;
    void setAutoDraw(bool bAutoDraw);

private:
    void beginWithClear(float r, float g, float b, float a, float depthValue, int stencilValue, GLbitfield flags);

protected:
    GLuint m_uFBO;
    GLuint m_uDepthRenderBufffer;
    GLint m_nOldFBO;
    CCTexture2D *m_pTexture;
    CCTexture2D *m_pTextureCopy;
    CCImage *m_pUITextureImage;
    GLenum m_ePixelFormat;

    GLbitfield m_uClearFlags;
    ccColor4F m_sClearColor;
    GLclampf m_fClearDepth;
    GLint m_nClearStencil;
    bool m_bAutoDraw;
};
// #line 11 "cocos2d/cocos-headers/cocos2dx/platform/CCDevice.h"
class CCDevice
{
private:
    CCDevice();

public:
    static int getDPI();
};
// #line 27 "cocos2d/cocos-headers/cocos2dx/platform/CCFileUtils.h"
#include <string>
#include <vector>
#include <map>

class CCDictionary;
class CCArray;

class CCFileUtils : public TypeInfo
{
    friend class CCArray;
    friend class CCDictionary;

public:
    // #line 56 "cocos2d/cocos-headers/cocos2dx/platform/CCFileUtils.h"
    virtual long getClassTypeInfo()
    {
        static const long id = getHashCodeByString(typeid(CCFileUtils).name());
        return id;
    }

    static CCFileUtils *sharedFileUtils();

    static void purgeFileUtils();

    virtual ~CCFileUtils();
    // #line 87 "cocos2d/cocos-headers/cocos2dx/platform/CCFileUtils.h"
    virtual void purgeCachedEntries();
    // #line 99 "cocos2d/cocos-headers/cocos2dx/platform/CCFileUtils.h"
    virtual unsigned char *getFileData(const char *pszFileName, const char *pszMode, unsigned long *pSize);
    // #line 110 "cocos2d/cocos-headers/cocos2dx/platform/CCFileUtils.h"
    virtual unsigned char *getFileDataFromZip(const char *pszZipFilePath, const char *pszFileName, unsigned long *pSize);
    // #line 158 "cocos2d/cocos-headers/cocos2dx/platform/CCFileUtils.h"
    virtual std::string fullPathForFilename(const char *pszFileName, bool);

    virtual void removeFullPath(const char *path);
    // #line 194 "cocos2d/cocos-headers/cocos2dx/platform/CCFileUtils.h"
    virtual void loadFilenameLookupDictionaryFromFile(const char *filename);
    // #line 203 "cocos2d/cocos-headers/cocos2dx/platform/CCFileUtils.h"
    virtual void setFilenameLookupDictionary(CCDictionary *pFilenameLookupDict);
    // #line 214 "cocos2d/cocos-headers/cocos2dx/platform/CCFileUtils.h"
    virtual const char *fullPathFromRelativeFile(const char *pszFilename, const char *pszRelativeFile);
    // #line 225 "cocos2d/cocos-headers/cocos2dx/platform/CCFileUtils.h"
    virtual void setSearchResolutionsOrder(const std::vector<std::string> &searchResolutionsOrder);
    // #line 233 "cocos2d/cocos-headers/cocos2dx/platform/CCFileUtils.h"
    virtual void addSearchResolutionsOrder(const char *order);
    // #line 243 "cocos2d/cocos-headers/cocos2dx/platform/CCFileUtils.h"
    virtual const std::vector<std::string> &getSearchResolutionsOrder();
    // #line 264 "cocos2d/cocos-headers/cocos2dx/platform/CCFileUtils.h"
    virtual void setSearchPaths(const std::vector<std::string> &searchPaths);

    virtual void addSearchPath(const char *path);
    // #line 279 "cocos2d/cocos-headers/cocos2dx/platform/CCFileUtils.h"
    virtual void removeSearchPath(const char *path);
    // #line 287 "cocos2d/cocos-headers/cocos2dx/platform/CCFileUtils.h"
    void removeAllPaths();
    // #line 297 "cocos2d/cocos-headers/cocos2dx/platform/CCFileUtils.h"
    virtual const std::vector<std::string> &getSearchPaths();

    virtual std::string getWritablePath() = 0;

    virtual std::string getWritablePath2();
    // #line 316 "cocos2d/cocos-headers/cocos2dx/platform/CCFileUtils.h"
    virtual bool isFileExist(const std::string &strFilePath) = 0;
    // #line 328 "cocos2d/cocos-headers/cocos2dx/platform/CCFileUtils.h"
    virtual bool isAbsolutePath(const std::string &strPath);

    virtual void setPopupNotify(bool bNotify);
    virtual bool isPopupNotify();

protected:
    CCFileUtils();
    // #line 351 "cocos2d/cocos-headers/cocos2dx/platform/CCFileUtils.h"
    virtual bool init();
    // #line 359 "cocos2d/cocos-headers/cocos2dx/platform/CCFileUtils.h"
    virtual std::string getNewFilename(const char *pszFileName);

    virtual bool shouldUseHD();
    virtual std::string addSuffix(std::string, std::string);
    // #line 372 "cocos2d/cocos-headers/cocos2dx/platform/CCFileUtils.h"
    virtual std::string getPathForFilename(const std::string &filename, const std::string &resolutionDirectory, const std::string &searchPath);
    // #line 384 "cocos2d/cocos-headers/cocos2dx/platform/CCFileUtils.h"
    virtual std::string getFullPathForDirectoryAndFilename(const std::string &strDirectory, const std::string &strFilename);

    virtual CCDictionary *createCCDictionaryWithContentsOfFile(const std::string &filename);

    virtual bool writeToFile(CCDictionary *dict, const std::string &fullPath);

    virtual CCArray *createCCArrayWithContentsOfFile(const std::string &filename);
    // #line 411 "cocos2d/cocos-headers/cocos2dx/platform/CCFileUtils.h"
    CCDictionary *m_pFilenameLookupDict;

    std::vector<std::string> m_searchResolutionsOrderArray;

    std::vector<std::string> m_searchPathArray;
    // #line 432 "cocos2d/cocos-headers/cocos2dx/platform/CCFileUtils.h"
    std::string m_strDefaultResRootPath;

    std::map<std::string, std::string> m_fullPathCache;

    static CCFileUtils *s_sharedFileUtils;
};
// #line 41 "cocos2d/cocos-headers/cocos2dx/platform/CCImage.h"
class CCImage : public CCObject
{
public:
    CCImage();

    ~CCImage();

    typedef enum
    {
        kFmtJpg = 0,
        kFmtPng,
        kFmtTiff,
        kFmtWebp,
        kFmtRawData,
        kFmtUnKnown
    } EImageFormat;

    typedef enum
    {
        kAlignCenter = 0x33,
        kAlignTop = 0x13,
        kAlignTopRight = 0x12,
        kAlignRight = 0x32,
        kAlignBottomRight = 0x22,
        kAlignBottom = 0x23,
        kAlignBottomLeft = 0x21,
        kAlignLeft = 0x31,
        kAlignTopLeft = 0x11,
    } ETextAlign;
    // #line 83 "cocos2d/cocos-headers/cocos2dx/platform/CCImage.h"
    bool initWithImageFile(const char *strPath, EImageFormat imageType = kFmtPng);
    // #line 92 "cocos2d/cocos-headers/cocos2dx/platform/CCImage.h"
    bool initWithImageFileThreadSafe(const char *fullpath, EImageFormat imageType = kFmtPng);
    // #line 104 "cocos2d/cocos-headers/cocos2dx/platform/CCImage.h"
    bool initWithImageData(void *pData,
                           int nDataLen,
                           EImageFormat eFmt = kFmtUnKnown,
                           int nWidth = 0,
                           int nHeight = 0,
                           int nBitsPerComponent = 8);
    // #line 121 "cocos2d/cocos-headers/cocos2dx/platform/CCImage.h"
    bool initWithString(
        const char *pText,
        int nWidth = 0,
        int nHeight = 0,
        ETextAlign eAlignMask = kAlignCenter,
        const char *pFontName = 0,
        int nSize = 0);
    // #line 160 "cocos2d/cocos-headers/cocos2dx/platform/CCImage.h"
    unsigned char *getData() { return m_pData; }
    int getDataLen() { return m_nWidth * m_nHeight; }

    bool hasAlpha() { return m_bHasAlpha; }
    bool isPremultipliedAlpha() { return m_bPreMulti; }
    // #line 173 "cocos2d/cocos-headers/cocos2dx/platform/CCImage.h"
    bool saveToFile(const char *pszFilePath, bool bIsToRGB = true);

protected:
    unsigned short m_nWidth;

public:
    virtual unsigned short getWidth(void) const { return m_nWidth; };

protected:
    unsigned short m_nHeight;

public:
    virtual unsigned short getHeight(void) const { return m_nHeight; };

protected:
    int m_nBitsPerComponent;

public:
    virtual int getBitsPerComponent(void) const { return m_nBitsPerComponent; };

protected:
    bool _initWithJpgData(void *pData, int nDatalen);
    bool _initWithPngData(void *pData, int nDatalen);
    bool _initWithTiffData(void *pData, int nDataLen);
    bool _initWithWebpData(void *pData, int nDataLen);

    bool _initWithRawData(void *pData, int nDatalen, int nWidth, int nHeight, int nBitsPerComponent, bool bPreMulti);

    bool _saveImageToPNG(const char *pszFilePath, bool bIsToRGB = true);
    bool _saveImageToJPG(const char *pszFilePath);

    unsigned char *m_pData;
    bool m_bHasAlpha;
    bool m_bPreMulti;

private:
    CCImage(const CCImage &rImg);
    CCImage &operator=(const CCImage &);
};
// #line 43 "cocos2d/cocos-headers/cocos2dx/platform/CCThread.h"
class CCThread
{
public:
    CCThread() : m_pAutoreasePool(0) {}
    ~CCThread();

    void createAutoreleasePool();

private:
    void *m_pAutoreasePool;
};
// #line 38 "cocos2d/cocos-headers/cocos2dx/platform/platform.h"
struct cc_timeval
{

    long tv_sec;

    int tv_usec;
};

class CCTime
{
public:
    static int gettimeofdayCocos2d(struct cc_timeval *tp, void *tzp);
    static double timersubCocos2d(struct cc_timeval *start, struct cc_timeval *end);
};
// #line 32 "cocos2d/cocos-headers/cocos2dx/platform/win32/CCAccelerometer.h"
class CCAccelerometer
{
public:
    CCAccelerometer();
    ~CCAccelerometer();

    void setDelegate(CCAccelerometerDelegate *pDelegate);
    void setAccelerometerInterval(float interval);
    void update(double x, double y, double z, double timestamp);

private:
    CCAcceleration m_obAccelerationValue;
    CCAccelerometerDelegate *m_pAccelDelegate;
};

// #line 54 "cocos2d/cocos-headers/cocos2dx/platform/win32/CCStdC.h"
struct timezone
{
    int tz_minuteswest;
    int tz_dsttime;
};

int gettimeofday(struct timeval *, struct timezone *);
// #line 30 "cocos2d/cocos-headers/cocos2dx/platform/CCApplicationProtocol.h"
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
// #line 53 "cocos2d/cocos-headers/cocos2dx/platform/CCApplicationProtocol.h"
class CCApplicationProtocol
{
public:
    virtual ~CCApplicationProtocol() {}

    virtual bool applicationDidFinishLaunching() = 0;

    virtual void applicationDidEnterBackground() = 0;

    virtual void applicationWillEnterForeground() = 0;

    virtual void applicationWillBecomeActive();
    virtual void applicationWillResignActive();
    virtual void trySaveGame();
    virtual void gameDidSave();
    // #line 89 "cocos2d/cocos-headers/cocos2dx/platform/CCApplicationProtocol.h"
    virtual void setAnimationInterval(double interval) = 0;

    virtual ccLanguageType getCurrentLanguage() = 0;

    virtual TargetPlatform getTargetPlatform() = 0;

    virtual void openURL(const char *url);
};
// #line 8 "cocos2d/cocos-headers/cocos2dx/platform/win32/CCApplication.h"
#include <string>

class CCRect;

class CCApplication : public CCApplicationProtocol
{
public:
    CCApplication();
    virtual ~CCApplication();

    virtual void gameDidSave();

    static CCApplication *sharedApplication();

    virtual void setAnimationInterval(double interval);
    virtual ccLanguageType getCurrentLanguage();

    virtual TargetPlatform getTargetPlatform();

    virtual void openURL(const char *url);
    virtual int run();
    virtual void setupGLView();
    virtual void platformShutdown();
    void toggleVerticalSync(bool);
    bool getVerticalSyncEnabled() const;
    // #line 54 "cocos2d/cocos-headers/cocos2dx/platform/win32/CCApplication.h"
    void setResourceRootPath(const std::string &rootResDir);

    const std::string &getResourceRootPath(void);

    void setStartupScriptFilename(const std::string &startupScriptFile);

    bool getControllerConnected() const;

    const std::string &getStartupScriptFilename(void)
    {
        return m_startupScriptFilename;
    }

public:
    HINSTANCE m_hInstance;
    HACCEL m_hAccelTable;
    LARGE_INTEGER m_nAnimationInterval;
    std::string m_resourceRootPath;
    std::string m_startupScriptFilename;

    static CCApplication *sm_pSharedApplication;
};
// #line 6 "cocos2d/cocos-headers/cocos2dx/platform/CCEGLViewProtocol.h"
enum ResolutionPolicy
{

    kResolutionExactFit,

    kResolutionNoBorder,

    kResolutionShowAll,
    // #line 21 "cocos2d/cocos-headers/cocos2dx/platform/CCEGLViewProtocol.h"
    kResolutionFixedHeight,
    // #line 26 "cocos2d/cocos-headers/cocos2dx/platform/CCEGLViewProtocol.h"
    kResolutionFixedWidth,

    kResolutionUnKnown,
};

class EGLTouchDelegate;
class CCSet;
// #line 44 "cocos2d/cocos-headers/cocos2dx/platform/CCEGLViewProtocol.h"
class CCEGLViewProtocol
{
public:
    CCEGLViewProtocol();

    virtual ~CCEGLViewProtocol();

    virtual void end() = 0;

    virtual bool isOpenGLReady() = 0;

    virtual void swapBuffers() = 0;

    virtual void setIMEKeyboardState(bool bOpen) = 0;

    virtual const CCSize &getFrameSize() const;

    virtual void setFrameSize(float width, float height);

    virtual CCSize getVisibleSize() const;

    virtual CCPoint getVisibleOrigin() const;
    // #line 106 "cocos2d/cocos-headers/cocos2dx/platform/CCEGLViewProtocol.h"
    virtual void setDesignResolutionSize(float width, float height, ResolutionPolicy resolutionPolicy);

    virtual const CCSize &getDesignResolutionSize() const;

    virtual void setTouchDelegate(EGLTouchDelegate *pDelegate);

    virtual void setViewPortInPoints(float x, float y, float w, float h);

    virtual void setScissorInPoints(float x, float y, float w, float h);

    virtual bool isScissorEnabled();

    virtual CCRect getScissorRect();

    virtual void setViewName(const char *pszViewName);

    const char *getViewName();

    virtual void handleTouchesBegin(int num, int ids[], float xs[], float ys[]);

    virtual void handleTouchesMove(int num, int ids[], float xs[], float ys[]);

    virtual void handleTouchesEnd(int num, int ids[], float xs[], float ys[]);

    virtual void handleTouchesCancel(int num, int ids[], float xs[], float ys[]);

    const CCRect &getViewPortRect() const;

    float getScaleX() const;

    float getScaleY() const;

private:
    void getSetOfTouchesEndOrCancel(CCSet &set, int num, int ids[], float xs[], float ys[]);

protected:
    EGLTouchDelegate *m_pDelegate;

    CCSize m_obScreenSize;

    CCSize m_obDesignResolutionSize;

    CCRect m_obViewPortRect;

    char m_szViewName[50];

    float m_fScaleX;
    float m_fScaleY;
    ResolutionPolicy m_eResolutionPolicy;
};
// #line 137 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
#include <stddef.h>
// #line 162 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
#include <GL/gl.h>
// #line 558 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
typedef void (*GLFWglproc)(void);
// #line 566 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
typedef struct GLFWmonitor GLFWmonitor;
// #line 574 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
typedef struct GLFWwindow GLFWwindow;
// #line 587 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
typedef void (*GLFWerrorfun)(int, const char *);
// #line 603 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
typedef void (*GLFWwindowposfun)(GLFWwindow *, int, int);
// #line 617 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
typedef void (*GLFWwindowsizefun)(GLFWwindow *, int, int);
// #line 629 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
typedef void (*GLFWwindowclosefun)(GLFWwindow *);
// #line 641 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
typedef void (*GLFWwindowrefreshfun)(GLFWwindow *);
// #line 655 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
typedef void (*GLFWwindowfocusfun)(GLFWwindow *, int);
// #line 670 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
typedef void (*GLFWwindowiconifyfun)(GLFWwindow *, int);
// #line 685 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
typedef void (*GLFWframebuffersizefun)(GLFWwindow *, int, int);
// #line 702 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
typedef void (*GLFWmousebuttonfun)(GLFWwindow *, int, int, int);
// #line 716 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
typedef void (*GLFWcursorposfun)(GLFWwindow *, double, double);
// #line 730 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
typedef void (*GLFWcursorenterfun)(GLFWwindow *, int);
// #line 744 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
typedef void (*GLFWscrollfun)(GLFWwindow *, double, double);
// #line 761 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
typedef void (*GLFWkeyfun)(GLFWwindow *, int, int, int, int);
// #line 774 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
typedef void (*GLFWcharfun)(GLFWwindow *, unsigned int);
// #line 787 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
typedef void (*GLFWmonitorfun)(GLFWmonitor *, int);
// #line 795 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
typedef struct GLFWvidmode
{

    int width;

    int height;

    int redBits;

    int greenBits;

    int blueBits;

    int refreshRate;
} GLFWvidmode;
// #line 825 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
typedef struct GLFWgammaramp
{

    unsigned short *red;

    unsigned short *green;

    unsigned short *blue;

    unsigned int size;
} GLFWgammaramp;
// #line 874 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
int glfwInit(void);
// #line 898 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwTerminate(void);
// #line 918 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwGetVersion(int *major, int *minor, int *rev);
// #line 948 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
const char *glfwGetVersionString(void);
// #line 973 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
GLFWerrorfun glfwSetErrorCallback(GLFWerrorfun cbfun);
// #line 995 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
GLFWmonitor **glfwGetMonitors(int *count);
// #line 1008 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
GLFWmonitor *glfwGetPrimaryMonitor(void);
// #line 1021 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwGetMonitorPos(GLFWmonitor *monitor, int *xpos, int *ypos);
// #line 1040 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwGetMonitorPhysicalSize(GLFWmonitor *monitor, int *width, int *height);
// #line 1056 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
const char *glfwGetMonitorName(GLFWmonitor *monitor);
// #line 1074 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
GLFWmonitorfun glfwSetMonitorCallback(GLFWmonitorfun cbfun);
// #line 1098 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
const GLFWvidmode *glfwGetVideoModes(GLFWmonitor *monitor, int *count);
// #line 1116 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
const GLFWvidmode *glfwGetVideoMode(GLFWmonitor *monitor);
// #line 1128 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwSetGamma(GLFWmonitor *monitor, float gamma);
// #line 1142 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
const GLFWgammaramp *glfwGetGammaRamp(GLFWmonitor *monitor);
// #line 1155 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwSetGammaRamp(GLFWmonitor *monitor, const GLFWgammaramp *ramp);
// #line 1168 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwDefaultWindowHints(void);
// #line 1190 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwWindowHint(int target, int hint);
// #line 1258 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
GLFWwindow *glfwCreateWindow(int width, int height, const char *title, GLFWmonitor *monitor, GLFWwindow *share);
// #line 1280 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwDestroyWindow(GLFWwindow *window);
// #line 1293 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
int glfwWindowShouldClose(GLFWwindow *window);
// #line 1308 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwSetWindowShouldClose(GLFWwindow *window, int value);
// #line 1322 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwSetWindowTitle(GLFWwindow *window, const char *title);
// #line 1339 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwGetWindowPos(GLFWwindow *window, int *xpos, int *ypos);
// #line 1367 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwSetWindowPos(GLFWwindow *window, int xpos, int ypos);
// #line 1385 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwGetWindowSize(GLFWwindow *window, int *width, int *height);
// #line 1409 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwSetWindowSize(GLFWwindow *window, int width, int height);
// #line 1427 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwGetFramebufferSize(GLFWwindow *window, int *width, int *height);
// #line 1444 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwIconifyWindow(GLFWwindow *window);
// #line 1461 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwRestoreWindow(GLFWwindow *window);
// #line 1477 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwShowWindow(GLFWwindow *window);
// #line 1493 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwHideWindow(GLFWwindow *window);
// #line 1505 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
GLFWmonitor *glfwGetWindowMonitor(GLFWwindow *window);
// #line 1519 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
int glfwGetWindowAttrib(GLFWwindow *window, int attrib);
// #line 1534 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwSetWindowUserPointer(GLFWwindow *window, void *pointer);
// #line 1547 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void *glfwGetWindowUserPointer(GLFWwindow *window);
// #line 1563 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
GLFWwindowposfun glfwSetWindowPosCallback(GLFWwindow *window, GLFWwindowposfun cbfun);
// #line 1579 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
GLFWwindowsizefun glfwSetWindowSizeCallback(GLFWwindow *window, GLFWwindowsizefun cbfun);
// #line 1606 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
GLFWwindowclosefun glfwSetWindowCloseCallback(GLFWwindow *window, GLFWwindowclosefun cbfun);
// #line 1630 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
GLFWwindowrefreshfun glfwSetWindowRefreshCallback(GLFWwindow *window, GLFWwindowrefreshfun cbfun);
// #line 1650 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
GLFWwindowfocusfun glfwSetWindowFocusCallback(GLFWwindow *window, GLFWwindowfocusfun cbfun);
// #line 1665 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
GLFWwindowiconifyfun glfwSetWindowIconifyCallback(GLFWwindow *window, GLFWwindowiconifyfun cbfun);
// #line 1680 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
GLFWframebuffersizefun glfwSetFramebufferSizeCallback(GLFWwindow *window, GLFWframebuffersizefun cbfun);
// #line 1711 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwPollEvents(void);
// #line 1744 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwWaitEvents(void);
// #line 1756 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
int glfwGetInputMode(GLFWwindow *window, int mode);
// #line 1794 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwSetInputMode(GLFWwindow *window, int mode, int value);
// #line 1820 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
int glfwGetKey(GLFWwindow *window, int key);
// #line 1838 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
int glfwGetMouseButton(GLFWwindow *window, int button);
// #line 1865 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwGetCursorPos(GLFWwindow *window, double *xpos, double *ypos);
// #line 1889 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwSetCursorPos(GLFWwindow *window, double xpos, double ypos);
// #line 1923 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
GLFWkeyfun glfwSetKeyCallback(GLFWwindow *window, GLFWkeyfun cbfun);
// #line 1942 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
GLFWcharfun glfwSetCharCallback(GLFWwindow *window, GLFWcharfun cbfun);
// #line 1963 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
GLFWmousebuttonfun glfwSetMouseButtonCallback(GLFWwindow *window, GLFWmousebuttonfun cbfun);
// #line 1980 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
GLFWcursorposfun glfwSetCursorPosCallback(GLFWwindow *window, GLFWcursorposfun cbfun);
// #line 1996 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
GLFWcursorenterfun glfwSetCursorEnterCallback(GLFWwindow *window, GLFWcursorenterfun cbfun);
// #line 2015 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
GLFWscrollfun glfwSetScrollCallback(GLFWwindow *window, GLFWscrollfun cbfun);
// #line 2026 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
int glfwJoystickPresent(int joy);
// #line 2045 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
const float *glfwGetJoystickAxes(int joy, int *count);
// #line 2064 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
const unsigned char *glfwGetJoystickButtons(int joy, int *count);
// #line 2082 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
const char *glfwGetJoystickName(int joy);
// #line 2099 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwSetClipboardString(GLFWwindow *window, const char *string);
// #line 2122 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
const char *glfwGetClipboardString(GLFWwindow *window);
// #line 2140 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
double glfwGetTime(void);
// #line 2155 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwSetTime(double time);
// #line 2173 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
void glfwMakeContextCurrent(GLFWwindow *window);
// #line 2189 "cocos2d/cocos-headers/cocos2dx/robtop/glfw/glfw3.h"
GLFWwindow *glfwGetCurrentContext(void);
void glfwSwapBuffers(GLFWwindow *window);
void glfwSwapInterval(int interval);
int glfwExtensionSupported(const char *extension);
GLFWglproc glfwGetProcAddress(const char *procname);
typedef LRESULT (*CUSTOM_WND_PROC)(UINT message, WPARAM wParam, LPARAM lParam, BOOL *pProcessed);

class CCEGL;

class CCEGLView : public CCEGLViewProtocol, public CCObject
{
public:
    CCEGLView();

    virtual bool isOpenGLReady();
    virtual void end();
    virtual void swapBuffers();
    virtual void setFrameSize(float width, float height);

    virtual void setIMEKeyboardState(bool bOpen);

    void setMenuResource(LPCWSTR menu);
    void setWndProc(CUSTOM_WND_PROC proc);

protected:
public:
    bool initGL();
    void destroyGL();

    void setHWnd(HWND hWnd);

    void resizeWindow(int width, int height);

    void setFrameZoomFactor(float fZoomFactor);
    float getFrameZoomFactor();

    void centerWindow();

    void showCursor(bool state);

    typedef void (*LPFN_ACCELEROMETER_KEYHOOK)(UINT message, WPARAM wParam, LPARAM lParam);
    void setAccelerometerKeyHook(LPFN_ACCELEROMETER_KEYHOOK lpfnAccelerometerKeyHook);

    virtual void setViewPortInPoints(float x, float y, float w, float h);
    virtual void setScissorInPoints(float x, float y, float w, float h);

    static CCEGLView *sharedOpenGLView();
    static CCEGLView *create(const std::string &);

    inline CCPoint getMousePosition() { return {m_fMouseX, m_fMouseY}; }
    void toggleFullScreen(bool fullscreen);
    GLFWwindow *getWindow(void) const;

protected:
    static CCEGLView *s_pEglView;
    bool m_bCaptured;

    bool m_bSupportTouch;
    bool m_bInRetinaMonitor;
    bool m_bRetinaEnabled;
    int m_nRetinaFactor;
    bool m_bCursorHidden;
    float m_fFrameZoomFactor;
    GLFWwindow *m_pMainWindow;
    GLFWmonitor *m_pPrimaryMonitor;
    CCSize m_obWindowedSize;
    float m_fMouseX;
    float m_fMouseY;
    bool m_bIsFullscreen;
    bool m_bShouldHideCursor;
    bool m_bShouldCallGLFinish;
    void onGLFWCharCallback(GLFWwindow *window, unsigned int entered);
    void onGLFWCursorEnterFunCallback(GLFWwindow *window, int entered);
    void onGLFWDeviceChangeFunCallback(GLFWwindow *window);
    void onGLFWError(int code, const char *description);
    void onGLFWframebuffersize(GLFWwindow *window, int width, int height);
    void onGLFWMouseMoveCallBack(GLFWwindow *window, double x, double y);
    void onGLFWMouseCallBack(GLFWwindow *window, int button, int action, int mods);
    void onGLFWKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
    void onGLFWMouseScrollCallback(GLFWwindow *window, double xoffset, double yoffset);
    void onGLFWWindowIconifyFunCallback(GLFWwindow *window, int iconified);
    void onGLFWWindowPosCallback(GLFWwindow *window, int x, int y);
    void onGLFWWindowSizeFunCallback(GLFWwindow *window, int width, int height);
};

class CCGLProgram;
class CCShaderCache : public CCObject
{
public:
    CCShaderCache();

    virtual ~CCShaderCache();

    static CCShaderCache *sharedShaderCache();

    static void purgeSharedShaderCache();

    void loadDefaultShaders();

    void reloadDefaultShaders();

    CCGLProgram *programForKey(const char *key);

    void addProgram(CCGLProgram *program, const char *key);

private:
    bool init();
    void loadDefaultShader(CCGLProgram *program, int type);

    CCDictionary *m_pPrograms;
};
extern const GLchar *ccPosition_uColor_frag;
extern const GLchar *ccPosition_uColor_vert;

extern const GLchar *ccPositionColor_frag;
extern const GLchar *ccPositionColor_vert;

extern const GLchar *ccPositionTexture_frag;
extern const GLchar *ccPositionTexture_vert;

extern const GLchar *ccPositionTextureA8Color_frag;
extern const GLchar *ccPositionTextureA8Color_vert;

extern const GLchar *ccPositionTextureColor_frag;
extern const GLchar *ccPositionTextureColor_vert;

extern const GLchar *ccPositionTextureColorAlphaTest_frag;

extern const GLchar *ccPositionTexture_uColor_frag;
extern const GLchar *ccPositionTexture_uColor_vert;

extern const GLchar *ccPositionColorLengthTexture_frag;
extern const GLchar *ccPositionColorLengthTexture_vert;

extern const GLchar *ccExSwitchMask_frag;

class CCAnimation;
class CCAnimationCache : public CCObject
{
public:
    CCAnimationCache();

    ~CCAnimationCache();

    static CCAnimationCache *sharedAnimationCache(void);

    static void purgeSharedAnimationCache(void);

    void addAnimation(CCAnimation *animation, const char *name);

    void removeAnimationByName(const char *name);

    CCAnimation *animationByName(const char *name);

    void addAnimationsWithDictionary(CCDictionary *dictionary, const char *plist = NULL);

    void addAnimationsWithFile(const char *plist);

    bool init(void);

private:
    void parseVersion1(CCDictionary *animations);
    void parseVersion2(CCDictionary *animations);

private:
    CCDictionary *m_pAnimations;
    static CCAnimationCache *s_pSharedAnimationCache;
};

class CCDictionary;
class CCArray;
class CCSprite;
class CCSpriteFrameCache : public CCObject
{
protected:
    CCSpriteFrameCache(void) : m_pSpriteFrames(NULL), m_pSpriteFramesAliases(NULL) {}

public:
    bool init(void);

    ~CCSpriteFrameCache(void);

private:
    void addSpriteFramesWithDictionary(CCDictionary *pobDictionary, CCTexture2D *pobTexture);

public:
    void addSpriteFramesWithFile(const char *pszPlist);

    void addSpriteFramesWithFile(const char *plist, const char *textureFileName);

    void addSpriteFramesWithFile(const char *pszPlist, CCTexture2D *pobTexture);

    void addSpriteFrame(CCSpriteFrame *pobFrame, const char *pszFrameName);
    // #line 108 "cocos2d/cocos-headers/cocos2dx/sprite_nodes/CCSpriteFrameCache.h"
    void removeSpriteFrames(void);

    void removeUnusedSpriteFrames(void);

    void removeSpriteFrameByName(const char *pszName);

    void removeSpriteFramesFromFile(const char *plist);

private:
    void removeSpriteFramesFromDictionary(CCDictionary *dictionary);

public:
    void removeSpriteFramesFromTexture(CCTexture2D *texture);

    CCSpriteFrame *spriteFrameByName(const char *pszName);

public:
    static CCSpriteFrameCache *sharedSpriteFrameCache(void);

    static void purgeSharedSpriteFrameCache(void);

private:
protected:
    CCDictionary *m_pSpriteFrames;
    CCDictionary *m_pSpriteFramesAliases;
    std::set<std::string> *m_pLoadedFileNames;
};
// #line 12 "cocos2d/cocos-headers/cocos2dx/support/ccUTF8.h"
#include <vector>

int cc_wcslen(const unsigned short *str);

void cc_utf8_trim_ws(std::vector<unsigned short> *str);
// #line 27 "cocos2d/cocos-headers/cocos2dx/support/ccUTF8.h"
bool isspace_unicode(unsigned short ch);
// #line 41 "cocos2d/cocos-headers/cocos2dx/support/ccUTF8.h"
long cc_utf8_strlen(const char *p, int max);
// #line 50 "cocos2d/cocos-headers/cocos2dx/support/ccUTF8.h"
unsigned int cc_utf8_find_last_not_char(std::vector<unsigned short> str, unsigned short c);

std::vector<unsigned short> cc_utf16_vec_from_utf16_str(const unsigned short *str);
// #line 62 "cocos2d/cocos-headers/cocos2dx/support/ccUTF8.h"
unsigned short *cc_utf8_to_utf16(const char *str_old, int length = -1, int *rUtf16Size = NULL);
// #line 89 "cocos2d/cocos-headers/cocos2dx/support/ccUTF8.h"
char *
cc_utf16_to_utf8(const unsigned short *str,
                 long len,
                 long *items_read,
                 long *items_written);
// #line 35 "cocos2d/cocos-headers/cocos2dx/support/CCNotificationCenter.h"
class CCNotificationCenter : public CCObject
{
public:
    CCNotificationCenter();

    ~CCNotificationCenter();

    static CCNotificationCenter *sharedNotificationCenter(void);

    static void purgeNotificationCenter(void);
    // #line 56 "cocos2d/cocos-headers/cocos2dx/support/CCNotificationCenter.h"
    void addObserver(CCObject *target,
                     SEL_CallFuncO selector,
                     const char *name,
                     CCObject *obj);

    void removeObserver(CCObject *target, const char *name);

    int removeAllObservers(CCObject *target);

    void registerScriptObserver(CCObject *target, int handler, const char *name);

    void unregisterScriptObserver(CCObject *target, const char *name);

    void postNotification(const char *name);

    void postNotification(const char *name, CCObject *object);

    inline int getScriptHandler() { return m_scriptHandler; };

    int getObserverHandlerByName(const char *name);

private:
    bool observerExisted(CCObject *target, const char *name);

    CCArray *m_observers;
    int m_scriptHandler;
};

class CCNotificationObserver : public CCObject
{
public:
    CCNotificationObserver(CCObject *target,
                           SEL_CallFuncO selector,
                           const char *name,
                           CCObject *obj);

    ~CCNotificationObserver();

    void performSelector(CCObject *obj);

private:
protected:
    CCObject *m_target;

public:
    virtual CCObject *getTarget(void);
    ;

protected:
    SEL_CallFuncO m_selector;

public:
    virtual SEL_CallFuncO getSelector(void);
    ;

protected:
    char *m_name;

public:
    virtual char *getName(void);
    ;

protected:
    CCObject *m_object;

public:
    virtual CCObject *getObject(void);
    ;

protected:
    int m_nHandler;

public:
    virtual int getHandler(void);

public:
    virtual void setHandler(int var);
    ;
};
// #line 47 "cocos2d/cocos-headers/cocos2dx/support/CCPointExtension.h"
#include <math.h>
// #line 66 "cocos2d/cocos-headers/cocos2dx/support/CCPointExtension.h"
static inline CCPoint
ccpNeg(const CCPoint &v)
{
    return -v;
}

static inline CCPoint
ccpAdd(const CCPoint &v1, const CCPoint &v2)
{
    return v1 + v2;
}

static inline CCPoint
ccpSub(const CCPoint &v1, const CCPoint &v2)
{
    return v1 - v2;
}

static inline CCPoint
ccpMult(const CCPoint &v, const float s)
{
    return v * s;
}

static inline CCPoint
ccpMidpoint(const CCPoint &v1, const CCPoint &v2)
{
    return (v1 + v2) / 2.f;
}

static inline float
ccpDot(const CCPoint &v1, const CCPoint &v2)
{
    return v1.dot(v2);
}

static inline float
ccpCross(const CCPoint &v1, const CCPoint &v2)
{
    return v1.cross(v2);
}

static inline CCPoint
ccpPerp(const CCPoint &v)
{
    return v.getPerp();
}

static inline CCPoint
ccpRPerp(const CCPoint &v)
{
    return v.getRPerp();
}

static inline CCPoint
ccpProject(const CCPoint &v1, const CCPoint &v2)
{
    return v1.project(v2);
}

static inline CCPoint
ccpRotate(const CCPoint &v1, const CCPoint &v2)
{
    return v1.rotate(v2);
}

static inline CCPoint
ccpUnrotate(const CCPoint &v1, const CCPoint &v2)
{
    return v1.unrotate(v2);
}

static inline float
ccpLengthSQ(const CCPoint &v)
{
    return v.getLengthSq();
}

static inline float
ccpDistanceSQ(const CCPoint p1, const CCPoint p2)
{
    return (p1 - p2).getLengthSq();
}

float ccpLength(const CCPoint &v);

float ccpDistance(const CCPoint &v1, const CCPoint &v2);

CCPoint ccpNormalize(const CCPoint &v);

CCPoint ccpForAngle(const float a);

float ccpToAngle(const CCPoint &v);

float clampf(float value, float min_inclusive, float max_inclusive);

CCPoint ccpClamp(const CCPoint &p, const CCPoint &from, const CCPoint &to);

CCPoint ccpFromSize(const CCSize &s);
// #line 257 "cocos2d/cocos-headers/cocos2dx/support/CCPointExtension.h"
CCPoint ccpCompOp(const CCPoint &p, float (*opFunc)(float));
// #line 266 "cocos2d/cocos-headers/cocos2dx/support/CCPointExtension.h"
CCPoint ccpLerp(const CCPoint &a, const CCPoint &b, float alpha);

bool ccpFuzzyEqual(const CCPoint &a, const CCPoint &b, float variance);

CCPoint ccpCompMult(const CCPoint &a, const CCPoint &b);

float ccpAngleSigned(const CCPoint &a, const CCPoint &b);

float ccpAngle(const CCPoint &a, const CCPoint &b);
// #line 298 "cocos2d/cocos-headers/cocos2dx/support/CCPointExtension.h"
CCPoint ccpRotateByAngle(const CCPoint &v, const CCPoint &pivot, float angle);
// #line 321 "cocos2d/cocos-headers/cocos2dx/support/CCPointExtension.h"
bool ccpLineIntersect(const CCPoint &p1, const CCPoint &p2,
                      const CCPoint &p3, const CCPoint &p4,
                      float *s, float *t);

bool ccpSegmentIntersect(const CCPoint &A, const CCPoint &B, const CCPoint &C, const CCPoint &D);

CCPoint ccpIntersectPoint(const CCPoint &A, const CCPoint &B, const CCPoint &C, const CCPoint &D);
// #line 32 "cocos2d/cocos-headers/cocos2dx/support/CCProfiling.h"
#include <string>
// #line 41 "cocos2d/cocos-headers/cocos2dx/support/CCProfiling.h"
class CCProfilingTimer;
// #line 51 "cocos2d/cocos-headers/cocos2dx/support/CCProfiling.h"
class CCProfiler : public CCObject
{
public:
    ~CCProfiler(void);

    void displayTimers(void);
    bool init(void);

public:
    static CCProfiler *sharedProfiler(void);

    CCProfilingTimer *createAndAddTimerWithName(const char *timerName);

    void releaseTimer(const char *timerName);

    void releaseAllTimers();

    CCDictionary *m_pActiveTimers;
};

class CCProfilingTimer : public CCObject
{
public:
    CCProfilingTimer();
    ~CCProfilingTimer();
    bool initWithName(const char *timerName);
    const char *description(void);
    struct cc_timeval *getStartTime(void) { return &m_sStartTime; };

    void reset();

    std::string m_NameStr;
    int numberOfCalls;
    int m_dAverageTime1;
    int m_dAverageTime2;
    long long totalTime;
    int minTime;
    int maxTime;
    struct cc_timeval m_sStartTime;
};

extern void CCProfilingBeginTimingBlock(const char *timerName);
extern void CCProfilingEndTimingBlock(const char *timerName);
extern void CCProfilingResetTimingBlock(const char *timerName);

extern bool kCCProfilerCategorySprite;
extern bool kCCProfilerCategoryBatchSprite;
extern bool kCCProfilerCategoryParticles;
// #line 28 "cocos2d/cocos-headers/cocos2dx/support/user_default/CCUserDefault.h"
#include <string>
// #line 45 "cocos2d/cocos-headers/cocos2dx/support/user_default/CCUserDefault.h"
class CCUserDefault
{
public:
    ~CCUserDefault();
    // #line 56 "cocos2d/cocos-headers/cocos2dx/support/user_default/CCUserDefault.h"
    bool getBoolForKey(const char *pKey);
    bool getBoolForKey(const char *pKey, bool defaultValue);

    int getIntegerForKey(const char *pKey);
    int getIntegerForKey(const char *pKey, int defaultValue);

    float getFloatForKey(const char *pKey);
    float getFloatForKey(const char *pKey, float defaultValue);

    double getDoubleForKey(const char *pKey);
    double getDoubleForKey(const char *pKey, double defaultValue);

    std::string getStringForKey(const char *pKey);
    std::string getStringForKey(const char *pKey, const std::string &defaultValue);

    void setBoolForKey(const char *pKey, bool value);

    void setIntegerForKey(const char *pKey, int value);

    void setFloatForKey(const char *pKey, float value);

    void setDoubleForKey(const char *pKey, double value);

    void setStringForKey(const char *pKey, const std::string &value);

    void flush();

    static CCUserDefault *sharedUserDefault();
    static void purgeSharedUserDefault();
    const static std::string &getXMLFilePath();
    static bool isXMLFileExist();

private:
    CCUserDefault();
    static bool createXMLFile();
    static void initXMLFilePath();

    static CCUserDefault *m_spUserDefault;
    static std::string m_sFilePath;
    static bool m_sbIsFilePathInitialized;
};
// #line 40 "cocos2d/cocos-headers/cocos2dx/support/CCVertex.h"
void ccVertexLineToPolygon(CCPoint *points, float stroke, ccVertex2F *vertices, unsigned int offset, unsigned int nuPoints);

bool ccVertexLineIntersect(float Ax, float Ay,
                           float Bx, float By,
                           float Cx, float Cy,
                           float Dx, float Dy, float *T);
// #line 38 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
#include <cctype>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
// #line 104 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
static const int TIXML2_MAJOR_VERSION = 1;
static const int TIXML2_MINOR_VERSION = 0;
static const int TIXML2_PATCH_VERSION = 9;

namespace tinyxml2
{
    class XMLDocument;
    class XMLElement;
    class XMLAttribute;
    class XMLComment;
    class XMLNode;
    class XMLText;
    class XMLDeclaration;
    class XMLUnknown;

    class XMLPrinter;
    // #line 127 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
    class StrPair
    {
    public:
        enum
        {
            NEEDS_ENTITY_PROCESSING = 0x01,
            NEEDS_NEWLINE_NORMALIZATION = 0x02,
            COLLAPSE_WHITESPACE = 0x04,

            TEXT_ELEMENT = NEEDS_ENTITY_PROCESSING | NEEDS_NEWLINE_NORMALIZATION,
            TEXT_ELEMENT_LEAVE_ENTITIES = NEEDS_NEWLINE_NORMALIZATION,
            ATTRIBUTE_NAME = 0,
            ATTRIBUTE_VALUE = NEEDS_ENTITY_PROCESSING | NEEDS_NEWLINE_NORMALIZATION,
            ATTRIBUTE_VALUE_LEAVE_ENTITIES = NEEDS_NEWLINE_NORMALIZATION,
            COMMENT = NEEDS_NEWLINE_NORMALIZATION
        };

        StrPair() : _flags(0), _start(0), _end(0) {}
        ~StrPair();

        void Set(char *start, char *end, int flags)
        {
            Reset();
            _start = start;
            _end = end;
            _flags = flags | NEEDS_FLUSH;
        }

        const char *GetStr();

        bool Empty() const
        {
            return _start == _end;
        }

        void SetInternedStr(const char *str)
        {
            Reset();
            _start = const_cast<char *>(str);
        }

        void SetStr(const char *str, int flags = 0);

        char *ParseText(char *in, const char *endTag, int strFlags);
        char *ParseName(char *in);

    private:
        void Reset();
        void CollapseWhitespace();

        enum
        {
            NEEDS_FLUSH = 0x100,
            NEEDS_DELETE = 0x200
        };

        int _flags;
        char *_start;
        char *_end;
    };
    // #line 190 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
    template <class T, int INIT>
    class DynArray
    {
    public:
        DynArray<T, INIT>()
        {
            _mem = _pool;
            _allocated = INIT;
            _size = 0;
        }

        ~DynArray()
        {
            if (_mem != _pool)
            {
                delete[] _mem;
            }
        }

        void Push(T t)
        {
            EnsureCapacity(_size + 1);
            _mem[_size++] = t;
        }

        T *PushArr(int count)
        {
            EnsureCapacity(_size + count);
            T *ret = &_mem[_size];
            _size += count;
            return ret;
        }

        T Pop()
        {
            return _mem[--_size];
        }

        void PopArr(int count)
        {
            {};
            _size -= count;
        }

        bool Empty() const
        {
            return _size == 0;
        }

        T &operator[](int i)
        {
            {};
            return _mem[i];
        }

        const T &operator[](int i) const
        {
            {};
            return _mem[i];
        }

        int Size() const
        {
            return _size;
        }

        int Capacity() const
        {
            return _allocated;
        }

        const T *Mem() const
        {
            return _mem;
        }

        T *Mem()
        {
            return _mem;
        }

    private:
        void EnsureCapacity(int cap)
        {
            if (cap > _allocated)
            {
                int newAllocated = cap * 2;
                T *newMem = new T[newAllocated];
                memcpy(newMem, _mem, sizeof(T) * _size);
                if (_mem != _pool)
                {
                    delete[] _mem;
                }
                _mem = newMem;
                _allocated = newAllocated;
            }
        }

        T *_mem;
        T _pool[INIT];
        int _allocated;
        int _size;
    };

    class MemPool
    {
    public:
        MemPool() {}
        virtual ~MemPool() {}

        virtual int ItemSize() const = 0;
        virtual void *Alloc() = 0;
        virtual void Free(void *) = 0;
        virtual void SetTracked() = 0;
    };

    template <int SIZE>
    class MemPoolT : public MemPool
    {
    public:
        MemPoolT() : _root(0), _currentAllocs(0), _nAllocs(0), _maxAllocs(0), _nUntracked(0) {}
        ~MemPoolT()
        {

            for (int i = 0; i < _blockPtrs.Size(); ++i)
            {
                delete _blockPtrs[i];
            }
        }

        virtual int ItemSize() const
        {
            return SIZE;
        }
        int CurrentAllocs() const
        {
            return _currentAllocs;
        }

        virtual void *Alloc()
        {
            if (!_root)
            {

                Block *block = new Block();
                _blockPtrs.Push(block);

                for (int i = 0; i < COUNT - 1; ++i)
                {
                    block->chunk[i].next = &block->chunk[i + 1];
                }
                block->chunk[COUNT - 1].next = 0;
                _root = block->chunk;
            }
            void *result = _root;
            _root = _root->next;

            ++_currentAllocs;
            if (_currentAllocs > _maxAllocs)
            {
                _maxAllocs = _currentAllocs;
            }
            _nAllocs++;
            _nUntracked++;
            return result;
        }
        virtual void Free(void *mem)
        {
            if (!mem)
            {
                return;
            }
            --_currentAllocs;
            Chunk *chunk = (Chunk *)mem;

            chunk->next = _root;
            _root = chunk;
        }
        void Trace(const char *name)
        {
            printf("Mempool %s watermark=%d [%dk] current=%d size=%d nAlloc=%d blocks=%d\n",
                   name, _maxAllocs, _maxAllocs * SIZE / 1024, _currentAllocs, SIZE, _nAllocs, _blockPtrs.Size());
        }

        void SetTracked()
        {
            _nUntracked--;
        }

        int Untracked() const
        {
            return _nUntracked;
        }

        enum
        {
            COUNT = 1024 / SIZE
        };

    private:
        union Chunk
        {
            Chunk *next;
            char mem[SIZE];
        };
        struct Block
        {
            Chunk chunk[COUNT];
        };
        DynArray<Block *, 10> _blockPtrs;
        Chunk *_root;

        int _currentAllocs;
        int _nAllocs;
        int _maxAllocs;
        int _nUntracked;
    };
    // #line 405 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
    class XMLVisitor
    {
    public:
        virtual ~XMLVisitor() {}

        virtual bool VisitEnter(const XMLDocument &)
        {
            return true;
        }

        virtual bool VisitExit(const XMLDocument &)
        {
            return true;
        }

        virtual bool VisitEnter(const XMLElement &, const XMLAttribute *)
        {
            return true;
        }

        virtual bool VisitExit(const XMLElement &)
        {
            return true;
        }

        virtual bool Visit(const XMLDeclaration &)
        {
            return true;
        }

        virtual bool Visit(const XMLText &)
        {
            return true;
        }

        virtual bool Visit(const XMLComment &)
        {
            return true;
        }

        virtual bool Visit(const XMLUnknown &)
        {
            return true;
        }
    };

    class XMLUtil
    {
    public:
        static const char *SkipWhiteSpace(const char *p)
        {
            while (!IsUTF8Continuation(*p) && isspace(*reinterpret_cast<const unsigned char *>(p)))
            {
                ++p;
            }
            return p;
        }
        static char *SkipWhiteSpace(char *p)
        {
            while (!IsUTF8Continuation(*p) && isspace(*reinterpret_cast<unsigned char *>(p)))
            {
                ++p;
            }
            return p;
        }
        static bool IsWhiteSpace(char p)
        {
            return !IsUTF8Continuation(p) && isspace(static_cast<unsigned char>(p));
        }

        inline static bool StringEqual(const char *p, const char *q, int nChar = INT_MAX)
        {
            int n = 0;
            if (p == q)
            {
                return true;
            }
            while (*p && *q && *p == *q && n < nChar)
            {
                ++p;
                ++q;
                ++n;
            }
            if ((n == nChar) || (*p == 0 && *q == 0))
            {
                return true;
            }
            return false;
        }
        inline static int IsUTF8Continuation(const char p)
        {
            return p & 0x80;
        }
        inline static int IsAlphaNum(unsigned char anyByte)
        {
            return (anyByte < 128) ? isalnum(anyByte) : 1;
        }
        inline static int IsAlpha(unsigned char anyByte)
        {
            return (anyByte < 128) ? isalpha(anyByte) : 1;
        }

        static const char *ReadBOM(const char *p, bool *hasBOM);

        static const char *GetCharacterRef(const char *p, char *value, int *length);
        static void ConvertUTF32ToUTF8(unsigned long input, char *output, int *length);

        static void ToStr(int v, char *buffer, int bufferSize);
        static void ToStr(unsigned v, char *buffer, int bufferSize);
        static void ToStr(bool v, char *buffer, int bufferSize);
        static void ToStr(float v, char *buffer, int bufferSize);
        static void ToStr(double v, char *buffer, int bufferSize);

        static bool ToInt(const char *str, int *value);
        static bool ToUnsigned(const char *str, unsigned *value);
        static bool ToBool(const char *str, bool *value);
        static bool ToFloat(const char *str, float *value);
        static bool ToDouble(const char *str, double *value);
    };
    // #line 543 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
    class XMLNode
    {
        friend class XMLDocument;
        friend class XMLElement;

    public:
        const XMLDocument *GetDocument() const
        {
            return _document;
        }

        XMLDocument *GetDocument()
        {
            return _document;
        }

        virtual XMLElement *ToElement()
        {
            return 0;
        }

        virtual XMLText *ToText()
        {
            return 0;
        }

        virtual XMLComment *ToComment()
        {
            return 0;
        }

        virtual XMLDocument *ToDocument()
        {
            return 0;
        }

        virtual XMLDeclaration *ToDeclaration()
        {
            return 0;
        }

        virtual XMLUnknown *ToUnknown()
        {
            return 0;
        }

        virtual const XMLElement *ToElement() const
        {
            return 0;
        }
        virtual const XMLText *ToText() const
        {
            return 0;
        }
        virtual const XMLComment *ToComment() const
        {
            return 0;
        }
        virtual const XMLDocument *ToDocument() const
        {
            return 0;
        }
        virtual const XMLDeclaration *ToDeclaration() const
        {
            return 0;
        }
        virtual const XMLUnknown *ToUnknown() const
        {
            return 0;
        }
        // #line 611 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
        const char *Value() const
        {
            return _value.GetStr();
        }

        void SetValue(const char *val, bool staticMem = false);

        const XMLNode *Parent() const
        {
            return _parent;
        }

        XMLNode *Parent()
        {
            return _parent;
        }

        bool NoChildren() const
        {
            return !_firstChild;
        }

        const XMLNode *FirstChild() const
        {
            return _firstChild;
        }

        XMLNode *FirstChild()
        {
            return _firstChild;
        }

        const XMLElement *FirstChildElement(const char *value = 0) const;

        XMLElement *FirstChildElement(const char *value = 0)
        {
            return const_cast<XMLElement *>(const_cast<const XMLNode *>(this)->FirstChildElement(value));
        }

        const XMLNode *LastChild() const
        {
            return _lastChild;
        }

        XMLNode *LastChild()
        {
            return const_cast<XMLNode *>(const_cast<const XMLNode *>(this)->LastChild());
        }

        const XMLElement *LastChildElement(const char *value = 0) const;

        XMLElement *LastChildElement(const char *value = 0)
        {
            return const_cast<XMLElement *>(const_cast<const XMLNode *>(this)->LastChildElement(value));
        }

        const XMLNode *PreviousSibling() const
        {
            return _prev;
        }

        XMLNode *PreviousSibling()
        {
            return _prev;
        }

        const XMLElement *PreviousSiblingElement(const char *value = 0) const;

        XMLElement *PreviousSiblingElement(const char *value = 0)
        {
            return const_cast<XMLElement *>(const_cast<const XMLNode *>(this)->PreviousSiblingElement(value));
        }

        const XMLNode *NextSibling() const
        {
            return _next;
        }

        XMLNode *NextSibling()
        {
            return _next;
        }

        const XMLElement *NextSiblingElement(const char *value = 0) const;

        XMLElement *NextSiblingElement(const char *value = 0)
        {
            return const_cast<XMLElement *>(const_cast<const XMLNode *>(this)->NextSiblingElement(value));
        }

        XMLNode *InsertEndChild(XMLNode *addThis);

        XMLNode *LinkEndChild(XMLNode *addThis)
        {
            return InsertEndChild(addThis);
        }

        XMLNode *InsertFirstChild(XMLNode *addThis);

        XMLNode *InsertAfterChild(XMLNode *afterThis, XMLNode *addThis);

        void DeleteChildren();

        void DeleteChild(XMLNode *node);
        // #line 738 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
        virtual XMLNode *ShallowClone(XMLDocument *document) const = 0;
        // #line 746 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
        virtual bool ShallowEqual(const XMLNode *compare) const = 0;
        // #line 770 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
        virtual bool Accept(XMLVisitor *visitor) const = 0;

        virtual char *ParseDeep(char *, StrPair *);

    protected:
        XMLNode(XMLDocument *);
        virtual ~XMLNode();
        XMLNode(const XMLNode &);
        XMLNode &operator=(const XMLNode &);

        XMLDocument *_document;
        XMLNode *_parent;
        mutable StrPair _value;

        XMLNode *_firstChild;
        XMLNode *_lastChild;

        XMLNode *_prev;
        XMLNode *_next;

    private:
        MemPool *_memPool;
        void Unlink(XMLNode *child);
    };
    // #line 809 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
    class XMLText : public XMLNode
    {
        friend class XMLBase;
        friend class XMLDocument;

    public:
        virtual bool Accept(XMLVisitor *visitor) const;

        virtual XMLText *ToText()
        {
            return this;
        }
        virtual const XMLText *ToText() const
        {
            return this;
        }

        void SetCData(bool isCData)
        {
            _isCData = isCData;
        }

        bool CData() const
        {
            return _isCData;
        }

        char *ParseDeep(char *, StrPair *endTag);
        virtual XMLNode *ShallowClone(XMLDocument *document) const;
        virtual bool ShallowEqual(const XMLNode *compare) const;

    protected:
        XMLText(XMLDocument *doc) : XMLNode(doc), _isCData(false) {}
        virtual ~XMLText() {}
        XMLText(const XMLText &);
        XMLText &operator=(const XMLText &);

    private:
        bool _isCData;
    };

    class XMLComment : public XMLNode
    {
        friend class XMLDocument;

    public:
        virtual XMLComment *ToComment()
        {
            return this;
        }
        virtual const XMLComment *ToComment() const
        {
            return this;
        }

        virtual bool Accept(XMLVisitor *visitor) const;

        char *ParseDeep(char *, StrPair *endTag);
        virtual XMLNode *ShallowClone(XMLDocument *document) const;
        virtual bool ShallowEqual(const XMLNode *compare) const;

    protected:
        XMLComment(XMLDocument *doc);
        virtual ~XMLComment();
        XMLComment(const XMLComment &);
        XMLComment &operator=(const XMLComment &);

    private:
    };
    // #line 886 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
    class XMLDeclaration : public XMLNode
    {
        friend class XMLDocument;

    public:
        virtual XMLDeclaration *ToDeclaration()
        {
            return this;
        }
        virtual const XMLDeclaration *ToDeclaration() const
        {
            return this;
        }

        virtual bool Accept(XMLVisitor *visitor) const;

        char *ParseDeep(char *, StrPair *endTag);
        virtual XMLNode *ShallowClone(XMLDocument *document) const;
        virtual bool ShallowEqual(const XMLNode *compare) const;

    protected:
        XMLDeclaration(XMLDocument *doc);
        virtual ~XMLDeclaration();
        XMLDeclaration(const XMLDeclaration &);
        XMLDeclaration &operator=(const XMLDeclaration &);
    };
    // #line 918 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
    class XMLUnknown : public XMLNode
    {
        friend class XMLDocument;

    public:
        virtual XMLUnknown *ToUnknown()
        {
            return this;
        }
        virtual const XMLUnknown *ToUnknown() const
        {
            return this;
        }

        virtual bool Accept(XMLVisitor *visitor) const;

        char *ParseDeep(char *, StrPair *endTag);
        virtual XMLNode *ShallowClone(XMLDocument *document) const;
        virtual bool ShallowEqual(const XMLNode *compare) const;

    protected:
        XMLUnknown(XMLDocument *doc);
        virtual ~XMLUnknown();
        XMLUnknown(const XMLUnknown &);
        XMLUnknown &operator=(const XMLUnknown &);
    };

    enum XMLError
    {
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
    // #line 977 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
    class XMLAttribute
    {
        friend class XMLElement;

    public:
        const char *Name() const
        {
            return _name.GetStr();
        }

        const char *Value() const
        {
            return _value.GetStr();
        }

        const XMLAttribute *Next() const
        {
            return _next;
        }

        int IntValue() const
        {
            int i = 0;
            QueryIntValue(&i);
            return i;
        }

        unsigned UnsignedValue() const
        {
            unsigned i = 0;
            QueryUnsignedValue(&i);
            return i;
        }

        bool BoolValue() const
        {
            bool b = false;
            QueryBoolValue(&b);
            return b;
        }

        double DoubleValue() const
        {
            double d = 0;
            QueryDoubleValue(&d);
            return d;
        }

        float FloatValue() const
        {
            float f = 0;
            QueryFloatValue(&f);
            return f;
        }

        XMLError QueryIntValue(int *value) const;

        XMLError QueryUnsignedValue(unsigned int *value) const;

        XMLError QueryBoolValue(bool *value) const;

        XMLError QueryDoubleValue(double *value) const;

        XMLError QueryFloatValue(float *value) const;

        void SetAttribute(const char *value);

        void SetAttribute(int value);

        void SetAttribute(unsigned value);

        void SetAttribute(bool value);

        void SetAttribute(double value);

        void SetAttribute(float value);

    private:
        enum
        {
            BUF_SIZE = 200
        };

        XMLAttribute() : _next(0) {}
        virtual ~XMLAttribute() {}

        XMLAttribute(const XMLAttribute &);
        void operator=(const XMLAttribute &);
        void SetName(const char *name);

        char *ParseDeep(char *p, bool processEntities);

        mutable StrPair _name;
        mutable StrPair _value;
        XMLAttribute *_next;
        MemPool *_memPool;
    };

    class XMLElement : public XMLNode
    {
        friend class XMLBase;
        friend class XMLDocument;

    public:
        const char *Name() const
        {
            return Value();
        }

        void SetName(const char *str, bool staticMem = false)
        {
            SetValue(str, staticMem);
        }

        virtual XMLElement *ToElement()
        {
            return this;
        }
        virtual const XMLElement *ToElement() const
        {
            return this;
        }
        virtual bool Accept(XMLVisitor *visitor) const;
        // #line 1123 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
        const char *Attribute(const char *name, const char *value = 0) const;

        int IntAttribute(const char *name) const
        {
            int i = 0;
            QueryIntAttribute(name, &i);
            return i;
        }

        unsigned UnsignedAttribute(const char *name) const
        {
            unsigned i = 0;
            QueryUnsignedAttribute(name, &i);
            return i;
        }

        bool BoolAttribute(const char *name) const
        {
            bool b = false;
            QueryBoolAttribute(name, &b);
            return b;
        }

        double DoubleAttribute(const char *name) const
        {
            double d = 0;
            QueryDoubleAttribute(name, &d);
            return d;
        }

        float FloatAttribute(const char *name) const
        {
            float f = 0;
            QueryFloatAttribute(name, &f);
            return f;
        }
        // #line 1173 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
        XMLError QueryIntAttribute(const char *name, int *value) const
        {
            const XMLAttribute *a = FindAttribute(name);
            if (!a)
            {
                return XML_NO_ATTRIBUTE;
            }
            return a->QueryIntValue(value);
        }

        XMLError QueryUnsignedAttribute(const char *name, unsigned int *value) const
        {
            const XMLAttribute *a = FindAttribute(name);
            if (!a)
            {
                return XML_NO_ATTRIBUTE;
            }
            return a->QueryUnsignedValue(value);
        }

        XMLError QueryBoolAttribute(const char *name, bool *value) const
        {
            const XMLAttribute *a = FindAttribute(name);
            if (!a)
            {
                return XML_NO_ATTRIBUTE;
            }
            return a->QueryBoolValue(value);
        }

        XMLError QueryDoubleAttribute(const char *name, double *value) const
        {
            const XMLAttribute *a = FindAttribute(name);
            if (!a)
            {
                return XML_NO_ATTRIBUTE;
            }
            return a->QueryDoubleValue(value);
        }

        XMLError QueryFloatAttribute(const char *name, float *value) const
        {
            const XMLAttribute *a = FindAttribute(name);
            if (!a)
            {
                return XML_NO_ATTRIBUTE;
            }
            return a->QueryFloatValue(value);
        }

        void SetAttribute(const char *name, const char *value)
        {
            XMLAttribute *a = FindOrCreateAttribute(name);
            a->SetAttribute(value);
        }

        void SetAttribute(const char *name, int value)
        {
            XMLAttribute *a = FindOrCreateAttribute(name);
            a->SetAttribute(value);
        }

        void SetAttribute(const char *name, unsigned value)
        {
            XMLAttribute *a = FindOrCreateAttribute(name);
            a->SetAttribute(value);
        }

        void SetAttribute(const char *name, bool value)
        {
            XMLAttribute *a = FindOrCreateAttribute(name);
            a->SetAttribute(value);
        }

        void SetAttribute(const char *name, double value)
        {
            XMLAttribute *a = FindOrCreateAttribute(name);
            a->SetAttribute(value);
        }

        void DeleteAttribute(const char *name);

        const XMLAttribute *FirstAttribute() const
        {
            return _rootAttribute;
        }

        const XMLAttribute *FindAttribute(const char *name) const;
        // #line 1279 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
        const char *GetText() const;
        // #line 1307 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
        XMLError QueryIntText(int *ival) const;

        XMLError QueryUnsignedText(unsigned *uval) const;

        XMLError QueryBoolText(bool *bval) const;

        XMLError QueryDoubleText(double *dval) const;

        XMLError QueryFloatText(float *fval) const;

        enum
        {
            OPEN,
            CLOSED,
            CLOSING
        };
        int ClosingType() const
        {
            return _closingType;
        }
        char *ParseDeep(char *p, StrPair *endTag);
        virtual XMLNode *ShallowClone(XMLDocument *document) const;
        virtual bool ShallowEqual(const XMLNode *compare) const;

    private:
        XMLElement(XMLDocument *doc);
        virtual ~XMLElement();
        XMLElement(const XMLElement &);
        void operator=(const XMLElement &);

        XMLAttribute *FindAttribute(const char *name);
        XMLAttribute *FindOrCreateAttribute(const char *name);

        char *ParseAttributes(char *p);

        int _closingType;

        XMLAttribute *_rootAttribute;
    };

    enum Whitespace
    {
        PRESERVE_WHITESPACE,
        COLLAPSE_WHITESPACE
    };
    // #line 1360 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
    class XMLDocument : public XMLNode
    {
        friend class XMLElement;

    public:
        XMLDocument(bool processEntities = true, Whitespace = PRESERVE_WHITESPACE);
        ~XMLDocument();

        virtual XMLDocument *ToDocument()
        {
            return this;
        }
        virtual const XMLDocument *ToDocument() const
        {
            return this;
        }
        // #line 1385 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
        XMLError Parse(const char *xml, size_t nBytes = (size_t)(-1));

        XMLError LoadFile(const char *filename);
        // #line 1401 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
        XMLError LoadFile(FILE *);

        XMLError SaveFile(const char *filename, bool compact = false);
        // #line 1417 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
        XMLError SaveFile(FILE *fp, bool compact = false);

        bool ProcessEntities() const
        {
            return _processEntities;
        }
        Whitespace WhitespaceMode() const
        {
            return _whitespace;
        }

        bool HasBOM() const
        {
            return _writeBOM;
        }

        void SetBOM(bool useBOM)
        {
            _writeBOM = useBOM;
        }

        XMLElement *RootElement()
        {
            return FirstChildElement();
        }
        const XMLElement *RootElement() const
        {
            return FirstChildElement();
        }
        // #line 1462 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
        void Print(XMLPrinter *streamer = 0);
        virtual bool Accept(XMLVisitor *visitor) const;

        XMLElement *NewElement(const char *name);

        XMLComment *NewComment(const char *comment);

        XMLText *NewText(const char *text);
        // #line 1494 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
        XMLDeclaration *NewDeclaration(const char *text = 0);

        XMLUnknown *NewUnknown(const char *text);

        void DeleteNode(XMLNode *node)
        {
            node->_parent->DeleteChild(node);
        }

        void SetError(XMLError error, const char *str1, const char *str2);

        bool Error() const
        {
            return _errorID != XML_NO_ERROR;
        }

        XMLError ErrorID() const
        {
            return _errorID;
        }

        const char *GetErrorStr1() const
        {
            return _errorStr1;
        }

        const char *GetErrorStr2() const
        {
            return _errorStr2;
        }

        void PrintError() const;

        char *Identify(char *p, XMLNode **node);

        virtual XMLNode *ShallowClone(XMLDocument *) const
        {
            return 0;
        }
        virtual bool ShallowEqual(const XMLNode *) const
        {
            return false;
        }

    private:
        XMLDocument(const XMLDocument &);
        void operator=(const XMLDocument &);
        void InitDocument();

        bool _writeBOM;
        bool _processEntities;
        XMLError _errorID;
        Whitespace _whitespace;
        const char *_errorStr1;
        const char *_errorStr2;
        char *_charBuffer;

        MemPoolT<sizeof(XMLElement)> _elementPool;
        MemPoolT<sizeof(XMLAttribute)> _attributePool;
        MemPoolT<sizeof(XMLText)> _textPool;
        MemPoolT<sizeof(XMLComment)> _commentPool;
    };
    // #line 1616 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
    class XMLHandle
    {
    public:
        XMLHandle(XMLNode *node)
        {
            _node = node;
        }

        XMLHandle(XMLNode &node)
        {
            _node = &node;
        }

        XMLHandle(const XMLHandle &ref)
        {
            _node = ref._node;
        }

        XMLHandle &operator=(const XMLHandle &ref)
        {
            _node = ref._node;
            return *this;
        }

        XMLHandle FirstChild()
        {
            return XMLHandle(_node ? _node->FirstChild() : 0);
        }

        XMLHandle FirstChildElement(const char *value = 0)
        {
            return XMLHandle(_node ? _node->FirstChildElement(value) : 0);
        }

        XMLHandle LastChild()
        {
            return XMLHandle(_node ? _node->LastChild() : 0);
        }

        XMLHandle LastChildElement(const char *_value = 0)
        {
            return XMLHandle(_node ? _node->LastChildElement(_value) : 0);
        }

        XMLHandle PreviousSibling()
        {
            return XMLHandle(_node ? _node->PreviousSibling() : 0);
        }

        XMLHandle PreviousSiblingElement(const char *_value = 0)
        {
            return XMLHandle(_node ? _node->PreviousSiblingElement(_value) : 0);
        }

        XMLHandle NextSibling()
        {
            return XMLHandle(_node ? _node->NextSibling() : 0);
        }

        XMLHandle NextSiblingElement(const char *_value = 0)
        {
            return XMLHandle(_node ? _node->NextSiblingElement(_value) : 0);
        }

        XMLNode *ToNode()
        {
            return _node;
        }

        XMLElement *ToElement()
        {
            return ((_node && _node->ToElement()) ? _node->ToElement() : 0);
        }

        XMLText *ToText()
        {
            return ((_node && _node->ToText()) ? _node->ToText() : 0);
        }

        XMLUnknown *ToUnknown()
        {
            return ((_node && _node->ToUnknown()) ? _node->ToUnknown() : 0);
        }

        XMLDeclaration *ToDeclaration()
        {
            return ((_node && _node->ToDeclaration()) ? _node->ToDeclaration() : 0);
        }

    private:
        XMLNode *_node;
    };

    class XMLConstHandle
    {
    public:
        XMLConstHandle(const XMLNode *node)
        {
            _node = node;
        }
        XMLConstHandle(const XMLNode &node)
        {
            _node = &node;
        }
        XMLConstHandle(const XMLConstHandle &ref)
        {
            _node = ref._node;
        }

        XMLConstHandle &operator=(const XMLConstHandle &ref)
        {
            _node = ref._node;
            return *this;
        }

        const XMLConstHandle FirstChild() const
        {
            return XMLConstHandle(_node ? _node->FirstChild() : 0);
        }
        const XMLConstHandle FirstChildElement(const char *value = 0) const
        {
            return XMLConstHandle(_node ? _node->FirstChildElement(value) : 0);
        }
        const XMLConstHandle LastChild() const
        {
            return XMLConstHandle(_node ? _node->LastChild() : 0);
        }
        const XMLConstHandle LastChildElement(const char *_value = 0) const
        {
            return XMLConstHandle(_node ? _node->LastChildElement(_value) : 0);
        }
        const XMLConstHandle PreviousSibling() const
        {
            return XMLConstHandle(_node ? _node->PreviousSibling() : 0);
        }
        const XMLConstHandle PreviousSiblingElement(const char *_value = 0) const
        {
            return XMLConstHandle(_node ? _node->PreviousSiblingElement(_value) : 0);
        }
        const XMLConstHandle NextSibling() const
        {
            return XMLConstHandle(_node ? _node->NextSibling() : 0);
        }
        const XMLConstHandle NextSiblingElement(const char *_value = 0) const
        {
            return XMLConstHandle(_node ? _node->NextSiblingElement(_value) : 0);
        }

        const XMLNode *ToNode() const
        {
            return _node;
        }
        const XMLElement *ToElement() const
        {
            return ((_node && _node->ToElement()) ? _node->ToElement() : 0);
        }
        const XMLText *ToText() const
        {
            return ((_node && _node->ToText()) ? _node->ToText() : 0);
        }
        const XMLUnknown *ToUnknown() const
        {
            return ((_node && _node->ToUnknown()) ? _node->ToUnknown() : 0);
        }
        const XMLDeclaration *ToDeclaration() const
        {
            return ((_node && _node->ToDeclaration()) ? _node->ToDeclaration() : 0);
        }

    private:
        const XMLNode *_node;
    };
    // #line 1807 "cocos2d/cocos-headers/cocos2dx/support/tinyxml2/tinyxml2.h"
    class XMLPrinter : public XMLVisitor
    {
    public:
        XMLPrinter(FILE *file = 0, bool compact = false);
        ~XMLPrinter() {}

        void PushHeader(bool writeBOM, bool writeDeclaration);

        void OpenElement(const char *name);

        void PushAttribute(const char *name, const char *value);
        void PushAttribute(const char *name, int value);
        void PushAttribute(const char *name, unsigned value);
        void PushAttribute(const char *name, bool value);
        void PushAttribute(const char *name, double value);

        void CloseElement();

        void PushText(const char *text, bool cdata = false);

        void PushText(int value);

        void PushText(unsigned value);

        void PushText(bool value);

        void PushText(float value);

        void PushText(double value);

        void PushComment(const char *comment);

        void PushDeclaration(const char *value);
        void PushUnknown(const char *value);

        virtual bool VisitEnter(const XMLDocument &);
        virtual bool VisitExit(const XMLDocument &)
        {
            return true;
        }

        virtual bool VisitEnter(const XMLElement &element, const XMLAttribute *attribute);
        virtual bool VisitExit(const XMLElement &element);

        virtual bool Visit(const XMLText &text);
        virtual bool Visit(const XMLComment &comment);
        virtual bool Visit(const XMLDeclaration &declaration);
        virtual bool Visit(const XMLUnknown &unknown);

        const char *CStr() const
        {
            return _buffer.Mem();
        }

        int CStrSize() const
        {
            return _buffer.Size();
        }

    private:
        void SealElement();
        void PrintSpace(int depth);
        void PrintString(const char *, bool restrictedEntitySet);
        void Print(const char *format, ...);

        bool _elementJustOpened;
        bool _firstElement;
        FILE *_fp;
        int _depth;
        int _textDepth;
        bool _processEntities;
        bool _compactMode;

        enum
        {
            ENTITY_RANGE = 64,
            BUF_SIZE = 200
        };
        bool _entityFlag[ENTITY_RANGE];
        bool _restrictedEntityFlag[ENTITY_RANGE];

        DynArray<const char *, 10> _stack;
        DynArray<char, 20> _buffer;
    };

}
// #line 37 "cocos2d/cocos-headers/cocos2dx/text_input_node/CCIMEDelegate.h"
typedef struct
{
    CCRect begin;
    CCRect end;
    float duration;
} CCIMEKeyboardNotificationInfo;

class CCIMEDelegate
{
public:
    virtual ~CCIMEDelegate();

    virtual bool attachWithIME();
    virtual bool detachWithIME();

protected:
    friend class CCIMEDispatcher;

    virtual bool canAttachWithIME() { return false; }

    virtual void didAttachWithIME() {}

    virtual bool canDetachWithIME() { return false; }

    virtual void didDetachWithIME();
    virtual void insertText(const char *text, int len);
    virtual void deleteBackward();

    virtual const char *getContentText() { return 0; }
    // #line 99 "cocos2d/cocos-headers/cocos2dx/text_input_node/CCIMEDelegate.h"
    virtual void keyboardWillShow(CCIMEKeyboardNotificationInfo &info);
    virtual void keyboardDidShow(CCIMEKeyboardNotificationInfo &info);
    virtual void keyboardWillHide(CCIMEKeyboardNotificationInfo &info);
    virtual void keyboardDidHide(CCIMEKeyboardNotificationInfo &info);

protected:
    CCIMEDelegate();
};
// #line 42 "cocos2d/cocos-headers/cocos2dx/text_input_node/CCIMEDispatcher.h"
class CCIMEDispatcher
{
public:
    ~CCIMEDispatcher();

    static CCIMEDispatcher *sharedDispatcher();
    // #line 60 "cocos2d/cocos-headers/cocos2dx/text_input_node/CCIMEDispatcher.h"
    void dispatchInsertText(const char *pText, int nLen);

    void dispatchDeleteBackward();

    const char *getContentText();
    // #line 75 "cocos2d/cocos-headers/cocos2dx/text_input_node/CCIMEDispatcher.h"
    void dispatchKeyboardWillShow(CCIMEKeyboardNotificationInfo &info);
    void dispatchKeyboardDidShow(CCIMEKeyboardNotificationInfo &info);
    void dispatchKeyboardWillHide(CCIMEKeyboardNotificationInfo &info);
    void dispatchKeyboardDidHide(CCIMEKeyboardNotificationInfo &info);

protected:
    friend class CCIMEDelegate;

    void addDelegate(CCIMEDelegate *pDelegate);

    bool attachDelegateWithIME(CCIMEDelegate *pDelegate);
    bool detachDelegateWithIME(CCIMEDelegate *pDelegate);

    void removeDelegate(CCIMEDelegate *pDelegate);

private:
    CCIMEDispatcher();

    class Impl;
    Impl *m_pImpl;
};
// #line 34 "cocos2d/cocos-headers/cocos2dx/text_input_node/CCTextFieldTTF.h"
class CCTextFieldTTF;
// #line 43 "cocos2d/cocos-headers/cocos2dx/text_input_node/CCTextFieldTTF.h"
class CCTextFieldDelegate
{
public:
    virtual bool onTextFieldAttachWithIME(CCTextFieldTTF *sender);
    virtual bool onTextFieldDetachWithIME(CCTextFieldTTF *sender);

    virtual bool onTextFieldInsertText(CCTextFieldTTF *sender, const char *text, int nLen);

    virtual bool onTextFieldDeleteBackward(CCTextFieldTTF *sender, const char *delText, int nLen);
    virtual bool onDraw(CCTextFieldTTF *sender);
};

class CCTextFieldTTF : public CCLabelTTF, public CCIMEDelegate
{
public:
    CCTextFieldTTF();

    virtual ~CCTextFieldTTF();

    static CCTextFieldTTF *textFieldWithPlaceHolder(const char *placeholder, const CCSize &dimensions, CCTextAlignment alignment, const char *fontName, float fontSize);

    static CCTextFieldTTF *textFieldWithPlaceHolder(const char *placeholder, const char *fontName, float fontSize);

    bool initWithPlaceHolder(const char *placeholder, const CCSize &dimensions, CCTextAlignment alignment, const char *fontName, float fontSize);

    bool initWithPlaceHolder(const char *placeholder, const char *fontName, float fontSize);

    virtual bool attachWithIME();

    virtual bool detachWithIME();

protected:
    CCTextFieldDelegate *m_pDelegate;

public:
    virtual CCTextFieldDelegate *getDelegate(void) const { return m_pDelegate; }

public:
    virtual void setDelegate(CCTextFieldDelegate *var) { m_pDelegate = var; };

protected:
    int m_nCharCount;

public:
    virtual int getCharCount(void) const { return m_nCharCount; };
    virtual const ccColor3B &getColorSpaceHolder();
    virtual void setColorSpaceHolder(const ccColor3B &color);

public:
    virtual void setString(const char *text);
    virtual const char *getString(void);

protected:
    std::string *m_pInputText;

public:
    virtual void setPlaceHolder(const char *text);
    virtual const char *getPlaceHolder(void);

protected:
    std::string *m_pPlaceHolder;
    ccColor3B m_ColorSpaceHolder;

public:
    virtual void setSecureTextEntry(bool value);
    virtual bool isSecureTextEntry();

protected:
    bool m_bSecureTextEntry;

protected:
    virtual void draw();
    // #line 170 "cocos2d/cocos-headers/cocos2dx/text_input_node/CCTextFieldTTF.h"
    virtual bool canAttachWithIME();
    virtual bool canDetachWithIME();
    virtual void insertText(const char *text, int len);
    virtual void deleteBackward();
    virtual const char *getContentText();

private:
    class LengthStack;
    LengthStack *m_pLens;
};
// #line 34 "cocos2d/cocos-headers/cocos2dx/textures/CCTextureCache.h"
#include <string>
// #line 44 "cocos2d/cocos-headers/cocos2dx/textures/CCTextureCache.h"
class CCLock;
class CCImage;
// #line 56 "cocos2d/cocos-headers/cocos2dx/textures/CCTextureCache.h"
class CCTextureCache : public CCObject
{
protected:
    CCDictionary *m_pTextures;

private:
    void addImageAsyncCallBack(float dt);

public:
    CCTextureCache();

    virtual ~CCTextureCache();

    const char *description(void);

    CCDictionary *snapshotTextures();

    static CCTextureCache *sharedTextureCache();

    static void purgeSharedTextureCache();
    // #line 105 "cocos2d/cocos-headers/cocos2dx/textures/CCTextureCache.h"
    CCTexture2D *addImage(const char *fileimage, bool);
    // #line 116 "cocos2d/cocos-headers/cocos2dx/textures/CCTextureCache.h"
    void addImageAsync(const char *path, CCObject *target, SEL_CallFuncO selector);
    // #line 132 "cocos2d/cocos-headers/cocos2dx/textures/CCTextureCache.h"
    CCTexture2D *addUIImage(CCImage *image, const char *key);

    CCTexture2D *textureForKey(const char *key);
    // #line 145 "cocos2d/cocos-headers/cocos2dx/textures/CCTextureCache.h"
    bool reloadTexture(const char *fileName);
    // #line 153 "cocos2d/cocos-headers/cocos2dx/textures/CCTextureCache.h"
    void removeAllTextures();

    void removeUnusedTextures();

    void removeTexture(CCTexture2D *texture);

    void removeTextureForKey(const char *textureKeyName);

    void dumpCachedTextureInfo();

    CCTexture2D *addPVRImage(const char *filename);

    CCTexture2D *addETCImage(const char *filename);

    static void reloadAllTextures();
};
// #line 29 "cocos2d/cocos-headers/cocos2dx/textures/CCTexturePVR.h"
// #line 44 "cocos2d/cocos-headers/cocos2dx/textures/CCTexturePVR.h"
struct CCPVRMipmap
{
    unsigned char *address;
    unsigned int len;
};

typedef struct _ccPVRTexturePixelFormatInfo
{
    GLenum internalFormat;
    GLenum format;
    GLenum type;
    uint32_t bpp;
    bool compressed;
    bool alpha;
    CCTexture2DPixelFormat ccPixelFormat;
} ccPVRTexturePixelFormatInfo;

enum
{
    CC_PVRMIPMAP_MAX = 16,
};
// #line 92 "cocos2d/cocos-headers/cocos2dx/textures/CCTexturePVR.h"
class CCTexturePVR : public CCObject
{
public:
    CCTexturePVR();
    virtual ~CCTexturePVR();

    bool initWithContentsOfFile(const char *path);

    static CCTexturePVR *create(const char *path);

    inline unsigned int getName() { return m_uName; }

    inline unsigned int getWidth() { return m_uWidth; }

    inline unsigned int getHeight() { return m_uHeight; }

    inline bool hasAlpha() { return m_bHasAlpha; }

    inline bool hasPremultipliedAlpha() { return m_bHasPremultipliedAlpha; }

    inline bool isForcePremultipliedAlpha() { return m_bForcePremultipliedAlpha; }

    inline unsigned int getNumberOfMipmaps() { return m_uNumberOfMipmaps; }
    inline CCTexture2DPixelFormat getFormat() { return m_eFormat; }
    inline bool isRetainName() { return m_bRetainName; }
    inline void setRetainName(bool retainName) { m_bRetainName = retainName; }

private:
    bool unpackPVRv2Data(unsigned char *data, unsigned int len);
    bool unpackPVRv3Data(unsigned char *dataPointer, unsigned int dataLength);
    bool createGLTexture();

protected:
    struct CCPVRMipmap m_asMipmaps[CC_PVRMIPMAP_MAX];
    unsigned int m_uNumberOfMipmaps;

    unsigned int m_uWidth, m_uHeight;
    GLuint m_uName;
    bool m_bHasAlpha;
    bool m_bHasPremultipliedAlpha;
    bool m_bForcePremultipliedAlpha;

    bool m_bRetainName;
    CCTexture2DPixelFormat m_eFormat;

    const ccPVRTexturePixelFormatInfo *m_pPixelFormatInfo;
};
// #line 34 "cocos2d/cocos-headers/cocos2dx/tilemap_parallax_nodes/CCParallaxNode.h"
struct _ccArray;
// #line 46 "cocos2d/cocos-headers/cocos2dx/tilemap_parallax_nodes/CCParallaxNode.h"
class CCParallaxNode : public CCNode
{

protected:
    struct _ccArray *m_pParallaxArray;

public:
    virtual struct _ccArray *getParallaxArray(void) const { return m_pParallaxArray; }

public:
    virtual void setParallaxArray(struct _ccArray *var) { m_pParallaxArray = var; }

public:
    CCParallaxNode();

    virtual ~CCParallaxNode();

    static CCParallaxNode *create();
    virtual void addChild(CCNode *child, unsigned int z, const CCPoint &parallaxRatio, const CCPoint &positionOffset);

    virtual void addChild(CCNode *child, unsigned int zOrder, int tag);
    virtual void removeChild(CCNode *child, bool cleanup);
    virtual void removeAllChildrenWithCleanup(bool cleanup);
    virtual void visit(void);

private:
    CCPoint absolutePosition();

protected:
    CCPoint m_tLastPosition;
};
// #line 45 "cocos2d/cocos-headers/cocos2dx/tilemap_parallax_nodes/CCTMXObjectGroup.h"
class CCTMXObjectGroup : public CCObject
{

protected:
    CCPoint m_tPositionOffset;

public:
    virtual const CCPoint &getPositionOffset(void) const { return m_tPositionOffset; }

public:
    virtual void setPositionOffset(const CCPoint &var) { m_tPositionOffset = var; };

protected:
    CCDictionary *m_pProperties;

public:
    virtual CCDictionary *getProperties(void);

public:
    virtual void setProperties(CCDictionary *var);
    ;

protected:
    CCArray *m_pObjects;

public:
    virtual CCArray *getObjects(void);

public:
    virtual void setObjects(CCArray *var);
    ;

public:
    CCTMXObjectGroup();

    virtual ~CCTMXObjectGroup();

    inline const char *getGroupName() { return m_sGroupName.c_str(); }
    inline void setGroupName(const char *groupName) { m_sGroupName = groupName; }

    CCString *propertyNamed(const char *propertyName);

    CCDictionary *objectNamed(const char *objectName);

protected:
    std::string m_sGroupName;
};
// #line 36 "cocos2d/cocos-headers/cocos2dx/tilemap_parallax_nodes/CCTMXXMLParser.h"
#include <string>

class CCTMXObjectGroup;
// #line 55 "cocos2d/cocos-headers/cocos2dx/tilemap_parallax_nodes/CCTMXXMLParser.h"
enum
{
    TMXLayerAttribNone = 1 << 0,
    TMXLayerAttribBase64 = 1 << 1,
    TMXLayerAttribGzip = 1 << 2,
    TMXLayerAttribZlib = 1 << 3,
};

enum
{
    TMXPropertyNone,
    TMXPropertyMap,
    TMXPropertyLayer,
    TMXPropertyObjectGroup,
    TMXPropertyObject,
    TMXPropertyTile
};

typedef enum ccTMXTileFlags_
{
    kCCTMXTileHorizontalFlag = 0x80000000,
    kCCTMXTileVerticalFlag = 0x40000000,
    kCCTMXTileDiagonalFlag = 0x20000000,
    kCCFlipedAll = (kCCTMXTileHorizontalFlag | kCCTMXTileVerticalFlag | kCCTMXTileDiagonalFlag),
    kCCFlippedMask = ~(kCCFlipedAll)
} ccTMXTileFlags;
// #line 89 "cocos2d/cocos-headers/cocos2dx/tilemap_parallax_nodes/CCTMXXMLParser.h"
class CCTMXLayerInfo : public CCObject
{
protected:
    CCDictionary *m_pProperties;

public:
    virtual CCDictionary *getProperties(void);

public:
    virtual void setProperties(CCDictionary *var);
    ;

public:
    std::string m_sName;
    CCSize m_tLayerSize;
    unsigned int *m_pTiles;
    bool m_bVisible;
    unsigned char m_cOpacity;
    bool m_bOwnTiles;
    unsigned int m_uMinGID;
    unsigned int m_uMaxGID;
    CCPoint m_tOffset;

public:
    CCTMXLayerInfo();
    virtual ~CCTMXLayerInfo();
};
// #line 117 "cocos2d/cocos-headers/cocos2dx/tilemap_parallax_nodes/CCTMXXMLParser.h"
class CCTMXTilesetInfo : public CCObject
{
public:
    std::string m_sName;
    unsigned int m_uFirstGid;
    CCSize m_tTileSize;
    unsigned int m_uSpacing;
    unsigned int m_uMargin;

    std::string m_sSourceImage;

    CCSize m_tImageSize;

public:
    CCTMXTilesetInfo();
    virtual ~CCTMXTilesetInfo();
    CCRect rectForGID(unsigned int gid);
};

// #line 148 "cocos2d/cocos-headers/cocos2dx/tilemap_parallax_nodes/CCTMXXMLParser.h"
class CCTMXMapInfo : public CCObject
{
public:
protected:
    int m_nOrientation;

public:
    virtual int getOrientation(void) const { return m_nOrientation; }

public:
    virtual void setOrientation(int var) { m_nOrientation = var; };

protected:
    CCSize m_tMapSize;

public:
    virtual const CCSize &getMapSize(void) const { return m_tMapSize; }

public:
    virtual void setMapSize(const CCSize &var) { m_tMapSize = var; };

protected:
    CCSize m_tTileSize;

public:
    virtual const CCSize &getTileSize(void) const { return m_tTileSize; }

public:
    virtual void setTileSize(const CCSize &var) { m_tTileSize = var; };

protected:
    CCArray *m_pLayers;

public:
    virtual CCArray *getLayers(void);

public:
    virtual void setLayers(CCArray *var);
    ;

protected:
    CCArray *m_pTilesets;

public:
    virtual CCArray *getTilesets(void);

public:
    virtual void setTilesets(CCArray *var);
    ;

protected:
    CCArray *m_pObjectGroups;

public:
    virtual CCArray *getObjectGroups(void);

public:
    virtual void setObjectGroups(CCArray *var);
    ;

protected:
    int m_nParentElement;

public:
    virtual int getParentElement(void) const { return m_nParentElement; }

public:
    virtual void setParentElement(int var) { m_nParentElement = var; };

protected:
    unsigned int m_uParentGID;

public:
    virtual unsigned int getParentGID(void) const { return m_uParentGID; }

public:
    virtual void setParentGID(unsigned int var) { m_uParentGID = var; };

protected:
    int m_nLayerAttribs;

public:
    virtual int getLayerAttribs(void) const { return m_nLayerAttribs; }

public:
    virtual void setLayerAttribs(int var) { m_nLayerAttribs = var; };

protected:
    bool m_bStoringCharacters;

public:
    virtual bool getStoringCharacters(void) const { return m_bStoringCharacters; }

public:
    virtual void setStoringCharacters(bool var) { m_bStoringCharacters = var; };

protected:
    CCDictionary *m_pProperties;

public:
    virtual CCDictionary *getProperties(void);

public:
    virtual void setProperties(CCDictionary *var);
    ;

public:
    CCTMXMapInfo();

    virtual ~CCTMXMapInfo();

    static CCTMXMapInfo *formatWithTMXFile(const char *tmxFile);

    static CCTMXMapInfo *formatWithXML(const char *tmxString, const char *resourcePath);

    bool initWithTMXFile(const char *tmxFile);

    bool initWithXML(const char *tmxString, const char *resourcePath);

    bool parseXMLFile(const char *xmlFilename);

    bool parseXMLString(const char *xmlString);

    CCDictionary *getTileProperties();
    void setTileProperties(CCDictionary *tileProperties);

    void startElement(void *ctx, const char *name, const char **atts);

    void endElement(void *ctx, const char *name);

    void textHandler(void *ctx, const char *ch, int len);

    inline const char *getCurrentString() { return m_sCurrentString.c_str(); }
    inline void setCurrentString(const char *currentString) { m_sCurrentString = currentString; }
    inline const char *getTMXFileName() { return m_sTMXFileName.c_str(); }
    inline void setTMXFileName(const char *fileName) { m_sTMXFileName = fileName; }

private:
    void internalInit(const char *tmxFileName, const char *resourcePath);

protected:
    std::string m_sTMXFileName;

    std::string m_sResources;

    std::string m_sCurrentString;

    CCDictionary *m_pTileProperties;
    unsigned int m_uCurrentFirstGID;
};
// #line 35 "cocos2d/cocos-headers/cocos2dx/tilemap_parallax_nodes/CCTMXLayer.h"
class CCTMXMapInfo;
class CCTMXLayerInfo;
class CCTMXTilesetInfo;
struct _ccCArray;
// #line 74 "cocos2d/cocos-headers/cocos2dx/tilemap_parallax_nodes/CCTMXLayer.h"
class CCTMXLayer : public CCSpriteBatchNode
{

protected:
    CCSize m_tLayerSize;

public:
    virtual const CCSize &getLayerSize(void) const { return m_tLayerSize; }

public:
    virtual void setLayerSize(const CCSize &var) { m_tLayerSize = var; };

protected:
    CCSize m_tMapTileSize;

public:
    virtual const CCSize &getMapTileSize(void) const { return m_tMapTileSize; }

public:
    virtual void setMapTileSize(const CCSize &var) { m_tMapTileSize = var; };

protected:
    unsigned int *m_pTiles;

public:
    virtual unsigned int *getTiles(void) const { return m_pTiles; }

public:
    virtual void setTiles(unsigned int *var) { m_pTiles = var; };

protected:
    CCTMXTilesetInfo *m_pTileSet;

public:
    virtual CCTMXTilesetInfo *getTileSet(void);

public:
    virtual void setTileSet(CCTMXTilesetInfo *var);
    ;

protected:
    unsigned int m_uLayerOrientation;

public:
    virtual unsigned int getLayerOrientation(void) const { return m_uLayerOrientation; }

public:
    virtual void setLayerOrientation(unsigned int var) { m_uLayerOrientation = var; };

protected:
    CCDictionary *m_pProperties;

public:
    virtual CCDictionary *getProperties(void);

public:
    virtual void setProperties(CCDictionary *var);
    ;

public:
    CCTMXLayer();

    virtual ~CCTMXLayer();

    static CCTMXLayer *create(CCTMXTilesetInfo *tilesetInfo, CCTMXLayerInfo *layerInfo, CCTMXMapInfo *mapInfo);

    bool initWithTilesetInfo(CCTMXTilesetInfo *tilesetInfo, CCTMXLayerInfo *layerInfo, CCTMXMapInfo *mapInfo);

    void releaseMap();
    // #line 122 "cocos2d/cocos-headers/cocos2dx/tilemap_parallax_nodes/CCTMXLayer.h"
    CCSprite *tileAt(const CCPoint &tileCoordinate);

    unsigned int tileGIDAt(const CCPoint &tileCoordinate);

    unsigned int tileGIDAt(const CCPoint &tileCoordinate, ccTMXTileFlags *flags);

    void setTileGID(unsigned int gid, const CCPoint &tileCoordinate);
    // #line 151 "cocos2d/cocos-headers/cocos2dx/tilemap_parallax_nodes/CCTMXLayer.h"
    void setTileGID(unsigned int gid, const CCPoint &tileCoordinate, ccTMXTileFlags flags);

    void removeTileAt(const CCPoint &tileCoordinate);

    CCPoint positionAt(const CCPoint &tileCoordinate);

    CCString *propertyNamed(const char *propertyName);

    void setupTiles();

    virtual void addChild(CCNode *child, int zOrder, int tag);

    void removeChild(CCNode *child, bool cleanup);

    inline const char *getLayerName() { return m_sLayerName.c_str(); }
    inline void setLayerName(const char *layerName) { m_sLayerName = layerName; }

private:
    CCPoint positionForIsoAt(const CCPoint &pos);
    CCPoint positionForOrthoAt(const CCPoint &pos);
    CCPoint positionForHexAt(const CCPoint &pos);

    CCPoint calculateLayerOffset(const CCPoint &offset);

    CCSprite *appendTileForGID(unsigned int gid, const CCPoint &pos);
    CCSprite *insertTileForGID(unsigned int gid, const CCPoint &pos);
    CCSprite *updateTileForGID(unsigned int gid, const CCPoint &pos);

    void parseInternalProperties();
    void setupTileSprite(CCSprite *sprite, CCPoint pos, unsigned int gid);
    CCSprite *reusedTileWithRect(CCRect rect);
    int vertexZForPos(const CCPoint &pos);

    unsigned int atlasIndexForExistantZ(unsigned int z);
    unsigned int atlasIndexForNewZ(int z);

protected:
    std::string m_sLayerName;

    unsigned char m_cOpacity;

    unsigned int m_uMinGID;
    unsigned int m_uMaxGID;

    int m_nVertexZvalue;
    bool m_bUseAutomaticVertexZ;

    CCSprite *m_pReusedTile;
    ccCArray *m_pAtlasIndexArray;

    float m_fContentScaleFactor;
};
// #line 34 "cocos2d/cocos-headers/cocos2dx/tilemap_parallax_nodes/CCTMXTiledMap.h"
class CCTMXObjectGroup;
class CCTMXLayer;
class CCTMXLayerInfo;
class CCTMXTilesetInfo;
class CCTMXMapInfo;
// #line 46 "cocos2d/cocos-headers/cocos2dx/tilemap_parallax_nodes/CCTMXTiledMap.h"
enum
{

    CCTMXOrientationOrtho,

    CCTMXOrientationHex,

    CCTMXOrientationIso,
};
// #line 109 "cocos2d/cocos-headers/cocos2dx/tilemap_parallax_nodes/CCTMXTiledMap.h"
class CCTMXTiledMap : public CCNode
{

protected:
    CCSize m_tMapSize;

public:
    virtual const CCSize &getMapSize(void) const { return m_tMapSize; }

public:
    virtual void setMapSize(const CCSize &var) { m_tMapSize = var; };

protected:
    CCSize m_tTileSize;

public:
    virtual const CCSize &getTileSize(void) const { return m_tTileSize; }

public:
    virtual void setTileSize(const CCSize &var) { m_tTileSize = var; };

protected:
    int m_nMapOrientation;

public:
    virtual int getMapOrientation(void) const { return m_nMapOrientation; }

public:
    virtual void setMapOrientation(int var) { m_nMapOrientation = var; };

protected:
    CCArray *m_pObjectGroups;

public:
    virtual CCArray *getObjectGroups(void);

public:
    virtual void setObjectGroups(CCArray *var);
    ;

protected:
    CCDictionary *m_pProperties;

public:
    virtual CCDictionary *getProperties(void);

public:
    virtual void setProperties(CCDictionary *var);
    ;

public:
    CCTMXTiledMap();

    virtual ~CCTMXTiledMap();

    static CCTMXTiledMap *create(const char *tmxFile);

    static CCTMXTiledMap *createWithXML(const char *tmxString, const char *resourcePath);

    bool initWithTMXFile(const char *tmxFile);

    bool initWithXML(const char *tmxString, const char *resourcePath);

    CCTMXLayer *layerNamed(const char *layerName);

    CCTMXObjectGroup *objectGroupNamed(const char *groupName);

    CCString *propertyNamed(const char *propertyName);

    CCDictionary *propertiesForGID(int GID);

private:
    CCTMXLayer *parseLayer(CCTMXLayerInfo *layerInfo, CCTMXMapInfo *mapInfo);
    CCTMXTilesetInfo *tilesetForLayer(CCTMXLayerInfo *layerInfo, CCTMXMapInfo *mapInfo);
    void buildWithMapInfo(CCTMXMapInfo *mapInfo);

protected:
    CCDictionary *m_pTileProperties;
};
// #line 34 "cocos2d/cocos-headers/cocos2dx/tilemap_parallax_nodes/CCTileMapAtlas.h"
struct sImageTGA;
class CCDictionary;
// #line 57 "cocos2d/cocos-headers/cocos2dx/tilemap_parallax_nodes/CCTileMapAtlas.h"
class CCTileMapAtlas : public CCAtlasNode
{

protected:
    struct sImageTGA *m_pTGAInfo;

public:
    virtual struct sImageTGA *getTGAInfo(void);

public:
    virtual void setTGAInfo(struct sImageTGA *var);
    ;

public:
    CCTileMapAtlas();

    virtual ~CCTileMapAtlas();

    static CCTileMapAtlas *create(const char *tile, const char *mapFile, int tileWidth, int tileHeight);

    bool initWithTileFile(const char *tile, const char *mapFile, int tileWidth, int tileHeight);

    ccColor3B tileAt(const CCPoint &position);

    void setTile(const ccColor3B &tile, const CCPoint &position);

    void releaseMap();

private:
    void loadTGAfile(const char *file);
    void calculateItemsToRender();
    void updateAtlasValueAt(const CCPoint &pos, const ccColor3B &value, unsigned int index);
    void updateAtlasValues();

protected:
    CCDictionary *m_pPosToAtlasIndex;

    int m_nItemsToRender;
};
// #line 40 "cocos2d/cocos-headers/cocos2dx/touch_dispatcher/CCTouchDispatcher.h"
typedef enum
{
    ccTouchSelectorBeganBit = 1 << 0,
    ccTouchSelectorMovedBit = 1 << 1,
    ccTouchSelectorEndedBit = 1 << 2,
    ccTouchSelectorCancelledBit = 1 << 3,
    ccTouchSelectorAllBits = (ccTouchSelectorBeganBit | ccTouchSelectorMovedBit | ccTouchSelectorEndedBit | ccTouchSelectorCancelledBit),
} ccTouchSelectorFlag;

enum
{
    CCTOUCHBEGAN,
    CCTOUCHMOVED,
    CCTOUCHENDED,
    CCTOUCHCANCELLED,

    ccTouchMax,
};

class CCSet;
class CCEvent;

struct ccTouchHandlerHelperData
{

    int m_type;
};

class EGLTouchDelegate
{
public:
    virtual void touchesBegan(CCSet *touches, CCEvent *pEvent) = 0;

    virtual void touchesMoved(CCSet *touches, CCEvent *pEvent) = 0;

    virtual void touchesEnded(CCSet *touches, CCEvent *pEvent) = 0;

    virtual void touchesCancelled(CCSet *touches, CCEvent *pEvent) = 0;

    virtual ~EGLTouchDelegate() {}
};

class CCTouchHandler;
struct _ccCArray;
// #line 116 "cocos2d/cocos-headers/cocos2dx/touch_dispatcher/CCTouchDispatcher.h"
class CCTouchDispatcher : public CCObject, public EGLTouchDelegate
{
public:
    ~CCTouchDispatcher();

    bool init(void);

    CCTouchDispatcher()
        : m_pTargetedHandlers(NULL), m_pStandardHandlers(NULL), m_pHandlersToAdd(NULL), m_pHandlersToRemove(NULL)

    {
    }

public:
    bool isDispatchEvents(void);
    void setDispatchEvents(bool bDispatchEvents);

    void addStandardDelegate(CCTouchDelegate *pDelegate, int nPriority);

    void addTargetedDelegate(CCTouchDelegate *pDelegate, int nPriority, bool bSwallowsTouches);

    void removeDelegate(CCTouchDelegate *pDelegate);

    void removeAllDelegates(void);

    void setPriority(int nPriority, CCTouchDelegate *pDelegate);

    void touches(CCSet *pTouches, CCEvent *pEvent, unsigned int uIndex);

    virtual void touchesBegan(CCSet *touches, CCEvent *pEvent);

    virtual void touchesMoved(CCSet *touches, CCEvent *pEvent);

    virtual void touchesEnded(CCSet *touches, CCEvent *pEvent);

    virtual void touchesCancelled(CCSet *touches, CCEvent *pEvent);

public:
    CCTouchHandler *findHandler(CCTouchDelegate *pDelegate);

    void incrementForcePrio(int priority);
    void decrementForcePrio(int priority);

protected:
    void forceRemoveDelegate(CCTouchDelegate *pDelegate);
    void forceAddHandler(CCTouchHandler *pHandler, CCArray *pArray);
    void forceRemoveAllDelegates(void);
    void rearrangeHandlers(CCArray *pArray);
    CCTouchHandler *findHandler(CCArray *pArray, CCTouchDelegate *pDelegate);

protected:
    CCArray *m_pTargetedHandlers;
    CCArray *m_pStandardHandlers;

    bool m_bLocked;
    bool m_bToAdd;
    bool m_bToRemove;
    CCArray *m_pHandlersToAdd;
    struct _ccCArray *m_pHandlersToRemove;
    bool m_bToQuit;
    bool m_bDispatchEvents;

    struct ccTouchHandlerHelperData m_sHandlerHelperData[ccTouchMax];

protected:
    bool m_bForcePrio;

public:
    bool getForcePrio(void) const { return m_bForcePrio; }

public:
    void setForcePrio(bool var) { m_bForcePrio = var; };

protected:
    int m_nTargetPrio;

public:
    int getTargetPrio(void) const { return m_nTargetPrio; }

public:
    void setTargetPrio(int var) { m_nTargetPrio = var; };
};
// #line 47 "cocos2d/cocos-headers/cocos2dx/touch_dispatcher/CCTouchHandler.h"
class CCTouchHandler : public CCObject
{
public:
    virtual ~CCTouchHandler(void);

    CCTouchDelegate *getDelegate();
    void setDelegate(CCTouchDelegate *pDelegate);

    int getPriority(void);
    void setPriority(int nPriority);

    int getEnabledSelectors(void);
    void setEnalbedSelectors(int nValue);

    virtual bool initWithDelegate(CCTouchDelegate *pDelegate, int nPriority);

public:
    static CCTouchHandler *handlerWithDelegate(CCTouchDelegate *pDelegate, int nPriority);

protected:
    CCTouchDelegate *m_pDelegate;
    int m_nPriority;
    int m_nEnabledSelectors;
};

class CCStandardTouchHandler : public CCTouchHandler
{
public:
    virtual bool initWithDelegate(CCTouchDelegate *pDelegate, int nPriority);

public:
    static CCStandardTouchHandler *handlerWithDelegate(CCTouchDelegate *pDelegate, int nPriority);
};
// #line 100 "cocos2d/cocos-headers/cocos2dx/touch_dispatcher/CCTouchHandler.h"
class CCTargetedTouchHandler : public CCTouchHandler
{
public:
    ~CCTargetedTouchHandler(void);

    bool isSwallowsTouches(void);
    void setSwallowsTouches(bool bSwallowsTouches);

    CCSet *getClaimedTouches(void);

    bool initWithDelegate(CCTouchDelegate *pDelegate, int nPriority, bool bSwallow);

public:
    static CCTargetedTouchHandler *handlerWithDelegate(CCTouchDelegate *pDelegate, int nPriority, bool bSwallow);

protected:
    bool m_bSwallowsTouches;
    CCSet *m_pClaimedTouches;
};
// #line 46 "cocos2d/cocos-headers/cocos2dx/CCScheduler.h"
class CCSet;
// #line 52 "cocos2d/cocos-headers/cocos2dx/CCScheduler.h"
class CCTimer : public CCObject
{
public:
    CCTimer(void);

    float getInterval(void) const;

    void setInterval(float fInterval);

    SEL_SCHEDULE getSelector() const;

    bool initWithTarget(CCObject *pTarget, SEL_SCHEDULE pfnSelector);

    bool initWithTarget(CCObject *pTarget, SEL_SCHEDULE pfnSelector, float fSeconds, unsigned int nRepeat, float fDelay);

    bool initWithScriptHandler(int nHandler, float fSeconds);

    void update(float dt);

public:
    static CCTimer *timerWithTarget(CCObject *pTarget, SEL_SCHEDULE pfnSelector);

    static CCTimer *timerWithTarget(CCObject *pTarget, SEL_SCHEDULE pfnSelector, float fSeconds);

    static CCTimer *timerWithScriptHandler(int nHandler, float fSeconds);

    inline int getScriptHandler() { return m_nScriptHandler; };

protected:
    CCObject *m_pTarget;
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
// #line 121 "cocos2d/cocos-headers/cocos2dx/CCScheduler.h"
struct _listEntry;
struct _hashSelectorEntry;
struct _hashUpdateEntry;

class CCArray;
// #line 138 "cocos2d/cocos-headers/cocos2dx/CCScheduler.h"
class CCScheduler : public CCObject
{
public:
    CCScheduler();

    ~CCScheduler(void);

    inline float getTimeScale(void) { return m_fTimeScale; }
    // #line 156 "cocos2d/cocos-headers/cocos2dx/CCScheduler.h"
    inline void setTimeScale(float fTimeScale) { m_fTimeScale = fTimeScale; }

    void update(float dt);
    // #line 176 "cocos2d/cocos-headers/cocos2dx/CCScheduler.h"
    void scheduleSelector(SEL_SCHEDULE pfnSelector, CCObject *pTarget, float fInterval, unsigned int repeat, float delay, bool bPaused);

    void scheduleSelector(SEL_SCHEDULE pfnSelector, CCObject *pTarget, float fInterval, bool bPaused);

    void scheduleUpdateForTarget(CCObject *pTarget, int nPriority, bool bPaused);

    void unscheduleSelector(SEL_SCHEDULE pfnSelector, CCObject *pTarget);

    void unscheduleUpdateForTarget(const CCObject *pTarget);
    // #line 210 "cocos2d/cocos-headers/cocos2dx/CCScheduler.h"
    void unscheduleAllForTarget(CCObject *pTarget);
    // #line 219 "cocos2d/cocos-headers/cocos2dx/CCScheduler.h"
    void unscheduleAll(void);
    // #line 227 "cocos2d/cocos-headers/cocos2dx/CCScheduler.h"
    void unscheduleAllWithMinPriority(int nMinPriority);
    // #line 235 "cocos2d/cocos-headers/cocos2dx/CCScheduler.h"
    unsigned int scheduleScriptFunc(unsigned int nHandler, float fInterval, bool bPaused);

    void unscheduleScriptEntry(unsigned int uScheduleScriptEntryID);
    // #line 248 "cocos2d/cocos-headers/cocos2dx/CCScheduler.h"
    void pauseTarget(CCObject *pTarget);
    // #line 256 "cocos2d/cocos-headers/cocos2dx/CCScheduler.h"
    void resumeTarget(CCObject *pTarget);

    bool isTargetPaused(CCObject *pTarget);

    CCSet *pauseAllTargets();

    CCSet *pauseAllTargetsWithMinPriority(int nMinPriority);

    void resumeTargets(CCSet *targetsToResume);

private:
    void removeHashElement(struct _hashSelectorEntry *pElement);
    void removeUpdateFromHash(struct _listEntry *entry);

    void priorityIn(struct _listEntry **ppList, CCObject *pTarget, int nPriority, bool bPaused);
    void appendIn(struct _listEntry **ppList, CCObject *pTarget, bool bPaused);

protected:
    float m_fTimeScale;
    // #line 300 "cocos2d/cocos-headers/cocos2dx/CCScheduler.h"
    struct _listEntry *m_pUpdatesNegList;
    struct _listEntry *m_pUpdates0List;
    struct _listEntry *m_pUpdatesPosList;
    struct _hashUpdateEntry *m_pHashForUpdates;

    struct _hashSelectorEntry *m_pHashForTimers;
    struct _hashSelectorEntry *m_pCurrentTarget;
    bool m_bCurrentTargetSalvaged;

    bool m_bUpdateHashLocked;
    CCArray *m_pScriptHandlerEntries;
};
// #line 29 "cocos2d/cocos-headers/cocos2dx/support/component/CCComponent.h"
#include <string>

class CCComponent : public CCObject
{
protected:
    CCComponent(void);

public:
    virtual ~CCComponent(void);
    virtual bool init();

    virtual void onEnter();

    virtual void onExit();
    virtual void update(float delta);
    virtual bool serialize(void *r);
    virtual bool isEnabled() const;
    virtual void setEnabled(bool b);
    static CCComponent *create(void);

    const char *getName() const;
    void setName(const char *pName);

    void setOwner(CCNode *pOwner);
    CCNode *getOwner() const;

protected:
    CCNode *m_pOwner;
    std::string m_strName;
    bool m_bEnabled;
};
// #line 32 "cocos2d/cocos-headers/cocos2dx/support/component/CCComponentContainer.h"
class CCComponent;
class CCNode;

class CCComponentContainer
{
protected:
    CCComponentContainer(CCNode *pNode);

public:
    virtual ~CCComponentContainer(void);
    virtual CCComponent *get(const char *pName) const;
    virtual bool add(CCComponent *pCom);
    virtual bool remove(const char *pName);
    virtual bool remove(CCComponent *pCom);
    virtual void removeAll();
    virtual void visit(float fDelta);

public:
    bool isEmpty() const;

private:
    void alloc(void);

private:
    CCDictionary *m_pComponents;
    CCNode *m_pOwner;

    friend class CCNode;
};
// #line 7 "cocos2d/cocos-headers/cocos2dx/robtop/keyboard_dispatcher/CCKeyboardDispatcher.h"
class CCKeyboardDispatcher : public CCObject
{
public:
    CCKeyboardDispatcher();
    CCKeyboardDispatcher(const CCKeyboardDispatcher &);
    virtual ~CCKeyboardDispatcher();
    CCKeyboardDispatcher &operator=(const CCKeyboardDispatcher &);
    void addDelegate(CCKeyboardDelegate *pDelegate);
    void removeDelegate(CCKeyboardDelegate *pDelegate);
    void forceAddDelegate(CCKeyboardDelegate *pDelegate);
    void forceRemoveDelegate(CCKeyboardDelegate *pDelegate);
    enumKeyCodes convertKeyCode(enumKeyCodes key);
    bool dispatchKeyboardMSG(enumKeyCodes key, bool);
    bool getAltKeyPressed() const;
    bool getCommandKeyPressed() const;
    bool getControlKeyPressed() const;
    bool getShiftKeyPressed() const;
    const char *keyToString(enumKeyCodes key);
    void updateModifierKeys(bool shft, bool ctrl, bool alt, bool cmd);

protected:
    CCArray *m_pDelegates;
    bool m_bUnknown24;
    bool m_bUnknown25;
    char pad7[2] = {};
    ccCArray *m_pUnknown28;
    ccCArray *m_pUnknown2c;
    bool m_bShiftPressed;
    bool m_bControlPressed;
    bool m_bAltPressed;
    bool m_bCommandPressed;
};
// #line 7 "cocos2d/cocos-headers/cocos2dx/robtop/mouse_dispatcher/CCMouseDispatcher.h"
class CCMouseDispatcher : public CCObject
{
public:
    CCMouseDispatcher();
    CCMouseDispatcher(const CCMouseDispatcher &);
    virtual ~CCMouseDispatcher();
    CCMouseDispatcher &operator=(const CCMouseDispatcher &);
    void addDelegate(CCMouseDelegate *pDelegate);
    void removeDelegate(CCMouseDelegate *pDelegate);
    void forceAddDelegate(CCMouseDelegate *pDelegate);
    void forceRemoveDelegate(CCMouseDelegate *pDelegate);
    bool dispatchScrollMSG(float x, float y);

protected:
    CCArray *m_pDelegates;
};
// #line 6 "cocos2d/cocos-headers/cocos2dx/robtop/scene_nodes/CCSceneTransitionDelegate.h"
class CCSceneTransitionDelegate
{
    CCSceneTransitionDelegate(const CCSceneTransitionDelegate &);
    CCSceneTransitionDelegate();
    CCSceneTransitionDelegate &operator=(const CCSceneTransitionDelegate &);
    virtual void sceneWillResume(void);
};
// #line 14 "cocos2d/cocos-headers/cocos2dx/robtop/xml/pugixml.hpp"
// #line 28 "cocos2d/cocos-headers/cocos2dx/robtop/xml/pugixml.hpp"
#include <stddef.h>
#include <exception>
#include <iterator>
#include <iosfwd>
#include <string>

// #line 77 "cocos2d/cocos-headers/cocos2dx/robtop/xml/pugixml.hpp"
namespace pugi
{

    typedef char char_t;

    typedef std::basic_string<char, std::char_traits<char>, std::allocator<char>> string_t;

}

namespace pugi
{

    enum xml_node_type
    {
        node_null,
        node_document,
        node_element,
        node_pcdata,
        node_cdata,
        node_comment,
        node_pi,
        node_declaration,
        node_doctype
    };
    // #line 109 "cocos2d/cocos-headers/cocos2dx/robtop/xml/pugixml.hpp"
    const unsigned int parse_minimal = 0x0000;

    const unsigned int parse_pi = 0x0001;

    const unsigned int parse_comments = 0x0002;

    const unsigned int parse_cdata = 0x0004;

    const unsigned int parse_ws_pcdata = 0x0008;

    const unsigned int parse_escapes = 0x0010;

    const unsigned int parse_eol = 0x0020;

    const unsigned int parse_wconv_attribute = 0x0040;

    const unsigned int parse_wnorm_attribute = 0x0080;

    const unsigned int parse_declaration = 0x0100;

    const unsigned int parse_doctype = 0x0200;
    // #line 145 "cocos2d/cocos-headers/cocos2dx/robtop/xml/pugixml.hpp"
    const unsigned int parse_ws_pcdata_single = 0x0400;
    // #line 150 "cocos2d/cocos-headers/cocos2dx/robtop/xml/pugixml.hpp"
    const unsigned int parse_default = parse_cdata | parse_escapes | parse_wconv_attribute | parse_eol;
    // #line 155 "cocos2d/cocos-headers/cocos2dx/robtop/xml/pugixml.hpp"
    const unsigned int parse_full = parse_default | parse_pi | parse_comments | parse_declaration | parse_doctype;

    enum xml_encoding
    {
        encoding_auto,
        encoding_utf8,
        encoding_utf16_le,
        encoding_utf16_be,
        encoding_utf16,
        encoding_utf32_le,
        encoding_utf32_be,
        encoding_utf32,
        encoding_wchar,
        encoding_latin1
    };

    const unsigned int format_indent = 0x01;

    const unsigned int format_write_bom = 0x02;

    const unsigned int format_raw = 0x04;

    const unsigned int format_no_declaration = 0x08;

    const unsigned int format_no_escapes = 0x10;

    const unsigned int format_save_file_text = 0x20;

    const unsigned int format_default = format_indent;

    struct xml_attribute_struct;
    struct xml_node_struct;

    class xml_node_iterator;
    class xml_attribute_iterator;
    class xml_named_node_iterator;

    class xml_tree_walker;

    class xml_node;

    class xml_text;

    class xpath_node;
    class xpath_node_set;
    class xpath_query;
    class xpath_variable_set;

    template <typename It>
    class xml_object_range
    {
    public:
        typedef It const_iterator;

        xml_object_range(It b, It e) : _begin(b), _end(e)
        {
        }

        It begin() const { return _begin; }
        It end() const { return _end; }

    private:
        It _begin, _end;
    };

    class xml_writer
    {
    public:
        virtual ~xml_writer() {}

        virtual void write(const void *data, size_t size) = 0;
    };

    class xml_writer_file : public xml_writer
    {
    public:
        xml_writer_file(void *file);

        virtual void write(const void *data, size_t size);

    private:
        void *file;
    };

    class xml_writer_stream : public xml_writer
    {
    public:
        xml_writer_stream(std::basic_ostream<char, std::char_traits<char>> &stream);
        xml_writer_stream(std::basic_ostream<wchar_t, std::char_traits<wchar_t>> &stream);

        virtual void write(const void *data, size_t size);

    private:
        std::basic_ostream<char, std::char_traits<char>> *narrow_stream;
        std::basic_ostream<wchar_t, std::char_traits<wchar_t>> *wide_stream;
    };

    class xml_attribute
    {
        friend class xml_attribute_iterator;
        friend class xml_node;

    private:
        xml_attribute_struct *_attr;

        typedef void (*unspecified_bool_type)(xml_attribute ***);

    public:
        xml_attribute();

        explicit xml_attribute(xml_attribute_struct *attr);

        operator unspecified_bool_type() const;

        bool operator!() const;

        bool operator==(const xml_attribute &r) const;
        bool operator!=(const xml_attribute &r) const;
        bool operator<(const xml_attribute &r) const;
        bool operator>(const xml_attribute &r) const;
        bool operator<=(const xml_attribute &r) const;
        bool operator>=(const xml_attribute &r) const;

        bool empty() const;

        const char_t *name() const;
        const char_t *value() const;

        const char_t *as_string(const char_t *def = "") const;

        int as_int(int def = 0) const;
        unsigned int as_uint(unsigned int def = 0) const;
        double as_double(double def = 0) const;
        float as_float(float def = 0) const;

        bool as_bool(bool def = false) const;

        bool set_name(const char_t *rhs);
        bool set_value(const char_t *rhs);

        bool set_value(int rhs);
        bool set_value(unsigned int rhs);
        bool set_value(double rhs);
        bool set_value(bool rhs);

        xml_attribute &operator=(const char_t *rhs);
        xml_attribute &operator=(int rhs);
        xml_attribute &operator=(unsigned int rhs);
        xml_attribute &operator=(double rhs);
        xml_attribute &operator=(bool rhs);

        xml_attribute next_attribute() const;
        xml_attribute previous_attribute() const;

        size_t hash_value() const;

        xml_attribute_struct *internal_object() const;
    };
    // #line 360 "cocos2d/cocos-headers/cocos2dx/robtop/xml/pugixml.hpp"
    class xml_node
    {
        friend class xml_attribute_iterator;
        friend class xml_node_iterator;
        friend class xml_named_node_iterator;

    protected:
        xml_node_struct *_root;

        typedef void (*unspecified_bool_type)(xml_node ***);

    public:
        xml_node();

        explicit xml_node(xml_node_struct *p);

        operator unspecified_bool_type() const;

        bool operator!() const;

        bool operator==(const xml_node &r) const;
        bool operator!=(const xml_node &r) const;
        bool operator<(const xml_node &r) const;
        bool operator>(const xml_node &r) const;
        bool operator<=(const xml_node &r) const;
        bool operator>=(const xml_node &r) const;

        bool empty() const;

        xml_node_type type() const;

        const char_t *name() const;
        const char_t *value() const;

        xml_attribute first_attribute() const;
        xml_attribute last_attribute() const;

        xml_node first_child() const;
        xml_node last_child() const;

        xml_node next_sibling() const;
        xml_node previous_sibling() const;

        xml_node parent() const;

        xml_node root() const;

        xml_text text() const;

        xml_node child(const char_t *name) const;
        xml_attribute attribute(const char_t *name) const;
        xml_node next_sibling(const char_t *name) const;
        xml_node previous_sibling(const char_t *name) const;

        const char_t *child_value() const;

        const char_t *child_value(const char_t *name) const;

        bool set_name(const char_t *rhs);
        bool set_value(const char_t *rhs);

        xml_attribute append_attribute(const char_t *name);
        xml_attribute prepend_attribute(const char_t *name);
        xml_attribute insert_attribute_after(const char_t *name, const xml_attribute &attr);
        xml_attribute insert_attribute_before(const char_t *name, const xml_attribute &attr);

        xml_attribute append_copy(const xml_attribute &proto);
        xml_attribute prepend_copy(const xml_attribute &proto);
        xml_attribute insert_copy_after(const xml_attribute &proto, const xml_attribute &attr);
        xml_attribute insert_copy_before(const xml_attribute &proto, const xml_attribute &attr);

        xml_node append_child(xml_node_type type = node_element);
        xml_node prepend_child(xml_node_type type = node_element);
        xml_node insert_child_after(xml_node_type type, const xml_node &node);
        xml_node insert_child_before(xml_node_type type, const xml_node &node);

        xml_node append_child(const char_t *name);
        xml_node prepend_child(const char_t *name);
        xml_node insert_child_after(const char_t *name, const xml_node &node);
        xml_node insert_child_before(const char_t *name, const xml_node &node);

        xml_node append_copy(const xml_node &proto);
        xml_node prepend_copy(const xml_node &proto);
        xml_node insert_copy_after(const xml_node &proto, const xml_node &node);
        xml_node insert_copy_before(const xml_node &proto, const xml_node &node);

        bool remove_attribute(const xml_attribute &a);
        bool remove_attribute(const char_t *name);

        bool remove_child(const xml_node &n);
        bool remove_child(const char_t *name);

        template <typename Predicate>
        xml_attribute find_attribute(Predicate pred) const
        {
            if (!_root)
                return xml_attribute();

            for (xml_attribute attrib = first_attribute(); attrib; attrib = attrib.next_attribute())
                if (pred(attrib))
                    return attrib;

            return xml_attribute();
        }

        template <typename Predicate>
        xml_node find_child(Predicate pred) const
        {
            if (!_root)
                return xml_node();

            for (xml_node node = first_child(); node; node = node.next_sibling())
                if (pred(node))
                    return node;

            return xml_node();
        }

        template <typename Predicate>
        xml_node find_node(Predicate pred) const
        {
            if (!_root)
                return xml_node();

            xml_node cur = first_child();

            while (cur._root && cur._root != _root)
            {
                if (pred(cur))
                    return cur;

                if (cur.first_child())
                    cur = cur.first_child();
                else if (cur.next_sibling())
                    cur = cur.next_sibling();
                else
                {
                    while (!cur.next_sibling() && cur._root != _root)
                        cur = cur.parent();

                    if (cur._root != _root)
                        cur = cur.next_sibling();
                }
            }

            return xml_node();
        }

        xml_node find_child_by_attribute(const char_t *name, const char_t *attr_name, const char_t *attr_value) const;
        xml_node find_child_by_attribute(const char_t *attr_name, const char_t *attr_value) const;

        string_t path(char_t delimiter = '/') const;

        xml_node first_element_by_path(const char_t *path, char_t delimiter = '/') const;

        bool traverse(xml_tree_walker &walker);

        xpath_node select_single_node(const char_t *query, xpath_variable_set *variables = 0) const;
        xpath_node select_single_node(const xpath_query &query) const;

        xpath_node_set select_nodes(const char_t *query, xpath_variable_set *variables = 0) const;
        xpath_node_set select_nodes(const xpath_query &query) const;

        void print(xml_writer &writer, const char_t *indent = "\t", unsigned int flags = format_default, xml_encoding encoding = encoding_auto, unsigned int depth = 0) const;

        void print(std::basic_ostream<char, std::char_traits<char>> &os, const char_t *indent = "\t", unsigned int flags = format_default, xml_encoding encoding = encoding_auto, unsigned int depth = 0) const;
        void print(std::basic_ostream<wchar_t, std::char_traits<wchar_t>> &os, const char_t *indent = "\t", unsigned int flags = format_default, unsigned int depth = 0) const;

        typedef xml_node_iterator iterator;

        iterator begin() const;
        iterator end() const;

        typedef xml_attribute_iterator attribute_iterator;

        attribute_iterator attributes_begin() const;
        attribute_iterator attributes_end() const;

        xml_object_range<xml_node_iterator> children() const;
        xml_object_range<xml_named_node_iterator> children(const char_t *name) const;
        xml_object_range<xml_attribute_iterator> attributes() const;

        ptrdiff_t offset_debug() const;

        size_t hash_value() const;

        xml_node_struct *internal_object() const;
    };
    // #line 593 "cocos2d/cocos-headers/cocos2dx/robtop/xml/pugixml.hpp"
    class xml_text
    {
        friend class xml_node;

        xml_node_struct *_root;

        typedef void (*unspecified_bool_type)(xml_text ***);

        explicit xml_text(xml_node_struct *root);

        xml_node_struct *_data_new();
        xml_node_struct *_data() const;

    public:
        xml_text();

        operator unspecified_bool_type() const;

        bool operator!() const;

        bool empty() const;

        const char_t *get() const;

        const char_t *as_string(const char_t *def = "") const;

        int as_int(int def = 0) const;
        unsigned int as_uint(unsigned int def = 0) const;
        double as_double(double def = 0) const;
        float as_float(float def = 0) const;

        bool as_bool(bool def = false) const;

        bool set(const char_t *rhs);

        bool set(int rhs);
        bool set(unsigned int rhs);
        bool set(double rhs);
        bool set(bool rhs);

        xml_text &operator=(const char_t *rhs);
        xml_text &operator=(int rhs);
        xml_text &operator=(unsigned int rhs);
        xml_text &operator=(double rhs);
        xml_text &operator=(bool rhs);

        xml_node data() const;
    };
    // #line 661 "cocos2d/cocos-headers/cocos2dx/robtop/xml/pugixml.hpp"
    class xml_node_iterator
    {
        friend class xml_node;

    private:
        mutable xml_node _wrap;
        xml_node _parent;

        xml_node_iterator(xml_node_struct *ref, xml_node_struct *parent);

    public:
        typedef ptrdiff_t difference_type;
        typedef xml_node value_type;
        typedef xml_node *pointer;
        typedef xml_node &reference;

        typedef std::bidirectional_iterator_tag iterator_category;

        xml_node_iterator();

        xml_node_iterator(const xml_node &node);

        bool operator==(const xml_node_iterator &rhs) const;
        bool operator!=(const xml_node_iterator &rhs) const;

        xml_node &operator*() const;
        xml_node *operator->() const;

        const xml_node_iterator &operator++();
        xml_node_iterator operator++(int);

        const xml_node_iterator &operator--();
        xml_node_iterator operator--(int);
    };

    class xml_attribute_iterator
    {
        friend class xml_node;

    private:
        mutable xml_attribute _wrap;
        xml_node _parent;

        xml_attribute_iterator(xml_attribute_struct *ref, xml_node_struct *parent);

    public:
        typedef ptrdiff_t difference_type;
        typedef xml_attribute value_type;
        typedef xml_attribute *pointer;
        typedef xml_attribute &reference;

        typedef std::bidirectional_iterator_tag iterator_category;

        xml_attribute_iterator();

        xml_attribute_iterator(const xml_attribute &attr, const xml_node &parent);

        bool operator==(const xml_attribute_iterator &rhs) const;
        bool operator!=(const xml_attribute_iterator &rhs) const;

        xml_attribute &operator*() const;
        xml_attribute *operator->() const;

        const xml_attribute_iterator &operator++();
        xml_attribute_iterator operator++(int);

        const xml_attribute_iterator &operator--();
        xml_attribute_iterator operator--(int);
    };

    class xml_named_node_iterator
    {
    public:
        typedef ptrdiff_t difference_type;
        typedef xml_node value_type;
        typedef xml_node *pointer;
        typedef xml_node &reference;

        typedef std::forward_iterator_tag iterator_category;

        xml_named_node_iterator();

        xml_named_node_iterator(const xml_node &node, const char_t *name);

        bool operator==(const xml_named_node_iterator &rhs) const;
        bool operator!=(const xml_named_node_iterator &rhs) const;

        xml_node &operator*() const;
        xml_node *operator->() const;

        const xml_named_node_iterator &operator++();
        xml_named_node_iterator operator++(int);

    private:
        mutable xml_node _node;
        const char_t *_name;
    };

    class xml_tree_walker
    {
        friend class xml_node;

    private:
        int _depth;

    protected:
        int depth() const;

    public:
        xml_tree_walker();
        virtual ~xml_tree_walker();

        virtual bool begin(xml_node &node);

        virtual bool for_each(xml_node &node) = 0;

        virtual bool end(xml_node &node);
    };

    enum xml_parse_status
    {
        status_ok = 0,

        status_file_not_found,
        status_io_error,
        status_out_of_memory,
        status_internal_error,

        status_unrecognized_tag,

        status_bad_pi,
        status_bad_comment,
        status_bad_cdata,
        status_bad_doctype,
        status_bad_pcdata,
        status_bad_start_element,
        status_bad_attribute,
        status_bad_end_element,
        status_end_element_mismatch
    };

    struct xml_parse_result
    {

        xml_parse_status status;

        ptrdiff_t offset;

        xml_encoding encoding;

        xml_parse_result();

        operator bool() const;

        const char *description() const;
    };

    class xml_document : public xml_node
    {
    private:
        char_t *_buffer;

        char _memory[192];

        xml_document(const xml_document &);
        const xml_document &operator=(const xml_document &);

        void create();
        void destroy();

        xml_parse_result load_buffer_impl(void *contents, size_t size, unsigned int options, xml_encoding encoding, bool is_mutable, bool own);

    public:
        xml_document();

        ~xml_document();

        void reset();

        void reset(const xml_document &proto);

        xml_parse_result load(std::basic_istream<char, std::char_traits<char>> &stream, unsigned int options = parse_default, xml_encoding encoding = encoding_auto);
        xml_parse_result load(std::basic_istream<wchar_t, std::char_traits<wchar_t>> &stream, unsigned int options = parse_default);

        xml_parse_result load(const char_t *contents, unsigned int options = parse_default);

        xml_parse_result load_file(const char *path, unsigned int options = parse_default, xml_encoding encoding = encoding_auto);
        xml_parse_result load_file(const wchar_t *path, unsigned int options = parse_default, xml_encoding encoding = encoding_auto);

        xml_parse_result load_buffer(const void *contents, size_t size, unsigned int options = parse_default, xml_encoding encoding = encoding_auto);

        xml_parse_result load_buffer_inplace(void *contents, size_t size, unsigned int options = parse_default, xml_encoding encoding = encoding_auto);

        xml_parse_result load_buffer_inplace_own(void *contents, size_t size, unsigned int options = parse_default, xml_encoding encoding = encoding_auto);

        void save(xml_writer &writer, const char_t *indent = "\t", unsigned int flags = format_default, xml_encoding encoding = encoding_auto) const;

        void save(std::basic_ostream<char, std::char_traits<char>> &stream, const char_t *indent = "\t", unsigned int flags = format_default, xml_encoding encoding = encoding_auto) const;
        void save(std::basic_ostream<wchar_t, std::char_traits<wchar_t>> &stream, const char_t *indent = "\t", unsigned int flags = format_default) const;

        bool save_file(const char *path, const char_t *indent = "\t", unsigned int flags = format_default, xml_encoding encoding = encoding_auto) const;
        bool save_file(const wchar_t *path, const char_t *indent = "\t", unsigned int flags = format_default, xml_encoding encoding = encoding_auto) const;

        xml_node document_element() const;
    };

    enum xpath_value_type
    {
        xpath_type_none,
        xpath_type_node_set,
        xpath_type_number,
        xpath_type_string,
        xpath_type_boolean
    };

    struct xpath_parse_result
    {

        const char *error;

        ptrdiff_t offset;

        xpath_parse_result();

        operator bool() const;

        const char *description() const;
    };

    class xpath_variable
    {
        friend class xpath_variable_set;

    protected:
        xpath_value_type _type;
        xpath_variable *_next;

        xpath_variable();

        xpath_variable(const xpath_variable &);
        xpath_variable &operator=(const xpath_variable &);

    public:
        const char_t *name() const;

        xpath_value_type type() const;

        bool get_boolean() const;
        double get_number() const;
        const char_t *get_string() const;
        const xpath_node_set &get_node_set() const;

        bool set(bool value);
        bool set(double value);
        bool set(const char_t *value);
        bool set(const xpath_node_set &value);
    };

    class xpath_variable_set
    {
    private:
        xpath_variable *_data[64];

        xpath_variable_set(const xpath_variable_set &);
        xpath_variable_set &operator=(const xpath_variable_set &);

        xpath_variable *find(const char_t *name) const;

    public:
        xpath_variable_set();
        ~xpath_variable_set();

        xpath_variable *add(const char_t *name, xpath_value_type type);

        bool set(const char_t *name, bool value);
        bool set(const char_t *name, double value);
        bool set(const char_t *name, const char_t *value);
        bool set(const char_t *name, const xpath_node_set &value);

        xpath_variable *get(const char_t *name);
        const xpath_variable *get(const char_t *name) const;
    };

    class xpath_query
    {
    private:
        void *_impl;
        xpath_parse_result _result;

        typedef void (*unspecified_bool_type)(xpath_query ***);

        xpath_query(const xpath_query &);
        xpath_query &operator=(const xpath_query &);

    public:
        explicit xpath_query(const char_t *query, xpath_variable_set *variables = 0);

        ~xpath_query();

        xpath_value_type return_type() const;

        bool evaluate_boolean(const xpath_node &n) const;

        double evaluate_number(const xpath_node &n) const;

        string_t evaluate_string(const xpath_node &n) const;
        size_t evaluate_string(char_t *buffer, size_t capacity, const xpath_node &n) const;
        xpath_node_set evaluate_node_set(const xpath_node &n) const;

        const xpath_parse_result &result() const;

        operator unspecified_bool_type() const;

        bool operator!() const;
    };

    class xpath_exception : public std::exception
    {
    private:
        xpath_parse_result _result;

    public:
        explicit xpath_exception(const xpath_parse_result &result);

        virtual const char *what() const throw();

        const xpath_parse_result &result() const;
    };

    class xpath_node
    {
    private:
        xml_node _node;
        xml_attribute _attribute;

        typedef void (*unspecified_bool_type)(xpath_node ***);

    public:
        xpath_node();

        xpath_node(const xml_node &node);
        xpath_node(const xml_attribute &attribute, const xml_node &parent);

        xml_node node() const;
        xml_attribute attribute() const;

        xml_node parent() const;

        operator unspecified_bool_type() const;

        bool operator!() const;

        bool operator==(const xpath_node &n) const;
        bool operator!=(const xpath_node &n) const;
    };
    // #line 1137 "cocos2d/cocos-headers/cocos2dx/robtop/xml/pugixml.hpp"
    class xpath_node_set
    {
    public:
        enum type_t
        {
            type_unsorted,
            type_sorted,
            type_sorted_reverse
        };

        typedef const xpath_node *const_iterator;

        xpath_node_set();

        xpath_node_set(const_iterator begin, const_iterator end, type_t type = type_unsorted);

        ~xpath_node_set();

        xpath_node_set(const xpath_node_set &ns);
        xpath_node_set &operator=(const xpath_node_set &ns);

        type_t type() const;

        size_t size() const;

        const xpath_node &operator[](size_t index) const;

        const_iterator begin() const;
        const_iterator end() const;

        void sort(bool reverse = false);

        xpath_node first() const;

        bool empty() const;

    private:
        type_t _type;

        xpath_node _storage;

        xpath_node *_begin;
        xpath_node *_end;

        void _assign(const_iterator begin, const_iterator end);
    };

    std::basic_string<char, std::char_traits<char>, std::allocator<char>> as_utf8(const wchar_t *str);
    std::basic_string<char, std::char_traits<char>, std::allocator<char>> as_utf8(const std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>> &str);

    std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>> as_wide(const char *str);
    std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>> as_wide(const std::basic_string<char, std::char_traits<char>, std::allocator<char>> &str);

    typedef void *(*allocation_function)(size_t size);

    typedef void (*deallocation_function)(void *ptr);

    void set_memory_management_functions(allocation_function allocate, deallocation_function deallocate);

    allocation_function get_memory_allocation_function();
    deallocation_function get_memory_deallocation_function();
};

class DS_Dictionary
{
public:
    pugi::xml_document doc;
    std::vector<pugi::xml_node> dictTree;
    bool compatible;

public:
    std::string cleanStringWhiteSpace(const std::string &);
    void split(const std::string &, char *, const std::vector<std::string> &);
    bool splitWithForm(const std::string &, std::vector<std::string> &);
    bool rectFromString(const std::string &, CCRect &);
    bool vec2FromString(const std::string &, CCPoint &);

public:
    DS_Dictionary();
    ~DS_Dictionary();

    static void copyFile(const char *, const char *);

    CCObject *decodeObjectForKey(const char *, bool, int);

    bool loadRootSubDictFromFile(const char *);
    bool loadRootSubDictFromCompressedFile(const char *);
    bool loadRootSubDictFromString(std::string);

    bool saveRootSubDictToFile(const char *);
    bool saveRootSubDictToCompressedFile(const char *);
    std::string saveRootSubDictToString();

    bool stepIntoSubDictWithKey(const char *);
    void stepOutOfSubDict();
    void stepBackToRootSubDict();

    unsigned int getNumKeys();
    std::string getKey(unsigned int);
    std::vector<std::string> getAllKeys();
    unsigned int getIndexOfKey(const char *);
    unsigned int getIndexOfKeyWithClosestAlphaNumericalMatch(const char *);
    void removeKey(unsigned int);
    void removeKey(const char *);
    void removeAllKeys();

    int getIntegerForKey(const char *);
    bool getBoolForKey(const char *);
    float getFloatForKey(const char *);
    std::string getStringForKey(const char *);
    CCPoint getVec2ForKey(const char *);
    CCRect getRectForKey(const char *);
    std::vector<std::string> getStringArrayForKey(const char *);
    std::vector<CCPoint> getVec2ArrayForKey(const char *);
    std::vector<CCRect> getRectArrayForKey(const char *);
    CCArray *getArrayForKey(const char *, bool);
    CCDictionary *getDictForKey(const char *, bool);
    CCObject *getObjectForKey(const char *);

    void setIntegerForKey(const char *, int);
    void setIntegerForKey(const char *, int, bool);
    void setBoolForKey(const char *, bool);
    void setBoolForKey(const char *, bool, bool);
    void setFloatForKey(const char *, float);
    void setFloatForKey(const char *, float, bool);
    void setStringForKey(const char *, const std::string &);
    void setStringForKey(const char *, const std::string &, bool);
    void setVec2ForKey(const char *, const CCPoint &);
    void setVec2ForKey(const char *, const CCPoint &, bool);
    void setRectForKey(const char *, const CCRect &);
    void setRectForKey(const char *, const CCRect &, bool);
    void setStringArrayForKey(const char *, const std::vector<std::string> &);
    void setStringArrayForKey(const char *, const std::vector<std::string> &, bool);
    void setVec2ArrayForKey(const char *, const std::vector<CCPoint> &);
    void setVec2ArrayForKey(const char *, const std::vector<CCPoint> &, bool);
    void setRectArrayForKey(const char *, const std::vector<CCRect> &);
    void setRectArrayForKey(const char *, const std::vector<CCRect> &, bool);
    void setArrayForKey(const char *, CCArray *);
    void setBoolMapForKey(const char *, const std::map<std::string, bool> &);
    void setSubDictForKey(const char *);
    void setSubDictForKey(const char *, bool, bool);
    void setDictForKey(const char *, CCDictionary *);
    void setObjectForKey(const char *, CCObject *);

    void addBoolValuesToMapForKey(const std::map<std::string, bool> &, const char *, bool);
    void addBoolValuesToMapForKeySpecial(const std::map<std::string, bool> &, const char *, bool);

    void checkCompatibility();
};





class CCHttpClient;
class CCHttpResponse;
typedef void (*SEL_HttpResponse)(CCHttpClient* client, CCHttpResponse* response);

typedef enum
{
    kHttpGet,
    kHttpPost,
    kHttpPut,
    kHttpDelete,
    kHttpUnkown,
} HttpRequestType;

class CCHttpRequest : public CCObject
{
public:
    /** Use this enum type as param in setReqeustType(param) */


protected:
    // properties
    HttpRequestType             _requestType;    /// kHttpRequestGet, kHttpRequestPost or other enums
    std::string                 _url;            /// target url that this request is sent to
    std::vector<char>           _requestData;    /// used for POST
    std::string                 _tag;            /// user defined tag, to identify different requests in response callback
    CCObject*          _pTarget;        /// callback target of pSelector function
    SEL_HttpResponse            _pSelector;      /// callback function, e.g. MyLayer::onHttpResponse(CCHttpClient *sender, CCHttpResponse * response)
    void*                       _pUserData;      /// You can add your customed data here 
    std::vector<std::string>    _headers;		      /// custom http headers

    int _requestTypeGJ;
    bool _shouldCancel;
    int _downloadProgress;
    int _readTimeout;
};


class CCHttpResponse : public CCObject
{

protected:    
    // properties
    CCHttpRequest*        _pHttpRequest;  /// the corresponding HttpRequest pointer who leads to this response 
    bool                _succeed;       /// to indecate if the http reqeust is successful simply
    std::vector<char>   _responseData;  /// the returned raw data. You can also dump it as a string
    std::vector<char>   _responseHeader;  /// the returned raw header data. You can also dump it as a string
    int                 _responseCode;    /// the status code returned from libcurl, e.g. 200, 404
    std::string         _errorBuffer;   /// if _responseCode != 200, please read _errorBuffer to find the reason 
};



class CCScale9Sprite : public CCNodeRGBA
{
public:
    CCScale9Sprite();
    virtual ~CCScale9Sprite();

public:
    /** Original sprite's size. */
    CCSize m_originalSize;
    /** Prefered sprite's size. By default the prefered size is the original size. */

    //if the preferredSize component is given as -1, it is ignored
    CCSize m_preferredSize; 
    /** 
     * The end-cap insets. 
     * On a non-resizeable sprite, this property is set to CGRectZero; the sprite 
     * does not use end caps and the entire sprite is subject to stretching. 
     */
    CCRect m_capInsets;
    /** Sets the left side inset */
    float _insetLeft;
    /** Sets the top side inset */
    float _insetTop;
    /** Sets the right side inset */
    float _insetRight;
    /** Sets the bottom side inset */
    float _insetBottom;

protected:
    bool m_bSpritesGenerated;
    CCRect m_spriteRect;
    bool   m_bSpriteFrameRotated;
    CCRect m_capInsetsInternal;
    bool m_positionsAreDirty;
    
    CCSpriteBatchNode* _scale9Image;
    CCSprite* _topLeft;
    CCSprite* _top;
    CCSprite* _topRight;
    CCSprite* _left;
    CCSprite* _centre;
    CCSprite* _right;
    CCSprite* _bottomLeft;
    CCSprite* _bottom;
    CCSprite* _bottomRight;

    bool _opacityModifyRGB;
    GLubyte _opacity;
    ccColor3B _color;
    
    void updateCapInset();
    void updatePositions();
};


// const char *cocos2dVersion();
