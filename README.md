## osxsleep

osxreachability allows to monitor a Mac's network reachability

Example usage:

```sh

  const reach = require('osxreachability');
   
  ...

  reach.Reachability.start(function(state){

	switch(state) {

		case reach.NOT_REACHABLE:
			// ...
			break;

		case reach.REACHABLE_WIFI:
			// ...
			break;
	}
  });

  ...
  
  reach.Reachability.stop();
 
```
