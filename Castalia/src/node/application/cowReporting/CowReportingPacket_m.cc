//
// Generated file, do not edit! Created by opp_msgc 4.5 from src/node/application/cowReporting/CowReportingPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "CowReportingPacket_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

CowReportData::CowReportData()
{
    nodeID = 0;
    sim_time = 0;
    gps_x = 0;
    gps_y = 0;
    acel_x = 0;
    acel_y = 0;
    acel_z = 0;
}

void doPacking(cCommBuffer *b, CowReportData& a)
{
    doPacking(b,a.nodeID);
    doPacking(b,a.sim_time);
    doPacking(b,a.gps_x);
    doPacking(b,a.gps_y);
    doPacking(b,a.acel_x);
    doPacking(b,a.acel_y);
    doPacking(b,a.acel_z);
}

void doUnpacking(cCommBuffer *b, CowReportData& a)
{
    doUnpacking(b,a.nodeID);
    doUnpacking(b,a.sim_time);
    doUnpacking(b,a.gps_x);
    doUnpacking(b,a.gps_y);
    doUnpacking(b,a.acel_x);
    doUnpacking(b,a.acel_y);
    doUnpacking(b,a.acel_z);
}

class CowReportDataDescriptor : public cClassDescriptor
{
  public:
    CowReportDataDescriptor();
    virtual ~CowReportDataDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(CowReportDataDescriptor);

CowReportDataDescriptor::CowReportDataDescriptor() : cClassDescriptor("CowReportData", "")
{
}

CowReportDataDescriptor::~CowReportDataDescriptor()
{
}

bool CowReportDataDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<CowReportData *>(obj)!=NULL;
}

const char *CowReportDataDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int CowReportDataDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int CowReportDataDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *CowReportDataDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "nodeID",
        "sim_time",
        "gps_x",
        "gps_y",
        "acel_x",
        "acel_y",
        "acel_z",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int CowReportDataDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "nodeID")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sim_time")==0) return base+1;
    if (fieldName[0]=='g' && strcmp(fieldName, "gps_x")==0) return base+2;
    if (fieldName[0]=='g' && strcmp(fieldName, "gps_y")==0) return base+3;
    if (fieldName[0]=='a' && strcmp(fieldName, "acel_x")==0) return base+4;
    if (fieldName[0]=='a' && strcmp(fieldName, "acel_y")==0) return base+5;
    if (fieldName[0]=='a' && strcmp(fieldName, "acel_z")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *CowReportDataDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "double",
        "double",
        "double",
        "double",
        "double",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *CowReportDataDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int CowReportDataDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    CowReportData *pp = (CowReportData *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string CowReportDataDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    CowReportData *pp = (CowReportData *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->nodeID);
        case 1: return oppstring2string(pp->sim_time);
        case 2: return double2string(pp->gps_x);
        case 3: return double2string(pp->gps_y);
        case 4: return double2string(pp->acel_x);
        case 5: return double2string(pp->acel_y);
        case 6: return double2string(pp->acel_z);
        default: return "";
    }
}

bool CowReportDataDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    CowReportData *pp = (CowReportData *)object; (void)pp;
    switch (field) {
        case 0: pp->nodeID = (value); return true;
        case 1: pp->sim_time = (value); return true;
        case 2: pp->gps_x = string2double(value); return true;
        case 3: pp->gps_y = string2double(value); return true;
        case 4: pp->acel_x = string2double(value); return true;
        case 5: pp->acel_y = string2double(value); return true;
        case 6: pp->acel_z = string2double(value); return true;
        default: return false;
    }
}

const char *CowReportDataDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *CowReportDataDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    CowReportData *pp = (CowReportData *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(CowReportingDataPacket);

CowReportingDataPacket::CowReportingDataPacket(const char *name, int kind) : ::ApplicationPacket(name,kind)
{
}

CowReportingDataPacket::CowReportingDataPacket(const CowReportingDataPacket& other) : ::ApplicationPacket(other)
{
    copy(other);
}

CowReportingDataPacket::~CowReportingDataPacket()
{
}

CowReportingDataPacket& CowReportingDataPacket::operator=(const CowReportingDataPacket& other)
{
    if (this==&other) return *this;
    ::ApplicationPacket::operator=(other);
    copy(other);
    return *this;
}

void CowReportingDataPacket::copy(const CowReportingDataPacket& other)
{
    this->extraData_var = other.extraData_var;
}

void CowReportingDataPacket::parsimPack(cCommBuffer *b)
{
    ::ApplicationPacket::parsimPack(b);
    doPacking(b,this->extraData_var);
}

void CowReportingDataPacket::parsimUnpack(cCommBuffer *b)
{
    ::ApplicationPacket::parsimUnpack(b);
    doUnpacking(b,this->extraData_var);
}

CowReportData& CowReportingDataPacket::getExtraData()
{
    return extraData_var;
}

void CowReportingDataPacket::setExtraData(const CowReportData& extraData)
{
    this->extraData_var = extraData;
}

class CowReportingDataPacketDescriptor : public cClassDescriptor
{
  public:
    CowReportingDataPacketDescriptor();
    virtual ~CowReportingDataPacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(CowReportingDataPacketDescriptor);

CowReportingDataPacketDescriptor::CowReportingDataPacketDescriptor() : cClassDescriptor("CowReportingDataPacket", "ApplicationPacket")
{
}

CowReportingDataPacketDescriptor::~CowReportingDataPacketDescriptor()
{
}

bool CowReportingDataPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<CowReportingDataPacket *>(obj)!=NULL;
}

const char *CowReportingDataPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int CowReportingDataPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int CowReportingDataPacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *CowReportingDataPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "extraData",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int CowReportingDataPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "extraData")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *CowReportingDataPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "CowReportData",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *CowReportingDataPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int CowReportingDataPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    CowReportingDataPacket *pp = (CowReportingDataPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string CowReportingDataPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    CowReportingDataPacket *pp = (CowReportingDataPacket *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getExtraData(); return out.str();}
        default: return "";
    }
}

bool CowReportingDataPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    CowReportingDataPacket *pp = (CowReportingDataPacket *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *CowReportingDataPacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return opp_typename(typeid(CowReportData));
        default: return NULL;
    };
}

void *CowReportingDataPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    CowReportingDataPacket *pp = (CowReportingDataPacket *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getExtraData()); break;
        default: return NULL;
    }
}


