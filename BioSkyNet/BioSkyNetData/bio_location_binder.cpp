#include "stdafx.h"
#include "bio_location_binder.hpp"


namespace Poco
{
	namespace Data
	{
		//typedef BioPerson PersonType;
		typedef Poco::Data::TypeHandler<LocationType> BaseClass;


		void BaseClass::bind(std::size_t pos, const LocationType& obj
			, AbstractBinder::Ptr pBinder, AbstractBinder::Direction dir)
		{
			poco_assert_dbg(!pBinder.isNull());

			pBinder->bind(pos++, obj.location_name()     	,dir);
			pBinder->bind(pos++, obj.port_name()         	,dir);
			pBinder->bind(pos++, obj.email_notification()	,dir);
			pBinder->bind(pos++, obj.camera_name()       	,dir);
			pBinder->bind(pos++, obj.age_treshold()      	,dir);
			pBinder->bind(pos++, obj.face_confidence()   	,dir);
			pBinder->bind(pos++, obj.min_eye_distance()  	,dir);
			pBinder->bind(pos++, obj.max_eye_distance()  	,dir);
			pBinder->bind(pos++, obj.matching_treshold() 	,dir);
			pBinder->bind(pos++, obj.index()							  ,dir);

		}

		void BaseClass::prepare(std::size_t pos, const LocationType& obj
			, AbstractPreparator::Ptr pPrepare)
		{
			//no-op (SQLite is prepare-less connector)
		}

		std::size_t BaseClass::size()
		{
			return BaseClass::DATABASE_COLUMNS_SIZE;
		}

		void BaseClass::extract(std::size_t pos, LocationType& obj
			, const LocationType& defVal, AbstractExtractor::Ptr pExt)
		{

			poco_assert_dbg(!pExt.isNull());

			std::string location_name     	;
			std::string port_name         	;
			std::string email_notification	;
			std::string camera_name       	;
			int         age_treshold      	;
			float       face_confidence   	;
			float       min_eye_distance  	;
			float       max_eye_distance  	;
			float				matching_treshold 	;
			int				  index           	 	;


			if (pExt->extract(pos++, index))
				obj.setIndex(index);
			else
				obj.setIndex(defVal.index());

			if (pExt->extract(pos++, port_name))
				obj.setPortName(port_name);
			else
				obj.setPortName(defVal.port_name());

			if (pExt->extract(pos++, email_notification))
				obj.setEmailNotifiaction(email_notification);
			else
				obj.setEmailNotifiaction(defVal.email_notification());

			if (pExt->extract(pos++, camera_name))
				obj.setCameraName(camera_name);
			else
				obj.setCameraName(defVal.camera_name());

			if (pExt->extract(pos++, age_treshold))
				obj.setAgeTreshold(age_treshold);
			else
				obj.setAgeTreshold(defVal.age_treshold());

			if (pExt->extract(pos++, face_confidence))
				obj.setFaceConfidence(face_confidence);
			else
				obj.setFaceConfidence(defVal.face_confidence());

			if (pExt->extract(pos++, min_eye_distance))
				obj.setMinEyeDistance(min_eye_distance);
			else
				obj.setMinEyeDistance(defVal.min_eye_distance());

			if (pExt->extract(pos++, max_eye_distance))
				obj.setMaxEyeDistance(max_eye_distance);
			else
				obj.setMaxEyeDistance(defVal.max_eye_distance());

			if (pExt->extract(pos++, matching_treshold))
				obj.setMatchingTreshold(matching_treshold);
			else
				obj.setMatchingTreshold(defVal.matching_treshold());

			
		}

	}
}