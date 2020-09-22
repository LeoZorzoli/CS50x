
function send()
{
    let name = document.querySelector('#name').value;
    if (name === '')
    {
        name = 'Visitor';
    }
    document.querySelector('#first').innerHTML = "Welcome to my page " + name + "!";
}



