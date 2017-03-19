/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2014 Natale Patriciello <natale.patriciello@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include "tcp-wireless-ecn.h"
#include "ns3/log.h"
#include "ns3/tcp-socket-base.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("TcpWirelessEcn");
NS_OBJECT_ENSURE_REGISTERED (TcpWirelessEcn);

TypeId
TcpWirelessEcn::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::TcpWirelessEcn")
    .SetParent<TcpNewReno> ()
    .AddConstructor<TcpWirelessEcn> ()
    .SetGroupName ("Internet")
 
  ;
  return tid;
}





uint32_t
TcpWirelessEcn::GetSsThresh (Ptr<const TcpSocketState> state,
                         uint32_t bytesInFlight)
{
  NS_LOG_FUNCTION (this << state << bytesInFlight);

  if ( state->m_congState== TcpSocketState::CA_LOSS)
  {
      //  if ( TcpSocketBase::m_ecnState==TcpSocketBase::ECN_ECE_RCVD)
      //  {
       //         return std::max (2 * state->m_segmentSize, bytesInFlight / 2);

       // }
       // else
        ///{

                return state->m_ssThresh;

       // }

  }
  else
  {

  return std::max (2 * state->m_segmentSize, bytesInFlight / 2);
  }
  

}

Ptr<TcpCongestionOps>
TcpWirelessEcn::Fork (void)
{
  return CopyObject<TcpWirelessEcn> (this);
}

std::string
TcpWirelessEcn::GetName () const
{
  return "TcpWirelessEcn";
}


} // namespace ns3
