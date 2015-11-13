#include "stdafx.h"
#include "bio_model.hpp"

namespace SmartBio {
	namespace Model
	{

		BioModel::BioModel() : IModel()
		{
			initialize();
		}


		BioModel::~BioModel()
		{
		}

		void BioModel::do_initialize()
		{						
			db_engine_ = new Data::BioDbIO("F:\\SmartProjects\\SmartBio\\SmartBio\\database\\bioskynet.db");
		}



	}
}