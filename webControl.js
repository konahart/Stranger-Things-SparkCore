var parameters = {action: 'your-command-goes-here'}

var https = require('https')
var options = {
  hostname: 'api.particle.io',
  port: 443,
  path: '/v1/devices/your-device-ID-goes-here/led?access_token=your-access-token-goes-here',
  method: 'POST',
  headers: {'Content-Type': 'application/x-www-form-urlencoded'},
}
var req = https.request(options)
req.write('args=' + parameters.action)
req.end()
