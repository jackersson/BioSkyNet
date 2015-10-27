#ifndef Bio_ToolBar_INCLUDED
#define Bio_ToolBar_INCLUDED

namespace SmartBio
{
	namespace View
	{
		class BioToolBarResource;
		class BioToolBar : public wxAuiToolBar
		{
		public:
			BioToolBar ( wxWindow* parent
				         , wxWindowID id = wxID_ANY
								 , const wxPoint& pos = wxDefaultPosition
								 , const wxSize& size = wxDefaultSize
								 , long style = wxAUI_TB_DEFAULT_STYLE );

			virtual ~BioToolBar();

		private:
			static const int  ICON_SIZE = 48;

			void create();

			void addTool(int id, BioToolBarResource& res);
		};

	}

}

#endif
