import sys

def generate_header_file(class_name):
	header_content = f'''#ifndef {class_name.upper()}_HPP
#define {class_name.upper()}_HPP

class {class_name} {{
public:
	{class_name}(void);
	{class_name}({class_name} const & src);
	~{class_name}(void);
	{class_name}&	operator=({class_name} const & rhs);

private:
	// Member variables

}};

#endif
'''

	with open(f'{class_name}.hpp', 'w') as file:
		file.write(header_content)

def generate_cpp_file(class_name):
	cpp_content = f'''#include "{class_name}.hpp"

{class_name}::{class_name}(void) {{
	return;
}}

{class_name}::{class_name}({class_name} const & src) {{
	*this = src;
	return;
}}

{class_name}::~{class_name}(void) {{
	return;
}}

{class_name}&	{class_name}::operator=({class_name} const & rhs) {{
	if (this == &rhs) {{
		return *this;
	}}
	return *this;
}}
'''

	with open(f'{class_name}.cpp', 'w') as file:
		file.write(cpp_content)


def generate_canonical_class_files(class_name):
	generate_header_file(class_name)
	generate_cpp_file(class_name)


if __name__ == '__main__':
	if len(sys.argv) != 2:
		print('Usage: python3 generate_canonical_class.py <class_name>')
	else:
		class_name = sys.argv[1]
		generate_canonical_class_files(class_name)

