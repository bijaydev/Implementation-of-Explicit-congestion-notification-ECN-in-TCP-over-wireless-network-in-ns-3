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
