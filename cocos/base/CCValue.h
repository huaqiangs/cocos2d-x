/****************************************************************************
 Copyright (c) 2013 cocos2d-x.org
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __cocos2d_libs__CCValue__
#define __cocos2d_libs__CCValue__

#include "CCPlatformMacros.h"
#include "ccMacros.h"
#include <string>
#include <vector>
#include <unordered_map>

NS_CC_BEGIN

class Value;

typedef std::vector<Value> ValueVector;
typedef std::unordered_map<std::string, Value> ValueMap;
typedef std::unordered_map<int, Value> IntValueMap;

class Value
{
public:
    Value();
    explicit Value(int v);
    explicit Value(float v);
    explicit Value(double v);
    explicit Value(bool v);
    explicit Value(const char* v);
    explicit Value(const std::string& v);
    
    explicit Value(const ValueVector& v);
    explicit Value(ValueVector&& v);
    
    explicit Value(const ValueMap& v);
	explicit Value(ValueMap&& v);
    
    explicit Value(const IntValueMap& v);
    explicit Value(IntValueMap&& v);
    
    Value(const Value& other);
    Value(Value&& other);
    ~Value();
    
    Value& operator= (const Value& other);
    Value& operator= (Value&& other);
    
    int asInt() const;
    float asFloat() const;
    double asDouble() const;
    bool asBool() const;
    std::string asString() const;
    
    inline ValueVector& asValueVector() { return *_vectorData; }
    inline const ValueVector& asValueVector() const { return *_vectorData; }
    
    inline ValueMap& asValueMap() { return *_mapData; }
    inline const ValueMap& asValueMap() const { return *_mapData; }
    
    inline IntValueMap& asIntKeyMap() { return *_intKeyMapData; }
    inline const IntValueMap& asIntKeyMap() const { return *_intKeyMapData; }

    inline bool isNull() const { return _type == Type::NONE; }
    
    enum class Type
    {
        NONE,
        INTEGER,
        FLOAT,
        DOUBLE,
        BOOLEAN,
        STRING,
        VECTOR,
        MAP,
        INT_KEY_MAP
    };

    inline Type getType() const { return _type; };
    
private:
    union
    {
        int intVal;
        float floatVal;
        double doubleVal;
        bool boolVal;
    }_baseData;
    
    std::string _strData;
    ValueVector* _vectorData;
    ValueMap* _mapData;
    IntValueMap* _intKeyMapData;

    Type _type;
};

NS_CC_END


#endif /* defined(__cocos2d_libs__CCValue__) */
