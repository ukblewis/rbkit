# Extending Rbkit

Currently Rbkit exposes hooks when data is ready to be sent from the server.
This allows you to dump data to files, or use a different transport mechanism,
or whatever it is you want to do with the data.

The following example shows how to do this:

```ruby
server = Rbkit.start_server

server.respond_callback = -> (message) { .. do what you want with response messages .. }
server.publish_callback = -> (message) { .. do what you want with messages containing profiling data .. }

server.process_incoming_request('handshake')
# Above triggers respond_callback with handshake response

server.process_incoming_request('objectspace_snapshot')
# Above triggers respond_callback with "ok" and
# publish_callback with MessagePacked data containing the objectspace dump when it's ready
```

Checkout how [Rbkit::Websocket](https://github.com/code-mancers/rbkit-websocket/blob/master/lib/rbkit/websocket.rb#L42-L48)
uses these callbacks to send the messages over websockets, to get a better idea.
