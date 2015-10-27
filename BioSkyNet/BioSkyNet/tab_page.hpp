#ifndef TAB_PAGE_H_INCLUDED
#define TAB_PAGE_H_INCLUDED

class TabController;

namespace SmartBio { namespace View
{
	class TabPage : public wxScrolledWindow
	{
	public:
		typedef enum
		{
			CLOSED,
			OPEN,
			ACTIVE
		} State;

		TabPage ( wxWindow *parent, wxWindowID winid = wxID_ANY );

		virtual ~TabPage();

		void close();

		void setLabel( const wxString& label );
		void setStateMonitorVariable( State *state );

	protected:
		virtual void onLeavePage() ;
		virtual void onSelectPage();
		virtual void onClose()     ;

		void create      ();
		void subscribe   ();
		void unsubscribe ();

	protected:
		State  current_state_;
		State* state_;

	private:
		void onCloseCallback     ();
		void onLeavePageCallback ();
		void onSelectPageCallback();

		friend class TabController;


	private:
		virtual void do_create      () = 0;
		virtual void do_subscribe   () = 0;
		virtual void do_unsubscribe () = 0;
	};

}}

#endif

