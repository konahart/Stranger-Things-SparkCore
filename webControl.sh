#!/bin/bash
curl https://api.particle.io/v1/devices/your-device-ID-goes-here/led \
  -d access_token=your-access-token-goes-here \
  -d params=your-command-goes-here

