#include "stdafx.h"
#include "bio_toolbar.hpp"

#include "bio_resources.hpp"
#include "bio_toolbar_resource.hpp"

#include <memory>

namespace SmartBio
{
	namespace View
	{

		BioToolBar::BioToolBar( wxWindow* parent
			                    , wxWindowID id 
			                    , const wxPoint& pos
			                    , const wxSize& size
			                    , long style ) 
													: wxAuiToolBar(parent, id, pos, size, style )
		{
			create();
		}

		BioToolBar::~BioToolBar()	{}

		void BioToolBar::create()
		{		
			this->SetToolBitmapSize(wxSize(ICON_SIZE, ICON_SIZE));
	
			std::unique_ptr<BioToolBarResource> resource( new BioToolBarResource() );
			
			addTool(UIToolbar::ID_JOURNAL      , *resource);
			addTool(UIToolbar::ID_MAIN_SETTINGS, *resource);
			addTool(UIToolbar::ID_USERS        , *resource);
			addTool(UIToolbar::ID_PERSONAL     , *resource);


			this->Realize();
		}		

		void BioToolBar::addTool(int index, BioToolBarResource& resource)
		{
			bool flag(false);
			UInfoItem item = resource.get(index, flag);

			if (flag)
			{
				this->AddTool(index, item.text(), item.bitmap(), item.hint());
			}			
		}	

	}
}