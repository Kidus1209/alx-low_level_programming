#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <elf.h>
#include <unistd.h>
void print_magic(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void check_elf(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void close_elf(int elf);

/**
 * print_type - Prints ELF Header Type,
 * @e_ident: An Indicator To An Array Which Has Class of Elf,
 *
 * @e_type: Type Of The ELf
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
        if (e_ident[EI_DATA] == ELFDATA2MSB)
                e_type >>= 8;

        printf(" Type: ");

        switch (e_type)
        {
        case ET_NONE:
                printf("NONE (None)\n");
                break;
        case ET_REL:
                printf("REL (Relocatable file)\n");
                break;
        case ET_EXEC:
                printf("EXEC (Executable file)\n");
                break;
        case ET_DYN:
                printf("DYN (Shared object file)\n");
                break;
        case ET_CORE:
                printf("CORE (Core file)\n");
                break;
        default:
                printf("<unknown: %x>\n", e_type);
        }
}

/**
 * @e_ident: An Indicator To An Array Which Has ABI version ELF,
 * print_abi - This Prints ELf Header Of Abi Version,
 *
 */
void print_abi(unsigned char *e_ident)
{
        printf(" ABI Version: %d\n",
                e_ident[EI_ABIVERSION]);
}

/**
 * check_elf - Checker Of Files if its elf or not
 * Description: If file ain't elf file then its exit code is 98,
 *
 * @e_ident: An Indicator To An Array Which Has magic numbers of elf,
 *
 */
void check_elf(unsigned char *e_ident)
{
	int V;

	for (V = 0; V < 4; V++)
	{
		if (e_ident[V] != 127 &&
		    e_ident[V] != 'E' &&
		    e_ident[V] != 'L' &&
		    e_ident[V] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * @e_ident: An Indicator To An Array Which Has Class of Elf,
 * print_class - This Prints ELf Header Of Class,
 *
 */
void print_class(unsigned char *e_ident)
{
	printf(" Class: ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * @e_ident: An Indicator To An Array Which Has version of Elf,
 * print_version - This Prints ELf Header Version,
 *
 */
void print_version(unsigned char *e_ident)
{
	 printf(" Version: %d",
			  e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * @e_ident: An Indicator To An Array Which Has version of Elf,
 *
 * print_osabi - This Prints Elf Header Of OS&ABI,
 */
void print_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI: ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_magic - This Prints Elf Magic Numbers,
 * Description: We Detach Magic Numbers By Using Space
 *
 * @e_ident: An Indicator To An Array Which Has magic numbers of elf,
 *
 */
void print_magic(unsigned char *e_ident)
{
        int v;

        printf(" Magic: ");

        for (v = 0; v < EI_NIDENT; v++)
        {
                printf("%02x", e_ident[v]);

                if (v == EI_NIDENT - 1)
                        printf("\n");
                else
                        printf(" ");
        }
}

/**
 * @e_ident: An Indicator To An Array Which Has Class of Elf,
 * print_data - This Prints ELf Header Of Class,
 *
 */
void print_data(unsigned char *e_ident)
{
        printf(" Data: ");

        switch (e_ident[EI_DATA])
        {
        case ELFDATANONE:
                printf("none\n");
                break;
        case ELFDATA2LSB:
                printf("2's complement, little endian\n");
                break;
        case ELFDATA2MSB:
                printf("2's complement, big endian\n");
                break;
        default:
                printf("<unknown: %x>\n", e_ident[EI_CLASS]);
        }
}

/**
 * print_type - Prints ELF Header Type,
 * @e_type: Type of ELf,
 *
 * @e_ident: An Indicator To An Array Which Has Class of Elf,
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf(" Type: ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}
/**
 * main - Shows The Information In The Header Of ELf,
 *
 * @argc: Amount Of Arguments Used,
 * @argv: Indicator To The Argument Array,
 *
 * Return: If Success Then It Is 0,
 * Description: If File Aint Elf File Then The Exit Code is 98,
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int J, I;

	J = open(argv[1], O_RDONLY);
	if (J == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(J);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	I = read(J, header, sizeof(Elf64_Ehdr));
	if (I == -1)
	{
		free(header);
		close_elf(J);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(J);
	return (0);
}

/**
 * print_entry - Prints the ELF headers Entry Point,
 *
 * @e_entry: Label Of Entry Point ELf,
 *
 * @e_ident: An Indicator To An Array Which Has Class of Elf,
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address: ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 7) & 0xFF00FF00) |
			  ((e_entry >> 7) & 0xFF00FF);
		e_entry = (e_entry << 14) | (e_entry >> 14);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}
