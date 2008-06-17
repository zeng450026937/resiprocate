#ifndef P2P_Signable_hxx
#define P2P_Signable_hxx

#include "rutil/Data.hxx"
#include <vector>

namespace p2p
{

class Signable 
{
   public:
   	  virtual ~Signable() {}
      void sign();
      bool isValid() const;
      
      const resip::Data& getSignature() const
      {
         return mSignature;
      }
      
   protected:         
      virtual std::vector<const resip::Data> collectSignableData() const = 0;
      void setSignature(const resip::Data& signature) 
      {
         mSignature = signature;
      }

   private:
      resip::Data mSignature;
};

#endif
