type Solution struct{}

func (s *Solution) Encode(strs []string) string {
	var b strings.Builder
	
	b.WriteByte('l')
	b.WriteString(strconv.Itoa(len(strs)))
	b.WriteByte(':')

	for _, str := range strs {
		b.WriteString(strconv.Itoa(len(str)))
		b.WriteByte(':')
		b.WriteString(str)
	}

	b.WriteByte('e')

	return b.String()
}

func (s *Solution) Decode(encoded string) []string {
	str := encoded 
	if len(str) < 2 || str[0] != 'l' {
		return nil 
	}

	str = str[1:]

	colonIdx := strings.Index(str, ":")
	numStrs, _ := strconv.Atoi(str[:colonIdx])
	str = str[colonIdx+1:]

	result := make([]string, 0, numStrs)
	for i := 0; i < numStrs; i++ {
		colonIdx = strings.Index(str, ":")
		strLen, _ := strconv.Atoi(str[:colonIdx])
		str = str[colonIdx+1:]
		result = append(result, str[:strLen])
		str = str[strLen:]
	}
	return result 
}
