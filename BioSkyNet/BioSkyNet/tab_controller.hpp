#ifndef TAB_CONTROLLER_H_INCLUDED
#define TAB_CONTROLLER_H_INCLUDED

namespace SmartBio { namespace View
{

	class TabController : public wxAuiNotebook
	{
	public:
		TabController( wxWindow* parent
			           , wxWindowID winid = wxID_ANY
			           , const wxPoint &pos = wxDefaultPosition
								 , const wxSize &size = wxDefaultSize
								 , long style = wxAUI_NB_DEFAULT_STYLE );

		virtual ~TabController();

		void closeAllPages();

	private:
		void onPageChange( wxAuiNotebookEvent& event );
		void onPageClose ( wxAuiNotebookEvent& event );

	private: 
		void subscribe  ();
		void unsubscribe();

	};

}}

#endif

