// Determine if any two array elements equal 8.
// Stop after the first find.
//
const findFirstSumOf8 = list => {
    for (let i = 0; i < list.length; i++) {
        for (let j = i + 1; j < list.length; j++) {
            if ((list[j] + list[i]) === 8) {
                return [
                    JSON.stringify(list),
                    `Element: ${i}, value ${list[i]}`,
                    `Element: ${j}, value ${list[j]}\n`
                ].join('\n');
            }
        }
    }

    return [
        JSON.stringify(list),
        'No two array elements equal 8\n'
    ].join('\n');
};

const listA = [1, 2, 4, 9];
console.log('listA...');
console.log(findFirstSumOf8(listA));

const listB = [1, 2, 7, 9];
console.log('listB...');
console.log(findFirstSumOf8(listB));

const listC = [3, -1, 5, 9];
console.log('listC...');
console.log(findFirstSumOf8(listC));

const listD = [-3, -1, 9, 17];
console.log('listD...');
console.log(findFirstSumOf8(listD));

