#if !defined(UDPTRANSPORT_HXX)
#define UDPTRANSPORT_HXX

namespace Vocal2
{

class TuIM
{
   public:

      class PageCallback
      {
         public:
            virtual void receivedPage(const Data& msg, const Uri& from ); 
            virtual ~PageCallback();
      };
      
      class ErrCallback
      {
         public:
            virtual void sendPageFailed(const Uri& dest );
            virtual ~ErrCallback();
      };
      
      TuIM(SipStack* stack, 
           const Uri& aor, 
           const Uri& contact,
           PageCallback* pageCallback, 
           ErrCallback* errCallback);
      
      void sendPage(const Data& text, const Uri& dest);

      void process();
      
   private:
      PageCallback* mPageCallback;
      ErrCallback* mErrCallback; 
      SipStack* mStack;
      Uri mAor;
      Uri mContact;
};

}

#endif


/* ====================================================================
 * The Vovida Software License, Version 1.0 
 */

