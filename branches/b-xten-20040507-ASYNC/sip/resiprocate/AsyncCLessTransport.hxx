#if !defined(RESIP_ASYNC_CLESS_TRANSPORT_HXX)
#define RESIP_ASYNC_CLESS_TRANSPORT_HXX

#include "resiprocate/external/AsyncTransportInterfaces.hxx"
#include "resiprocate/Transport.hxx"
#include "resiprocate/MsgHeaderScanner.hxx"

namespace resip
{
class AsyncCLessTransport : public Transport, public ExternalAsyncCLessTransportHandler
{
   public:
	 
      enum { MaxBufferSize = 65535 };
     

      AsyncCLessTransport(Fifo<Message>& rxFifo, ExternalAsyncCLessTransport* eaTransport, bool ownedByMe);
      virtual ~AsyncCLessTransport();

      //UDP send buffer overflows are not being captured
      bool isFinished() const { return true; }

      virtual bool isReliable() const { return false; }

      virtual TransportType transport() const { return mTransportType; }
      virtual bool isAsynchronous() const { return true; }

      virtual bool requiresProcess() { return true; }

      //may go away w/ transportSelector rewrite
      virtual void process(FdSet&) { assert(false); }
      virtual void buildFdSet( FdSet&){ assert(false); }
//      virtual int maxFileDescriptors() const { return 1;}
      virtual bool hasDataToSend() const { return false; }

      //ExternalAsyncCLessTransportHandler
      virtual void handleReceive(AsyncCLessReceiveResult res);

   protected:
      virtual void transmit(const Tuple& dest, const Data& pdata, const Data& tid);

      TransportType mTransportType;
      ExternalAsyncCLessTransport* mExternalTransport;
      MsgHeaderScanner mMsgHeaderScanner;
      bool mOwnedByMe;
};
}

/* ====================================================================
 * The Vovida Software License, Version 1.0 
* 
* Copyright (c) 2000 Vovida Networks, Inc.  All rights reserved.
* 
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
* 
* 1. Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
* 
* 2. Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in
*    the documentation and/or other materials provided with the
*    distribution.
* 
* 3. The names "VOCAL", "Vovida Open Communication Application Library",
*    and "Vovida Open Communication Application Library (VOCAL)" must
*    not be used to endorse or promote products derived from this
*    software without prior written permission. For written
*    permission, please contact vocal@vovida.org.
*
* 4. Products derived from this software may not be called "VOCAL", nor
*    may "VOCAL" appear in their name, without prior written
*    permission of Vovida Networks, Inc.
* 
* THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESSED OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND
* NON-INFRINGEMENT ARE DISCLAIMED.  IN NO EVENT SHALL VOVIDA
* NETWORKS, INC. OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT DAMAGES
* IN EXCESS OF $1,000, NOR FOR ANY INDIRECT, INCIDENTAL, SPECIAL,
* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
* PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
* OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
* USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
* 
* ====================================================================
* 
* This software consists of voluntary contributions made by Vovida
* Networks, Inc. and many individuals on behalf of Vovida Networks,
* Inc.  For more information on Vovida Networks, Inc., please see
* <http://www.vovida.org/>.
*
 */



#endif

