from stem.descriptor import parse_file

for desc in parse_file('/home/btoll/.tor/cached-consensus'):
  print('found relay %s %s %s' % (desc.nickname, desc.address, desc.fingerprint))

