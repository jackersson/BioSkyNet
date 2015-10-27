#include "stdafx.h"
#include "bio_info_resource.hpp"

#include "bio_resources.hpp"

namespace SmartBio
{
	namespace View
	{
		BioInfoResource::BioInfoResource() {
			initialize();
		}

		BioInfoResource::~BioInfoResource()	{}

		void BioInfoResource::do_initialize()
		{
		
			std::string p_personal_info         = "Personal information";
			std::string p_personal_info_icon    = "resources\\pages\\profile.png";

			std::string p_face_info             = "Faces manager";
			std::string p_face_info_icon        = "resources\\pages\\face.png";
			 
			std::string p_fingerprint_info      = "Fingerprints manager";
			std::string p_fingerprint_info_icon = "resources\\pages\\fingerprint.png";

			std::string p_irises_info           = "Irises manager";
			std::string p_irises_info_icon      = "resources\\pages\\iris.png";


			UInfoItem personal_info   ( p_personal_info   , "", p_personal_info_icon   , "");
			UInfoItem face_info       ( p_face_info       , "", p_face_info_icon       , "");
			UInfoItem fingerprint_info( p_fingerprint_info, "", p_fingerprint_info_icon, "");
			UInfoItem irises_info     ( p_irises_info     , "", p_irises_info_icon     , "");

			insert(UIResources::ID_PERSON_INFO_PAGE     , personal_info   );
			insert(UIResources::ID_FACE_INFO_PAGE       , face_info       );
			insert(UIResources::ID_FINGERPRINT_INFO_PAGE, fingerprint_info);
			insert(UIResources::ID_IRIS_INFO_PAGE       , irises_info     );
		}
	}
}