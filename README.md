# ofxFunctional_08x

use functional in v0.8.x in Xcode/clang

## HOW TO

first, include.

	#include <ofxFunctional_08x.h>

and use like this. (this is blocks clang extension)
	
	function<int(int)> f = ^(int x) { ofLogNotice() << x; };

but we can't use like this...

	function<int(int)> f = [](int x) { ofxLogNotice() << x; };

## Reference

* ofxSatoruHiga

## Author

* ISHII 2bit [bufferRenaiss co., ltd.]
* ishii[at]buffer-renaiss.com

* HIGA Satoru

## License

MIT License.