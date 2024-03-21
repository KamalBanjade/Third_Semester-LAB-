const actualPassword = 'K@M@L'; // Replace this with the actual password
const encodedPassword = encodeURIComponent(actualPassword);

const uri = `mongodb+srv://kamalbanjade:${encodedPassword}@cluster0.sf0urdt.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0`;

console.log(uri);
