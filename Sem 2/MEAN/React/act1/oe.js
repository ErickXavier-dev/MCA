const num = Number(process.argv[2]);

if(num %2 == 0){
    console.log(`${num} is an even number.`);
} else {
    console.log(`${num} is an odd number.`);
}