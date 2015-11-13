#include "stdafx.h"
#include "bio_visitor_binder.hpp"


namespace Poco
{
	namespace Data
	{
		//typedef BioPerson PersonType;
		typedef Poco::Data::TypeHandler<VisitorType> BaseClass;


		void BaseClass::bind(std::size_t pos, const VisitorType& obj
			, AbstractBinder::Ptr pBinder, AbstractBinder::Direction dir)
		{
			poco_assert_dbg(!pBinder.isNull());

			pBinder->bind(pos++, obj.index()            , dir);
			pBinder->bind(pos++, obj.personIndexs()     , dir);
			pBinder->bind(pos++, obj.photoIndexs()      , dir);
			pBinder->bind(pos++, obj.detectedFaceCount(), dir);
			pBinder->bind(pos++, obj.fullPhotoPathway() , dir);
			pBinder->bind(pos++, obj.detectionTime()    , dir);
			pBinder->bind(pos++, obj.locationIndex()   , dir);
			pBinder->bind(pos++, obj.status()           , dir);

		}


		void BaseClass::prepare(std::size_t pos, const VisitorType& obj
			, AbstractPreparator::Ptr pPrepare)
		{
			//no-op (SQLite is prepare-less connector)
		}

		std::size_t BaseClass::size()
		{
			return BaseClass::DATABASE_COLUMNS_SIZE;
		}

		void BaseClass::extract(std::size_t pos, VisitorType& obj
			, const VisitorType& defVal, AbstractExtractor::Ptr pExt)
		{

			poco_assert_dbg(!pExt.isNull());

			std::string    person_indexs      ;
			std::string    photo_indexs       ;
			int       	   detected_face_count;
			std::string    full_photo_pathway ;
			Poco::DateTime detection_time     ;
			int            location_indexs    ;
			int            status             ;
			int            index              ;
			std::string    detection_time_str ;



			if (pExt->extract(pos++, index))
				obj.setIndex(index);
			else
				obj.setIndex(defVal.index());

			if (pExt->extract(pos++, person_indexs))
				obj.setPersonIndexs(person_indexs);
			else
				obj.setPersonIndexs(defVal.personIndexs());

			if (pExt->extract(pos++, photo_indexs))
				obj.setPhotoIndexs(photo_indexs);
			else
				obj.setPhotoIndexs(defVal.photoIndexs());

			if (pExt->extract(pos++, detected_face_count))
				obj.setDetectedFaceCount(detected_face_count);
			else
				obj.setDetectedFaceCount(defVal.detectedFaceCount());

			if (pExt->extract(pos++, detection_time_str))
			{
				int timezone;
				DateTimeParser::parse(DateTimeFormat::SORTABLE_FORMAT, detection_time_str, detection_time, timezone);
				obj.setDetectionTime(detection_time);
			}
			else
				obj.setDetectionTime(defVal.detectionTime());

			if (pExt->extract(pos++, location_indexs))
				obj.setLocationIndexs(location_indexs);
			else
				obj.setLocationIndexs(defVal.locationIndex());

			if (pExt->extract(pos++, status))
				obj.setStatus((SmartBio::Status)(status));
			else
				obj.setStatus(defVal.status());
		}

	}
}