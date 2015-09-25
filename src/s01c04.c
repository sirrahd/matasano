

void main(int argc, char * argv[])
{
    const char * filename;

    if (argc <= 1)
    {
        const char defaultFile[] = "/share/s01c04.txt";
        filename = defaultFile;
    }
    else
    {
        filename = argv[1];
    }
}
