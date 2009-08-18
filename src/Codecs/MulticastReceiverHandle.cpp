// Copyright (c) 2009, Object Computing, Inc.
// All rights reserved.
// See the file license.txt for licensing information.
//
#include <Common/QuickFASTPch.h>
#include "MulticastReceiverHandle.h"
#include <Codecs/MulticastReceiver.h>

namespace QuickFAST{
  namespace Codecs {
    class MulticastReceiverHandle_i
    {
    public:
      MulticastReceiverHandle_i(
        const std::string & multicastGroupIP,
        const std::string & listenInterfaceIP,
        unsigned short portNumber)
        :ptr_(new MulticastReceiver(
                  multicastGroupIP,
                  listenInterfaceIP,
                  portNumber))
      {
      }

      MulticastReceiverPtr ptr_;
    };
  }
}


using namespace QuickFAST;
using namespace Codecs;

MulticastReceiverHandle::MulticastReceiverHandle(
    const std::string & multicastGroupIP,
    const std::string & listenInterfaceIP,
    unsigned short portNumber)
  : pImpl_(new MulticastReceiverHandle_i(
            multicastGroupIP,
            listenInterfaceIP,
            portNumber))
{
}

MulticastReceiverHandle::~MulticastReceiverHandle()
{
  delete pImpl_;
}

size_t
MulticastReceiverHandle::bytesReadable() const
{
  return pImpl_->ptr_->packetsProcessed();
}

size_t
MulticastReceiverHandle::noBufferAvailable() const
{
  return pImpl_->ptr_->packetsProcessed();
}

size_t
MulticastReceiverHandle::packetsReceived() const
{
  return pImpl_->ptr_->packetsProcessed();
}

size_t
MulticastReceiverHandle::packetsProcessed() const
{
  return pImpl_->ptr_->packetsProcessed();
}

size_t
MulticastReceiverHandle::packetsWithErrors() const
{
  return pImpl_->ptr_->packetsProcessed();
}

size_t
MulticastReceiverHandle::emptyPackets() const
{
  return pImpl_->ptr_->packetsProcessed();
}

size_t
MulticastReceiverHandle::bytesReceived() const
{
  return pImpl_->ptr_->packetsProcessed();
}

size_t
MulticastReceiverHandle::bytesProcessed() const
{
  return pImpl_->ptr_->packetsProcessed();
}

void
MulticastReceiverHandle::start(
  BufferConsumer &  bufferConsumer,
  size_t bufferSize,
  size_t bufferCount)
{
  pImpl_->ptr_->start(bufferConsumer, bufferSize, bufferCount);
}

void
MulticastReceiverHandle::run(unsigned short additionalThreads, bool useThisThread)
{
  pImpl_->ptr_->runThreads(additionalThreads, useThisThread);
}

void
MulticastReceiverHandle::joinThreads()
{
  pImpl_->ptr_->joinThreads();
}

void
MulticastReceiverHandle::stop()
{
  pImpl_->ptr_->stop();
}
