#include "stdafx.h"
#include "bio_visitors.hpp"

namespace SmartBio
{
	namespace Data
	{
		BioVisitor::BioVisitor() : person_indexs_("")
			, photo_indexs_					("")
			, detected_face_count_  (0)
			, full_photo_pathway_   ("")
			, detection_time_       (0)
			, location_indexs_      ("")
			, status_               (Status::Access)

		{
			
		}
		BioVisitor::BioVisitor(int index
			, const std::string&    person_indexs
			, const std::string&    photo_indexs
			, int               	  detected_face_count
			, const std::string&    full_photo_pathway
			, const Poco::DateTime& detection_time
			, const std::string&    location_indexs
			, Status                status             )
			: index_(index)
			, person_indexs_      (person_indexs      )
			, photo_indexs_       (photo_indexs       )
			, detected_face_count_(detected_face_count)
			, full_photo_pathway_ (full_photo_pathway )
			, detection_time_     (detection_time     )
			, location_indexs_    (location_indexs    )
			, status_             (status             )

		{

		}

		BioVisitor::~BioVisitor() {}


		const std::string& BioVisitor::personIndexs() const
		{
			return person_indexs_;
		}

		const std::string&  BioVisitor::photoIndexs() const
		{
			return photo_indexs_;
		}

		int  BioVisitor::detectedFaceCount() const
		{
			return detected_face_count_;
		}

		const std::string& BioVisitor::fullPhotoPathway() const
		{
			return full_photo_pathway_;
		}

		const Poco::DateTime& BioVisitor::detectionTime() const
		{
			return detection_time_;
		}

		const std::string& BioVisitor::locationIndexs() const
		{
			return location_indexs_;
		}


		int BioVisitor::index() const
		{
			return index_;
		}

		Status BioVisitor::status() const
		{
			return status_;
		}

		void BioVisitor::setPersonIndexs(const std::string& person_indexs)
		{
			person_indexs_ = person_indexs;
		}

		void BioVisitor::setPhotoIndexs(const std::string& photo_indexs)
		{
			photo_indexs_ = photo_indexs;
		}

		void BioVisitor::setDetectedFaceCount(const int detected_face_count)
		{
			detected_face_count_ = detected_face_count;
		}

		void BioVisitor::setFullPhotoPathway(const std::string& full_photo_pathway)
		{
			full_photo_pathway_ = full_photo_pathway;
		}

		void BioVisitor::setDetectionTime(const Poco::DateTime& detection_time)
		{
			detection_time_ = detection_time;
		}

		void BioVisitor::setLocationIndexs(const std::string& location_indexs)
		{
			location_indexs_ = location_indexs;
		}

		void BioVisitor::setStatus(Status status)
		{
			status_ = status;
		}

		void BioVisitor::setIndex(int index)
		{
			index_ = index;
		}
		


	}
}