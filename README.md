# ofxFunctional_08x

use functional in v0.8.x in Xcode/clang

## HOW TO

first, include.

	#include "ofxFunctional_08x.h"

and use like this. (this is *blocks*, clang extension)
	
	function<int(int)> f = ^(int x) { ofLogNotice() << x; };

but we can't use like this...

	function<int(int)> f = [](int x) { ofxLogNotice() << x; };

default capture is immutable copy.

    int m = 0;
    function<void(void)> f = ^(){ ofLogNotice() << m++; }; // Error
    f();

use **ofxFunctionalReference** like this.

    ofxFunctionalReference(int, n);
    function<void(void)> g = ^(){ n = 100; ofLogNotice() << n; };

and like this.

    ofxFunctionalReference(int, k) = 0;
    function<void(void)> h = ^(){ ofLogNotice() << k++; };
    h();
    h();
    h();

or use *__block* keyword directly like this. (but we **DON'T** recommend)

    __block string str = "";
    function<const string &()> p = ^{ return str += "str"; };
    ofLogNotice() << p();
    ofLogNotice() << p();
    ofLogNotice() << p();

## Reference

* ofxSatoruHiga

## Author

* ISHII 2bit [bufferRenaiss co., ltd.]
* ishii[at]buffer-renaiss.com

* HIGA Satoru

## License

MIT License.