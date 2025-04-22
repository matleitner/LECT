from lxml import etree

def main():
    doc = etree.parse("playlist.xspf")

    schema  =etree.parse("xspf-1_0.7.rng")
    validator = etree.RelaxNG(schema)
    print(validator.validate(doc))

    print(validator.error_log.last_error)


main()