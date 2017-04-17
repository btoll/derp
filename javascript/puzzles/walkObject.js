const walkObject = (o, str) => {
    const idx = str.indexOf('.');

    if (!~idx) {
        return [
            (!o || !o[str]) ?
                null :
                o,
            str
        ];
    }

    // If fn is called with foo object and 'bar.baz.quux', recurse, i.e.:
    //
    //      const foo = {
    //          bar: {
    //              baz: {
    //                  quux: true
    //              }
    //          }
    //      };
    //
    //      walkObject(foo, 'bar.baz.quux');
    //      // returns [{ quux: true }, 'quux']
    //
    //      Stack...
    //      fn(o['baz'], 'quux');
    //      fn(o['bar'], 'baz.quux');
    //      fn(o['foo'], 'bar.baz.quux');
    //
    return walkObject(o[str.slice(0, idx)], str.slice(idx + 1));
};

