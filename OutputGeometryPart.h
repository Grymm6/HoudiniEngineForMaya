#ifndef __OutputGeometryPart_h__
#define __OutputGeometryPart_h__

#include <maya/MIntArray.h>
#include <maya/MFloatPointArray.h>
#include <maya/MFloatArray.h>
#include <maya/MFnArrayAttrsData.h>
#include <maya/MVectorArray.h>
#include <maya/MString.h>

class Asset;

class OutputGeometryPart
{
    public:
        OutputGeometryPart(
                HAPI_NodeId nodeId,
                HAPI_PartId partId
                );
        ~OutputGeometryPart();

        MStatus compute(
                const MTime &time,
                MDataHandle& handle,
                bool hasMaterialChanged,
                bool &needToSyncOutputs
                );

    protected:
        void update();

    private:
        void computeMaterial(
                const MTime &time,
                MDataHandle &materialHandle
                );

        void computeMesh(
                const MTime &time,
                MDataHandle &hasMeshHandle,
                MDataHandle &meshHandle
                );
        void computeParticle(
                const MTime &time,
                MDataHandle &hasParticlesHandle,
                MDataHandle &particleHandle
                );
        void computeCurves(
                const MTime &time,
                MDataHandle &curvesHandle,
                MDataHandle &curvesIsBezierHandle
                );
        void computeVolume(
                const MTime &time,
                MDataHandle &volumeHandle
                );
        void computeVolumeTransform(
                const MTime &time,
                MDataHandle &volumeTransformHandle
                );
        void computeInstancer(
                const MTime &time,
                MDataHandle &hasInstancerHandle,
                MDataHandle &instanceHandle
                );
        void computeExtraAttributes(
                const MTime &time,
                MDataHandle &extraAttributesHandle
                );
        void computeGroups(
                const MTime &time,
                MDataHandle &extraAttributesHandle
                );

        template<typename T>
        bool getAttributeData(
                std::vector<T> &array,
                const char* name,
                HAPI_AttributeOwner owner
                );

        template<typename T>
        void convertParticleAttribute(
                T arrayDataFn,
                const char* houdiniName
                );

        bool computeExtraAttribute(
                MDataHandle &dataHandle,
                HAPI_AttributeOwner attributeOwner,
                const char* attributeName
                );

        void markAttributeUsed(const std::string &attributeName);
        bool isAttributeUsed(const std::string &attributeName);
        void clearAttributesUsed();

    private:
        HAPI_NodeId myNodeId;
        HAPI_PartId myPartId;

        std::vector<std::string> myAttributesUsed;

        HAPI_GeoInfo myGeoInfo;
        HAPI_PartInfo myPartInfo;
        HAPI_VolumeInfo myVolumeInfo;
        HAPI_CurveInfo myCurveInfo;
};

#endif
